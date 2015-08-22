#include <stdio.h>

struct SEG
{
	int x1, x2;
};

int n, flag;
SEG seg[10005];

void lisan(int l, int r, int j)
{
	if(j == n)
	{
		if(l < r) flag = 1;
		return;
	}
	if(l >= seg[j].x1 && r <= seg[j].x2) return;
	else
	{
		if(l >= seg[j].x2) lisan(l, r, j + 1);
		else if(r <= seg[j].x1) lisan(l, r, j + 1);
		else 
		{
			if(l < seg[j].x1) lisan(l, seg[j].x1, j + 1);
			if(r > seg[j].x2) lisan(seg[j].x2, r, j + 1);
		}	
	}
}

int main()
{
	int ca, ans;
	scanf("%d", &ca);
	while(ca--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d", &seg[i].x1, &seg[i].x2);
			seg[i].x1--;
		}
		ans = 0;
		for(int i = n - 1;i >= 0;i--)
		{
			flag = 0;
			lisan(seg[i].x1, seg[i].x2, i + 1);
			if(flag == 1) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
