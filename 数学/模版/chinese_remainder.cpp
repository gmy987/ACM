#include <iostream>
using namespace std;

int Extended_Euclid(int a,int b,int &x,int &y)    //扩展欧几里得算法
{
	int d;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	d=Extended_Euclid(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

int Chinese_Remainder(int a[],int w[],int len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数
{
	int i,d,x,y,m,n,ret;
	ret=0;
	n=1;
	for (i=0;i<len;i++)
		n*=w[i];
	for (i=0;i<len;i++)
	{
		m=n/w[i];
		d=Extended_Euclid(w[i],m,x,y);
		ret=(ret+y*m*a[i])%n;
	}
	return (n+ret%n)%n;
}


int main()
{
	int n,i;
	int w[15],b[15];
	while (scanf("%d",&n),n)   
	{
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&w[i],&b[i]);
		}
		printf("%d/n",Chinese_Remainder(b,w,n));
	}
	return 0;
}
