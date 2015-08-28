#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 100

using namespace std;
struct Mat{
	int r;
	int mat[maxn][maxn];
	void init(){
		memset(mat,0,sizeof(mat));
	}
};
Mat mul( Mat &a,Mat &b){
	Mat c;
	c.init();
	c.r = a.r;
	for( int i = 0 ; i < a.r ; i++ )
		for( int k = 0 ; k < a.r ; k++ )
			if(a.mat[i][k])
				for( int j = 0 ; j < a.r ; j++ )
					c.mat[i][j] += a.mat[i][k]*b.mat[k][j];
	return c;
}
Mat fast_mul( Mat &a , int n ){
	Mat ans;
	ans.r = a.r;
	ans.init();
	for( int i = 0 ; i < a.r ; i++ ) ans.mat[i][i] = 1;
	while(n){
		if(n&1) ans = mul(ans,a);
		a = mul(a,a);
		n>>=1;
	}
	return ans;
}
char str[maxn];
char s[maxn];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(!n&&!m) break;
		Mat a;
		int b;
		a.r = n;
		a.init();
		for( int i = 0 ; i < n ; i++ ){
			scanf("%d",&b);
			a.mat[i][b-1] = 1;
		}
		a = fast_mul(a,m);
		getchar();
		gets(str);
		for( int i = 0 ; i < a.r ; i++ )
			for( int j = 0 ; j < a.r ; j++ )
				if(a.mat[i][j]) s[j] = str[i];
		for( int i = 0 ; i < n ; i++ ) printf("%c",s[i]);
		puts("");
	}
	return 0;
}
