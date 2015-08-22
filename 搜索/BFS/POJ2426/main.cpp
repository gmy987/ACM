    #include<cstdio>
    #include<cstring>
    #include<queue>
    using namespace std;
    #define NN 30
    #define MM 1010

    int tsv[MM],tt[MM],fa[MM],fao[MM],vis[MM];
    int asv[MM];

    char ch[]={'0','+','-','*','%'};

    int mod(int a,int b){return (a%b+b)%b;}

    int bfs(int n,int endsta,int k,int m,int func){

        int cnt;
        if (func==0){
            cnt=0;
        }
        else if (func==1){
            cnt=1;tsv[1]=4;
        }
        else if (func==2){
            cnt=2;tsv[1]=3;tsv[2]=4;
        }
        if (n==endsta) return cnt;

        queue<int> q;
        q.push(n);
        memset(vis,0,sizeof(vis));
        vis[n]=1;
        fa[n]=-1;
        fao[n]=-1;
        int u,v;

        while(!q.empty()){
            u=q.front();
            q.pop();
            if (u==endsta) break;
            if (!vis[v=mod(u+m,k)]){
                vis[v]=1;
                q.push(v);
                fa[v]=u;
                fao[v]=1;
            }
            if (!vis[v=mod(u-m,k)]){
                vis[v]=1;
                q.push(v);
                fa[v]=u;
                fao[v]=2;
            }
            if (!vis[v=mod(u*m,k)]){
                vis[v]=1;
                q.push(v);
                fa[v]=u;
                fao[v]=3;
            }
        }
        if (!vis[endsta]) return -1;
        int p=endsta,tc=0;

        while(fa[p]!=-1){
            tt[++tc]=fao[p];
            p=fa[p];
        }
        int i;
        for(i=tc;i>=1;--i){
            tsv[++cnt]=tt[i];
        }
        return cnt;
    }


    int main(){
        int i;
        int ans,cnt;
        int n,k,m;
        while(1){
            scanf("%d%d%d",&n,&k,&m);
            if (n==0&&k==0&&m==0) break;
            ans=1000000;
            cnt=bfs(mod(n,k),mod(n+1,k),k,m,0);//normal
            if (cnt>0) {
                ans=cnt;
                for(i=1;i<=cnt;++i){
                    asv[i]=tsv[i];
                }
            }
            cnt=bfs(0,mod(n+1,k),k,m,2);//*%...
            if (cnt!=-1&&cnt<ans){
                ans=cnt;
                for(i=1;i<=cnt;++i){
                    asv[i]=tsv[i];
                }
            }
            cnt=bfs(mod(mod(n,m),k),mod(n+1,k),k,m,1);//%...
            if (cnt!=-1&&cnt<ans){
                ans=cnt;
                for(i=1;i<=cnt;++i){
                    asv[i]=tsv[i];
                }
            }
            if (ans>10000) puts("0");
            else {
                printf("%d\n",ans);
                for(i=1;i<=ans;++i){
                    printf("%c",ch[asv[i]]);
                }
                printf("\n");
            }
        }
        return 0;
    }
