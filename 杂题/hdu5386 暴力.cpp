/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-13 18:22
*
* Filename: hdu5386.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#define maxn 600

using namespace std;
stack<int> st;
struct Node{
    char str[3];
    int x,y;
}node[maxn];
int vis[maxn];
int a[maxn][maxn];

int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    while(t--){
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        bool flag;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                scanf("%d",&a[i][j]);
        for( int i = 1 ; i <= n ; i ++)
            for( int j = 1 ; j <= n ; j++ )
                scanf("%d",&a[i][j]);
        for( int i = 0 ; i < m ; i++ )
            scanf("%s%d%d",node[i].str,&node[i].x,&node[i].y);
        for( int i = 0 ; i < m ; i++ )
            for( int j = 0 ; j < m ; j++ )
            {
                if(vis[j]) continue;
                flag = true;
                if(node[j].str[0]=='H'){
                    for( int k = 1 ; k <= n ; k++ )
                        if(a[node[j].x][k]!=0&&a[node[j].x][k]!=node[j].y){
                            flag = false;
                            break;
                        }
                    if(!flag) continue;
                    vis[j] = 1;
                    st.push(j);
                    for( int k = 1 ; k <= n ; k++ )
                        a[node[j].x][k] = 0;
                }
                else{
                    for( int k = 1 ; k <= n ; k++ )
                        if(a[k][node[j].x]!=0&&a[k][node[j].x]!=node[j].y){
                            flag = false;
                            break;
                        }
                    if(!flag) continue;
                    vis[j] = 1;
                    st.push(j);
                    for( int k = 1 ; k <= n ; k++ )
                        a[k][node[j].x] = 0;
                }
            }
        for( int i = 0 ; i < m ; i++ )
            if(!i) printf("%d",st.top()+1),st.pop();
            else printf(" %d",st.top()+1),st.pop();
        puts("");
    }
    return 0;
}
