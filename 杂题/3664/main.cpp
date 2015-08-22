#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
struct Node{
    int x;
    int y;
    int index;
};

bool cmp( Node x,Node y)
{
    return x.x>y.x;
}

bool cmp2( Node x,Node y)
{
    return x.y>y.y;
}

int main()
{
    int n,k,f,s;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        Node *cow = new Node[n];
        for( int i= 0 ; i < n ; i++ ){
            scanf("%d%d",&cow[i].x,&cow[i].y);
            cow[i].index = i+1;
        }
        sort(cow,cow+n,cmp);
        sort(cow,cow+k,cmp2);
        printf("%d\n",cow[0].index);
    }
}
