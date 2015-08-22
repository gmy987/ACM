#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a,b,c,num[25][25][25];
int w( int a , int b , int c )
{
    if(a<=0||b<=0||c<=0)
        return 1;
    else if( a > 20 || b > 20 || c >20 )
        return num[20][20][20] = w(20,20,20);
    else if( num[a][b][c] != -1)
        return num[a][b][c];
    else if( a < b && b < c )
        return num[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else
        return num[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) ;

}

int main()
{
    memset(num,-1,sizeof(num));
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if( a==-1 && b==-1 && c==-1 ) break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
    return 0;
}
