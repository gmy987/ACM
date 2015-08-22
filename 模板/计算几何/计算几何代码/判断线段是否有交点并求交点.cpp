/*cug_1078判断线段是否有交点并求交点*/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

const double eps = 1e-6; 

typedef struct TPodouble  
{ 
    double x; 
    double y; 
}TPodouble; 

typedef struct TLine 
{ 
    double a, b, c; 
}TLine; 

double max(double x, double y) 
{ 
    if(x > y) return x; 
    else return y;  
} 

double min(double x, double y) 
{ 
    if(x < y) return x; 
    else return y;  
} 
double multi(TPodouble  p1, TPodouble  p2, TPodouble  p0) 
{ 
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y); 
} 

TLine lineFromSegment(TPodouble p1, TPodouble p2) 
{ 
    TLine tmp; 
    tmp.a = p2.y - p1.y; 
    tmp.b = p1.x - p2.x; 
    tmp.c = p2.x * p1.y - p1.x * p2.y; 
    return tmp; 
} 

void Linedoubleer(TLine l1, TLine l2) 
{ 
    double x, y; 
    double a1 = l1.a; 
    double b1 = l1.b; 
    double c1 = l1.c; 
    double a2 = l2.a; 
    double b2 = l2.b; 
    double c2 = l2.c; 
    if(b1 == 0){ 
        x = -c1 / (double)a1;   
        y = (-c2 - a2 * x) / (double)b2; 
    }        
    else{ 
        x = (double)(c1 * b2 - b1 * c2) / (double)(b1 * a2 - b2 * a1); 
        y = (double)(-c1 - a1 * x) /(double)b1; 
    } 
    printf("%.3lf %.3lf\n", x, y); 
} 

bool isIntersected(TPodouble s1, TPodouble e1, TPodouble s2, TPodouble e2){ 

    if( 
    (max(s1.x, e1.x) >= min(s2.x, e2.x)) && 
    (max(s2.x, e2.x) >= min(s1.x, e1.x)) && 
    (max(s1.y, e1.y) >= min(s2.y, e2.y)) && 
    (max(s2.y, e2.y) >= min(s1.y, e1.y)) && 
    (multi(s2, e1, s1) * multi(e1, e2, s1) >= 0) && 
    (multi(s1, e2, s2) * multi(e2, e1, s2) >= 0) 
    )  return true; 
     
    return false;     
} 

double dis(TPodouble a, TPodouble b) 
{ 
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
} 

int ISSAME(TPodouble  a, TPodouble  b) 
{ 
    if(fabs(a.x - b.x) > eps) return 0; 
    if(fabs(a.y - b.y) > eps) return 0; 
    return 1; 
} 

void between(TPodouble s1, TPodouble e1, TPodouble s2, TPodouble  e2) 
{ 
    double d1 = dis(s1, s2); 
    double d2 = dis(s1, e2); 
    double d3 = dis(e1, s2); 
    double d4 = dis(e1, e2); 
    double d5 = dis(s1, e1); 
    double d6 = dis(s2, e2); 
    if(ISSAME(s1, s2) && fabs(d5 + d6 - d4) < eps) printf("%.3lf %.3lf\n", s1.x, s1.y); 
    else if(ISSAME(s1, e2) && fabs(d3 - d5 - d6) < eps) printf("%.3lf %.3lf\n", s1.x, s1.y); 
    else if(ISSAME(e1, s2) && fabs(d2 - d5 - d6) < eps) printf("%.3lf %.3lf\n", s2.x, s2.y); 
    else if(ISSAME(e1, e2) && fabs(d1 - d5 - d6) < eps) printf("%.3lf %.3lf\n", e2.x, e2.y); 
    else printf("Too much points in common\n"); 
} 

int main() 
{ 
    TPodouble s1, e1, s2, e2; 
    TLine l1, l2; 
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &s1.x, &s1.y, &e1.x, &e1.y, &s2.x, &s2.y, &e2.x, &e2.y) != EOF){ 
        if(fabs((s1.y - e1.y) * (s2.x - e2.x) - (s1.x - e1.x) * (s2.y - e2.y)) < eps){ 
            l1 = lineFromSegment(s1, e1); 
            l2.c = -(l1.a * s2.x + l1.b * s2.y); 
            if(fabs((l1.c - l2.c) / sqrt((double)l1.a * l1.a + l1.b * l1.b)) > 0){ 
                printf("No point in common\n"); 
            } 
            else { 
                if(!isIntersected(s1, e1, s2, e2)) printf("No point in common\n"); 
                else between(s1, e1, s2, e2); 
            } 
        } 
        else { 
            if(isIntersected(s1, e1, s2, e2)){ 
                l1 = lineFromSegment(s1, e1); 
                l2 = lineFromSegment(s2, e2); 
                Linedoubleer(l1, l2);     
            } 
            else printf("No point in common\n"); 
        }     
    } 
    return 0; 
} 

