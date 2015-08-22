/*
判断矩形是否在矩形中 
*/
#include <stdio.h>
#include <math.h>

#define pi acos(-1)

void swap(double &a, double &b)
{
    double tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    double a, b, x, y;
    while(scanf("%lf%lf%lf%lf", &a, &b, &x, &y)){
        if(a == 0 && b == 0 && x== 0 && y== 0) break;
        if(a * b <= x * y){
            printf("Box cannot be dropped.\n");
            continue;
        }
        if(a < b) swap(a, b);
        if(x < y) swap(x, y);
        if((a >= x && b >= y) || (x <= b)){
            printf("Escape is possible.\n");
            continue;
        }
        int tag = 0;
        for(double i = 0;i <= 90;i += 0.2){
            double angle = i * pi / 180;
            if(x * cos(angle) + y * sin(angle) < a 
               && y * cos(angle) + x * sin(angle ) < b){
                    printf("Escape is possible.\n");
                    tag = 1;
                    break;
                }
        }
        if(tag == 0) printf("Box cannot be dropped.\n");  
    }
    return 0;
}
