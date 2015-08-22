#include <iostream>
#include <cstdio>

using namespace std;

struct Edge
{
    int to,w,next;//to保存每条边的终点
                  //w保存边权值
                  //next保存下一条同起点的边；
}edge[NUM_OF_EDGE];

//往图里加边的操作
void add( int u , int v , int w )
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
//最后head[i]中保存的是以i为起点的最后一条添加的边

//遍历以u节点为起始位置的所有边
for( int i = head[u] ; ~i ; i = edge[i].next )
{
    /*.......
    .....
    .........*/
}

//当需要求各点到终点的最短路时，需要求反向图
//加边操作如下：
void add( int u , int v , int w )
{
    //构造正向图
    edge[cnt<<1].w = w;
    edge[cnt<<1].to = v;
    edge[cnt<<1].next = head[u];
    head[u] = cnt<<1;

    //构造反向图，原来的起点变为终点，终点变为起点。
    //tail[i]保存正向图中以i为终点的各边，即在反向图中以i为起点的各边
    edge[cnt<<1|1].w = w;
    edge[cnt<<1|1].to = u;
    edge[cnt<<1|1].next = tail[v];
    tail[v] = cnt<<1|1;

    cnt++;
}
