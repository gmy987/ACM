/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-31 18:44
*
* Filename: b.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

char str[30];
stack<int> st;
int n;
int main(){
    while(~scanf("%s",str)){
        scanf("%d",&n);
        int total = str[0]-'0';
        for( int i = 1 ; i < strlen(str) ; i+=2 ){
            if(str[i]=='+') total += str[i+1]-'0';
            else total *= str[i+1]-'0'; 
        }
        int sum = 0;
        for( int i = 0 ; i < strlen(str) ; i++ ){
            if(i%2==0) st.push(str[i]-'0');
            else if(str[i]=='*'){
                int tmp = st.top();
                st.pop();
                st.push(tmp*(str[i+1]-'0'));
                i++;
            }
        }
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        if(sum==n&&total==n) puts("U");
        else if(sum==n) puts("M");
        else if(total==n) puts("L");
        else puts("I");
    }
    return 0;
}
