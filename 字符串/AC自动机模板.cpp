/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-10 15:25
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
#define maxn 26

using namespace std;
struct Node{
    Node *next[maxn];
    Node *fail;
    int cnt;
    Node()
    {
        memset(next,NULL,sizeof(next));
        cnt = 0;
        fail = NULL;
    }
}; 
Node *p,*rt = new Node();
void insert(char *s)
{
    int i,k;
    for( p = rt , i = 0 ; s[i] ; i++ )
    {
        k = s[i]-'a';
        if(p->next[k]==NULL) p->next[k] = new Node();
        p = p->next[k];
    }
    p->cnt++;
}
void findFail()
{
    int i;
    p = rt;
    Node *son,*tmp;
    queue<Node *>q;
    q.push(p);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for( i = 0 ; i < maxn ; i++ )
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
                ans+=tmp->cnt;
                tmp->cnt=-1;
            }
            else break;
            tmp = tmp->fail;
        }
    }
    return ans;
}

int main()
{
    return 0;
} 
