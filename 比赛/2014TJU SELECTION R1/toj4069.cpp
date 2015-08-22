#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

char t[10];
char a[205];
int cnt[15];
int b[15];
int main()
{
    while(scanf("%s",t))
    {
        memset(cnt,0,sizeof(cnt));
        memset(b,0,sizeof(b));
        scanf("%s",a);
        int len = strlen(a);
        for( int i = 0 ; i < len ; i++ )
            b[a[i]-'0']++;
        len = strlen(t);
        for( int i = 0 ; i < len ; i++ )
            cnt[t[i]-'0']++;
        b[2] += b[5];
        b[6] += b[9];
        cnt[2] += cnt[5];
        cnt[6] += cnt[9];
        int m = 0x7fffffff;
        for( int i = 0 ; i < 9 ; i++ )
        {
            if( i == 5 )
                continue;
            if(cnt[i] == 0 )
                continue;
            m = min(m,b[i]/cnt[i]);
        }
        printf("%d\n",m);
    }
    return 0;
}
