//�������ڽӾ���
#include <stdio.h>
#include <string.h>
#define MAXN 208
#define MAXM 208

int g[MAXN][MAXM], f[MAXM], rm[MAXM], lm[MAXN];
//ԭͼ1�б�0�ޱߡ��Ƿ�������·�ϡ��Ҽ��ϵ�ƥ���ĸ���㡢�󼯺ϵ�ƥ���ĸ��ҵ�
int N, M;  //�󼯺ϵ������Ҽ��ϵ���

bool path(int s)
{  //Ѱ������·
	for(int i = 1;i <= M;i++)
	{
		if(!f[i] && g[s][i])
		{
			f[i] = 1;
            //�ұߵĵ�û�б�ƥ�䣬���߿����ҵ�����·
			if(!rm[i] || path(rm[i]))
			{
			   rm[i] = s;
			   lm[s] = i;   //ƥ����
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
	//̰�ġ���ƥ�����ƥ��
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
            //δƥ��
	        memset(f,0,sizeof(f));
            if(path(i))  //Ѱ������·
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
