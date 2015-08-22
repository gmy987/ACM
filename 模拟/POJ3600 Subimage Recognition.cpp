#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int am,an,bm,bn;
char  map1[25][25],map2[25][25];
bool col[25];
int markb;
bool judge()
{
	int markrow = 0 , l = 0;
	bool flag;
	for( int i = 0 ; i < an&&l<bn ; i){
		flag = true;
		for( int j = 0, k = 0 ; j < am ; j++, k++)
		{
			while(col[k]) k++;
			if( map1[i][j] != map2[l][k])
			{
				flag = false;
				break;
			}
		}
		if(!flag)
			l++;
		else
		{
			i++ , l++;
			markrow++;
		}
	}
	if( markrow == an )
		return true;
	return false;

}
bool dfs( int deep , int y )
{
	if(deep == 0 )	
	{
		if(judge())
			return true;
		else return false;
	}
	if( y >= bm )
		return false;
	for( int i = y ; i < bm ; i++)
	{
		col[i] = 1;
		if(dfs(deep-1,i+1))
			return true;
		col[i] = 0;
	}
	return false;
}
int main(){
	scanf("%d%d",&an,&am);
	for( int i = 0 ; i < an ; i++)
		scanf("%s",map1[i]);
	scanf("%d%d",&bn,&bm);
	for( int i = 0 ; i < bn ; i++)
		scanf("%s",map2[i]);
	bool flag = false;
	markb = bm - am;
	memset( col , false , sizeof(col));
	if(dfs( markb , 0  ))
		flag = true;
	if( flag )
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
