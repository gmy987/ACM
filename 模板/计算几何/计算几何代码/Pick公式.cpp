//A = b / 2 + i -1  ���� b �� i �քe��ʾ�ڱ߽��ϼ��Ȳ��ĸ��ӵ�֮����
//http://www.hwp.idv.tw/bbs1/htm/%A6V%B6q%B7L%BFn%A4%C0/%A6V%B6q%B7L%BFn%A4%C0.htm
// http://acm.pku.edu.cn/JudgeOnline/problem?id=2954

#include <stdio.h>
#include <stdlib.h>

typedef struct TPoint
{
	int x;
	int y;
}TPoint;

typedef struct TLine
{
	int a, b, c;
}TLine;

int triangleArea(TPoint p1, TPoint p2, TPoint p3)
{
    //��֪������������������꣬�������ε���� 
    int k = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y
      - p2.x * p1.y - p3.x * p2.y - p1.x * p3.y;  
    if(k < 0) return -k;
    else return k;
}

TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //�߶�����ֱ��,����ֱ�߷��̵�����ϵͳ 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

int Count(TPoint p1, TPoint p2)
{
	int i, sum = 0, y;
	TLine l1 =  lineFromSegment(p1, p2);
	if(l1.b == 0) return abs(p2.y - p1.y) + 1;
	if(p1.x > p2.x) swap(p1.x, p2.x); //����û�н���WA���� 
	for(i = p1.x;i <= p2.x;i++){
		y = -l1.c - l1.a * i;
		if(y % l1.b == 0) sum++;
	}
	return sum;	
}

int main()
{
 	//freopen("in.in", "r", stdin);
	//freopen("OUT.out", "w", stdout);
	TPoint p1, p2, p3;
	while(scanf("%d%d%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF){
		if(p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0 && p3.x == 0 && p3.y == 0) break;
		int  A = triangleArea(p1, p2, p3);//AΪ��������� 
		int b = 0;
		int i;
		b = Count(p1, p2) + Count(p1, p3) + Count(p3, p2) - 3;//3�������������һ�� 
		//i = A / 2- b / 2 + 1;
		i = (A - b) / 2 + 1;
		printf("%d\n", i);	
	} 
	return 0;	
}
