#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    //数组num中保存数字序列，长度为len
    //长度为len的序列共有2^len-1个组合
    //可将其看作一串0和1组成的序列，i这个数看作2进制1的位置代表选择这个数，0代表不选
    for( int i = 1 ; i < (1<<len) ; i++ )
    {
        cnt = 0;
        for( int j = 0 ; j < len ; j++ )
        {
            //判断j这个位置在i中是否为1
            if( i&(1<<j))
                ans[cnt++] = num[i];
        }
        //
    }
    return 0;
}


