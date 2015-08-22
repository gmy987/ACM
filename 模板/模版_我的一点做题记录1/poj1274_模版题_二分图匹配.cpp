#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 210
int n,m;
int g[maxn][maxn],f[maxn],rm[maxn],lm[maxn];

bool path(int s)
{
    for(int j = 1;j <= m;j++)
    {
        if(!f[j] && g[s][j])
        {
            f[j] = 1;
            if(!rm[j] || path(rm[j]))
            {
                rm[j] = s;
                lm[s] = j;
                return true;
            }
        }
    }
    return false;
}

int maxMatch()
{
    int ans = 0;
    memset(lm,0,sizeof(lm));
    memset(rm,0,sizeof(rm));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;!lm[i] && j <= m;j++)
        {
            if(g[i][j] && !rm[j])
            {
                lm[i] = j;
                rm[j] = i;
                ans++;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(!lm[i])
        {
            memset(f,0,sizeof(f));
            if(path(i))
                ans++;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(g,0,sizeof(g));
        int nm,elem;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&nm);
            while(nm--)
            {
                scanf("%d",&elem);
                g[i][elem] = 1;
            }
        }
        int res = maxMatch();
        printf("%d\n",res);
    }
    return 0;
}
