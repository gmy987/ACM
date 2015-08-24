/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-24 09:30
*
* Filename: c.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define maxn 50005
using namespace std;
string a[]={
	"h", "he",
	"li", "be", "b", "c", "n", "o", "f", "ne",
	"na", "mg", "al", "si", "p", "s", "cl", "ar",
	"k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
	"rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe",
	"cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
	"fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv",
	"la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
	"ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr",
};
int dp[maxn];
map<string,int> mm;
string str;
int main(){
    for(int i = 0 ; i < 114 ; i++ ) mm.insert(pair<string,int>(a[i],1));
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>str;
        memset(dp,0,sizeof(dp));
        int len = str.length(); 
        if(mm.count(str.substr(0,1))) dp[0] = 1;
        if(mm.count(str.substr(1,1))&&dp[0]) dp[1] = 1;
        if(mm.count(str.substr(0,2))) dp[1] = 1;
        for(int i = 2 ; i < len ; i++ ){
            if(dp[i-1]&&mm.count(str.substr(i,1))) dp[i] = 1;
            if(dp[i-2]&&mm.count(str.substr(i-1,2))) dp[i] = 1;
        }
        if(dp[len-1]) puts("YES");
        else puts("NO");
    }
    return 0;
}
