#include <cstdio>
#include <iostream>
#include <cstring>
#define maxn 105

using namespace std;
long long dp[maxn][maxn];
int a[maxn];

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		if(!n&&!k) break;
		memset(dp,0,sizeof(dp));
		for( int i = 0 ; i < n ; i++ ){
			scanf("%d",&a[i]);
			dp[i][1] = 1;
		}
		for( int i = 1 ; i < n ; i++ )
			for( int j = 0 ; j < i ; j++){
				if(a[i]>a[j]){
					for( int l = 2 ; l <= k ; l++ ) dp[i][l] += dp[j][l-1];
				}
			}
		long long ans = 0;
		for( int i = 0 ; i < n ; i++ ) ans += dp[i][k];
		printf("%I64d\n",ans);
	}
	return 0;
}
