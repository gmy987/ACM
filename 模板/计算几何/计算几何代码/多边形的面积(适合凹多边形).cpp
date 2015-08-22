double polygonArea(TPolygon p, int n)
{
    //已知多边形各顶点的坐标，求其面积
    double area;
    int i;
    area = 0;
    for(i = 1;i <= n;i++){
        area += (p.p[i - 1].x * p.p[i % n].y - p.p[i % n].x * p.p[i - 1].y);
    }  
    return area / 2;   
}
