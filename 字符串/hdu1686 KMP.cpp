/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-07 16:36
*
* Filename: 1686.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1111111

using namespace std;
char t[maxn],p[maxn];
int nnext[maxn];
int n,m;
void findnext()
{
    nnext[0]=-1;
    int k = -1 , j = 0;
    while( j < n )
    {
        if(k==-1||p[k]==p[j])
        {
            if(p[++k]!=p[++j]) nnext[j] = k;
            else nnext[j] = nnext[k]; 
        }
        else k = nnext[k];
    }
}
int kmp()
{
    int cnt = 0;
    int i = 0 , j = 0;
    while(i<m)
    {
        if(j==-1||t[i]==p[j]) i++,j++;
        else j = nnext[j];
        if(j==n) cnt++,j=nnext[j];
    }
    return cnt;
}


int main()
{
    int T;
    scanf("%d",&T);
    for( int i = 0 ; i < T ; i++)
    {
        scanf("%s",p);
        scanf("%s",t);
        n = strlen(p);
        m = strlen(t);
        findnext();
        printf("%d\n",kmp());
    }
    return 0;
}
