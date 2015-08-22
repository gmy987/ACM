#include<stdio.h>
#include<string.h>
#define MAXN 105
#define MAXM 105

int g[MAXN][MAXM], f[MAXM], match[MAXM], lm[MAXN];
int n, m, ans;

int path(int s){
	int i;
	for(i = 1; i <= m; ++i){
		if(f[i] == 0 && g[s][i] == 1){
			f[i] = 1;
			if(match[i] == 0 || path(match[i])){
			   match[i] = s; lm[s] = i;
			   return 1;
			}
		}
	}
     return 0;
}

int  MaxMatch(){
	ans = 0;
	memset(lm, 0, sizeof(lm));
	memset(match, 0, sizeof(match));
	for(int i = 1; i <= n; ++i)
	   for(int j = 1; !lm[i] && j <= m; ++j)
	      if(g[i][j] && !match[j]){
				match[j] = i; lm[i] = j; ans++;
			}
	for(int i = 1; i <= n; ++i)
		if(!lm[i]){
	      memset(f, 0, sizeof(f));
	      if(path(i))  ans++;
	   }
	return ans;
}

int main()
{
     int T;int pa,pb;int edge;
        scanf("%d",&T);
        for(int ce=1;ce<=T;ce++)
        {
                memset(g,0,sizeof(g));
                scanf("%d%d%d",&n,&m,&edge);
                for(int t=0;t<edge;t++)
              {
                scanf("%d%d",&pa,&pb);
                g[pa][pb]=1;
              }
                int rety=MaxMatch();
                printf("Case %d: %d\n",ce,rety);
        }
}

