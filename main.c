#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double hord(double x1, double x2, double eps, unsigned int iteration, unsigned int N);
double half_div (double x1, double x2, double eps, unsigned int iteration, unsigned int N);
double f(double);

int main()
{
    double x1, x2, eps, time;
    unsigned int variant, need_iterations, N;
    time_t start, end;
    while(1)
    {
        do
        {
            printf("Choose Method:\n1 = Hord method\n2 = Half-Div method\n");
            scanf("%u", &variant);
        } while(variant!=1 && variant!=2);
        do
        {
            printf("Show count of iteranions?\n1 = Yes\n2 = No\n");
            scanf("%u", &need_iterations );
            system("cls");
            if(need_iterations==1)
            {
                do
                {
                    printf("Enter:\nN(>=1): ");
                    scanf("%u", &N);
                } while(N<1);
            } else N=1;
        } while(need_iterations!=1 && need_iterations!=2);
        printf("\nX1:");
        scanf("%lf", &x1);
        printf("\nX2:");
        scanf("%lf",&x2);
        printf("\nEpsilon(>0.00001):");
        scanf("%lf",&eps);
        system("cls");
        while(f(x1)*f(x2)>0 || eps<0.00001)
        {
            if(f(x1)*f(x2)>0)
            {
                printf("\nNo answers\nEnter:\nX1:");
                scanf("%lf", &x1);
                printf("\nx2:");
                scanf("%lf",&x2);
            }
            else if (eps<0.00001)
            {
                printf("Epsilon to low\nEnter:\nEpsilon:");
                scanf("%lf", &eps);
            }
        }
        start = clock();
        switch(variant)
        {
        case 1:
            printf("Xi = %.10lf\n", hord(x1, x2, eps, need_iterations, N));
        break;
        case 2:
            printf("Xi = %.10lf\n", half_div(x1, x2, eps, need_iterations, N));
        break;
        }
        end=clock();
        time=(end - start);
        if(need_iterations==2) printf("\tUsed Time: %.lfms\n", time);
    return 0;
    }
}

double f(double x)
{
    double y;
    y = pow((x-200), 5) - pow((x-100), 3) - 50*x - 25;
    return y;
}

double hord(double x1, double x2, double eps, unsigned int need_iterations, unsigned int N)
{
    double xi;
    while(fabs(f(xi)) > eps)
    {
        xi = (f(x2) * x1 - f(x1) * x2)/(f(x2) - f(x1));
        if (f(xi)*f(x1)>0) x1=xi;
        else x2=xi;
        if(need_iterations==1)
        {
            printf("Xi = %.10lf\n", xi);
            unsigned int i;
            i++;
            if(i>=N)
            {
                i=0;
            }
        }
    }
    return xi;
}

double half_div(double x1, double x2, double eps, unsigned int need_iterations, unsigned int N)
{
    double xi;
    while(fabs(x2-x1) >= eps)
    {
        xi = (x1+x2)/2;
        if(f(xi)==0) break;
        else if(f(xi)*f(x1)>0) x1=xi;
        else x2=xi;
        if(need_iterations==1)
        {
            printf("Xi = %.10lf\n", xi);
            unsigned int i;
            i++;
            if(i>=N)
            {
                i=0;
            }
        }
    }
    return xi;
}
