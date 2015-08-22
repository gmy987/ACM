/* KM O(V^3)
�걸ƥ�� ����ƥ��ı߳�ʼ��Ϊ -INF �Ը���Ҳ����

����СȨƥ��
��һ��ֻ�轫��Ȩ ��Ϊ����
������w[i][j] = f - w[i][j], f Ϊһ���� f > max(w[i][j]) * n
*/
#include <stdio.h>
#include <string.h>
#define MAX 208
#define INF 0x3f3f3f3f

int N;     //N �󼯺ϵĵ���, �Ҽ��ϵ�����ͬ
int A[MAX], B[MAX], rm[MAX], xv[MAX], yv[MAX];
// A�󼯺Ͽ��ж���, BΪ�Ҽ��Ͽ��ж���, rm[]Ϊ�Ҽ��ϵ�ƥ���󼯺��ĸ���
// xv[] yv[] �ֱ��ʾ���Ҽ��ϵ��Ƿ��ڽ�������, 1�ǣ�0����

int W[MAX][MAX], slack[MAX];  //slack[] Ϊ�ɳ���

int path(int i)
{                               //Ѱ�ҿ�����·
    int t;
	xv[i] = 1;    //��� Xi �ڽ�������
	for(int j = 1;j <= N;j++)
	{
	    if(yv[j])
	        continue;
		t = A[i] + B[j] - W[i][j];
		if(t == 0)   //�Ƿ��� A[i] + B[j] = W[i][j]
		{
		    yv[j] = 1;	     //��� Yj �ڽ�������
		    if(rm[j] == 0 || path(rm[j]))//jδ��ƥ�� ���� �����ҵ�������·
		    {
				rm[j] = i;    //ƥ��
				return 1;
			}
	    }
	    // Xi �ڽ������У�Yj ���ڽ�������
	    else if(slack[j] > t)
            slack[j] = t;     //slack[j] = min(slack[j], A[i]+B[j]-w[i, j])
	}
	return 0;
}

int KM()
{
	int d;
	memset(B, 0, sizeof(B));     //�����ʼ�� B[j] = 0
	for(int i = 1;i <= N;i++)
	{
	    A[i] = -INF;
	    for(int j = 1;j <= N;j++)  // A[i] = max(w[i][j])
	    {
	        if(W[i][j] > A[i])
                A[i] = W[i][j];
	    }
	}
	memset(rm,0,sizeof(rm));    //Y���ϵ�δ��ƥ��
	for(int i = 1;i <= N;i++)
	{
	    memset(slack,0x3f,sizeof(slack));   //�ɳ�����ʼֵ�ܴ�
	    memset(xv,0,sizeof(xv));
	    memset(yv,0,sizeof(yv));
	    while(!path(i))   //Ѱ������·
	    {        //û���ҵ� �޸Ķ���ֵ
                 // d = min{A[i]+B[j] - w[i,j]} Xi�ڽ������У�Yi���ڽ�������
            d = INF;
		    for(int j = 1;j <= N;j++)
		    {
		        if (!yv[j])      //Yj ���ڽ�������
                    d = min(d, slack[j]);
		    }
		    //��������
		    for(int k = 1;k <= N;k++)
		    {
		        if(xv[k])
		        {
		            A[k] -= d;      //X����Ķ���ȫ����Сĳ��ֵd��
		            xv[k] = 0;
		        }
			    if(yv[k])
			    {
			        B[k] += d;
			        yv[k] = 0;    //Y����Ķ���ȫ������ͬһ��ֵd
			    }else
			    slack[k] -= d;     // �޸Ķ����Ҫ�����е�slackֵ����ȥd
            }
        }
    }
	int sum = 0;
	for(int i = 1;i <= N;i++)
        sum += W[rm[i]][i];
	return sum;
}

int main()
{
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
            W[i][j]               //wΪ�йر�Ȩ�Ľ�ͼ�洢
    }
    KM();
    return 0;
}
