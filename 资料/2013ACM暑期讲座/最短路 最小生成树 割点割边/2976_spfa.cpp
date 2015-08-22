#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 102

int dist[MAX], flag[MAX];
int que[MAX], front, rear;     //ʹ��ѭ������,���Խ�ʡ�ڴ�

struct Node
{
   int id, d;
   Node(){}
   Node(int _id, int _d):
      id(_id), d(_d){} 
};

vector <Node> mp[MAX];        //vectorģ���ڽ����� 

void SPFA(int s)              //sΪ��� 
{
   int i, u, v;
   memset(flag, 0, sizeof(flag));     //flag[]Ϊ0˵�����ڶ����У�1���෴ 
   memset(dist, 0x1f, sizeof(dist));
   dist[s] = 0;
   flag[s] = 1;
   front = rear = 0;
   que[rear++] = s;
   while (front != rear)             //�����зǿ� 
   {
      u = que[front++];             //ȡ����Ԫ�� u
      flag[u] = 0;
      if (front >= MAX)          
         front = 0;
      for (i = 0; i < mp[u].size(); ++i)
      {
         v = mp[u][i].id;               //����u���ڵĵ�v�������ɳڲ��� 
         if (dist[u] + mp[u][i].d < dist[v])  
         {
            dist[v] = dist[u] + mp[u][i].d;
            if (flag[v] == 0)          //��v���ڶ����У�������� 
            {
               que[rear++] = v;
               flag[v] = 1;            //��ӱ�� 
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
      for (i = 1; i <= n; ++i)            //��ձ� 
         mp[i].clear();
      for (i = 0; i < m; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         mp[a].push_back(Node(b, c));     //˫��� 
         mp[b].push_back(Node(a, c));
      }
      SPFA(1);
      printf("%d\n", dist[n]);
   }   
   return 0;
}







