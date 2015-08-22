#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int m,num[25],sum,len,vis[25];
bool flag;
bool cmp ( int a , int b )
{
    return a > b ;
}

bool dfs( int index , int length , int number )
{
    if( length == 0 )
    {
        number--;
        if( number == 0 )
            return true;
        int i;
        for( i = 1 ; vis[i] ; i++ );
        //cout<<num[i]<<endl;
        vis[i] = 1;
        if(dfs( i , len - num[i] , number ))
            return true;
        vis[i] = 0;
        number++;

    }
    else
    {
        for( int j = index ; j < m ; j++ )
        {
            if(vis[j]) continue;
            if( length >= num[j] )
            {
                vis[j] = 1;
                if(dfs( j , length - num[j] , number ))
                    return true;
                vis[j] = 0;
                if(length==num[j])
                    break;
            }
        }
    }
    return false;
}

int main()
{//freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        sum = 0;
        memset( num , 0 , sizeof( num ));
        memset( vis , 0 , sizeof( vis ));
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        if(sum%4)
        {
            printf("no\n");
            continue;
        }
        len = sum/4;
        sort( num , num + m ,cmp );
        if( num[0] > len )
        {
            printf("no\n");
            continue;
        }
        vis[0] = 1;
        if(dfs( 0 , len - num[0] , 4))
            printf("yes\n");
        else
            printf("no\n");
    }
}
