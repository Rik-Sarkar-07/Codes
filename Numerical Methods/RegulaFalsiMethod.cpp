#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (x * x * x + 3 * x - 1)
int main(int argc, char const *argv[])
{
    double x0, x1, x2;
    double err;

    printf("Enter the Initial values [x1 & x2] :\n");
    scanf("%lf%lf", &x1, &x2);

    while (f(x1) * f(x2) > 0)
    {
        printf("Enter the Initial values again [x1 & x2] :\n");
        scanf("%lf%lf", &x1, &x2);
    }

    if (f(x1) == 0)
    {
        printf("The Exact root is = %lf\n", x1);
        exit(0);
    }
    if (f(x2) == 0)
    {
        printf("The Exact root is = %lf\n", x2);
        exit(0);
    }

    printf("Enter the Error value = ");
    scanf("%lf", &err);

    int it = 0;

    while ((fabs(x2 - x1)) / x2 > err)
    {

        x0 = (x1 - (((x2 - x1) * f(x1)) / (f(x2) - f(x1))));

        if (f(x0) == 0)
        {
            printf("The Exact root is = %lf\n", x0);
            exit(0);
        }
        else if (f(x1) * f(x0) < 0)
        {
            x2 = x0;
        }
        else if (f(x0) * f(x2) < 0)
        {
            x1 = x0;
        }
        it++;
    }

    printf("After %d Iterations Root is = %0.4f (Approx)\n", it, x0);

    return 0;
}
