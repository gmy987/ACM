#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPrime( int n )
{
    if( n == 0||n==1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for( int i = 3 ; i<=sqrt(n);i+=2)
    {
        if( n%i==0 )
            return false;
    }
    return true;
}

int a[10000];

int main()
{
    int sum,n,cnt;
    for( int i = 2 , j = 0 ; i < 10000 ; i++ )
    {
        if(isPrime(i))
            a[j++] = i;
    }
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        cnt = 0;
        for( int i = 0 ; i < 1229 && i < n ; i++ )
        {
            sum = 0;
            for( int j = i ; j < 1229&&sum<n;j++)
            {
                sum+=a[j];
                if(sum==n)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}
