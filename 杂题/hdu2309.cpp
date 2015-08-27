#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,a;
	while(~scanf("%d",&n)){
		if(!n) break;
		int mmax = -1,mmin = 2000;
		int sum = 0;
		for( int i = 0 ; i < n ; i++){
			scanf("%d",&a);
			mmax = max(a,mmax);
			mmin = min(a,mmin);
			sum += a;
		}
		sum -= mmax;
		sum -= mmin;
		printf("%d\n",sum/(n-2));
	}
	return 0;
}
