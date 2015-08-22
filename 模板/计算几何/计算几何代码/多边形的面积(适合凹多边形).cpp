double polygonArea(TPolygon p, int n)
{
    //��֪����θ���������꣬�������
    double area;
    int i;
    area = 0;
    for(i = 1;i <= n;i++){
        area += (p.p[i - 1].x * p.p[i % n].y - p.p[i % n].x * p.p[i - 1].y);
    }  
    return area / 2;   
}
