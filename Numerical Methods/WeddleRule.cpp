#include <iostream>
#include <math.h>
using namespace std;
double f(double x)
{
    return (1 / (x * x + 1));
}
int main()
{
    double a, b, n;
    cout << "Enter the lower limit = ";
    cin >> a;
    cout << "Enter the higher limit = ";
    cin >> b;
    cout << "Enter the number of intervals[it must be multiple of six] = ";
    cin >> n;

    double h = (b - a) / n;
    double sum = 0;
    int ns = 6;
    do
    {
        sum = sum + (((3 * h) / 10) * (f(a) + f(a + 2 * h) + 5 * f(a + h) + 6 * f(a + 3 * h) + f(a + 4 * h) + 5 * f(a + 5 * h) + f(a + 6 * h)));
        a = a + ns * h;
    } while (a < b);

    cout << "∫f(x)dx = " << sum << endl;
    return 0;
}
