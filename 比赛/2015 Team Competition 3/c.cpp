#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 150

using namespace std;
char str1[MAXN],str2[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--)
    {
        scanf("%s%s",str1,str2);
        int len1 = strlen(str1),len2 = strlen(str2);
        int ans = 0;
        for( int i  = 0 ; i < len1 ; i++ )
            ans+=str1[i]-'0';
        for( int i = 0 ; i < len2 ; i++ )
            ans += str2[i]-'0';
        printf("Case %d: ",cas++);
        printf("%d\n",ans);
    }

    return 0;
}
