#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string table[26]={"4","|3","(","|)","3","|=","6","#","|","_|","|<","|_","|\\/|","|\\|",
    "0","|0","(,)","|?","5","7","|_|","\\/","\\/\\/","><","-/","2"};
vector<string> v;
int dp[10005];
int main()
{
    v.clear();
    for( int i = 0 ; i < 26 ; i++ )
        v.push_back(table[i]);
    char str[105];
    while(scanf("%s",str))
    {
        if(!strcmp(str,"end"))
            break;
        int len = strlen(str);
        string sentence="";
        for( int i = 0 ; i < len ; i++ )
            sentence+=table[str[i]-'A'];
        len = sentence.length();
        memset( dp , 0,sizeof(dp));
        dp[0] = 1;
        for( int i = 1 ; i <= len ; i++ )
        {
            for( int j = max( i - 7 , 0 ) ; j < i ; j++ )
                if(find(v.begin(),v.end(),sentence.substr(j,i-j))!=v.end())
                {

                    dp[i] += dp[j];
                }
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}
