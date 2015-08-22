#include <iostream>
using namespace std;
#define max 500005
int a[max],b[max];
long long sum;
void merge(int left,int mid,int right);
void mergesort(int left,int right)
{
     if(left<right)
     {
         int mid = (left + right)/2;
         mergesort(left,mid);
         mergesort(mid+1,right);
         merge(left,mid,right);
     }
}

void merge(int left,int mid,int right)
{
    int i=left,j=mid+1,k=left;
    while(i<=mid && j<=right)
    {
           if(a[j]<a[i])
           {
               b[k++]=a[j++];
               sum+=mid+1-i;
           }
           else
           {
               b[k++]=a[i++];
           }
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=right)
        b[k++]=a[j++];
    for(int i=left;i<=right;i++)
        a[i]=b[i];
}

int main()
{
    int n;
    while(cin>>n,n)
    {
        sum=0;
        for(int i=0;i<n;i++)
        cin>>a[i];
        mergesort(0,n-1);
        cout<<sum<<endl;
    }
    return 0;
}
