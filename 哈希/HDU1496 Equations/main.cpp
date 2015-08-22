#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c,d;
int f1[1000005],f2[1000005];//f1保存得数为正的，f2保存得数为负的
int main()
{
    while(~scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0))
        {
            printf("0\n");
            continue;
        }
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        memset(f1 , 0 , sizeof(f1));
        memset(f2 , 0 , sizeof(f2));
        int ans = 0 ,k;
        for( int i = 1 ; i <= 100 ; i++ )
            for( int j = 1 ; j <= 100 ; j++ )
            {
                k = a * i * i + b * j * j;
                if( k >= 0 )
                    f1[k]++;
                else
                    f2[-k]++;
            }
        for( int i = 1 ; i <= 100 ; i++ )
            for( int j = 1 ; j <= 100 ; j++ )
            {
                k = c * i * i + d * j * j;
                if( k > 0 )
                    ans+=f2[k];
                else
                    ans+=f1[-k];
            }
        //cout<<ans<<endl;
        printf("%d\n",ans*16);
    }
}
