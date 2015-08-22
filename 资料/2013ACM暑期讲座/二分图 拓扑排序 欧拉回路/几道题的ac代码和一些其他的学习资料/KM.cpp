/* KM O(V^3)  
完备匹配 不能匹配的边初始化为 -INF 对负的也可以
 
求最小权匹配 
法一：只需将边权 改为负的
法二：w[i][j] = w - w[i][j], w 为一大数 w > max(w[i][j]) * n
*/

#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAX 208
#define INF 0x3f3f3f3f 

int N;     //N 左集合的点数, 右集合点数相同 
int A[MAX], B[MAX], rm[MAX], xv[MAX], yv[MAX];  
// A左集合可行顶标, B为右集合可行顶标, rm[]为右集合点匹配左集合哪个点
// xv[] yv[] 分别表示左、右集合点是否在交错树中, 1是，0不是 

int W[MAX][MAX], slack[MAX];  //slack[] 为松弛量 

int path(int i) { //寻找可增广路 
	int j, t, u;
	xv[i] = 1;    //标记 Xi 在交错树中 
	for (j = 1; j <= N; ++j) {
      if (yv[j])  continue;
		t = A[i] + B[j] - W[i][j];  
		if (t == 0) {        //是否有 A[i] + B[j] = W[i][j] 
		   yv[j] = 1;	     //标记 Yj 在交错树中 
		   if (rm[j] == 0 || path(rm[j])) {  //j未被匹配 或者 可以找到可增广路 
				rm[j] = i;    //匹配 
				return 1;
			}
	   }
	  // Xi 在交错树中，Yj 不在交错树中
	   else if (slack[j] > t) 
			slack[j] = t;     //slack[j] = min(slack[j], A[i]+B[j]-w[i, j])
	}		 
	return 0;	
}

int KM() {
	int i, j, d, k;
	memset(B, 0, sizeof(B));     //顶标初始化 B[j] = 0 
	for (i = 1; i <= N; ++i) {     
	   A[i] = -INF;       
	   for (j = 1; j <= N; ++j)  // A[i] = max(w[i][j])
	      if (W[i][j] > A[i])
	         A[i] = W[i][j];
	}
	memset(rm, 0, sizeof(rm));    //Y集合点未被匹配 
	for (i = 1; i <= N; ++i) {
	   memset(slack, 0x3f, sizeof(slack));   //松弛量初始值很大 
	   memset(xv, 0, sizeof(xv));
	   memset(yv, 0, sizeof(yv));
	   while (!path(i)) {        //寻找增广路
	   
		//没有找到 修改顶标值 
      // d = min{A[i]+B[j] - w[i,j]} Xi在交错树中，Yi不在交错树中
        d = INF;
		  for (j = 1; j <= N; ++j)
		     if (!yv[j])      //Yj 不在交错树中 
		         d = min(d, slack[j]); 
		         
		/* 朴素实现 O(N ^ 2)
		for (k = 1; k <= N; ++k)
         if (xv[k])
            for (j = 1; j <= N; ++j)
               if (!yc[j])
                  d = min(d, A[k] + B[j] - W[k][j]);
      */ 
		         
      //交错树中 
		  for (k = 1; k <= N; ++k) {
			  if (xv[k])  A[k] -= d, xv[k] = 0;    //X顶点的顶标全都减小某个值d，
			  if (yv[k])  B[k] += d, yv[k] = 0;    //Y顶点的顶标全都增加同一个值d
			  else slack[k] -= d;     // 修改顶标后，要把所有的slack值都减去d
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
