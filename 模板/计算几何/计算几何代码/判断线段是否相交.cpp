bool isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //�ж��߶��Ƿ��ཻ
    //1.�����ų������ж��������߶�Ϊ�Խ��ߵ����������Ƿ��ཻ 
    //2.��������
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
