#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    double s,pi=3.14159265;
    while(scanf("%lf",&s)!=EOF)
    {
        double r=sqrt(s/pi)/2;
        double h=sqrt(s*2/pi);
        double V=sqrt(s*s*s/(2*pi))/6;
        printf("%.2f\n",V);
        printf("%.2f\n",h);
        printf("%.2f\n",r);
    }
    return 0;
}
