#include <iostream>
#include <cmath>

using namespace std;

typedef struct TPoint
{
    double x;
    double y;
    double z;
}TPoint;

const double eps = 1e-6;
int  main()
{
    TPoint a, b, c, d, ab, ac, abc;
    int n, i;
    cin >> n;
    while(n--){
        cin >> a.x >> a.y >> a.z
            >> b.x >> b.y >> b.z
            >> c.x >> c.y >> c.z
            >> d.x >> d.y >> d.z;
        
        ab.x = b.x - a.x;
        ab.y = b.y - a.y;
        ab.z = b.z - a.z;
        
        ac.x = c.x - a.x;
        ac.y = c.y - a.y;
        ac.z = c.z - a.z;
        
        abc.x = ab.y * ac.z - ab.z * ac.y;
        abc.y = -(ab.x * ac.z - ab.z * ac.x);
        abc.z = ab.x * ac.y - ab.y * ac.x;
        
        //abc.x * (x - a.x) + abc.y * (y - a.y) + abc.z * (z - a.z) = 0; 
        if(fabs(abc.x * (d.x - a.x) + abc.y * (d.y - a.y) 
           + abc.z * (d.z - a.z)) < eps)
           printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
