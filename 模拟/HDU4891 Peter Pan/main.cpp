#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
string s;
int n;
bool flag;
long long ans;
int main()
{//freopen ( "input.txt" , "r" , stdin );
    while(~scanf("%d",&n))
    {
        getchar();
        ans = 1;
        flag = false;
        int a = 1 , b = 1;
        bool p = false , p2 = false , con = false ;
        for( int i = 0 ; i < n ; i++ )
        {
            getline( cin , s );
            int len = s.length();
            for ( int j = 0 ; j < len ; j++ )
            {
                if(flag) break;
                if(p)
                    if(s[j]=='|')
                        a++;
                if(s[j]=='}')
                {
                    p = false;
                    ans *= a;
                    if( ans > 1e5 )
                    {
                        flag = true;
                        break;
                    }
                    a = 1;
                }
                if(s[j]=='{')
                    p = true;
                if(p2)
                {
                    if( s[j] == ' ' && !con )
                    {
                        con = true;
                        b++;
                    }
                    else if( s[j] == ' ' )
                        b++;
                    else if ( s[j] != ' ')
                    {
                        con = false;
                        ans *= b;
                        if( ans > 1e5 )
                        {
                            flag = true;
                            break;
                        }
                        b = 1;
                    }
                }
                if( s[j] == '$' && !p2 )
                    p2 = true;
                else if( s[j] == '$' && p2 )
                {
                    con = false;
                    p2 = false;
                    b = 1;
                }
            }
        }
        if( flag )
            printf("doge\n");
        else
            printf("%d\n",ans);
    }
}
