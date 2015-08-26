/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-22 09:04
*
* Filename: 252B.CPP
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100005

using namespace std;
struct Node{
    int val,id;
}node[maxn];
bool cmp(Node a,Node b){
    return a.val==b.val?a.id<b.id:a.val<b.val;
}
struct Ans{
    int val,d;
}ans[maxn];
int cnt;

int main(){
    int n;
    while(~scanf("%d",&n)){
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&node[i].val);
            node[i].id = i;
        }
        sort(node,node+n,cmp);
        cnt = 0;
        bool flag = true;
        int tmpd;
        int i;
        for( i = 0 ; i < n-1 ; i++ ){
            tmpd = -1;
            flag = true;
            while(node[i].val==node[i+1].val){
                if(tmpd==-1) tmpd = node[i+1].id-node[i].id;
                else if(node[i+1].id-node[i].id!=tmpd) flag = false;
                i++;
            }
            if(tmpd==-1){
                ans[cnt].val = node[i].val;
                ans[cnt++].d = 0;
            }
            else if(flag){
                ans[cnt].val = node[i].val;
                ans[cnt++].d = tmpd;
            }
        }
        if( i == n-1 ){
            ans[cnt].val = node[i].val;
            ans[cnt++].d = 0;
        }
        printf("%d\n",cnt);
        for( int i = 0 ; i < cnt ; i++ ){
            printf("%d %d\n",ans[i].val,ans[i].d);
        }
    }
    return 0;
}
