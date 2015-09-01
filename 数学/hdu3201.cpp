/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-09-01 09:06
*
* Filename: hdu3201.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main(){
    int l;
    while(scanf("%d",&l)&&l){
        printf("%.2lf\n",l*l/(2*PI));
    }
    return 0;
}
