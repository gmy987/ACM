#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#define MAXN 3200

using namespace std;
int p[MAXN];
int prime[MAXN];
int cnt;
bool vis[10000005];
int len;
int group[10];
int ans = 0;
void findPrime()
{
    cnt = 0;
    memset( p , 0 , sizeof(p) );
    for( int i = 2 ; i < MAXN ; i++  )
    {
        if(!p[i])
        {
            for( int j = 2*i ; j< MAXN ; j+=i )
                p[j] = 1;
        }
    }
    for( int i = 2 ; i < MAXN ; i++ )
        if(!p[i]) prime[cnt++] = i;
}
bool isPrime( int x )
{
    if( x == 0 || x == 1 ) return false;
    for( int i = 0 ; i < cnt&&prime[i]<=sqrt(x) ; i++ )
        if( x%prime[i] == 0 ) return false;
    return true;
}
int calculate(int len )
{
    int sum = 0;
    for( int i = 0 ; i < len ; i++ )
        sum = sum*10+group[i];
    return sum;
}

int main()
{
    findPrime();
    char str[10];
    int a[8];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        ans = 0;
        memset( vis , 0 , sizeof(vis) );
        len = strlen(str);
        for( int i = 0 ;  i < len ; i++ )
            a[i] = str[i]-'0';
        sort( a , a + len );
        set<int> number;
        for( int i = 1 ; i < (1<<len) ; i++ )
        {
            int tmp = 0;
            for( int j = 0 ; j < len ; j++ )
            {
                if( i&(1<<j) ) group[tmp++] = a[j];
            }
            do
            {
                int t = calculate(tmp);
                if( !number.count(t) && isPrime(t) ) 
                {
                    number.insert(t);
                    ans++;
                }
            }while(next_permutation(group,group+tmp));
        }
        printf("%d\n",ans);
    }
    return 0;
}
