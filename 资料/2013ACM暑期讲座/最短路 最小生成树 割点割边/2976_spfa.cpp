#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 102

int dist[MAX], flag[MAX];
int que[MAX], front, rear;     //使用循环队列,可以节省内存

struct Node
{
   int id, d;
   Node(){}
   Node(int _id, int _d):
      id(_id), d(_d){} 
};

vector <Node> mp[MAX];        //vector模拟邻接链表 

void SPFA(int s)              //s为起点 
{
   int i, u, v;
   memset(flag, 0, sizeof(flag));     //flag[]为0说明不在队列中，1则相反 
   memset(dist, 0x1f, sizeof(dist));
   dist[s] = 0;
   flag[s] = 1;
   front = rear = 0;
   que[rear++] = s;
   while (front != rear)             //若队列非空 
   {
      u = que[front++];             //取队首元素 u
      flag[u] = 0;
      if (front >= MAX)          
         front = 0;
      for (i = 0; i < mp[u].size(); ++i)
      {
         v = mp[u][i].id;               //对于u相邻的点v，进行松弛操作 
         if (dist[u] + mp[u][i].d < dist[v])  
         {
            dist[v] = dist[u] + mp[u][i].d;
            if (flag[v] == 0)          //若v不在队列中，加入队列 
            {
               que[rear++] = v;
               flag[v] = 1;            //入队标记 
               if (rear >= MAX)
                  rear = 0;
            }
         }
      }
   }
}

int main()
{
   int a, b, c, i, n, m;
   while (scanf("%d%d", &n, &m) && n != 0)
   {
      for (i = 1; i <= n; ++i)            //清空表 
         mp[i].clear();
      for (i = 0; i < m; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         mp[a].push_back(Node(b, c));     //双向边 
         mp[b].push_back(Node(a, c));
      }
      SPFA(1);
      printf("%d\n", dist[n]);
   }   
   return 0;
}







