#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10005
#define MAXM 80

using namespace std;
char board[MAXN][MAXM]; 
int num[MAXM];
int nxt[MAXN];
int n,m;
bool cmp( char a[] , char b[] , int len )
{
    for( int i = 0 ; i < len ; i++ )
        if( a[i] != b[i] ) return false;
    return true;
}
void findnxt( int len )
{
    memset( nxt , 0 , sizeof(nxt) );
    nxt[0] = 0;
    for( int q = 1 , k = 0 ; q < n ; q++ )
    {
        while( k > 0 && !cmp(board[q],board[k],len))
            k = nxt[k-1];
        if( cmp(board[q],board[k],len))
            k++;
        nxt[q] = k;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( num , 0 , sizeof(num) );
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%s",board[i]);
            for( int k = m-1 ; k >= 0 ; k-- )
            {
                int p,q;
                for( p = 0 , q = k ; q<m && board[i][p]==board[i][q] ; p++,q++ );
                if( q == m )
                    num[k]++;
            }
        }
        int width=0,height;
        for( int i = 1 ; i < m ; i++ )
            if( num[i] == n )
            {
                width = i;
                break;
            }
        if( width == 0 ) width = m;
        findnxt(width);
        height = n-nxt[n-1];
       printf("%d\n",width*height); 
    }
}

