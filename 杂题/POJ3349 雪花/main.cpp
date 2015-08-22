#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const long long MOD = 999983;
const int MAX_SIZE = 100009;
vector<int> h[MOD];
int snow[MAX_SIZE][6];

bool isSame( int a , int b )
{
    for( int i = 0 ; i < 6 ; i++ )
    {
        if( (snow[a][0]==snow[b][i]&&
            snow[a][1]==snow[b][(i+1)%6]&&
            snow[a][2]==snow[b][(i+2)%6]&&
            snow[a][3]==snow[b][(i+3)%6]&&
            snow[a][4]==snow[b][(i+4)%6]&&
            snow[a][5]==snow[b][(i+5)%6] )||
            (snow[a][0]==snow[b][i]&&
            snow[a][1]==snow[b][(i+5)%6]&&
            snow[a][2]==snow[b][(i+4)%6]&&
            snow[a][3]==snow[b][(i+3)%6]&&
            snow[a][4]==snow[b][(i+2)%6]&&
            snow[a][5]==snow[b][(i+1)%6]))
            return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d" , &n );
    int i , j;
    for( i = 0 ; i < n ; i++ )
    {
        for( j = 0 ; j < 6 ; j++ )
            scanf("%d",&snow[i][j]);
    }

    for( i = 0 ; i < n ; i++ )
    {
        int key,sum = 0;
        for( j = 0 ; j < 6 ; j++ )
            sum+=snow[i][j];
        key = sum%MOD;
        for( j = 0 ; j < h[key].size() ; j++ )
        {
            if( isSame ( h[key][j] , i )){
                printf("Twin snowflakes found.\n");
                return 0;
            }
        }
        h[key].push_back(i);
    }
    printf( "No two snowflakes are alike.\n");
    return 0 ;
}

