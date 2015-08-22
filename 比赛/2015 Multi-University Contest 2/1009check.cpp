#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double dp[10000];
int check[10000];
int main(){
    int n;
    int a,b;
    char x;
    //freopen("1009x.out","r",stdin);
    while(cin>>n){
        memset(check,0,sizeof(check));
        memset(dp,0,sizeof(check));
        for(int i = 1;i <= n; i++)
            dp[i] = n;
        cout<<n<<"  case:"<<endl;

        for(int i = 1; i < n; i++){
            cin>>a;
            if(a == -1){
                cout<<"ans: "<<-1<<endl;
                goto xx;
            }
                cin>>x>>b;
            check[a]++,check[b]++;
            if(x == '+')
                dp[n+i] = dp[a] + dp[b];
            else if(x == '-')
                dp[n+i] = dp[a] - dp[b];
            else if(x == '*')
                dp[n+i] = dp[a] * dp[b];
            else if(x == '/')
                dp[n+i] = dp[a] / dp[b];
            else
                cout<<"wrong"<<endl;
        }
        for(int i = 1;i < n * 2 -1; i++)
            if(check[i] != 1)
                cout<<i<<" didn't occur"<<endl;
        cout<<dp[n+n-1]<<endl;
        xx:;
    }
    return 0;
}
