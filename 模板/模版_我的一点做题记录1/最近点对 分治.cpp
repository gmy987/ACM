#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define maxn 100005
#define mx 100000000
typedef struct{
    double x,y;
}List;
List lista[maxn];
List listb[maxn];
bool cmpx(List a,List b)
{
    return a.x < b.x;
}
bool cmpy(List a,List b)
{
    return a.y < b.y;
}

double dis(List a,List b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)))/2;
}

double cal(int s,int e)
{
    if(s == e)
        return mx;
    int mid = (s+e)/2;
    double d;
    d = min(cal(s,mid),cal(mid+1,e));
    int tail = 0;
    for(int i = mid;i >= s && lista[mid].x - lista[i].x < d;i--)
        listb[tail++] = lista[i];
    for(int i = mid+1;i <= e && lista[i].x - lista[mid].x < d;i++)
        listb[tail++] = lista[i];
    sort(listb,listb+tail,cmpy);
    for(int i = 0;i < tail-1;i++)
    {
        for(int j = i+1;j < tail && listb[j].y-listb[i].y < d;j++)
        {
            if(d > dis(listb[i],listb[j]))
                d = dis(listb[i],listb[j]);
        }
    }
    return d;
}

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i = 0;i < n;i++)
            scanf("%lf%lf",&lista[i].x,&lista[i].y);
        sort(lista,lista+n,cmpx);
        double res = cal(0,n-1);
        printf("%.2lf\n",res);
    }
}
