/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-25 18:39
*
* Filename: hdu2861.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
string a[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
string table="QWERTYUIOPASDFGHJKLZXCVBNM";
map<char,char> mm;
char str[1005];
char ans[1005];

int main(){
    for( int i = 0 ; i < 26 ; i++ ) mm.insert(pair<char,char>(table[i],'A'+i));
    while(~scanf("%s",str)){
        int len = strlen(str);
        int cnt = 0;
        for( int i = 0 ; i < len ; i+=2 ){
            ans[cnt++] = mm[a[str[i]-'0'][str[i+1]-'0'-1]];
        }

        bool flag = false;
        if(cnt&1){ printf("%c",ans[cnt/2]) ; flag = true; }

        for( int i = cnt-1 , j = cnt/2-1 ; j >= 0 ; i--,j-- ){
            printf("%c%c",ans[i],ans[j]);
        }
        puts("");
    }
    return 0;
}
