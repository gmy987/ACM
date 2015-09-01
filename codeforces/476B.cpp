/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-09-01 19:47
*
* Filename: 476B.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 15

using namespace std;
char s1[maxn];
char s2[maxn];
int step;
int total,cnt;
int n1,n2;
void dfs( int s , int pos ){
    if(pos==n2){
        if(s==step) cnt++;
        total++;
        return;
    }
    if(s2[pos]=='+') dfs(s+1,pos+1);
    else if(s2[pos]=='-') dfs(s-1,pos+1);
    else{
        dfs(s+1,pos+1);
        dfs(s-1,pos+1);
    }
}
int main(){
    while(~scanf("%s",s1)){
        scanf("%s",s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        step  = cnt = total = 0;
        for( int i = 0 ; i < n1 ; i++ ){
            if(s1[i]=='+') step++;
            else step--;
        }
        dfs(0,0);
        printf("%.10f\n",((double)cnt)/total);
    }
    return 0;
}
