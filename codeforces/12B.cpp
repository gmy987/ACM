/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 12:35
*
* Filename: 12B.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
char a[100],b[100];
int cnta[15],cntb[15];
int main(){
    while(~scanf("%s",a)){
        scanf("%s",b);
        sort(a,a+strlen(a));
        int cnt = strlen(a);
        int pos = 0;
        while(a[pos]=='0'&&pos<cnt) pos++;
        if(pos<cnt) swap(a[0],a[pos]);
        if(strcmp(b,a)) puts("WRONG_ANSWER");
        else puts("OK");
    }
    return 0;
}
