#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 16000000
using namespace std;
long a,c,m,r0;
int vis[INF],num[INF];
int main()
{
    while(~scanf("%ld%ld%ld%ld",&a,&c,&m,&r0))
    {
        //cout<<a<<" "<<c<<" "<<m<<" "<<r0<<endl;
        long *vis = new long[m];
        long *num = new long[m];
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        long temp = r0,i = 1;
        num[0] = r0;
        vis[r0] = 1;
        while(true)
        {
            temp = (a*temp+c)%m;
            if(!vis[temp]){
                vis[temp] = 1;
                num[i++] = temp;
            }
            else
                break;
        }
        sort(num,num+i);
        //for( int j = 0 ; j < i ; j++ )
            //cout<< num[j]<<endl;
        long m = 0,t;
        for( long j = 1 ; j < i ; j++ )
        {
            t = num[j] - num[j-1];
            m = max(t,m);
        }
        printf("%ld\n",m);
        //delete[]vis;
        //delete[]num;
    }
}
