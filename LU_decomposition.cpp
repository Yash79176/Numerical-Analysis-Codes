#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int i, j, k, p; //Input here the size of the matrix.  
    int N = 50;
    double x[N],y[N],A[N][N], B[N], sum, L[N][N], U[N][N];
	for( i=1;i<=N;i++)
	{
		for( j=1;j<=N;j++)
		{
			if(i==j)
			{
				A[i][j] = 5;
			}
			else if(j==i+1)
			{
				A[i][j] = -1;
			}
			else if(j==i-1)
			{
				A[i][j] = -1;
			}
			else
			{
				A[i][j] = 0;
			}
		}
	}
    //Displaying A-matrix:
    cout<<"The A-Matrix is:"<<endl;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++)
        cout<<A[i][j]<<" ";
        cout<<"\n";
        }
        cout<<endl;

    //Taking Initial guess of x = 0
    for(int i =0;i<N;i++){
        x[i]= {0};
    }

    //Taking Initial guess of L = 0
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
        L[i][j] = {0};
    }
}
    //Taking Initial guess of U = 0
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            U[i][j] = {0};
    }
}

//Displaying the initial guesses of L and U
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            cout<<U[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            cout<<L[i][j]<<"  ";
        }
        cout<<endl;
    }

    for(k=1;k<=N;k++){
        L[k][k] = 1;
        for(j=k;j<=N;j++){
            sum = 0;
            for(p=1;p<=k-1;p++){
               sum += L[k][p]*U[p][j];  
            }
        U[k][j] = A[k][j] - sum;
        }
        for(i=k+1;i<=N;i++){
            sum = 0;
            for(p=1;p<=k-1;p++){
                sum += L[i][p]*U[p][k];
            }
            L[i][k] = (A[i][k] - sum)/U[k][k];
        }     
    }

    
    //******** Displaying LU matrix**********
    cout<<endl<<endl<<"LU matrix is "<<endl<<"lower"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout<<L[i][j]<<"  ";
        cout<<endl;
    }
    cout<<"upper"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout<<U[i][j]<<"  ";
        cout<<endl;
    }
    
    // Solving Ax = b: LUx = b: Ly = b, where, y = Ux
        //Getting B-column from the N number of output matrix possible:
        int c;
        cout<<"Enter the column number from the given B-matrix :"<<endl;
        cin>>c;
        cout<<"The B-column matrix is:"<<endl;
        for(i=0;i<N;i++)
	{
			if(i+c<=N+1)
			{
				B[i] = i+c-1;
			}
			else
			{
				B[i] = i+c-(N+1);
			}
            cout<<B[i]<<" ";
		
        cout<<endl;
    }
    //Solving Ly = B:
   // cout<<"The y matrix is:"<<endl;
   //Taking Initial guess of y = 0
    for(int i =0;i<N;i++){
        y[i]= {0};
    }

    for(k=1;k<=N;k++){
        if(i==1)
            y[i] = B[i];
        sum=0;
        for(j=1;j<=k-1;j++){
            sum += L[k][j]*y[j];
        }
        y[k] = B[k] - sum;
    }

    // Solving Ux = y:
    cout<<endl<<endl<<"The output x-matrix is: "<<endl;
    x[N-1] = y[N-1]/U[N-1][N-1];
    for(i=N-2;i>=0;i--){
        sum = 0;
        for(j=i+1;j<N;j++){
            sum += U[i][j]*x[j];
        }
        x[i] = (y[i] - sum)/U[i][i];
    }

    //*********** DISPLAYING SOLUTION**************  
    for(i=0;i<N;i++){
        cout<<endl<<x[i]<<" ";
    }
    return 0;
    }