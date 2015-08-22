/*
ƽ����N���㣬��һ���뾶R��Բȥ���ǣ�����ܸ��Ƕ��ٸ��㣿

�ȽϾ������Ŀ��

��ÿ������RΪ�뾶��Բ����N��Բ�����󽻡���һ��O(N^2)������ת��Ϊ�󱻸��Ǵ������Ļ���

��ÿһ��Բ�������ϵ�ÿ�λ��ص�����������AԲ��BԲ�ཻ��A��[PI/3, PI/2]�����䱻B����(PIΪԲ����)����ô����AԲ��������PI/3����һ��+1��ǣ���PI/2����һ��-1��ǡ�

����[PI*5/3, PI*7/3]�������0�������ֻҪ��0�㴦������μ��ɡ�

��һ��Բ�ϵ����б�����򣬴�ͷ��ʼɨ�衣��ʼans = 0������+1��Ǹ�ans++������-1���ans--��ɨ�������ans�����ֵ����Բ�ϱ��������Ļ���������Բ��ans�����ֵ���Ǵ𰸡�

�ܸ��Ӷ�O(N^2 * logN)

*/#include <stdio.h>
#include <math.h>

#define eps 1e-6

struct point 
{
	double x, y;
};

double dis(point p1, point p2)
{
	point p3;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	return p3.x * p3.x + p3.y * p3.y;
}

point find_centre(point p1, point p2)
{
	point p3, mid, centre;
	double b, c, ang;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;		
	b = dis(p1, mid);
	c = sqrt(1 - b);
	if(fabs(p3.y) < eps)//���ߵ�б��90��
	{
		centre.x = mid.x;
		centre.y = mid.y + c;
	}
	else 
	{
		ang = atan(-p3.x / p3.y);
		centre.x = mid.x + c * cos(ang);
		centre.y = mid.y + c * sin(ang);
	}
	return centre;	
}

int main()
{
    int n, ans, tmpans, i, j, k;
    point p[305], centre;
    double tmp;
    while(scanf("%d", &n) && n)
    {
		for(i = 0;i < n;i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		ans = 1;
		for(i = 0;i < n;i++)
			for(j = i + 1;j < n;j++)
			{
				if(dis(p[i], p[j]) > 4) continue;
				tmpans = 0;
				centre = find_centre(p[i], p[j]);
				for(k = 0;k < n;k++)
				{
					//if(tmpans + n - k <= ans) break;
					tmp = dis(centre, p[k]);
					//if(tmp < 1.0 || fabs(tmp - 1.0) < eps) tmpans++;
					if(tmp <= 1.000001) tmpans++;
				}
				if(ans < tmpans) ans = tmpans;
			}
		printf("%d\n", ans);		
    }
    return 0;
}

