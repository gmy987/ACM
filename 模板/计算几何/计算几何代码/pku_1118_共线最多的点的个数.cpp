/*
2617120 chenhaifeng 1118 Accepted 512K 1890MS C++ 977B 2007-09-04 18:43:26 
ֱ��O(n^3)��ʱ����һ��������飬���i,j����ֱ���Ѿ����ҹ�����������

��ţ��˼��
���������� O(n3) �ģ���ʱ���ҵ�������ö��ÿ���㣬
Ȼ����������������ߵ�б�ʣ������������͵õ�����
�õ��ֱ������ܾ��������㡣������ֵ�����ˡ���
�Ӷ��� O(n2logn) �ġ������򻻳� hash��
�����Ż��� O(n2)�� 
2617134 chenhaifeng 1118 Accepted 276K 312MS G++ 1394B 2007-09-04 18:49:08 
*/
#include <stdio.h>
#include <math.h>

bool f[705][705];
int a[705];

int main()
{
	int n, i, j, s, num, maxn;
	int x[705], y[705];
	int t, m;

	
	while(scanf("%d", &n) != EOF && n){
		for(i = 0;i <= n - 1;i++){
			scanf("%d%d", &x[i], &y[i]);
		}
		maxn = -1;
		for(i = 0;i <= n - 1;i++){
			for(j = i;j <= n - 1;j++){
				f[i][j] = false;
			}
		}
		for(i = 0;i <= n - 1;i++){
			for(j = i + 1;j <= n - 1;j++){
				if(f[i][j] == true) continue;
				if(n - j < maxn) break;
				num = 2;
				t = 2;
				a[0] = i;
				a[1] = j;
				f[i][j] = true; 
				for(s = j + 1;s <= n - 1;s++){
					if(f[i][s] == true || f[j][s] == true) continue;
					if((y[i] - y[s]) * (x[j] - x[s]) == (x[i] - x[s]) * (y[j] - y[s])){
						 num++;	
						 a[t] = s;
						 for(m = 0;m <= t - 1;m++){
								f[m][s] = true;
						}
						t++;	
					}	 			
				}
				if(num > maxn) maxn = num;	
			}			
		}
		printf("%d\n", maxn);			
	}
	return 0;
} 

