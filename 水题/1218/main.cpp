#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n,t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        printf("%d\n",(int)(sqrt(t)));
    }
    return 0;
}
