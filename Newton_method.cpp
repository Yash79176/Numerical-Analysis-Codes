// Newton's method to find the zeros of a problem!
#include<iostream>
#include<math.h>
using namespace std;

float Y(double x) {       // Y(x) is the given function
    return (x*exp(x) - 1);
}
float G(double x) {  
   return (x+1)*exp(x);  //G =  Derivative of the given function
}

double tol = 1e-6; // Tolerance
int N = 20; // Maximam 
int main(){
    double x,y1, g1, x1, error, A[20];
    // A[] stores the new values of x3.
    // error = difference between final root and root found in each iteration.
    int i, iteration_count =0;
    cout<<"Enter the initial guess, x:"<<endl;
    cin>>x;

    cout<<"SNo."<<"   "<<"x{i}"<<"   "<<"x{i+1}"<<"     "<< "|x{i+1}-x{i}|" <<endl;

    do {
       x1 = x;    //x1 = old value, x = New value
       y1 = Y(x1);
       g1 = G(x1);
       x = x1 - (y1/g1);
       i = i+1;
       A[i] = x;
    cout<<i<<"      "<<x1<<"    "<<x<<"   "<<fabs(x-x1)<<endl;
        if(g1 == 0) {
        cout<<"Error, denominator cannot be zero!";
        }       
    } 
    while (fabs(y1)>=tol);
    cout<<endl<<"The root of the equation is:"<<x1<<endl;

    iteration_count = i;
    cout<<"The difference between obtained root & root in each step is: "<<endl;
    for(i=1; i<= iteration_count;i++) {
        error = fabs(x1-A[i-1]);
        cout<<error<<endl;
    }
    return 0;
}