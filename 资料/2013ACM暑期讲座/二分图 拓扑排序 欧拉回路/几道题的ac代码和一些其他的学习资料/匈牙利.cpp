//�������ڽӾ��� 
#include <stdio.h>
#include <string.h>
#define MAXN 208
#define MAXM 208

int g[MAXN][MAXM], f[MAXM], rm[MAXM], lm[MAXN];
//ԭͼ1�б�0�ޱߡ��Ƿ�������·�ϡ��Ҽ��ϵ�ƥ���ĸ���㡢�󼯺ϵ�ƥ���ĸ��ҵ�
int N, M;  //�󼯺ϵ������Ҽ��ϵ��� 

int path(int s) {  //Ѱ������· 
	int i;
	for (i = 1; i <= M; ++i) {
		if (f[i] == 0 && g[s][i] == 1) {
			f[i] = 1;
         //�ұߵĵ�û�б�ƥ�䣬���߿����ҵ�����· 
			if (rm[i] == 0 || path(rm[i])) {
			   rm[i] = s; lm[s] = i;   //ƥ���� 
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
	//̰�ġ���ƥ�����ƥ��
	for (i = 1; i <= N; ++i)
	   for (j = 1; !lm[i] && j <= M; ++j)
	      if (g[i][j] && !rm[j]) {
				rm[j] = i; lm[i] = j;
            ans++;
			}
	
	for (i = 1; i <= N; ++i)
		if (!lm[i]) {   //δƥ�� 
	      memset(f, 0, sizeof(int) * (N + 1));
	      if (path(i))  //Ѱ������· 
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
