bool isPointOnSegment(TPoint p, TPoint p1, TPoint p2)
{
    // 判断p点是否在线段p1p2上
    //1.p是否在直线p1p2上 
    //2.p是否在以p1p2为对角线的矩形中
    if(multi(p1, p2, p) != 0) return false ;
    if((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x)) return false;
    if((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y)) return false;
    return true;   
}
