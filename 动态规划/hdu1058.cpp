#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int dp[5900];
int a[4];
int judge( int n )
{
    n%=100;
    if( n/10 == 1 )
        return 4;
    else return n%10;
}
int main()
{
    int n;
    int tmp;
    dp[1]=1;
    int t=1,j=1,k=1,l=1;
    for( int i = 2 ; i <= 5842 ; i++ )
    {
        dp[i]=min(2*dp[t],min(3*dp[j],min(5*dp[k],7*dp[l])));
        if(dp[i]==2*dp[t]) t++;
        if(dp[i]==3*dp[j]) j++;
        if(dp[i]==5*dp[k]) k++;
        if(dp[i]==7*dp[l]) l++;
    }
    while(~scanf("%d",&n)&&n)
    {
        int suffix = judge(n);
        printf("The %d",n);
        if( suffix == 1 )
            printf("st");
        else if( suffix == 2 )
            printf("nd");
        else if( suffix==3 )
            printf("rd");
        else printf("th");
        printf(" humble number is %d.\n",dp[n]);
    }
    return 0;
}
