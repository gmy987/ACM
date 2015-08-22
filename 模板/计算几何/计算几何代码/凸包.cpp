/*Í¹°ücug_1038*/
#include <stdio.h> 
#include <stdlib.h> 

struct point 
{ 
    int x, y; 
}pp; 
point p[100005]; 
int stack[100005], top; 
int dis(point a, point b) 
{ 
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
} 
int multi(point b, point c, point a) 
{ 
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 
} 
void swap(point p[], int s, int t) 
{ 
    point tmp; 
    tmp = p[s]; 
    p[s] = p[t]; 
    p[t] = tmp; 
} 
int cmp(const void *a, const void *b) 
{ 
    point *c = (point *)a; 
    point *d = (point *)b; 
    double k = multi(*c, *d, pp); 
    if(k < 0) return 1; 
    else if(k == 0 && dis(*c, pp) >= dis(*d, pp)) return 1; 
    else return -1; 
} 
void Graham(point p[], int n, int stack[], int &top) 
{ 
    int i, u; 
    u = 0; 
    for(i = 1;i < n;i++){        
        if(p[i].y == p[u].y && p[i].x < p[u].x) u = i;  
        else if(p[i].y < p[u].y) u = i; 
    } 
    swap(p, 0, u); 
    pp = p[0]; 
    qsort(p + 1, n - 1, sizeof(p[0]), cmp); 
    stack[0] = 0; 
    stack[1] = 1; 
    top = 1; 
    for(i = 2;i < n;i++){ 
        while(multi(p[i], p[stack[top]], p[stack[top - 1]]) >= 0){ 
            if(top == 0) break; 
            top--; 
        } 
        top++; 
        stack[top] = i; 
    }   
} 
int main() 
{ 
    int ca, i, j, n; 
    int area; 
    scanf("%d", &ca); 
    for(i = 1;i <= ca;i++){ 
        scanf("%d", &n); 
        for(j = 0;j < n;j++){ 
            scanf("%d%d", &p[j].x, &p[j].y); 
        }  
        Graham(p, n, stack, top); 
        area = 0; 
        for(j = 1;j <= top - 1;j++){ 
            area +=  abs(multi(p[stack[0]], p[stack[j]], p[stack[j + 1]])); 
        } 
        printf("%.1lf\n", (double)area / 2); 
    } 
    return 0; 
} 
