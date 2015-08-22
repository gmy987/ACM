/*
http://acm.pku.edu.cn/JudgeOnline/problem?id=2226
*/

//�������ڽӾ��� 
#include <stdio.h>
#include <string.h>
#define MAXN 1300
#define MAXM 1300

int g[MAXN][MAXM], f[MAXM], rm[MAXM], lm[MAXN];
//ԭͼ1�б�0�ޱߡ��Ƿ�������·�ϡ��Ҽ��ϵ�ƥ���ĸ���㡢�󼯺ϵ�ƥ���ĸ��ҵ�
int N, M;  //�󼯺ϵ������Ҽ��ϵ��� 

int path(int s)   //Ѱ������· 
{
	int i;
	for (i = 1; i <= M; ++i)
   {
		if (f[i] == 0 && g[s][i] == 1)
      {
			f[i] = 1;
			if (rm[i] == 0 || path(rm[i])) //�ұߵĵ�û�б�ƥ�䣬���߿����ҵ�����· 
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
	//̰�ġ���ƥ�����ƥ��
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
   for (i = 0; i < r; ++i)    //���б�� 
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
   for (j = 0; j < c; ++j)    //���б�� 
   {
      flag = 0;
      for (i = 0; i < r; ++i)
      {
         if (mp[i][j] == '*')
         {
            if (flag == 0)
               ccnt++;
            g[ccnt][rnum[i][j]] = 1;   //���� 
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