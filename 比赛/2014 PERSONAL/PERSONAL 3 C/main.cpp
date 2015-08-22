#include <iostream>
#include <cstdio>

using namespace std;
bool findAWay( int a[100000000][1000000000],int x1,int y1,int x2,int y2)
{
    int flag;
    if(x1==x2&&y1==y2)
        return true;
    if( a[x1+1][y1+1]==0)
        flag = findAWay(a,x1+1,y1+1,x2,y2);
    else if( a[x1+1][y1]==0)
        flag = findAWay(a,x1+1,y1,x2,y2);
    else if( a[x1][y1+1]==0)
        flag = findAWay(a,x1,y1+1,x2,y2);
    else if( a[x1-1][y1+1]==0)
        flag = findAWay(a,x1-1,y1+1,x2,y2);
    else if( a[x1-1][y1]==0)
        flag = findAWay(a,x1-1,y1,x2,y2);
    else if( a[x1-1][y1-1]==0)
        flag = findAWay(a,x1-1,y1-1,x2,y2);
    else if( a[x1][y1-1]==0)
        flag = findAWay(a,x1,y1-1,x2,y2);
    else if( a[x1+1][y1-1]==0)
        flag = findAWay(a,x1+1,y1-1,x2,y2);
    else
        return false;
}


int main()
{
    int x1,y1,x2,y2,row;
    int table[1000000000][1000000000]={0};
    while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&row)!=EOF)
    {
        int *r = new int[row];
        int *a = new int[row];
        int *b = new int[row];
        for( int i = 0 ; i < row ; i++ ){
            scanf("%d%d%d",&r[i],&a[i],&b[i]);
            for( int j = a[i] - 1 ; j < b[i] ; j++ )
                table[r[i]-1][j] = 1;
        }
        bool flag = findAWay( table , x1 , y1 , x2 , y2 );
        if(flag)
            printf("true\n");
        else
            printf("false\n");
    }
}
