/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-10 19:04
*
* Filename: hdu3065.cpp
*
* Description: 
*
=============================================================================*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 30

using namespace std;
struct Node{
    Node *next[maxn];
    Node *fail;
    int cnt;
    int id;
    Node()
    {
        memset(next,0,sizeof(next));
        fail = NULL;
        cnt = 0;
    }
};
Node *p,*rt,*tmp,*son;
char str[1005][60];
int ans[1005];
void insert(char *s,int num)
{
    int i,k;
    for( i = 0 , p = rt ; s[i] ; i++ )
    {
        k = s[i]-'A';
        if(!p->next[k]) p->next[k] = new Node();
        p = p->next[k];
    }
    p->cnt++;
    p->id = num;
}
void findFail()
{
    p = rt;
    queue<Node *> q;
    q.push(p);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for( int i = 0 ; i < 26 ; i++ )
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
    int i,k;
    for( i = 0 , p = rt ; s[i] ; i++ )
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            k = s[i]-'A';
            while(!p->next[k]&&p!=rt) p = p->fail;
            p = p->next[k];
            if(!p) p = rt;
        }
        else p = rt;
        tmp = p;
        while(tmp!=rt)
        {
            if(tmp->cnt>0)
                ans[tmp->id]++;
            tmp = tmp->fail;
        }
    }
}

int main()
{
    int n;
    char a[2000005];
    while(~scanf("%d",&n))
    {
        rt = new Node();
        memset(ans,0,sizeof(ans));
        for( int i = 0 ; i< n ; i++ )
        {
            scanf("%s",str[i]);
            insert(str[i],i);
        }
        findFail();
        scanf("%s",a);
        query(a);
        for( int i = 0 ; i < n ; i++ )
            if(ans[i]>0)
                printf("%s: %d\n",str[i],ans[i]);
    }
    return 0;
}
