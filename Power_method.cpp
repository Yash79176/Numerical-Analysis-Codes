#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>    //Returns the number of elements in a vector.
using namespace std;
using vec    = vector<double>;         // vector
using matrix = vector<vec>;            // matrix (=collection of (row) vectors)

int main() {
    matrix A = { {5,4,1,1}, {4,5,1,1}, {1,1,4,2},{1,1,2,4} };
    int i,j,n=4, k=1, Nmax = 20;
    double x1[n], x2[n], xp, xq, nu,error[n], e, tol = 0.00001;
    cout<<("The A-Matrix is:")<<endl;
    for(i=0;i<n;i++) {
       for(j=0;j<n;j++){
        cout << A[i][j] << '\t';
        }
    cout << '\n';
    }
    // Taking initial guess of x:
    cout << '\n';
    cout<<"The initial guess of x is:"<<endl;
        for (i=0;i<n;i++){
            x1[i] = rand()%10;
        }
        for(i=0;i<n;i++){
        cout<<x1[i]<<'\t';
    }
    xp = 0;
    for(i=0;i<n;i++){
        if (x1[i] > xp)
            xp = x1[i];
        }
        cout<<endl<<"the highest value in x1 is:"<<xp;
        for(i=0;i<n;i++){
           x1[i] = x1[i]/xp;
        }
        cout << '\n';
        cout<<endl<<"x1[i] after applying infinity Norm condition is:"<<endl;
        for(i=0;i<n;i++){
        cout<<x1[i]<<'\t';
    }
    while(k<Nmax){
        for(i=0;i<n;i++) {
            x2[i] = 0;
            for(j=0;j<n;j++){  
            x2[i] += A[i][j]*x1[j];
            }
        }
    xq = 0;
    for(i=0;i<n;i++){
        if (x2[i] > xq)
            xq = x2[i];
        }
        nu = xq;
        if(xq == 0){
            cout<<"Matrix-A has a zero eigen value, start with new guesses of x1!"<<endl;
            break;
        }
        for(i=0;i<n;i++){
            x2[i] = x2[i]/xq;
        }
        for(i=0;i<n;i++){
            error[i] = x1[i] - x2[i];
        }
        e = 0;
        for(i=0;i<n;i++){
            if(error[i] > e)
                e = error[i];
        }
        for(i=0;i<n;i++){
        x1[i] = x2[i];
        }
        if(e<tol){
            cout<<endl<<endl<<"The eigen-value is: "<<nu<<endl;
            cout<<endl<<"The eigenvector is:"<<endl;
            for(i=0;i<n;i++){
                cout<<x2[i]<<'\t';
            }
            break;
        }
        k = k+1;       
    }
        cout<<endl<<"The number of iteration is:"<<k;
    return 0;
}