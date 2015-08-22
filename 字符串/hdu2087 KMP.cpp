/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-07 19:37
*
* Filename: hdu2087.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1005
using namespace std;
int nex[maxn];
char p[maxn],t[maxn];
int n,m;
void findnex()
{
    nex[0]=-1;
    int k=-1,j=0;
    while(j<m)
    {
        if(k==-1||p[k]==p[j])
        {
            if(p[++k]!=p[++j]) nex[j] = k;
            else nex[j] = nex[k];
        }
        else k = nex[k];
    }
}
int kmp()
{
    int cnt = 0;
    int i = 0 , j = 0;
    while(i<n)
    {
        if(j==-1||t[i]==p[j]) i++,j++;
        else j = nex[j];
        if(j==m) j = 0,cnt++;
    }
    return cnt;
}

int main()
{
    while(true)
    {
        scanf("%s",t);
        if(!strcmp(t,"#"))break;
        scanf("%s",p);
        n = strlen(t);
        m = strlen(p);
        findnex();
        printf("%d\n",kmp());
    }
    return 0;
}
