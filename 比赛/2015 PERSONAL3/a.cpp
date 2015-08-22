#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    while(getline(cin,a))
    {
        if(a=="#")
            break;
        int ans = 0;
        for( int i = 0 ; i < a.length() ; i++ )
        {
            if( a[i] == ' ')
                continue;
            ans+=(i+1)*(a[i]-'A'+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
