TPoint symmetricalPointofLine(TPoint p, TLine L)
{
    //p�����ֱ��L�ĶԳƵ� 
    TPoint p2;
    double d;
    d = L.a * L.a + L.b * L.b;
    p2.x = (L.b * L.b * p.x - L.a * L.a * p.x - 
            2 * L.a * L.b * p.y - 2 * L.a * L.c) / d;
    p2.y = (L.a * L.a * p.y - L.b * L.b * p.y - 
            2 * L.a * L.b * p.x - 2 * L.b * L.c) / d;
    return p2;
}

//������߶εĶԳƵ�
//���ȿ��Ը����߶ε������˵�����߶����ڵ�ֱ��L��Ȼ��������ָ��
//�����ֱ��L�ĶԳƵ�
