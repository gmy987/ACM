#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 160000005;
const int NUM = 256;
char str[MAX];
bool hashTable[MAX] = {false};
int m[NUM] = {0};

int main()
{
    int n ,nc ,cnt = 0 ,seed = 0;
    scanf( "%d%d%s",&n,&nc,str);
    for( int i = 0 ; str[i] != '\0' && seed != nc ; i++ )
    {
        if( m[str[i]]==0 )
            m[str[i]] = seed++;
    }

    int len = strlen(str);
    for( int i = 0 ; i <= len-n ; i++ )
    {
        int key = 0;
        for( int j = i ; j < n + i ; j++ )
            key = key*nc+m[str[j]];
        if( hashTable[key] == false )
        {
            cnt++;
            hashTable[key]=true;
        }

    }
    printf("%d\n",cnt);

    return 0;
}
