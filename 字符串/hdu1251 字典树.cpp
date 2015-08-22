/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-10 13:06
*
* Filename: hdu1251.cpp
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
    bool flag;
    int cnt;
    Node()
    {
        memset(next,NULL,sizeof(next));
        flag = cnt = 0;
    }
};
Node *p,*rt=new Node();
void insert(char *s)
{
    int i,k;
    for( p = rt , i = 0 ; s[i] ; i++ )
    {
        k = s[i]-'a';
        if(p->next[k]==NULL) p->next[k] = new Node();
        p = p->next[k];
        p->cnt++;
    }
    p->flag = 1;
}
int search(char *s)
{
    int i,k;
    for( p = rt , i = 0 ; s[i] ; i++ )
    {
        k = s[i]-'a';
        if(p->next[k]==NULL) return 0;
        p = p->next[k];
    }
    return p->cnt;
}

int main()
{
    char s[30];
    while(gets(s),*s) insert(s);
    while(gets(s))
    {
        printf("%d\n",search(s));
    }
    return 0;
}
