#include <iostream>
using namespace std;
int n,sum;
int cal(int a, int n)
{
    if(n==1)
        return a;
    sum = cal(a,n/2);
    sum = (sum%2006)*(sum%2006)%2006;
    if(n%2)
        sum = (sum%2006)*(a%2006)%2006;
    return sum;
}

int main()
{
    while(cin>>n &&n)
    {
      cout<<cal(n,n)<<endl;
    }
    return 0;
}
