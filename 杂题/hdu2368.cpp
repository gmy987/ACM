#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	int r;
	int t = 1;
	int a,b;
	while(~scanf("%d",&r)&&r){
		r+=r;
		scanf("%d%d",&a,&b);
		if(a*a+b*b<=r*r) printf("Pizza %d fits on the table.\n",t++);
		else printf("Pizza %d does not fit on the table.\n",t++);
	}
	return 0;
}
