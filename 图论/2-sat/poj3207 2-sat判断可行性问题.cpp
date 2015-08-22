/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-01 19:59
*
* Filename: poj3207.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define maxn 2000

using namespace std;
vector<int> vect[maxn];
int n,m;
int s[maxn],t[maxn];
int vis[maxn],dfn[maxn],low[maxn];
int cnt,deep,ans;
int mark[maxn];
bool judge( int x1 , int y1 , int x2 , int y2 )
{
    if(x1<x2&&x2<y1&&y1<y2) return true;
    if(x2<x1&&x1<y2&&y2<y1) return true;
    return false;
}
stack<int> st;
void tarjan(int x)
{
    int i;
    dfn[x] = low[x] = ++deep;
    vis[x] = 1;
    st.push(x);
    for( i = 0 ; i < vect[x].size() ; i++ )
    {
        int v = vect[x][i];
        if(dfn[v]==-1)
        {
            tarjan(v);
            if(low[x]>low[v])
                low[x] = low[v];
        }
        else if(vis[v]&&low[x]>dfn[v])
            low[x]=dfn[v];
    }
    if(low[x]==dfn[x])
    {
        ans++;
        while(!st.empty())
        {
            i = st.top();
            st.pop();
            vis[i] = 0;
            mark[i] = ans;
            if(i==x) break;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        memset(dfn,0xff,sizeof(dfn));
        memset(low,0,sizeof(low));
        deep = 0,ans=0;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&s[i],&t[i]);
            if(s[i]>t[i]) swap(s[i],t[i]);
        }
        for( int i = 0 ; i < m-1 ; i++ )
            for( int j = i+1 ; j < m ; j++ )
                if(judge(s[i],t[i],s[j],t[j]))
                {
                    vect[i].push_back(j+m);
                    vect[j].push_back(i+m);
                    vect[i+m].push_back(j);
                    vect[j+m].push_back(i);
                }
        for( int i = 0 ; i < m*2 ; i++ )
            if(dfn[i]==-1)
                tarjan(i);
        bool flag = true;
        for( int i = 0 ; i < m ; i++ )
            if(mark[i]==mark[i+m])
            {
                printf("the evil panda is lying again\n");
                flag = false;
                break;
            }
        if(flag) printf("panda is telling the truth...\n");
        for( int i = 0 ; i < m*2 ; i++ )
            vect[i].clear();
    }
    return 0;
}
