#include <iostream>

using namespace std;

int main()
{
    int time,n,u,f,d;
    while(cin>>time>>n>>u>>f>>d)
    {
        char a[100005];
        int cnt = 0,ans = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            cin>>a[i];
            if(a[i]=='u'||a[i] == 'd')
                cnt += u+d;
            if(a[i]=='f')
                cnt += 2*f;
            if( cnt <= time )
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
