#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 1000000

using namespace std;
int f[MAXN],prime[MAXN];
int cnt;
void findprime()
{
    memset( f, 0 , sizeof(f)) ;
    cnt = 0;
    for( int i = 2 ; i < MAXN ; i++ )
    {
        if(!f[i]) prime[cnt++] = i;
        for( int k = 0 ; k < cnt && prime[k]*i < MAXN ; k++ )
        {
            f[prime[k]*i] = 1;
            if( i % prime[k]) break;
        }
    }
}

int main()
{
    int t,l,g;
    scanf("%d",&t);
    findprime();
    while(t--)
    {
        scanf("%d%d",&g,&l);
        if(l%g)
        {
            printf("0\n");
            continue;
        }
        int tmp = l/g;
        int ans = i;
        for( int i = 0 ; i < cnt ; i++ )
        {
            if( prime[i]*prime[i] > tmp )
                break;
            if( tmp%prime[i] ) continue;
            int c = 0;
            while( tmp%prime[i] == 0 )
                tmp/=prime[i],c++;
            ans *= c*6;
        }
        if(tmp!=1)
            ans*=6;
        printf("%d\n",ans);
    }

    return 0;
}
