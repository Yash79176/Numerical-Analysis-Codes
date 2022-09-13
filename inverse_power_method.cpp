#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>    //Returns the number of elements in a vector.
using namespace std;
using vec    = vector<double>;         // vector
using matrix = vector<vec>;            // matrix (=collection of (row) vectors)

int main() {
    matrix A = { {5,4,1,1}, {4,5,1,1}, {1,1,4,2},{1,1,2,4} };
    int i,j,n=4, k, Nmax = 10000;
    double x0[n],q,c[n],sum1, sum2,I[n][n], AMinusQ[n][n],p,yn, y0[n], xm, ym, nu,x1[n], lambda, tol = 0.00000001;
    double ratio,delta=0.1, sum3;
    int iteration = 1;

    //printing A-matrix:
    cout<<("The A-Matrix is:")<<endl;
    for(i=0;i<n;i++) {
       for(j=0;j<n;j++){
        cout << A[i][j] << '\t';
        }
    cout << '\n';

    }
    // Taking initial guess of x:
    cout << '\n';
    cout<<"The initial guess of x0 is:"<<endl;
        for (i=0;i<n;i++){
            x0[i] = rand()%10;
        }
        for(i=0;i<n;i++){
        cout<<x0[i]<<'\t';
    }
    //getting maximam element in x0 matrix and updating it by dividing by maximam element:
    xm = 0;
    for(i=0;i<n;i++){
        if(fabs(x0[i]) > xm)
            xm = fabs(x0[i]);
    }
    for(i=0;i<n;i++){
        x0[i] = x0[i]/xm;
    }
    do{
    //Getting value of q:
    /* for(i=0;i<n;i++){
        c[i] = 0;
        for(j=0;j<n;j++){
            c[i] += A[i][j] * x0[j];
        }
    }
    sum1 = 0; sum2 = 0;
    for(i=0;i<n;i++){
        sum1 += x0[i] * c[i];
        sum2 += x0[i] * x0[i];
    }
    q = sum1/sum2;*/
 //   cout<<endl<<endl<<"q = "<<q;
   // cout<<endl;
    q = 0;
  
    //Getting identity matrix:
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            if(i==j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    //Getting matrix (A-qI):
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            AMinusQ[i][j] = A[i][j] - q*I[i][j];
        }
    }
  /*  cout<<endl<<endl<<"AMinusQ matrix:"<<endl;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            cout<<AMinusQ[i][j]<<'\t';
        }
        cout<<'\n';
    }
        cout<<endl;
     for(i=0;i<n;i++){
        cout<<x0[i]<<'\t';
    }*/
    //Collecting all matrix need to be solved to get y:
    //  cout << '\n';
    //implementing gauss element 
    // partial pivoting
/*	
    for(i=n-1;i>0;i--)        
    {
        if(AMinusQ[i-1][0]<AMinusQ[i][0])
            for(j=0;j<=n;j++)
            {
                p=AMinusQ[i][j];
                AMinusQ[i][j]=AMinusQ[i-1][j];
                AMinusQ[i-1][j]=p;
            }
    }
*/
    //changing AMinusQ-matrix into upper triangular matrix:
    //Forward elimination process  
    for(k=0;k<n-1;k++){
        for(i=k;i<n-1;i++)
        {
            p= (AMinusQ[i+1][k]/AMinusQ[k][k]) ;

            for(j=0;j<n;j++){
                AMinusQ[i+1][j]-=p*AMinusQ[k][j];
            }
            x0[i+1] = x0[i+1] - p*x0[k];
        }
    }
    //printing upper triangular matrix:
 /*   cout<<endl<<("The upper-triangular AMinusQ-Matrix is:")<<endl;
    for(i=0;i<n;i++) {
       for(j=0;j<n;j++){
        cout << AMinusQ[i][j] << '\t';
        }
    cout << '\n';
    }
    cout<<endl<<endl<<"The updated x0 matrix:"<<endl;
        for(i=0;i<n;i++){
        cout<<x0[i]<<'\t';
    }*/
    //Getting maximam value in x0-mtrix:
   /* xm = 0;
    for(i=0;i<n;i++){
        if(fabs(x0[i]) > xm)
            xm = fabs(x0[i]);
    }*/
    //Backward Substitution method

    for(i=n-1;i>0;i--){
        sum3=0;
        for(j=i;j<=n;j++)
            sum3=sum3+AMinusQ[i][j]*x0[j];

        y0[i]=(AMinusQ[i][n]-sum3)/AMinusQ[i][i];
    }
 /*   cout<<endl<<endl;
    cout<<"y0 matrix is:"<<endl;
    for(i=0;i<n;i++) {
        cout<<y0[i]<<'\t';
    }*/
    ym = 0;
    for(i=0;i<n;i++){
        if(fabs(y0[i]) > ym)
            ym = fabs(y0[i]);
    }
    xm = 0;
    for(i=0;i<n;i++){
        if(fabs(x0[i]) > xm)
            xm = fabs(x0[i]);
    }
  //  cout<<endl<<"Biggest y0[i] element is: "<<ym<<endl;

    nu = ym/xm;
    for(i=0;i<n;i++){
        y0[i] = y0[i]/ym;
        x0[i] = y0[i];
    }
    lambda = q + 1/nu;
    nu = 1/(lambda-q);
    iteration += 1;
    }while(nu>=tol && iteration<=Nmax );
    cout<<endl<<endl<<"eigen-value is:"<<lambda;

    return 0;
}