/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-05 16:58
*
* Filename: hdu5349.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;
multiset<int> s;
multiset<int>::iterator it;
int n;
int op,x;

int main()
{
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%d",&op);
            if( op == 1 )
            {
                scanf("%d",&x);
                s.insert(x);
            }
            else if(op==2&&!s.empty())
            {
                it = s.begin();
                s.erase(it);
            }
            else if(op == 3 && s.empty()) printf("0\n");
            else if(op == 3 )
            {
                it = s.end();
                it--;
                printf("%d\n",*it);
            }
        }
    }
    return 0;
}
