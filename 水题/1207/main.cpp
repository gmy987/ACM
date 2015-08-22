#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b,cnt,m ;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        m = 0;
        int t1,t2;
        if( a <= b )
        {
            t1 = a;
            t2 = b;
        }
        else
        {
            t1 = b;
            t2 = a;
        }
        for(int i = t1 ; i <= t2 ; i++ )
        {
            cnt = 0;
            int temp = i;
            while(temp!=1)
            {
                cnt++;
                if(temp%2==1)
                    temp = 3*temp+1;
                else
                    temp/=2;
            }
            if(temp==1)
                cnt++;
            if(m<cnt)
                m = cnt;
        }
        printf("%d %d %d\n",a,b,m);
    }
    return 0;
}
