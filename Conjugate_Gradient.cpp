#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>    //Returns the number of elements in a vector.
using namespace std;
using vec    = vector<double>;         // vector
using matrix = vector<vec>;            // matrix (=collection of (row) vectors)

int main() {
    matrix A = { { 0.2,0.1,1,1,0}, {0.1,4,-1,1,-1}, {1,-1,60,0,-2},{1,1,0,8,4},{0,-1,-2,4,700} };
    vec B = {1,2,3,4,5};
    int m = A.size(), n = A[0].size();
    int p = B.size();
    m=n=p=5;
    int N=1;
    double TOLERANCE = 0.00000000001;
    int i, j, Nmax = 100000,iter;
    double sum1,sum2,alpha,beta, k[n], l[n],M;

//Printing A-matrix
    cout<<("The A-Matrix is:")<<endl;
    for(i=0;i<m;i++) {
       for(j=0;j<n;j++){
        cout << A[i][j] << '\t';
        }
    cout << '\n';
    }
//Printing B-matrix
    cout<<("\nThe B-Matrix is:")<<endl;
    for(i=0;i<m;i++) {
        cout<<B[i]<<'\t';
    }
// Taking initial guess of x:
    cout << '\n';
        double x0[n],x[n];
        for (i=0;i<n;i++){
            x0[i] = rand()%10;
        }
      for(i=0;i<n;i++){
        cout<<x0[i]<<'\t';
     }
    double d[n], r[n],mul;
    cout<<endl;
//getting r[0] and d[0]
    for(i=0;i<m;i++){
        mul = 0;
        for(j=0;j<n;j++){
            mul += A[i][j] * x[j];
        }
        r[i] = B[i] - mul;
        d[i] = r[i];
    }
     for(i=0;i<m;i++){
        cout<<d[i]<<'\t';
     }
 //Implementing conjugent gradient procedure

    cout<<endl;
   // double sum1,sum2,alpha,beta, k[n], l[n],M;
        do{
            iter=0;
            for(i=0;i<m;i++)
		{
			x0[i] = x[i];
		}
            sum1=0;
            sum2=0;
        for(i=0;i<n;i++){
        
            sum1 += r[i]*r[i];
            l[i]=0;
            for(j=0;j<m;j++)
			{
				l[i] +=  A[i][j]*d[j];
			}
           
            sum2 += (d[i]*l[i]);
        }
     
            alpha = (sum1)/(sum2);

            for(i=0;i<m;i++){
            x[i] = x[i] + (alpha*d[i]);
            }
            sum1=0;
            sum2=0;       
            for(i=0;i<m;i++){
            sum2 += (d[i]*r[i]);
            r[i] = r[i] - (alpha*l[i]);
            sum1 += r[i]*r[i];  
           
            }
            beta = (sum1)/(sum2);
            for(i=0;i<m;i++){
            d[i] = r[i] + beta*d[i];
            }

        for(i=0;i<m;i++)
		{
			k[i] = x[i] - x0[i];
			iter += pow(k[i],2);
		}
		M = sqrt(iter);
		
		N = N + 1;
	}while((N<=Nmax)&&(M>TOLERANCE));
    cout<<"The output x-matrix is:"<<endl;
    for(i = 0;i<m;i++){
        cout<<x[i]<<'\t';
    }
    	cout<<endl<<"Number of iterations are: "<<N;	
return 0;
}
