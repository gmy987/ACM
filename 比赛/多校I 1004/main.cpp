#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int time,level;
    bool flag;
}machine[100005],task[100005];
bool cmp(Node a , Node b)
{
    return a.time > b.time;
}
bool cmp2( Node a , Node b )
{
    return a.level < b.level;
}
int main()
{
    int m,n;
    while(~scanf("%d%d",&n,&m))
    {
        memset(machine , 0 , sizeof(machine));
        memset(task , 0 , sizeof(task));
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d",&machine[i].time , &machine[i].level);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d%d",&task[i].time , &task[i].level);
        sort( machine , machine + n , cmp );
        sort( task , task + m , cmp );
        int cnt = 0,max = 0,j = 0;
        for( int i = 0 ; i < m ; i++ )
        {
            int low = j, high = n-1;
            while(low<=high)
            {
                j = low + high >> 1;
                if( machine[j].time > task[i].time )
                    low = j + 1;
                else
                    high = j - 1;
            }
            for( int k = 0 ; k <= j ; k++ )
            {
                sort(machine,machine+j,cmp2);
                if( machine[k].flag )  continue;
                if( task[i].level <= machine[k].level ){
                    cnt++;
                    max+=500*task[i].time + 2*task[i].level;
                    machine[k].flag = true;
                    break;
                }
            }
        }
        printf("%d %d\n",cnt,max);
    }
}
