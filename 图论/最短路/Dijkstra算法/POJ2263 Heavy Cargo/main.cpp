#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>

using namespace std;

struct Edge
{
    int w,next;
    string to;

}edge[200000];

map<string,int> head,h;
map<string,bool> vis;
int cnt,n,r;
string s,t;

void addEdge( string &u , string &v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

struct cmp{
    bool operator() ( string a , string b)
    {
        return h[a] < h[b];
    }
};

void Dijkstra()
{
    priority_queue<string,vector<string>,cmp> q;
    h[s] = 0x7ffff;
    q.push(s);
    while(!q.empty())
    {

        string u = q.top();
        q.pop();
        vis[u] = 1;
        for( int i = head[u] ; i ; i = edge[i].next )
        {
            string v = edge[i].to;
            int w = edge[i].w;
            if( h[v] < min(w,h[u]) )
            {
                h[v] = min( w , h[u]);
                q.push(v);
            }
        }
    }

}

int main()
{
    int num = 1;
    while(~scanf("%d%d",&n,&r))
    {
        if(!n&&!r) break;
        head.clear();
        h.clear();
        vis.clear();
        cnt = 1;
        string a,b;
        int c;
        for( int i = 0 ; i < r ; i++ )
        {
            cin >> a >> b >> c;
            addEdge ( a , b , c );
            addEdge ( b , a , c );
        }
        cin>>s>>t;
        Dijkstra();
        printf("Scenario #%d\n",num++);
        cout << h[t] << " tons"<< endl << endl;
    }
    return 0;
}
