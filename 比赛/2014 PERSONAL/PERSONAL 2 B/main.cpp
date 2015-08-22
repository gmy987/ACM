#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

struct f{
    string first;
    string second;
};
map<string , int> shop,have;
map<string , f> formula;
int cnt;

int money( string s )
{
    int cnt = 0;
    if( have[s] != 0 )
    {
        have[s]--;
        return 0;
    }
    if( have[formula[s].first]!=0)
        have[formula[s].first]--;

    else if( shop[formula[s].first] != 0)
        cnt+=shop[formula[s].first];

    else
        cnt+=money(formula[s].first);

    if( have[formula[s].second]!=0)
        have[formula[s].second]--;

    else if( shop[formula[s].second] != 0)
        cnt+=shop[formula[s].second];

    else
        cnt+=money(formula[s].second);

    return cnt;
}

int main()
{
    while(1){
    int n,i,m;
    cnt = 0;
    string s,s2,s3;
    scanf("%d",&n);
    for( i = 0 ; i<n ; i++ )
    {
        cin>>s>>m;
        shop.insert(pair<string,int>(s,m));
    }
    scanf("%d",&n);
    for( i = 0 ; i<n ; i++ )
    {
        cin>>s>>m;
        have.insert(pair<string,int>(s,m));
    }
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ )
    {
        f f1;
        cin>>f1.first>>s>>f1.second>>s2>>s3;
        formula.insert(pair<string,f>(s3,f1));
    }
    scanf("%d",&n);
    for( i = 0 ; i<n ; i++ )
    {
        cin>>s>>m;
        for( int j = 0 ; j < m ; j++ )
            cnt+=money(s);

    }
    printf("%d\n",cnt);
    }
    return 0;

}
