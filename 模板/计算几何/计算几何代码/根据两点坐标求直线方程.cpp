TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //�߶�����ֱ��,����ֱ�߷��̵�����ϵͳ 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}
