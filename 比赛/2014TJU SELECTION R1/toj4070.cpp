#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int dp[25];
char a[25];
int ans;
bool flag;
void dfs( int x , int cost )
{
    if(x==strlen(a)-1)
    {
        flag = true;
        ans = min(ans,cost);
    }
    for( int i = x+1 ; i < strlen(a) ; i++ )
    {
        if( (a[x] == 'R' && a[i] == 'G')||(a[x]=='G'&&a[i]=='B')||(a[x]=='B'&&a[i]=='R'))
            dfs(i,cost+(i-x)*(i-x));
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        ans = 0x7fffffff;
        flag = false;
        dfs(0,0);
        if(flag)
        printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
