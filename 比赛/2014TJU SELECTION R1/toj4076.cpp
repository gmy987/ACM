#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;
string str;

int main()
{
    int ans = 0;
    while(getline(cin,str))
    {
        int len = str.length();
        bool flag = false;
        for( int i = 0 ; i < len ; i++ )
        {
            flag = false;
            while((isalpha(str[i])||isdigit(str[i]))&&i<len)
            {
                i++;
                flag = true;
            }
            if(flag)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
