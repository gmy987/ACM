#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1005;
const int MOD = 999983;
int px[N],py[N];
vector<int> hashTable[MOD];
long long cnt;
int n;


void resetHash()
{
    for( int i = 0 ; i < MOD ; i++ )
        hashTable[i].clear();
    cnt = 0;
}

bool checkHash( int x , int y , int i)
{
    if( x == px[i] && y==py[i] )
        return true;
    else
        return false;
}

int main()
{
    while( scanf( "%d" , &n ) != EOF && n!=0 )
    {
        resetHash();
        for( int i = 0 ; i < n ; i++){
            scanf("%d %d",&px[i],&py[i]);
            int key = (px[i] * px[i] + py[i] * py[i])%MOD;
            hashTable[key].push_back(i);
        }
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = i+1 ; j < n ; j++)
            {
                int x1 = px[i] - ( py[i] - py[j] );
                int y1 = py[i] + ( px[i] - px[j] );
                int x2 = px[j] - ( py[i] - py[j] );
                int y2 = py[j] + ( px[i] - px[j] );
                int key1 = ( x1 * x1 + y1 * y1 )%MOD;
                int key2 = ( x2 * x2 + y2 * y2 )%MOD;
                for( int k = 0 ; k < hashTable[key1].size() ; k++ )
                {
                    if( checkHash( x1 , y1 , hashTable[key1][k] ))
                    {
                        for( int m = 0 ; m < hashTable[key2].size() ; m++ )
                        {
                            if( checkHash( x2 , y2 , hashTable[key2][m]))
                                cnt++;
                        }
                    }
                }

            }
        }
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = i+1 ; j < n ; j++)
            {
                int x1 = px[i] + ( py[i] - py[j] );
                int y1 = py[i] - ( px[i] - px[j] );
                int x2 = px[j] + ( py[i] - py[j] );
                int y2 = py[j] - ( px[i] - px[j] );
                int key = (x1 * x1 + x2 * x2)%MOD;
                int key1 = ( x1 * x1 + y1 * y1 )%MOD;
                int key2 = ( x2 * x2 + y2 * y2 )%MOD;
                for( int k = 0 ; k < hashTable[key1].size() ; k++ )
                {
                    if( checkHash( x1 , y1 , hashTable[key1][k] ))
                    {
                        for( int m = 0 ; m < hashTable[key2].size() ; m++ )
                        {
                            if( checkHash( x2 , y2 , hashTable[key2][m]))
                                cnt++;
                        }
                    }
                }
            }
        }
        cnt/=4;
        printf("%lld\n",cnt);

    }
    return 0;
}

