#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int fib[50];
void init(){
	fib[1] = 1;
	fib[2] = 2;
	for( int i = 3 ; i < 30 ; i++ ){
		fib[i] = fib[i-1]+fib[i-2];
	}
}
int cnt[30];
void find(int x){
	memset(cnt,0,sizeof(cnt));
	for( int i = 29 ; i >= 1 ; i--){
		if(fib[i]<=x) cnt[i] = 1,x-=fib[i];
	}
}

int main(){
	init();
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		find(n);
		int ans = 0;
		for( int i = 2 ; i < 30 ; i++ ) ans+=cnt[i]*fib[i-1];
		printf("%d\n",ans);
	}
	return 0;
}
