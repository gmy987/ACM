#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    long long n;
    vector<vector<int> > v;
    vector<int> vv;
    while(~scanf("%lld",&n))
    {
        v.clear();
        int i = 1 , k = 1;
        long long tmp = 1;
        while( ((long long)k)*k <= n && i <= k )
        {
            if( tmp < n )
            {
                k++;
                tmp+=((long long)k)*k;
            }
            else if( tmp == n )
            {
                vv.clear();
                for( int j = i ; j <= k ; j++ )
                    vv.push_back(j);
                v.push_back(vv);
                tmp-=((long long)i)*i;
                i++;
            }
            else 
            {
                tmp-=((long long)i)*i;
                i++;
            }
        }
        printf("%d\n",v.size());
        for( int i = 0 ; i < v.size() ; i++ )
        {
            printf("%d",v[i].size());
            for( int j = 0 ; j < v[i].size() ; j++ )
                printf(" %d",v[i][j]);
            printf("\n");
        }
    }
    return 0;
}
