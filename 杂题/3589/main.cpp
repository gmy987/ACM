#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[5],b[5];
        bool c[256]={0};
        scanf("%s%s",&a,&b);
        int A = 0,B = 0;
        for( int i = 0 ; i < 4 ; i++ )
        {
            if(a[i]==b[i])
                A++;
            else
                c[a[i]]=true;
        }
        for( int i = 0 ; i < 4 ; i++ )
        {
            if(c[b[i]]==true)
                B++;
        }
        printf("%dA%dB\n",A,B);
    }
}
