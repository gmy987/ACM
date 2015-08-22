#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1000005

using namespace std;
int phi[MAXN],prime[MAXN];
int cnt;
__int64 ans[MAXN];
void phi_prime()
{
    cnt = 0,phi[1] = 1;
    int i,j;
    memset(phi,0,sizeof(phi));
    for( int i = 2 ; i < MAXN ; i++ )
    {
        if(!phi[i])
        {
            prime[cnt++] = i;
            phi[i] = i-1;
        }
        for( int k = 0 ; k < cnt && prime[k]*i<MAXN ; k++ )
            if( i % prime[k] )
                phi[i*prime[k]] = phi[i]*(prime[k]-1);
            else
            {
                phi[i*prime[k]] = phi[i]*prime[k];
                break;
            }
    }
    ans[1] = 0;
    for( int i = 2 ; i < MAXN ; i++ )
        ans[i] = (long long)phi[i];
    for( int i = 2 ; i <= 1000 ; i++ )
    {
        ans[i*i]+=(long long)phi[i]*(long long)i;
        for( int j = i*i+i , k = i+1 ; j < MAXN ; j+=i , k++ )
            ans[j]+=(long long)i*(long long)phi[k]+(long long)k*(long long)phi[i];
    }
    for( int i = 1 ; i < MAXN ; i++ )
        ans[i] += ans[i-1];
}

int main()
{
    int n;
    phi_prime();
    while(scanf("%d",&n)&&n)
    {
        printf("%I64d\n",ans[n]);
    }
    return 0;
}
