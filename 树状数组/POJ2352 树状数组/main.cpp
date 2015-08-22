#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int x[32005];
int level[15005];
int n;
int lowbit( int i )
{
    return -i&i;
}
void set(int i,int a)
{
    if( i > 32005 )
        return;
    x[i]+=a;
    set(i+lowbit(i),a);
}

int get(int i)
{
    if(!i)
        return 0;
    return get(i-lowbit(i))+x[i];
}

int main()
{
    int i,x,y;
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ )
    {
        scanf("%d%d",&x,&y);
        x++;
        level[get(x)]++;
        set(x,1);
    }
    for( int i = 0 ; i < n ; i++ )
        printf("%d\n",level[i]);
    return 0;
}
