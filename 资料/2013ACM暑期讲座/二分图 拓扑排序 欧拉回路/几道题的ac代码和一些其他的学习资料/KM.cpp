/* KM O(V^3)  
�걸ƥ�� ����ƥ��ı߳�ʼ��Ϊ -INF �Ը���Ҳ����
 
����СȨƥ�� 
��һ��ֻ�轫��Ȩ ��Ϊ����
������w[i][j] = w - w[i][j], w Ϊһ���� w > max(w[i][j]) * n
*/

#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAX 208
#define INF 0x3f3f3f3f 

int N;     //N �󼯺ϵĵ���, �Ҽ��ϵ�����ͬ 
int A[MAX], B[MAX], rm[MAX], xv[MAX], yv[MAX];  
// A�󼯺Ͽ��ж���, BΪ�Ҽ��Ͽ��ж���, rm[]Ϊ�Ҽ��ϵ�ƥ���󼯺��ĸ���
// xv[] yv[] �ֱ��ʾ���Ҽ��ϵ��Ƿ��ڽ�������, 1�ǣ�0���� 

int W[MAX][MAX], slack[MAX];  //slack[] Ϊ�ɳ��� 

int path(int i) { //Ѱ�ҿ�����· 
	int j, t, u;
	xv[i] = 1;    //��� Xi �ڽ������� 
	for (j = 1; j <= N; ++j) {
      if (yv[j])  continue;
		t = A[i] + B[j] - W[i][j];  
		if (t == 0) {        //�Ƿ��� A[i] + B[j] = W[i][j] 
		   yv[j] = 1;	     //��� Yj �ڽ������� 
		   if (rm[j] == 0 || path(rm[j])) {  //jδ��ƥ�� ���� �����ҵ�������· 
				rm[j] = i;    //ƥ�� 
				return 1;
			}
	   }
	  // Xi �ڽ������У�Yj ���ڽ�������
	   else if (slack[j] > t) 
			slack[j] = t;     //slack[j] = min(slack[j], A[i]+B[j]-w[i, j])
	}		 
	return 0;	
}

int KM() {
	int i, j, d, k;
	memset(B, 0, sizeof(B));     //�����ʼ�� B[j] = 0 
	for (i = 1; i <= N; ++i) {     
	   A[i] = -INF;       
	   for (j = 1; j <= N; ++j)  // A[i] = max(w[i][j])
	      if (W[i][j] > A[i])
	         A[i] = W[i][j];
	}
	memset(rm, 0, sizeof(rm));    //Y���ϵ�δ��ƥ�� 
	for (i = 1; i <= N; ++i) {
	   memset(slack, 0x3f, sizeof(slack));   //�ɳ�����ʼֵ�ܴ� 
	   memset(xv, 0, sizeof(xv));
	   memset(yv, 0, sizeof(yv));
	   while (!path(i)) {        //Ѱ������·
	   
		//û���ҵ� �޸Ķ���ֵ 
      // d = min{A[i]+B[j] - w[i,j]} Xi�ڽ������У�Yi���ڽ�������
        d = INF;
		  for (j = 1; j <= N; ++j)
		     if (!yv[j])      //Yj ���ڽ������� 
		         d = min(d, slack[j]); 
		         
		/* ����ʵ�� O(N ^ 2)
		for (k = 1; k <= N; ++k)
         if (xv[k])
            for (j = 1; j <= N; ++j)
               if (!yc[j])
                  d = min(d, A[k] + B[j] - W[k][j]);
      */ 
		         
      //�������� 
		  for (k = 1; k <= N; ++k) {
			  if (xv[k])  A[k] -= d, xv[k] = 0;    //X����Ķ���ȫ����Сĳ��ֵd��
			  if (yv[k])  B[k] += d, yv[k] = 0;    //Y����Ķ���ȫ������ͬһ��ֵd
			  else slack[k] -= d;     // �޸Ķ����Ҫ�����е�slackֵ����ȥd
         }
      }
   }
	int sum = 0;
	for (i = 1; i <= N; ++i)
	  sum += W[rm[i]][i];
	return sum;
	//printf("%d\n", sum);	
}

int main() {
   int i, j;
   scanf("%d", &N);
   for (i = 1; i <= N; ++i)
      for (j = 1; j <= N; ++j)
         W[i][j] = -INF;
 //  initial();
   KM();
}
