#include<iostream>
#include<map>
#include<string>
using namespace std;

double m[32][32];
map<string, int> mm;
int n;

int floyed() {
	int i, j, k;
	for (k = 1; k <= n; ++k)
	  for (i = 1; i <= n; ++i)
	    for (j = 1; j <= n; ++j)
	       if (m[i][j] < m[i][k] * m[k][j])
	          m[i][j] = m[i][k] * m[k][j];
	for (i = 1; i <= n; ++i)
	  if (m[i][i] > 1)
	    return 1;
    return 0;
}

int main(){
	int i, j, p, t = 1;
	double r;
	char ch1[30], ch2[30];
	while (scanf("%d", &n), n) {
		for (i = 1; i <= n; ++i) {
		   scanf("%s", ch1);
		   mm[ch1] = i;    
		}
	   scanf("%d", &p);
	   memset(m, 0, sizeof(m));
	   for (i = 0; i < p; ++i) {
			scanf("%s%lf%s", ch1, &r, ch2);
			m[mm[ch1]][mm[ch2]] = r;
		}
		if (floyed())
		   printf("Case %d: Yes\n", t++);
		else 
		   printf("Case %d: No\n", t++);		
    }
    return 0;
}
