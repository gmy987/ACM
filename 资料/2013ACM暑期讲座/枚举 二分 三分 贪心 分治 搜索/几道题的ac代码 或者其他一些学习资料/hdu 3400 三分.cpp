#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 0.000000001
using namespace std;

double p,q,r;
struct point
{
    double x;
    double y;
};
point a,b,c,d,th;
double dis(point a,point b)  // 两点距离
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}


double cut_cd()       // CD上做的三分
{
    double tim1,tim2;
    point midc,midd,cc=c,dd=d;
    midc.x=(cc.x+dd.x)/2;
    midd.x=(midc.x+dd.x)/2;
    midc.y=(cc.y+dd.y)/2;
    midd.y=(midc.y+dd.y)/2;
    tim1=dis(d,midc)/q+dis(midc,th)/r;
    tim2=dis(d,midd)/q+dis(midd,th)/r;
    while(fabs(tim1-tim2)>eps)
    {
        if(tim1<tim2)
        dd=midd;
        else
        cc=midc;
    midc.x=(cc.x+dd.x)/2;
    midd.x=(midc.x+dd.x)/2;
    midc.y=(cc.y+dd.y)/2;
    midd.y=(midc.y+dd.y)/2;
    tim1=dis(d,midc)/q+dis(midc,th)/r;
    tim2=dis(d,midd)/q+dis(midd,th)/r;
    }
    return tim1;
}

double cut_ab()
{

    double tim1,tim2;
    point mida,midb,aa=a,bb=b;
    mida.x=(aa.x+bb.x)/2;
    midb.x=(mida.x+bb.x)/2;
    mida.y=(aa.y+bb.y)/2;
    midb.y=(mida.y+bb.y)/2;
    th=mida;
    tim1=cut_cd()+dis(a,mida)/p;
    th=midb;
    tim2=dis(a,midb)/p+cut_cd();

    while(fabs(tim1-tim2)>eps)
    {
        if(tim1<tim2)
        bb=midb;
        else
        aa=mida;
    mida.x=(aa.x+bb.x)/2;
    midb.x=(mida.x+bb.x)/2;
    mida.y=(aa.y+bb.y)/2;
    midb.y=(mida.y+bb.y)/2;
    th=mida;
    tim1=cut_cd()+dis(a,mida)/p;
    th=midb;
    tim2=dis(a,midb)/p+cut_cd();
    }
    return tim1;
}

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf(" %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
            scanf(" %lf %lf %lf %lf",&c.x,&c.y,&d.x,&d.y);
            scanf(" %lf %lf %lf",&p,&q,&r);
            printf("  %lf  %lf  %lf  %lf\n",a.x,a.y,b.x,b.y);
            printf("  %lf  %lf  %lf  %lf\n",c.x,c.y,d.x,d.y);
            printf("%.2lf\n",cut_ab());
        }
        return 0;
    }

