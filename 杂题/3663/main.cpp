#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int num,len;
    while( scanf("%d%d",&num,&len) != EOF)
    {
        int  *a = new int[num];
        for( int i = 0 ; i < num ; i++ )
            scanf("%d" , &a[i]);
        int cnt = 0;
        sort( a , a + num);
        for(int i = 0 ; i < num - 1 ; i++ )
        {
            if( a[i] + a[i+1] > len )
                break;
            for(int j = i + 1 ; j < num ; j++ )
            {
                if( a[i] + a[j] <= len )
                    cnt++;
                else
                    break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
