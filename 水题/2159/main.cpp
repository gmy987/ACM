#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char a[101];
    int b[26] = {0},c[26] = {0};
    cin>>a;
    for( int i = 0 ; a[i]!='\0';i++)
        b[a[i]-'A']++;
    cin>>a;
    for(int i = 0 ; a[i]!='\0';i++)
        c[a[i]-'A']++;
    sort(b,b+26);
    sort(c,c+26);

    for( int i = 0 ; i<26 ; i++ )
    {
        if( b[i] != c[i] ){
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;

    return 0;


}
