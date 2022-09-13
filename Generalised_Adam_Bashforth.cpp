#include<iostream>
#include<math.h>
using namespace std;

double F(float t, float Y){
    return(2-2*t+4*pow(t,2)-4*pow(t,3)-4*pow(t,4));
}
int main(){
    double t0,L,sum,h,t, p[20],k1,k2,k3,k4;
        int i,N;

        t0 = 0.0;
        L = 1.0;
        N = 10; //N = Number of steps between initial and final value of t

        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(6);

        //Initial values
        h = (L - t0) / N;
        t = t0;
        p[0] = 1;

    //Applying RK-4 method to find the initial 3 values of the function
        // NOTE: The "for" loop starts with i = 1. 
    cout<<"For h = "<<h<<endl;
    cout<<"x-value"<<"  "<<"y-value"<<endl<<"-------"<<" "<<"-------"<<endl;

    for (i=1; i<=3; i++) 
      {
         k1 = h*F(t, p[i-1]);
         k2 = h*F(t + h/2.0, p[i-1] + k1/2.0);
         k3 = h*F(t + h/2.0, p[i-1] + k2/2.0);
         k4 = h*F(t + h, p[i-1] + k3);

         p[i] = p[i-1] + 1/6.0*(k1 + 2.0*k2 + 2.0*k3 + k4);

         t = t0 + i * h;

         cout << t <<" "<< p[i] << endl;
      }

      //Applying Adam-Bashforth formula:
      for(i = 4; i <= N; i++)
      {
          sum = 55.0*F(t, p[i-1]) - 59.0*F(t-h, p[i-2]) + 37.0*F(t-2.0*h, p[i-3]) - 9.0*F(t-3.0*h, p[i-4]);
          p[i] = p[i-1] + h/24.0*sum;

          t = t0 + i * h;

          cout << t <<" "<< p[i] << endl;
      }

      return 0;
}
