#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int am,an,bm,bn;
int  map1[25][25],map2[25][25];
char board[25][25],board2[25][25];
bool row[25],col[25];
int marka,markb;
bool judge()
{
	for( int i = 1 , k = 1 ; i <= an ; i++ , k++)
		for( int j = 1 , l = 1 ; j <= am ; j++ , l++)
		{
			if(col[l]) l++;
			if(row[k])  k++;
			if( map1[i][j]!=map2[k][l])
				return false;
		}
	return true;
}
bool dfs( int x , int y , int a , int b )
{
	if( a > marka || b > markb )
		return false;
	if(a = marka , b = markb){
		if(judge())
			return true;
		else
			return false;
	}
	for( int i = x ; i <= an ; i++)
		for( int j = y ; j <= bn ; j++)
		{
			row[i] = 1;
			if(dfs( i+1 , j , a+1 , b ))
				return true;
			row[i] = 0;
			col[j] = 1;
			if(dfs( i , j+1 , a , b+1 ))
				return true;
			col[j] = 0;
			row[i] = 1;
			col[j] = 1;
			if(dfs( i+1 , j+1 , a+1 , b+1))
				return true;
			row[i] = 0;
			col[j] = 0;

		}
	return false;
}
int main(){
	scanf("%d%d",&an,&am);

	for( int i = 0 ; i < an ; i++)
		scanf("%s",board[i]);
	scanf("%d%d",&bn,&bm);
	for( int i = 0 ; i < bn ; i++)
		scanf("%s",board2[i]);
	for( int i = 0 ; i < an ; i++ )
		for( int j = 0 ; j < am ; j++)
			map1[i+1][j+1] = board[i][j]-'0';
	for( int i = 0 ; i < bn ; i++)
		for( int j = 0 ; j < bm ; j++)
			map2[i+1][j+1] = board2[i][j]-'0';
	bool flag = false;
	marka = bn - an , markb = bm - am;
	memset( row , false , sizeof(row));
	memset( col , false , sizeof(col));
	if(dfs( 1 , 1 , 0 , 0 ))
		flag = true;
	if( flag )
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
