#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int T;
    int n,m;
    int x,y;
    int map[10][10];
    int a[10];
    scanf("%d",&T);
    while(T--)
    {
        memset(map,0,sizeof(map));
            scanf("%d%d",&n,&m);
            for(int t=1;t<=m;t++)
            {
                scanf("%d%d",&x,&y);
                map[x][y]=1;
            }
    for(int t=1;t<=n;t++)
    {
        a[t]=t;
    }
            int ans=0;
            do
            {
bool can=true;
                for(int t=1;t<=n;t++)
                {
                    for(int tt=t+1;tt<=n;tt++)
                    {
                        if(map[a[tt]][a[t]]==1)
                        {
                            can=false;
                        }
                    }
                }
                if(can){
                ans++;
                }
            }while(next_permutation(a+1,a+1+n));
            printf("%d\n",ans);
    }
}


