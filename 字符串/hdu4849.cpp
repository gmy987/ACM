/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-30 16:26
*
* Filename: hdu4849.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int cnt = 0;
    string str;
    while(cin>>str){
        for( int i = 0 ; i < str.length() ; i++ ){
            if(tolower(str[i])=='d'){
                if(tolower(str[i+1])=='o'&&tolower(str[i+2])=='g'&&tolower(str[i+3])=='e'){
                    cnt++;
                    i+=3;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
