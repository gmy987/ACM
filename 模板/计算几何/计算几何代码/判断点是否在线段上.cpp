bool isPointOnSegment(TPoint p, TPoint p1, TPoint p2)
{
    // �ж�p���Ƿ����߶�p1p2��
    //1.p�Ƿ���ֱ��p1p2�� 
    //2.p�Ƿ�����p1p2Ϊ�Խ��ߵľ�����
    if(multi(p1, p2, p) != 0) return false ;
    if((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x)) return false;
    if((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y)) return false;
    return true;   
}
