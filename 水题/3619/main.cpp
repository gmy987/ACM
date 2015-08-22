#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
    int speed;
    int time;
    int rest;
};

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        Node *cow = new Node[k];
        for(int i = 0 ; i < k ; i++ )
            scanf("%d%d%d",&cow[i].speed,&cow[i].time,&cow[i].rest);
        for( int i = 0 ; i < k ; i++ )
        {
            int cnt = n/(cow[i].speed*cow[i].time);
            if( cnt == 0 )
            {
                if( n % cow[i].speed == 0 )
                    printf("%d\n",n/cow[i].speed);
                else
                    printf("%d\n",n/cow[i].speed+1);
                continue;
            }
            if( n% (cow[i].speed*cow[i].time)==0)
            {
                printf("%d\n",cow[i].time+(cnt-1)*(cow[i].time+cow[i].rest));
                continue;
            }
            int left = n%(cow[i].speed*cow[i].time);
            int ans = cnt*(cow[i].time+cow[i].rest);
            if( left%cow[i].speed==0)
                ans+=left/cow[i].speed;
            else
                ans+=left/cow[i].speed+1;
            printf("%d\n",ans);
        }
    }
}
