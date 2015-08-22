#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int result[10],vis[10],n,num[10],len;
char read[10];
int main()
{
    while(~scanf("%d%s",&n,read))
    {
        if(n==0&&read[0]=='0')
            break;
        memset(result , 0 , sizeof(result));
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        len = strlen(read);
        int sum = 0;
        for( int i = 0 ; i < len ; i++ )
        {
            num[i] = read[i]-'0';
            sum+=num[i];
        }
        if(sum>n)
        {
            printf("error\n");
            continue;
        }

    }
}
