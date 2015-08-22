#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ )
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",(int)sqrt(a));
    }
    return 0;
}
