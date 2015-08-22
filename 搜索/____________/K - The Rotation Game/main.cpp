#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int map[25],countArry[25];
char outPath[100];
//char op[] = {'A','B','C','D','E','F','G','H'};
int deep,centerNum;

//判断是否到达了目标局面
bool judge( const int map[] )
{
    int tmp = map[7];
    return tmp == map[8] && tmp == map[9] && tmp == map[12] &&
           tmp == map[13] && tmp == map[16] && tmp == map[17] && tmp == map[18];
}

//统计局面的中心区域含有相同数字的最大数量
int findMax( const int map[] )
{
    memset( countArry , 0 , sizeof(countArry) );
    countArry[map[7]]++; countArry[map[8]]++; countArry[map[9]]++;
    countArry[map[12]]++; countArry[map[13]]++; countArry[map[16]]++;
    countArry[map[17]]++; countArry[map[18]]++;
    return max ( countArry[3] , max( countArry[2] , countArry[1] ) );
}

void change ( int state[] , int a1 , int a2 , int a3 , int a4 , int a5 , int a6 , int a7 )
{
    int tmp = state[a1];
    state[a1] = state[a2]; state[a2] = state[a3]; state[a3] = state[a4];
    state[a4] = state[a5]; state[a5] = state[a6]; state[a6] = state[a7];
    state[a7] = tmp;
}
bool dfs ( int state[] , int dv , int pre )
{
    //当前局面的估价函数值+当前的搜索深度 > 预定义的最大搜索深度
    if( 8 - findMax( state ) + dv > deep )
        return false;

    //超过了当前的搜索深度
    if( dv >= deep )
        return false;


    int tmp[25];
    for( int i = 1 ; i <= 8 ; i++ )
    {
        //剪枝：前后连续的相反方向的两次旋转是没有意义的
        if(( i == 1 && pre == 6 ) || ( i == 6 && pre == 1 )) continue;
        if(( i == 2 && pre == 5 ) || ( i == 5 && pre == 2 )) continue;
        if(( i == 3 && pre == 8 ) || ( i == 8 && pre == 3 )) continue;
        if(( i == 4 && pre == 7 ) || ( i == 7 && pre == 4 )) continue;

        //用一个tmp数组保存改变后的状态
        for( int i = 1 ; i <= 24 ; i++ )
            tmp[i] = state[i];

        switch(i)
        {
            //记录搜索路径
            case 1 : outPath[dv] = 'A' ; change(tmp,1,3,7,12,16,21,23);     break;
            case 2 : outPath[dv] = 'B' ; change(tmp,2,4,9,13,18,22,24);     break;
            case 3 : outPath[dv] = 'C' ; change(tmp,11,10,9,8,7,6,5);       break;
            case 4 : outPath[dv] = 'D' ; change(tmp,20,19,18,17,16,15,14);  break;
            case 5 : outPath[dv] = 'E' ; change(tmp,24,22,18,13,9,4,2);     break;
            case 6 : outPath[dv] = 'F' ; change(tmp,23,21,16,12,7,3,1);     break;
            case 7 : outPath[dv] = 'G' ; change(tmp,14,15,16,17,18,19,20);  break;
            case 8 : outPath[dv] = 'H' ; change(tmp,5,6,7,8,9,10,11);       break;
        }
        if( judge( tmp ) )
        {
            centerNum = tmp[7] ;
            outPath[dv+1] = '\0';
            return true;
        }
        if( dfs( tmp , dv + 1 , i ))
            return true;
    }

    return false;

}

int main()
{
    while(~scanf("%d",&map[1]) && map[1])
    {
        for( int i = 2 ; i <= 24 ; i++ )
            scanf( "%d" , &map[i] );
        if( judge(map) )
            printf("No moves needed\n%d\n",map[7]);
        else
        {
            deep = 1;
            while(1)
            {
                if(dfs(map,0,-1))
                    break;
                deep++;
            }
            printf("%s\n%d\n",outPath,centerNum);
        }
        memset( map , 0 , sizeof( map ) );
    }
}
