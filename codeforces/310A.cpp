#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    string str;
    while(~scanf("%d",&n))
    {
        int cnt = 0;
        cin>>str;
        for( int i = 0 ; i < n ; i++ )
        {
            if( str[i] == '0' )
                cnt++;
        }
        cnt = min(cnt,n-cnt);
        printf("%d\n",n-cnt*2);
    }
    return 0;
}
