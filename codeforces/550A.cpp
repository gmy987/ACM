/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 18:41
*
* Filename: 550A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v1,v2;

char str[100005];
int main(){
    scanf("%s",str);
    for( int i = 0 ; i < strlen(str)-1 ; i++ ){
        if(str[i]=='A'&&str[i+1]=='B') v1.push_back(i);
        if(str[i]=='B'&&str[i+1]=='A') v2.push_back(i);
    }
    bool flag = false;
    for( int i = 0 ; i < v1.size(); i++ ){
       for( int j = 0 ; j < v2.size() ; j++ )
          if(abs(v1[i]-v2[j])>=2) {
              flag = true;
              break;
          } 
       if(flag) break;
    }
    printf(flag?"YES":"NO");puts("");
    return 0;
}
