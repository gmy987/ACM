#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 105 
#define MAXP 2005
#define ll long long
using namespace std;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int x[MAXN],y[MAXN],z[MAXN],r[MAXN];
struct Point{
    int x,y,z;
}point[MAXP];
int m,n,p,q;
int judgePlane(int k,int i)
{
    return ((ll)point[i].x)*(ll)a[k]+(ll)point[i].y*(ll)b[k]+(ll)point[i].z*(ll)c[k]+(ll)d[k]>(ll)0?1:0;
}
int judgeCircle( int k , int i )
{
    return (ll)(point[i].x-x[k])*(ll)(point[i].x-x[k])+(ll)(point[i].y-y[k])*(ll)(point[i].y-y[k])+(ll)(point[i].z-z[k])*(ll)(point[i].z-z[k])>(ll)r[k]*(ll)r[k]?1:0;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&m,&n,&p,&q);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d%d%d",&x[i],&y[i],&z[i],&r[i]);
        if( p == 0 )
        {
            for( int i = 0 ; i < q ; i++ )
                scanf("%d%d%d",&x[i],&y[i],&z[i]);
            for( int i = 0 ; i < q ; i++ )
                printf("Both\n");
            if(t)
                printf("\n");
            continue;
        }
        bool flag = true;
        int tmp=0,color=0;
        for( int i = 0 ; i < p ; i++ )
        {
            tmp = color;
            color = 0;
            scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].z);
            if( flag )
            {
                for( int k = 0 ; k < m ; k++ )
                    color^=judgePlane(k,i);
                for( int k = 0 ; k < n ; k++ )
                    color^=judgeCircle(k,i);
            }
            if(i&&tmp!=color)
                flag = false;
        }
        for( int i = 0 ; i < q ; i++ )
            scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].z);
        if( !flag )
        {
            printf("Impossible\n");
            if(t) printf("\n");
        }
        else
        {
            for( int i = 0 ; i < q ; i++ )
            {
                tmp = 0;
                for( int k = 0 ; k < m ; k++ )
                    tmp^=judgePlane(k,i);
                for( int k = 0 ; k < n ; k++ )
                    tmp^=judgeCircle(k,i);
                if( tmp == color )
                    printf("Y\n");
                else printf("R\n");
            }
            if(t)
            printf("\n");
        }
    }
    return 0;
}
