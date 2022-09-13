#include <iostream>
using namespace std;

float fact(int f)
{
    if (f == 0 || f == 1)
    {
        return 1;
    }
    else
    {
        return f * fact(f - 1);
    }
}
int main()
{
    int n, r, i;
    float Pi = 3.141592654;
    cout << "Enter the mumber of terms" << endl;
    cin >> n;
    cout << "Enter the value of r:" << endl;
    cin >> r;
    r = r * Pi / 180;

    double p, a[n], b[n - 1];
    for (int i = 0; i < n; i++)
    {
        a[i+1] = 1 / fact(2 * i + 1);
    }
    for (int i = 1; i < n; i++)
    {
        cout <<"Tailor's series coefficients, a's are:"<<a[i] << " ";
    }
    cout << endl;
    b[n - 1] = a[n];
    for (i = n - 1; i >= 0; i--)
    {
        b[i - 1] = a[i] + r * b[i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        cout <<"Horner's coefficients, b's are:"<<b[i] << " ";
    }
    p =  r * b[0];
    cout << endl
         <<"Horner's algorithm result is: "<<p;
    return 0;
}