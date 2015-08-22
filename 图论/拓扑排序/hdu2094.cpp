#include<cstdio>
#include<cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define MAXN 1500

using namespace std;
int n;
int graph[MAXN][MAXN];
int in[MAXN];
int cnt;
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset( graph , 0 , sizeof(graph));
        memset( in , 0 , sizeof(in));
        string a,b;
        map<string,int> m;
        cnt = 1;
        for( int i = 0 ; i < n ; i++ )
        {
            cin>>a>>b;
            if( m[a] == 0 )
                m[a] = cnt++;
            if( m[b] == 0 )
                m[b] = cnt++;
            if(!graph[m[a]][m[b]]){
                graph[m[a]][m[b]] = 1;
                in[m[b]]++;
            }
        }
        bool flag = 0;
        for( int i = 1 ; i < cnt ; i++ )
        {
            if( in[i] == 0 && !flag)
                flag = 1;
            else if( in[i] == 0 && flag )
            {
                flag = 0;
                break;
            }
        }
        if( flag )
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
