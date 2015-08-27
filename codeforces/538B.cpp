#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int ans[1000005][10];
int number[19];

int main(){
	int n;
	while(~scanf("%d",&n)){
		int cc = 0;
		int cnt = 0;
		while(n){
			number[cnt++] = n%10;
			n/=10;
		}
		bool flag = true;
		while(flag){
			flag = false;
			for( int i = cnt-1,j=0 ; i >= 0 ; i--,j++){
				if(number[i]>0){ ans[cc][j] = 1;number[i]--;flag=true;}
				else ans[cc][j] = 0;
			}
			if(flag) cc++;
		}
		printf("%d\n",cc);
		int i = 0;
		while(ans[0][i]==0) i++;
		for( i ; i < cnt ; i++ ) printf("%d",ans[0][i]);
		for( int i = 1 ; i < cc ; i++ ){
			int j = 0;
			printf(" ");
			while(ans[i][j]==0) j++;
			for( j ; j < cnt ; j++ ) printf("%d",ans[i][j]);
		}
		puts("");
	}
	return 0;
}
