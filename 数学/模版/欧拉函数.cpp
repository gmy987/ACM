#include <cstdio>
#include <iostream>

using namespace std;
int phi[MAXN],prime[MAXN];
int cnt;

void phi_prime()
{
    cnt = 0,phi[1] = 1;
    for( int i = 2 ; i <= n ; i++ )
    {
        if(!phi[i])
        {
            prime[cnt++] = i;
            phi[i] = i-1;
        }
        for( int k = 0  ; k < cnt && prime[k]*i<=n ; k++)
            if(i%prime[k])
                phi[i*prime[k]] = phi[i]*(prime[k]-1);
            else
            {
                phi[i*prime[k]] = phi[i]*prime[k];
                break;
            }
    }
}
