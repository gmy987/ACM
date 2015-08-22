/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-08 08:44
*
* Filename: hdu3746.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
#define maxn  100005

using namespace std;
int nex[maxn];
char p[maxn];
int m;
void findnext()
{
    nex[0] = -1;
    int k=-1,j=0;
    while(j<m)
    {
        if(k==-1||p[k]==p[j]) nex[++j] = ++k;
        else k = nex[k];
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",p);
        m = strlen(p);
        findnext();
        int ans = m - nex[m];
        if(ans!=m&&m%ans==0) puts("0");
        else printf("%d\n",ans-nex[m]%ans);
    }
    return 0;
}
