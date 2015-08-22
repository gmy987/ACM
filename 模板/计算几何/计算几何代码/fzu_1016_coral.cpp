#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	double a, b, x, y, temp, a0, b0;
	double len2, num3, len1;
	while(scanf("%lf %lf %lf %lf",&a,&b,&x,&y) != EOF)
	{
		if(a == 0 && b == 0 && x == 0 && y == 0)break;
		if(a < b){temp = a; a = b; b = temp;}
		if(x < y){temp = x; x = y; y = temp;}
		if(x < a && y < b)printf("Escape is possible.\n");
		else if(a * b < x * y || a * a + b * b < x)printf("Box cannot be dropped.\n");
		else 
		{
			a = a / 2;
			b = b / 2;
			x = x / 2;
			y = y / 2;
			len1 =  a * a + b * b ;
		    len2 =  x * x + y * y ;
			if(len2 < len1)
			{
				a0 = sqrt (len2 - b * b);
				b0 = sqrt (len2 - a * a);
				num3 = 2 * len2 - 2 * a0 * a - 2 * b0 * b;
				if( num3 > 4 * y * y)printf("Escape is possible.\n");
				else printf("Box cannot be dropped.\n");
			}
			else printf("Box cannot be dropped.\n");
		}
	}
	return 0;
} 
