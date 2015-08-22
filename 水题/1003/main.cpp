#include <iostream>
using namespace std;
int main()
{
	int n;
	double c,sum=0.00;
	cin>>c;
	while(c!=0.00)
	{
		for(n=1;sum<=c;n++)
		{
			sum+=1.0/(n+1);
		}
		cout<<n-1<<" card(s)"<<endl;
		cin>>c;
		sum=0;
	}
	return 0;
}
