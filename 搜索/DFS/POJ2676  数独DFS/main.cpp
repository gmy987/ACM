#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int map[15][15];
bool row[15][15],col[15][15],sq[15][15],isFind;

void print()
{
    for( int i = 0 ; i < 9 ; i++ ){
        for( int j = 0 ; j < 9 ; j++ )
            printf("%d",map[i][j]);
        printf("\n");
    }
}

bool judge( int x , int y,int a)
{
    return (!row[x][a])&&(!col[y][a])&&(!sq[(x/3)*3+y/3][a]);
}

void dfs(int pos)
{
    if(isFind)
        return;
    if(pos == 9*9)
    {
        isFind = true;
        print();
        return;
    }
    int x = pos/9;
    int y = pos%9;
    if( map[x][y] )
    {
        dfs(pos+1);
        return;
    }
    for( int i = 1 ; i <= 9 ; i++ )
    {
        if( judge(x,y,i) )
        {
            row[x][i] = true;
            col[y][i] = true;
            sq[(x/3)*3+y/3][i] = true;
            map[x][y] = i;
            dfs(pos+1);
            if( isFind )
                return;
            map[x][y] = 0;
            row[x][i] = 0;
            col[y][i] = 0;
            sq[(x/3)*3+y/3][i] = false;
        }
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[15];
        memset(map,0,sizeof(map));
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        memset(sq,0,sizeof(sq));
        for( int i = 0 ; i < 9 ; i++ )
        {
            scanf("%s",&a);
            for( int j = 0 ; j < 9 ; j++ )
            {
                map[i][j] = a[j]-'0';
                if( map[i][j]!=0 )
                {
                    row[i][map[i][j]] = true;
                    col[j][map[i][j]] = true;
                    sq[(i/3)*3+j/3][map[i][j]] = true;
                }
            }
        }
        isFind = false;

        dfs(0);
    }
}
