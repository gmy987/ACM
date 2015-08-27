#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int n;
	int m;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		int sum = 1;
		int a;
		for( int i = 0 ; i < m ; i++){
			scanf("%d",&a);
			sum += a;
		}
		printf("%d\n",sum-m);
	}
	return 0;
}
