#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double exact(double x)
{
    return (x * x + (16 / x));
}

double f1(double x, double y, double z) // z are y'
{
    return (32 + 2 * x * x * x - y * z) / 8;
}

double g1(double z)
{
    return z;
}

double f2(double a, double psi, double b, double z1) // here z1 and psi'
{
    return (a * psi + b * z1);
}

double g2(double z1)
{
    return z1;
}

int main()
{
    ofstream out;
    out.open("outut_BVP.txt");
    double x, y, x0, y0, z, z0, xmax, k, k1, k2, k3, k4, l, l1, l2, l3, l4, yn;
    double h, a, b, psi, psip, zpsi, p, q, p1, p2, p3, p4, q1, q2, q3, q4, z1, m, error;
    int i, j, n, itr;
    n = 20; // no of step size given
    m = 30; // guess initial slope
    x0 = 1, y0 = 17, z0 = m, xmax = 3, yn =(43/3);
    h = (xmax - x0) / n;
    itr = 1;
    error = 0.1;
    while (itr < 5000 && error > 0.00001) // tolerance is 10^-5
    {
        z0 = m;
        x = x0;
        y = y0;
        z = z0;
        psi = 0; // psi initial
        z1 = 1;  // psi initial slope

        for (i = 0; i < n; i++)
        {
            l1 = h * g1(z);
            k1 = h * f1(x, y, z);
            l2 = h * g1(z + k1 / 2);
            k2 = h * f1(x + h / 2, y + l1 / 2, z + k1 / 2);
            l3 = h * g1(z + k2 / 2);
            k3 = h * f1(x + h / 2, y + l2 / 2, z + k2 / 2);
            l4 = h * g1(z + k3);
            k4 = h * f1(x + h, y + l3, z + k3);
            k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
            l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
            z = z + k;
            y = y + l;
            x = x + h;

            a = -z / 8;
            b = -y / 8;
            p1 = h * f2(a, psi, b, z1);
            q1 = h * g2(z1);
            p2 = h * f2(a, psi + q1 / 2, b, z1 + p1 / 2);
            q2 = h * g2(z1 + p1 / 2);
            p3 = h * f2(a, psi + q2 / 2, b, z1 + p2 / 2);
            q3 = h * g2(z1 + p2 / 2);
            p4 = h * f2(a, psi + q3, b, z1 + p3);
            q4 = h * g2(z1 + p3);
            p = (p1 + 2 * p2 + 2 * p3 + p4) / 6;
            q = (q1 + 2 * q2 + 2 * q3 + q4) / 6;

            z1 = z1 + p;
            psi = psi + q;
        }

        error = (y - yn);
        m = m - (error / psi);
        itr++;
        error = abs(error);
    }
    out << "solution of BVP by shooting_RK4 method:" << endl;
    out << "correct value of m is:" << m << endl;
    // now solving the problem by getting correct value of slope
    z0 = m;
    x = x0;
    y = y0;
    z = z0;
    out << "solution of BVP by shooting method:" << endl;
    out << x << '\t' << y << endl;
    for (i = 0; i < n; i++)
    {
        l1 = h * g1(z);
        k1 = h * f1(x, y, z);
        l2 = h * g1(z + k1 / 2);
        k2 = h * f1(x + h / 2, y + l1 / 2, z + k1 / 2);
        l3 = h * g1(z + k2 / 2);
        k3 = h * f1(x + h / 2, y + l2 / 2, z + k2 / 2);
        l4 = h * g1(z + k3);
        k4 = h * f1(x + h, y + l3, z + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        z = z + k;
        y = y + l;
        x = x + h;
        out << x << '\t' << y << endl;
    }

    out << "Exact solution by given function is:" << endl;
    x = x0;
    for (i = 0; i<=n; i++)
    {
        y = exact(x);
        out << x << '\t' << y << endl;
        x = x + h;
    }
    cout << "soution by both RK4 shooting and exact method has printed in 'output_BVP' file:" << endl;
    return 0;
}