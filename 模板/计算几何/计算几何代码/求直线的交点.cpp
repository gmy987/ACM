/*��ֱ�ߵĽ��㣬ע��ƽ�ε�����޽⣬����RE*/
TPoint LineInter(TLine l1, TLine l2)
{
    //����ֱ�ߵý�������
    TPoint tmp; 
    double a1 = l1.a;
    double b1 = l1.b;
    double c1 = l1.c;
    double a2 = l2.a;
    double b2 = l2.b;
    double c2 = l2.c;
    //ע������b1 = 0 
    if(fabs(b1) < eps){
        tmp.x = -c1 / a1;  
        tmp.y = (-c2 - a2 * tmp.x) / b2;
    }       
    else{
        tmp.x = (c1 * b2 - b1 * c2) / (b1 * a2 - b2 * a1);
        tmp.y = (-c1 - a1 * tmp.x) / b1;
    }
    //cout << "��������" << endl; 
    //cout << a1 * tmp.x + b1 * tmp.y + c1 << endl;
    //cout << a2 * tmp.x + b2 * tmp.y + c2 << endl;
	return tmp;
}
