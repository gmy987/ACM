#include <stdio.h>

#include <math.h>

#define pi acos(-1)

double dis(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt((x1 - x2) * (x1 - x2) +
	   (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main()
{
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",
	      &x1, &y1, &z1, &x2, &y2, &z2, 
		  &x3, &y3, &z3) != EOF){
	  double a, b, c;
	  double p, s, s1, s2, r1, r2;
	  a = dis(x1, y1, z1, x2, y2, z2);
	  b = dis(x2, y2, z2, x3, y3, z3);
	  c = dis(x3, y3, z3, x1, y1, z1);
	  p = (a + b + c) / 2;
	  s = sqrt(p * (p - a) * (p - b) * (p - c));
	  r1 = a * b * c / s / 4;
	  r2 = 2 * s / (a + b +c);
	  s1 = pi * r2 * r2;
	  s2 = pi * r1 * r1;
	  
	  printf("%.3lf\n", s1 / s2);
	}
	return 0;	
}
