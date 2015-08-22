//特别注意此题要按照字典序输出，因此，dir的顺序必须是x从小到达，x相同时y从小到大

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
bool flag;
int m[50][50],step,p,q;

struct Node
{
    int x,y;
}n[1000];

void dfs(int x,int y)
{
    if( step == p*q )
    {
        flag = true;
        return;
    }
    for( int i = 0 ; i < 8 ; i++ )
    {
        int xa = x+dir[i][0],ya = y+ dir[i][1];
        if( xa >0 && xa <= p && ya > 0 && ya <= q && !m[xa][ya] )
        {
            n[step].x = xa;
            n[step].y = ya;
            step++;
            m[xa][ya] = 1;
            dfs(xa,ya);
            if( step == p*q )
            {
                flag = true;
                return;
            }
            m[xa][ya] = 0;
            step--;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for( int i = 1 ; i <= t ; i++ )
    {
        memset(m,0,sizeof(m));
        memset(n,0,sizeof(n));
        flag = false;
        n[0].x = 1;
        n[0].y = 1;
        m[1][1] = 1;
        scanf("%d%d",&q,&p);
        step = 1;
        dfs(1,1);
        printf("Scenario #%d:\n",i);
        if( !flag )
            printf("impossible\n\n");
        else
        {
            for( int i = 0 ; i < p*q ; i++ )
                printf("%c%d",(n[i].x+'A'-1),n[i].y);
            printf("\n\n");
        }
    }
    return 0;
}
