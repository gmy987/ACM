/*
先说明一下，这里我把编号设定为1-24，而不是题目的0-23，并且设0为虚点
设x[i]是实际雇用的i时刻开始工作的员工数
R[i]是题目需要的i时刻正在工作的最少员工数
注意了，i时刻开始工作跟i时刻正在工作是完全不同的
设s[i] = x[1] + x[2] + …… + x[i]
则s[i]表示1-i这段时间开始工作的员工数
再设num[i]表示i时刻开始工作的最多可以雇用的员工数
∴有0 <= x[i] <= num[i]
即 0 <= s[i] - s[i-1] <= num[i]
由于是求最小值，所以用最长路
则有：①s[i] - s[i-1] >= 0；②s[i-1] - s[i] >= -num[i]；
(1 <= i <= 24，虽然0是虚点，但是s[1] - s[0]也是必要的！因为x[1]也是有范围的！)
由于员工可以持续工作8个小时(R[i]是i时刻正在工作的最少人数)
∴x[i-7] + x[i-6] + …… + x[i] >= R[i]【i-7开始工作的人在i时刻也在工作，其他同理】
即：③s[i] - s[i-8] >= R[i] (8 <= i <= 24)
但是有个特殊情况，就是从夜晚到凌晨的一段8小时工作时间
(x[i+17] + …… + x[24]) + (x[1] + x[2] + …… + x[i]) >= R[i]；
则：s[24] - s[i+16] + s[i] >= R[i];
整理一下：④s[i] - s[i+16] >= R[i] - s[24];
(1 <= i < 8，注意i=0是没有意义的，因为R[0]没有意义)
由于s[24]就是全天实际雇用的人数，而一共有n个员工可以雇用
所以设ans = s[24]
则：⑤s[i] - s[i+16] >= R[i] - ans;( 1 <= i < 8 )
所以就可以从小到大暴力枚举ans【或二分枚举】，通过spfa检验是否有解即可【存在负环无解】
但是还有一个问题，起点在哪里……
这时候虚点0就起作用了，我称它为超级起点
于是建图后直接判断spfa(0)是否有解就可以了
PS：还有另外一个条件必须用到……：⑥s[24] - s[0] >= ans]
不用这个条件二分枚举ans可以AC，但这只是数据问题，暴力从小到大枚举木有这条件就会错，所以说这个条件最关键而又难找……要仔细找特殊点和虚点的约束关系

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
struct Edge
{
    int to , next , w;
}edge[1000];
int h[100],head[100],cnt[100],c,t,r[30],num[30],n;
bool vis[1000];
void addEdge( int u , int v , int w)
{
    edge[c].to = v;
    edge[c].w = w;
    edge[c].next = head[u];
    head[u] = c++;
}

bool spfa()
{
    memset( vis , 0 , sizeof(vis));
    for( int i = 0 ; i <= 24 ; i++ )
        h[i] = -INF;
    memset( cnt , 0 ,sizeof(cnt));
    h[0] = 0;
    vis[0] = 1;
    queue<int>q;
    q.push(0);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] < w + h[u] )
            {
                h[v] = w + h[u];
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
                if( ++cnt[v] > 24 )
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset( num , 0 , sizeof(num));
        memset( r , 0 , sizeof(r));
        bool f = false;
        for( int i = 1 ; i <= 24 ; i++ ){
            scanf("%d",&r[i]);
            if(r[i]) f = true;
        }
        scanf("%d",&n);
        int temp;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&temp);
            num[temp+1]++;
        }
        if( !f )
        {
            printf("0\n");
            continue;
        }
        int ans;
        bool flag = false;
        //枚举s[24]所有可能值，s[24]为1-24时间内需要开始工作的人数，即所求
        for( int i = 1 ; i <= n ; i++ )
        {
            //注意每次枚举都需要初始化数据
            memset( head , -1 , sizeof(head));
            c = 1;

            for( int j = 1 ; j <= 24 ; j++)
            {
                addEdge( j - 1 , j , 0);        //s[i] - s[i-1] >= 0
                addEdge( j , j - 1 , -num[j]);  //s[i-1] - s[i] >= num[i]
                if( j >= 8 )
                    addEdge( j - 8 , j , r[j]); //s[i] - s[i-8] >= r[i]
            }

            for( int j = 1 ; j < 8 ; j++ )
                addEdge( j + 16 , j , r[j] - i ); //s[i] - s[i+16] >= r[i] - s[24]

            addEdge( 0 , 24 , i );       //s[24] - s[0] >= s[24]
            if(spfa())
            {
                flag = true;
                ans = i;
                break;
            }
        }
        if(flag) printf("%d\n",ans);
        else printf("No Solution\n");
    }
    return 0;
}
