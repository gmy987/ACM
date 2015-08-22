#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,q,left,right,pos,dir;
    bool flag;
    char a[1000],b[1000];
    while(scanf("%d%d%s",&n,&q,&a)!=EOF)
    {
        for( int i = 0 ; i < q ; i++ )
        {
            memcpy( b , a , sizeof(a));
            int num[10] = {0};
            scanf("%d%d",&left,&right);
            left--,right--;
            flag = false;
            dir = 1;
            pos = 0;
            for( int i = left ; i<=right&&i>=left ; i+=dir)
            {
                if( b[i]>='0'&&b[i]<='9')
                {
                    num[b[i]-'0']++;
                    if( b[i] == '0' )
                        b[i] = 0;
                    else
                        b[i]--;
                    flag = false;
                }
                else if( b[i]=='>')
                {
                    dir = 1;
                    if(flag)
                        b[pos] = 0;
                    flag = true;
                    pos = i;
                }
                else if( b[i] == '<' )
                {
                    dir = -1;
                    if(flag)
                        b[pos] = 0;
                    flag = true;
                    pos = i;
                }
            }
            for( int i = 0 ; i < 10 ; i++ )
            {
                if( i < 9)
                    printf("%d " , num[i]);
                else
                    printf("%d\n", num[i]);
            }
        }
    }
    return 0;
}
