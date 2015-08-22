#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-10
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    double v1,v2,r,d;
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&v1,&v2,&r,&d);
        double temp = r/v1*asin(v1/v2);
        temp *= v2;
        if( temp + eps > d )
            printf("Why give up treatment\n");
        else
            printf("Wake up to code\n");
    }
    return 0;
}
