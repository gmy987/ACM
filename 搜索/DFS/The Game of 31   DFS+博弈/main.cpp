#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int b[10];
char a[100];
int len,sum;

bool dfs( int sum )
{
    int i;
    if( sum > 31 )
        return false;
    for( i = 1 ; i<=6 ; i++){
        if( b[i] != 0 && sum + i <= 31 )
        {
            b[i]--;
            if( dfs(sum+i) == false )
            {
                b[i]++;
                return true;
            }
            b[i]++;
        }
    }
    return false;
}

int main()
{
    while( cin >> a )
    {
        len = strlen(a);
        sum = 0 ;
        for( int i = 1 ; i<7 ; i++)
            b[i] = 4;
        for( int i = 0 ;i<len ; i++)
        {
            b[a[i]-'0']--;
            sum += (a[i]-'0');
        }
        cout<<a<<" ";
        if(dfs(sum))
            cout<<(len%2?"B":"A")<<endl;
        else
            cout<<(len%2?"A":"B")<<endl;

    }
}
