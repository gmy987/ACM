//匈牙利邻接矩阵
#include <stdio.h>
#include <string.h>
#define MAXN 208
#define MAXM 208

int g[MAXN][MAXM], f[MAXM], rm[MAXM], lm[MAXN];
//原图1有边0无边、是否在增广路上、右集合点匹配哪个左点、左集合点匹配哪个右点
int N, M;  //左集合点数、右集合点数

bool path(int s)
{  //寻找增广路
	for(int i = 1;i <= M;i++)
	{
		if(!f[i] && g[s][i])
		{
			f[i] = 1;
            //右边的点没有被匹配，或者可以找到增广路
			if(!rm[i] || path(rm[i]))
			{
			   rm[i] = s;
			   lm[s] = i;   //匹配上
			   return true;
			}
		}
	}
    return false;
}

int maxMatch()
{
    int ans = 0;
	memset(lm, 0, sizeof(lm));
	memset(rm, 0, sizeof(rm));
	//贪心、能匹配的先匹配
	for(int i = 1;i <= N;i++)
	{
	    for(int j = 1;!lm[i] && j <= M;j++)
	    {
	        if(g[i][j] && !rm[j])
	        {
				rm[j] = i;
				lm[i] = j;
                ans++;
			}
	    }
	}
	for(int i = 1;i <= N;i++)
	{
	    if(!lm[i])
	    {
            //未匹配
	        memset(f,0,sizeof(f));
            if(path(i))  //寻找增广路
                ans++;
        }
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
