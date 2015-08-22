#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 4100;

struct edge{
    int v,next,num;
}edge[3999972];

int head[3999972];
int hash(int num){
    return (num+3899971)%3999971;
}
int tot;

void add_edge(int num){
    int s=hash(num);
    for(int i=head[s];i!=-1;i=edge[i].next){
        if(edge[i].v==num){
            edge[i].num++;
            return ;
        }
    }
    edge[tot].v=num;
    edge[tot].num=1;
    edge[tot].next=head[s];
    head[s]=tot++;
}

int find(int num){
    int s=hash(num);
    for(int i=head[s];i!=-1;i=edge[i].next){
        if(edge[i].v==num){
            return edge[i].num;
        }
    }
    return 0;
}

int a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=1;i<=n;i++)
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                add_edge(a[i]+b[j]);
            }
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ans+=find(-c[i]-d[j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
