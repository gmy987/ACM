/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-24 10:23
*
* Filename: UVAL6262.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double dist( double x , double y ){
    return sqrt(x*x+y*y);
}

int main(){
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        int ans = 0;
        scanf("%d",&n);
        double x,y;
        int tmp;
        double dis;
        for( int i = 0 ; i < n ; i++ ){
            scanf("%lf%lf",&x,&y);
            dis = dist(x,y);
            tmp = dis/20;
            if(tmp>10) continue;
            if(tmp*20.0 == dis && tmp != 0) ans+=10-tmp+1;
            else ans += 10-tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
