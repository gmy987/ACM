TPoint symmetricalPointofLine(TPoint p, TLine L)
{
    //p点关于直线L的对称点 
    TPoint p2;
    double d;
    d = L.a * L.a + L.b * L.b;
    p2.x = (L.b * L.b * p.x - L.a * L.a * p.x - 
            2 * L.a * L.b * p.y - 2 * L.a * L.c) / d;
    p2.y = (L.a * L.a * p.y - L.b * L.b * p.y - 
            2 * L.a * L.b * p.x - 2 * L.b * L.c) / d;
    return p2;
}

//点关于线段的对称点
//首先可以根据线段的两个端点求出线段所在的直线L，然后再来求指定
//点关于直线L的对称点
