#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
char str[10000005];
map<char,int> mm;

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		getchar();
		gets(str);
		mm.clear();
		int len = strlen(str);
		int ans = 0;
		int diff = 0;
		int p = -1;
		for( int i = 0 ; i < len ; i++ ){
			mm[str[i]]++;
			if(mm[str[i]]==1){
				diff++;
				if(diff>n){
					while(--mm[str[i-ans]]>0) ans--;
				}
				else ans++;
			}
			else ans++;
			p = max(p,ans);
		}
		printf("%d\n",p);
	}
	return 0;
}
