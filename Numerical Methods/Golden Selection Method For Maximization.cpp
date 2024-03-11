#include <iostream>
#include <cmath>
#include <iomanip>
#define G 0.61803
#define PINF 999999
#define NINF -99999
using namespace std;

double function(double x)
{
    return (2 * x - 1.75 * x * x + 1.1 * pow(x, 3) - 0.25 * pow(x, 4));
}
int main()
{
    double x1, x2, a, b, l, r, e = NINF, t;
    int k, n = PINF;
    cout << setprecision(4) << fixed;
    cout << "Enter the Intervals & Interations \n";
    cout << "Enter the lower interval = ";
    cin >> a;
    l = a;
    cout << "Enter the upper interval = ";
    cin >> b;
    r = b;
    cout << "Enter the number of iterations or error = ";
    cin >> t;
    if (t > 1)
    {
        n = (int)t;
    }
    else
    {
        e = t;
    }
    k = 1;

    cout << "\n\nK \t L \t R \t X1 \t X2 \t f(X1) \t f(X2) \t L/R\n\n";

    while (1)
    {
        x2 = l + G * (r - l);
        x1 = (l + r) - x2;
        cout << k << "\t" << l << "\t" << r << "\t" << x1 << "\t" << x2 << "\t" << function(x1) << "\t" << function(x2) << "\t";
        if (k == n)
        {
            break;
        }
        else if (fabs(r - l) <= e)
        {
            break;
        }
        else if (function(x1) < function(x2))
        {
            l = x1;
            x1 = x2;
            cout << "R" << endl;
        }
        else
        {
            r = x2;
            x2 = x1;
            cout << "L" << endl;
        }
        k++;
    }

    cout << "\n\n Maxima at the point  = " << (r + l) / 2 << "\tAfter " << fabs(r - l) << " Uncertainty and " << k << " Iterations." << endl;
    cout << "The value at that point = " << function((r + l) / 2) << endl;

    return 0;
}
