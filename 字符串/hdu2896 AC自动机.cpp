/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-10 16:50
*
* Filename: hdu2896.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iterator>
#include <set>
#define maxn 128

using namespace std;
struct Node{
    Node *next[maxn];
    Node *fail;
    int id;
    int cnt;
    Node()
    {
        memset(next,0,sizeof(next));
        cnt = 0;
        fail = NULL;
    }
};
Node *rt,*p;
set<int> ss;
bool vis[505];
void insert(char *s,int num)
{
    int i,k;
    for( p = rt , i = 0 ; s[i] ; i++ )
    {
        k = s[i];
        if(!p->next[k]) p->next[k] = new Node();
        p = p->next[k];
    }
    p->cnt++;
    p->id=num;
}
void findFail()
{
    Node *son,*tmp;
    p = rt;
    queue<Node *> q;
    q.push(p);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for( int i = 0 ; i < maxn ; i++ )
        {
            son = tmp->next[i];
            if(son)
            {
                if(tmp==rt) son->fail = rt;
                else
                {
                    p = tmp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            son->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(!p) son->fail = rt;
                }
                q.push(son);
            }
        } 
    }
}
void query(char *s)
{
    int ans = 0,i,k;
    Node *tmp;
    ss.clear();
    for( i = 0 , p = rt ; s[i] ; i++ )
    {
        k = s[i];
        while(!p->next[k]&&p!=rt) p = p->fail;
        p = p->next[k];
        if(!p) p = rt;
        tmp = p;
        while(tmp!=rt)
        {
            if(tmp->cnt>0&&!vis[tmp->id])
            {
                ss.insert(tmp->id);
                vis[tmp->id] = 1;
            }
            tmp = tmp->fail;
        }
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        char str[10005]; 
        rt = new Node();
        for( int i = 1 ; i <= n ;i++ )
        {
            scanf("%s",str);
            insert(str,i);
        }
        findFail();
        scanf("%d",&n);
        int ans = 0;
        set<int>::iterator it;
        for( int i = 1; i <= n ;i++ )
        {
            scanf("%s",str);
            memset(vis,0,sizeof(vis));
            query(str);
            if(!ss.empty())
            {
                ans++;
                printf("web %d:",i);
                for( it = ss.begin() ; it!=ss.end() ; it++ )
                    printf(" %d",*it);
                printf("\n");
            }
        }
        printf("total: %d\n",ans);
    }
    return 0;
}
