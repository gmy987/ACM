/*
http://acm.pku.edu.cn/JudgeOnline/problem?id=2226
*/

//匈牙利邻接矩阵 
#include <stdio.h>
#include <string.h>
#define MAXN 1300
#define MAXM 1300

int g[MAXN][MAXM], f[MAXM], rm[MAXM], lm[MAXN];
//原图1有边0无边、是否在增广路上、右集合点匹配哪个左点、左集合点匹配哪个右点
int N, M;  //左集合点数、右集合点数 

int path(int s)   //寻找增广路 
{
	int i;
	for (i = 1; i <= M; ++i)
   {
		if (f[i] == 0 && g[s][i] == 1)
      {
			f[i] = 1;
			if (rm[i] == 0 || path(rm[i])) //右边的点没有被匹配，或者可以找到增广路 
         {
			   rm[i] = s; lm[s] = i;
			   return 1;
			}
		}		
	}
   return 0;
}

int maxMatch()
{
   int i, j, ans;
	ans = 0;
	memset(lm, 0, sizeof(int) * (N + 1)); 	
	memset(rm, 0, sizeof(int) * (M + 1));
	//贪心、能匹配的先匹配
	for (i = 1; i <= N; ++i)
	   for (j = 1; !lm[i] && j <= M; ++j)
	      if (g[i][j] && !rm[j])
         {
				rm[j] = i; lm[i] = j;
            ans++;
			}
	
	for (i = 1; i <= N; ++i)
		if (!lm[i])
      {
	      memset(f, 0, sizeof(int) * (N + 1));
	      if (path(i))
            ans++;
	   }
	//printf("%d\n", ans);
   return ans;
}

char mp[52][52];
int rnum[52][52], rcnt, ccnt, r, c;

void preSolve()
{
   int i, j, flag;
   rcnt = 0;
   memset(rnum, 0, sizeof(rnum));
   for (i = 0; i < r; ++i)    //给行标号 
   {
      flag = 0;
      for (j = 0; j < c; ++j)
      {
         if (mp[i][j] == '*')
         {
            if (flag == 0)
               rcnt++;
            rnum[i][j] = rcnt;
            flag = 1;
         }
         else
            flag = 0;
      }
   }
   ccnt = 0;
   memset(g, 0, sizeof(g));
   for (j = 0; j < c; ++j)    //给列标号 
   {
      flag = 0;
      for (i = 0; i < r; ++i)
      {
         if (mp[i][j] == '*')
         {
            if (flag == 0)
               ccnt++;
            g[ccnt][rnum[i][j]] = 1;   //连边 
            flag = 1;
         }
         else
            flag = 0;
      }
   }
   N = ccnt, M = rcnt;
}

int main()
{
   int i;
   scanf("%d%d", &r, &c);
   getchar();
   for (i = 0; i < r; ++i)
      gets(mp[i]);
   preSolve();
   printf("%d\n", maxMatch());
}