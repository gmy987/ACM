/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-10 15:59
*
* Filename: hdu2222.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 26

using namespace std;
struct Node{
    Node *next[maxn];
    Node *fail;
    int cnt;
    Node()
    {
        memset(next,0,sizeof(next));
        fail = NULL;
        cnt = 0;
    }
};
Node *p,*rt;
void insert(char *s)
{
    int i,k;
    for( i = 0 , p = rt ; s[i] ; i++ )
    {
        k = s[i]-'a';
        if(!p->next[k]) p->next[k] = new Node();
        p = p->next[k];
    }
    p->cnt++;
}
void findFail()
{
    Node *son,*tmp;
    p=rt;
    queue<Node *>q;
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
int query(char *s)
{
    int i,ans=0,k;
    Node *tmp;
    for( i = 0 , p = rt ; s[i] ; i++ )
    {
        k = s[i]-'a';
        while(!p->next[k]&&p!=rt) p = p->fail;
        p = p->next[k];
        if(!p) p = rt;
        tmp = p;
        while(tmp!=rt)
        {
            if(tmp->cnt>=0)
            {
                ans += tmp->cnt;
                tmp->cnt = -1;
            }
            else break;
            tmp = tmp->fail;
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    char str[1000006];
    while(t--)
    {
        rt = new Node();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",str);
            insert(str);
        }
        findFail();
        scanf("%s",str);
        printf("%d\n",query(str));

    }
    return 0;
}
