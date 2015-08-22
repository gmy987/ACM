/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-10 12:43
*
* Filename: Trie.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 26

using namespace std;
struct Node{
    Node *next[MAX];
    bool flag;
    int cnt;
    Node(){
        memset(next,null,sizeof(next));
        cnt = flag = 0;
    }
};
Node *p,*rt=new Node();
void insert(char *s)
{
    int i,k;
    for( p = rt , i = 0 ; s[i] ; i++ )
    {
        k = s[i]-'a';
        if(p->next[k]==null) p->next[k] = new Node();
        p = p->next[k];
        p->count++;
    }
    p->flag=true;
}
bool search(char *s)
{
    int i,k;
    for( p = rt , i = 0 ; s[i] ; i++ )
    {
        k = s[i]-'a';
        if(p->next[k]==null) return false;
        p = p->next[k];
    }
    return p->flag;
}
void del(Node *t)
{
    int i;
    if(t==null) return;
    for( i = 0 ; i < MAX ; i++ )
        if(t->next[i]!=null) del(t->next[i]);
    free(t);
}
