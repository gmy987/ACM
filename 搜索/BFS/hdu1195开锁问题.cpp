#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
char s1[5],s2[5];
struct Node{
    char s[5];
    int step;
};
bool vis[10000];

int cal( char s[5] )
{
    return 1000*(s[0]-'0')+100*(s[1]-'0')+10*(s[2]-'0')+(s[3]-'0');
}
bool equal( char s1[5] , char s2[5] )
{
    for( int i = 0 ; i < 4 ; i++ )
        if( s1[i] != s2[i] )
            return false;
    return true;
}
int bfs()
{
    Node u;
    for( int i = 0 ; i < 4 ; i++ )
        u.s[i] = s1[i];
    u.step = 0;
    queue<Node> q;
    q.push(u);
    int a = cal(s1);
    vis[a] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        Node v;
        if( equal(s2,u.s))
            return u.step;
        for( int i = 0 ; i < 4 ; i++ )
        {
            v.s[i] = u.s[i]+1;
            if( u.s[i] == '9') v.s[i] = '1';
            for( int j = 0 ; j < 4 ; j++ )
                if( i != j )
                    v.s[j] = u.s[j];
            if(!vis[cal(v.s)])
            {
                vis[cal(v.s)] = 1;
                v.step = u.step + 1;
                q.push(v);
            }
            v.s[i] = u.s[i]-1;
            if( u.s[i] == '1' ) v.s[i] = '9';
            for( int j = 0 ; j < 4 ; j++ )
                if( i!=j )
                    v.s[j] = u.s[j];
            if( !vis[cal(v.s)] )
            {
                vis[cal(v.s)] = 1;
                v.step = u.step + 1;
                q.push(v);
            }
        }
        for( int i = 0 ;i < 3 ; i++ )
        {
            v.s[i] = u.s[i+1];
            v.s[i+1] = u.s[i];
            for( int j = 0 ; j < 4 ; j++ )
                if( j != i && j != i+1)
                    v.s[j] = u.s[j];
            if( !vis[cal(v.s)])
            {
                vis[cal(v.s)] = 1;
                v.step = u.step + 1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis , 0 , sizeof(vis));
        scanf("%s",s1);
        scanf("%s",s2);
        printf("%d\n",bfs());
    }
}
