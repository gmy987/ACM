#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int prime[1010000];
int prime2[1010000];
int su[1001000];
int msu[1001000];
int shai()
{
    memset(prime,0,sizeof(prime));
    memset(prime2,0,sizeof(prime2));
    memset(msu,0,sizeof(msu));
    memset(su,0,sizeof(su));
    for(int t=2;t<=1000000;t++)
    {
        if(prime[t]==0)
        for(int i=2;;i++)
        {
            if(t*i>1000000)
            break;
            prime[t*i]=1;
        }
    }
    int ir=2,is=2;
    su[1]=2;msu[1]=2;
    for(int t=3;t<=1000000;t++)
    {
        if(prime[t]==0)
        su[is]=t,is+=1;
        if( prime[t]==0 && (t-1)%4==0 )
        msu[ir]=t,ir+=1;
    }
    int s=2;
    is=1;ir=1;
    prime[1]=0;
    prime2[1]=0;
    while(s<=1000000)
    {

        if(s==su[is])
        {
            prime[s]=prime[s-1]+1,is++;
            if(s==msu[ir])
            prime2[s]=prime2[s-1]+1,ir++;
            else
            prime2[s]=prime2[s-1];
        }
        else
        {
            prime[s]=prime[s-1];
            prime2[s]=prime2[s-1];
        }

    s++;
    }
}

int main()
{
    int x,y;
    shai();
    while(scanf("%d%d",&x,&y)  )
    {
        if(x==-1 && y==-1 )
        break;
        printf("%d %d " ,x,y);
        if(x<=0)x=1;
        if(y<=0)y=1;
        printf("%d %d\n",prime[y]-prime[x-1],prime2[y]-prime2[x-1]);
    }
}
