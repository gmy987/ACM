#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int cnt;
void getPrime()
{
    memset( prime , 0 , sizeof(prime));
    memset( f , 0 , sizeof(f));
    cnt = 0;
    for( int i = 2 ; i < MAXN ; i++ )
    {
        if( !f[i] ) prime[cnt++] = i;
        for( int j = 0 ; j < cnt && prime[j]*i < MAXN ; j++ )
        {
            f[prime[j]*i] = 1;
            if(!(i%prime[j]))
                break;
        }
    }
}

int main()
{
    return 0;
}
