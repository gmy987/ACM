#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string , string > hashTable;

int main()
{
    string line;
    while( getline ( cin , line ))
    {
        string english , foreign;
        if( line.length()==0 )
            break;
        int pos = line.find(' ');
        english = line.substr( 0 , pos );
        foreign = line.substr( pos + 1 , line.length() - pos - 1);
        hashTable.insert( pair<string , string>( foreign , english));
    }
    while( getline( cin , line))
    {
        if( line.length()==0)
            break;
        if( hashTable[line] == "" )
            printf("eh\n");
        else
        {
            printf( "%s\n" , hashTable[line].c_str());
        }
    }
    return 0;
}
