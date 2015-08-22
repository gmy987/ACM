//匈牙利邻接矩阵 
#include <stdio.h>
#include <string.h>
#define MAXN 208
#define MAXM 208

int g[MAXN][MAXM], f[MAXM], rm[MAXM], lm[MAXN];
//原图1有边0无边、是否在增广路上、右集合点匹配哪个左点、左集合点匹配哪个右点
int N, M;  //左集合点数、右集合点数 

int path(int s) {  //寻找增广路 
	int i;
	for (i = 1; i <= M; ++i) {
		if (f[i] == 0 && g[s][i] == 1) {
			f[i] = 1;
         //右边的点没有被匹配，或者可以找到增广路 
			if (rm[i] == 0 || path(rm[i])) {
			   rm[i] = s; lm[s] = i;   //匹配上 
			   return 1;
			}
		}		
	}
   return 0;
}

int maxMatch() {
   int i, j, ans;
	ans = 0;
	memset(lm, 0, sizeof(int) * (N + 1)); 	
	memset(rm, 0, sizeof(int) * (M + 1));
	//贪心、能匹配的先匹配
	for (i = 1; i <= N; ++i)
	   for (j = 1; !lm[i] && j <= M; ++j)
	      if (g[i][j] && !rm[j]) {
				rm[j] = i; lm[i] = j;
            ans++;
			}
	
	for (i = 1; i <= N; ++i)
		if (!lm[i]) {   //未匹配 
	      memset(f, 0, sizeof(int) * (N + 1));
	      if (path(i))  //寻找增广路 
            ans++;
	   }
	//printf("%d\n", ans);
   return ans;
}

int main()
{
	while (scanf("%d%d", &N, &M) != EOF)
   {
		memset(g, 0, sizeof(g));
	//	initial();
		maxMatch();
	}
	return 0;
} 
