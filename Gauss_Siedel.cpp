#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main(){
   //Reading file statement
    ifstream fileA; 
    //output file statement
    //ofstream out_file;
    //out_file.open("output_problem2.txt");

    int m,n, step;
    m=n=10;  //Input size of the matrix
    double A[m][n], sum,sum2, e,k, Nmax = 100, tolerance = 0.00001;
    int i, j;

    //reading A-matrix:
    fileA.open("newdata.txt",ios::out);
    for(i=0;i<m;i++){
    for(j=0;j<n;j++){
    fileA>>A[i][j];
    }
    }
    fileA.close();
    //Output A-matrix
   // out_file<<"The A-Matrix is:"<<endl;
    for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
    cout<<A[i][j]<<" ";
    cout<<"\n";
    }
    cout<<endl;


    //reading B-matrix:
    ifstream fileB;
    double B[m];
    fileB.open("newb.txt",ios::out);
    for(i=0;i<m;++i)
    fileB>>B[i];

    //Output B-matrix
    cout<<"The B-Matrix is:"<<endl;
    for(i=0;i<m;i++){
    cout<<B[i];
    cout<<"\n";
    }
   
    cout<<endl;
    double x[m],y[n], delta, r;
    //initial guess of x
     //Taking Initial guess of x = 0
    for(int i =0;i<n;i++){
        x[i]= {0};
    }
   cout<<endl;
   for(int i =0;i<n;i++){
        cout<<x[i]<<' ';
    }
   cout<<endl;
   do{
     // delta = 0;
      for (i = 0; i < m; i++) {
         sum = 0;
         for (j = 0; j < n; j++) {
            if (j == i)
               continue;
            sum += A[i][j]*x[j];
         }
         
         x[i] = (B[i] - sum)/A[i][i];
      }
      delta = 0;
      for (i = 0; i < m; i++) {
         sum2 = 0;
         for (j = 0; j < n; j++) {
            sum2 += A[i][j]*x[j];
         }
         r = B[i] - sum2;
         delta += pow(r,2);
      }
      
      delta = sqrt(delta);
      k = k+1;
   }
   while(k<Nmax && delta> tolerance );

   
   for (i = 0; i < m; i++) {
   cout<<endl<<"x"<<i + 1 << "="<<x[i]<<" ";
      }
   cout << "\n";
    return 0;
}