#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct edge
{
    int from;
    int to;
    string name;
}E[1010];//设置边 
int s;//边数 
int rd[27];//入度 
int cd[27];//初度 
int mark[1010];
int cnt;
int maxcnt;
edge edge_list[1010];
int dfs(int k) {
       
		for (int t=0;t<s;t++)
		{
            if(E[t].from==k and mark[t]==0)
            {
                mark[t]=1;
                dfs(E[t].to);
                edge_list[cnt]=E[t]; cnt++;
            }
		}
	}

int main()
{
        int cs;
        cin>>cs;
        while(cs--)
        {
                   cnt=0;
                maxcnt=0;
                cin>>s;
                string q;int lq;
                int d1,d2;
                 memset(rd,0,sizeof(rd));
                 memset(cd,0,sizeof(cd));
                 memset(mark,0,sizeof(mark));
                for(int t=0;t<s;t++)
                {
                    cin>>q;
                    E[t].name=q;
                    lq=q.length()-1;
                    d1=q[0]-'a'+1;
                    d2=q[lq]-'a'+1;
                    E[t].from=d1;
                    E[t].to=d2;
                    cd[d1]++;
                    rd[d2]++;
                }
                for(int t=0;t<s-1;t++)
                {
                        for(int t1=t+1;t1<s;t1++)
                        {
                                if(E[t].name>E[t1].name)
                                swap(E[t1],E[t]);
                                }
                        }
                int dcduo=0;
                int dcshao=0;
                int flag1=0,flag2=0;
                int key=0;int start;int end;
        for(int t=26;t>=1;t--)
        {
            if(cd[t]==rd[t]+1)
            {
                dcduo++;start=t;
                flag1++;
            }
            else if(rd[t]==cd[t]+1)
            {
                dcshao++;end=t;
                flag2++;
            }
            else if(rd[t]==cd[t])
            {
                 if(cd[t]!=0 and flag1==0)
                 start=t,end=t;
            }
            else {
                key=1;
            }
        }
        if(flag1>1 or flag2>1)
        key=1;
        else if(flag1!=flag2)
        key=1;
         if(key==1)
        {
          cout<<"***"<<endl;
          continue;
        }
        
        dfs(start);


     if(cnt!=s)
     {
         cout<<"***"<<endl;
          continue;
     }

     cout<<edge_list[cnt-1].name;
     for(int ww=cnt-2;ww>=0;ww--)
     {
        cout<<"."<< edge_list[ww].name;
     }
       cout<<endl;
        }
}