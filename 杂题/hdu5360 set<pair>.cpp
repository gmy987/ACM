/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-06 19:06
*
* Filename: hdu5360.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#define maxn 111111
#define INF 0x7fffffff

using namespace std;
struct Node{
    int l,r,id;
}node[maxn];

bool cmp( Node a , Node b )
{
    return (a.l<b.l)|| (a.l==b.l&&a.r<b.r);
}
int ans[maxn];
int vis[maxn];
int n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        set<pair<int,int> > s;
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&node[i].l);
            node[i].id = i;
        }
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&node[i].r);
        sort(node+1,node+n+1,cmp);
        int cur = 0;
        int num;
        int tmp,tmp2;
        memset(vis,0,sizeof(vis));
        int pos = 1;
        set<pair<int,int> >::iterator it;
        while(true)
        {
            while(pos<=n)
            {
                if(node[pos].l<=cur)
                {
                    s.insert(make_pair(node[pos].r,node[pos].id));
                }
                else if(node[pos].l>cur) break;
                pos++;
            }
            if(s.empty()) break;
            while(!s.empty())
            {
                it = s.begin();
                tmp = it->second;
                tmp2 = it->first;
                s.erase(it);
                if(cur<=tmp2)
                {
                    ans[cur++] = tmp;
                    vis[tmp] = 1;
                    break;
                }
            }
        }
        printf("%d\n",cur);
        for( int i = 0 ; i < cur ; i++ )
        {
            if(!i) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        for( int i = 1 ; i <= n ; i++ )
            if(cur==0&&i==1) printf("%d",node[i].id); 
            else if(!vis[node[i].id])
                printf(" %d",node[i].id);
        printf("\n");
    }
    return 0;
}
