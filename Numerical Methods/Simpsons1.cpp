#include <iostream>
#include <math.h>
using namespace std;
double f(double x)
{
    return (1 / (x * x + 1));
}
int main(int argc, char const *argv[])
{
    double a = 0, b = 0;
    cout << "Enter the lower limit = ";
    cin >> a;
    cout << "Enter the upper limit = ";
    cin >> b;
    int n;
    cout << "Enter the intervals [intervals must be even] = ";
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "This Interval Can not Applicable\n";
        exit(0);
    }
    int points = n + 1;
    double h = (b - a) / n;

    double *x = (double *)calloc(sizeof(double), (points));
    double *y = (double *)calloc(sizeof(double), (points));

    int i = 0;
    double valX = a;

    while (i < points)
    {
        x[i++] = valX;
        valX += h;
    }

    i = 0;
    int j = 0;

    while (i < points)
    {
        y[i++] = f(x[j++]);
    }

    double result = y[0] + y[n];
    for (int i = 1; i < n; i = i + 2)
    {
        result += 4 * y[i];
    }
    for (int i = 2; i < n; i = i + 2)
    {
        result += 2 * y[i];
    }
    result = (h / 3) * result;
    cout << "Result = " << result << endl;
    return 0;
}
