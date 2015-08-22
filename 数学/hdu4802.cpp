/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-08 20:04
*
* Filename: hdu4802.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
double grade[]={4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.3,1.0,0};

int main()
{
    int n;
    int credit;
    char str[5];
    while(~scanf("%d",&n))
    {
        double sum = 0.0;
        double total = 0.0;
        int tmp;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%s",&credit,str);
            if(str[0]=='A'&&str[1]=='-') tmp = 1;
            else if(str[0]=='A') tmp = 0;
            else if(str[0]=='B'&&str[1]=='-') tmp = 4;
            else if(str[0]=='B'&&str[1]=='+') tmp = 2;
            else if(str[0]=='B') tmp = 3;
            else if(str[0]=='C'&&str[1]=='-') tmp = 7;
            else if(str[0]=='C'&&str[1]=='+') tmp = 5;
            else if(str[0]=='C') tmp = 6;
            else if(str[0]=='D'&&str[1]=='-') tmp = 9;
            else if(str[0]=='D') tmp = 8;
            else if(str[0]=='F') tmp = 10;
            else continue;
            sum += credit;
            total+=credit*grade[tmp]; 
        }
        if(sum==0.0) printf("0.00\n");
        else printf("%.2f\n",total/sum);
    }
    return 0;
}
