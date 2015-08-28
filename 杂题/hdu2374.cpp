#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 100

using namespace std;
int a[maxn];

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		for( int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
		long long ans = 0;
		for( int i = n-1 ; i >= 0 ; i-- ){
			ans *= 2;
			ans += a[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
