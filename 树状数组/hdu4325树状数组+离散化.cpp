#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define maxn 100005

using namespace std;
int n,m;
int sum[maxn];
int h[maxn];
struct Node{
	int l,r;
}node[maxn];
int cnt,len;
bool cmp( Node a , Node b){
	return a.l==b.l?a.r<b.r:a.l<b.l;
}
int lowbit( int x ){
	return x&-x;
}
void update( int x , int c  ){
	while(x<=len){
		sum[x]+=c;
		x+=lowbit(x);
	}
}
int query( int x ){
	int ans=0;
	while(x>0){
		ans+=sum[x];
		x-=lowbit(x);
	}
	return ans;
}
int q[maxn];
int main(){
	int t,tmp;
	int cas = 1;
	scanf("%d",&t);
	while(t--){
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&m);
		int cnt = 0;
		for( int i = 0 ; i < n ; i++ ){
			scanf("%d%d",&node[i].l,&node[i].r);
			h[cnt++] = node[i].l;
			h[cnt++] = node[i].r;
		}
		for( int i = 0 ; i < m ; i++ ){
			scanf("%d",&q[i]);
			h[cnt++] = q[i];
		}
		sort(h,h+cnt);
		len = unique(h,h+cnt)-h;
		int x,y;
		for( int i = 0 ; i < n ; i++ ){
			x = lower_bound(h,h+len,node[i].l)-h+1;
			y = lower_bound(h,h+len,node[i].r)-h+1;
			update(x,1);
			update(y+1,-1);
		}
		printf("Case #%d:\n",cas++);
		for( int i = 0 ; i < m ; i++ ){
			x = lower_bound(h,h+len,q[i])-h+1;
			printf("%d\n",query(x));
		}
	}
	return 0;
}
