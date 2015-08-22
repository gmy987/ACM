/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-07 15:46
*
* Filename: kmp.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int next[maxn];
int p[maxn];
void findNext()
{
    next[0]= -1;
    //j为当前位置,k为公共前后缀的长度
    int j = 0 , k = -1;
    while( j < strlen(p) )
    {
        if(k==-1||p[j]==p[k])
        {
            if(p[++j]==p[++k]) next[j] = next[k];
            else next[j] = k;
        }
        else k = next[k];
    }
}
int kmp()
{
    // t为目标串,p为模式串,i为t中的位置,j为模式串的位置
    int i = 0 , j = 0;
    while( i < strlen(t) && j < strlen(p) )
    {
        if(j==-1||t[i]==p[j]) i++,j++;
        else j = next[j];
    }
    if(j==strlen(p)) return i-j;
    else return -1;
}


int main()
{
    return 0;
}

