#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n<=3)
            printf("-1\n");
        else if(n==4)
            printf("1 * 2\n5 + 3\n6 + 4\n");
        else if(n==5)
            printf("1 * 2\n6 * 3\n7 - 4\n8 / 5\n");
        else if(n==6)
            printf("1 + 2\n7 + 3\n8 + 4\n9 + 5\n10 - 6\n");
        else if(n==7)
            printf("1 + 2\n8 + 3\n9 / 4\n5 + 6\n11 + 7\n10 + 12\n");
        else if(n==8)
            printf("1 + 2\n9 + 3\n4 + 5\n11 - 6\n12 - 7\n13 / 8\n10 + 14\n");
        else if(n==9)
            printf("1 + 2\n10 + 3\n4 + 5\n12 + 6\n13 / 7\n11 - 14\n15 + 8\n16 - 9\n");
        else if(n==10)
            printf("1 + 2\n4 + 3\n12 + 5\n13 + 6\n14 / 7\n11 + 15\n8 - 9\n17 / 10\n16 + 18\n");
        else if(n==11)
            printf("1 + 2\n3 + 4\n13 / 5\n12 + 14\n15 + 6\n16 - 7\n17 + 8\n18 - 9\n19 + 10\n20 - 11\n");
        else if(n==13)
            printf("1 + 2\n14 + 3\n4 + 5\n16 + 6\n17 + 7\n18 + 8\n19 + 9\n20 + 10\n21 + 11\n22 * 15\n23 / 12\n24 / 13\n");
        else
        {
            printf("1 + 2\n%d + 3\n%d + 4\n",n+1,n+2);
            printf("5 + 6\n%d + 7\n%d + 8\n%d + 9\n%d + 10\n",n+4,n+5,n+6,n+7);
            printf("%d / 11\n%d / 12\n%d * %d\n",n+3,n+8,n+9,n+10);
            int tmp = n-12;
            if( tmp&1 )
            {
                tmp--;
                if(tmp==2)
                    printf("13 - 14\n27 / 15\n28 + 26\n");
                else if(tmp==4)
                {
                    printf("13 + 14\n29 - 15\n30 - 16\n31 / 17\n32 + 28\n");
                }
                else
                {
                    printf("13 + 14\n");
                    printf("%d - %d\n%d - %d\n",n+12,15,n+13,16);
                    for( int i = 1 ; i<= tmp-4 ; i+=2 )
                        printf("%d + %d\n%d - %d\n",n+13+i,16+i,n+14+i,17+i);
                    printf("%d / %d\n",2*n-3,12+tmp+1);
                    printf("%d + %d\n",n+11,2*n-2);
                }
            }
            else 
            {
                for( int i = 1 ; i <= tmp ; i+=2 )
                    printf("%d + %d\n%d - %d\n",n+10+i,12+i,n+11+i,13+i);
            }
        }
            
    }
    return 0;
}
