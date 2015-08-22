/*

���͹�������һ�㲽�裺
1.����n���㣬�ҳ���С���ұߵĵ�v0�������õ����һ���㽻�����ס�õ����� 
2.�����������v0��������x��ļнǣ���������нǴӴﵽС���� 
3.
 
*/

//���㼸���е�͹���������(graham�㷨)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 10000

/* ��������Ͷ��� */
typedef struct {
	double x;
	double y;
	double arCos;
}Point1;
int n;     // ����ĸ���
Point1 points[MAXN];     // ��������
int stack[MAXN];  // ջ

/*������*/
int main()
{
	void Init();
	void Make();
	Init();    //�������ݵĶ���
	Make();    //�����㷨����
	while(1); 
	return 0;
}

/*���ݶ��뺯��*/
void Init()
{
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) 
    scanf("%lf%lf", &points[i].x, &points[i].y);
}

/*�㷨ʵ�ֺ���*/
void Make()
{
	int Multi(Point1, Point1, Point1);   //�������������Ļ�
	double Angle(int);      //�������ඥ�����һ����ĽǶ�,Ϊ������׼��
	void QSort(int, int);     //�Զ�����п�������
	void Swap(int, int);      
	int i, j, t;
	double min = 32767.0;
	for(i = 0; i < n; ++i){     //�ҵ�һ������,��Ϊ�㷨����ʼ����
		if(points[i].y < min) {
			j = i;
			min = points[i].y;
		}
    }
	Swap(0, j);
	for(i = 1; i < n; ++i){     //�������һ����������ඥ�㵽��һ����߶���x��ļн�
		points[i].arCos = Angle(i);
	}
	QSort(1, n-1);       //�������õ��ĽǶȽ��п�������.
	for(i = 0; i <= 2; ++i) stack[i] = i;   //��ǰ3������ѹջ
	t = 2;
	//i= 3�� 
	while(i < n) {
		/*����µĵ�,�������ջ�е�2�㹹����һ��"��"��, ��ջ��Ԫ�س�ջ. ֱ����ջ�����*/
		while(Multi(points[stack[t-1]], points[stack[t]], points[i]) && t >= 1)t--;     
		t++;        // ���µ�ѹջ
		stack[t] = i;
		i++;
	}
	/*��ӡ���*/
	for(i = 0; i <=t; ++i) 
		printf("<%.2lf, %.2lf>\n",points[stack[i]].x, points[stack[i]].y);
}
int Multi(Point1 px, Point1 py, Point1 pz)
{
	double k;
	k = (py.x-px.x)*(pz.y-py.y) - (pz.x-py.x)*(py.y-px.y);  // ��������������������,
	// �ж�3�������ɵĽ��ǲ���һ��"��"��.
	if(k < 0) return 1;
	return 0; 
}

/*�Ƕȼ��㺯��*/
double Angle(int i)
{
	double j, k, m, n;
	j = fabs(points[i].x - points[0].x);
	k = fabs(points[i].y - points[0].y);
	m = sqrt(j*j+k*k);     //�õ�����i ����һ������߶γ���.
	n = acos(j/m);      //�õ����߶���x��ĽǶ�
	//ǿ�� 
	return n;
}

void QSort(int top, int bot)
{
    //���� 
	int Loc(int, int);
	int pos;
	
	if(top < bot) {
		pos = Loc(top, bot);
		QSort(top, pos-1);
		QSort(pos+1, bot);
	}
}

int Loc(int top, int bot)
{
	void Swap(int, int);
	double x = points[top].arCos;
	int j, k;
	j = top+1;
	k = bot;
	while(1) {
		while(j < bot && points[j].arCos < x) j++;
		while(k > top && points[k].arCos > x) k--;
		
		if(j >= k) break;
		
		Swap(j, k);
	}
	Swap(top, k);
	return k;
}

void Swap(int px, int py)
{
	Point1 k;
	k = points[px];
	points[px] = points[py]; //ע�� 
	points[py] = k;
}
