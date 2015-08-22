#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 32770

using namespace std;
int prime[MAXN],phi[MAXN];
int cnt;
void findphi()
{
    memset(prime,0,sizeof(prime));
    memset(phi,0,sizeof(phi));
    cnt = 0;
    phi[1] = 1;
    for( int i = 2; i < MAXN ; i++ )
    {
        if(!phi[i]) prime[cnt++] = i,phi[i] = i-1;
        for( int j = 0 ; j < cnt && prime[j]*i < MAXN ; j++ )
        {
            if(i%prime[j]==0)
            {
                phi[prime[j]*i] = phi[i]*prime[j];
                break;
            }
            else phi[i*prime[j]] = phi[i]*(prime[j]-1);
        }
    }
}

int main()
{
    int t,n;
    scanf("%d",&t);
    findphi();
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }
    return 0;
}
