/*
这个题目很垃圾，非__int64 
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define Maxn 1000005 

int change[10][2] = {{0, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                  {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

typedef struct TPoint
{
	int x, y;
}TPoint;

char str[Maxn];

int main()
{
	int i, test, n;
	__int64 area;
	TPoint p1, p2;
	scanf("%d", &test);
	while(test--){
		scanf("%s", str);
		p1.x = 0;
		p1.y = 0;
		area = 0;
		for(i = 0;str[i];i++){
			if(str[i] == '5') break;
			p2.x = p1.x + change[str[i] - '0'][0];
			p2.y = p1.y + change[str[i] - '0'][1];	
			area += (p1.x * p2.y - p2.x * p1.y);
			p1 = p2;
		}
		if(area < 0) area = -area;
		if(area % 2 == 0) printf("%I64d\n", area / 2);
		else printf("%I64d.5\n", area / 2);
	}
	return 0;
}
