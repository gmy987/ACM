TCircle incircleOfTriangle(TTriangle t)
{
    //三角形的内接圆(未检验正确性) 
    TCircle tmp;
    double a, b, c, angleA, angleB, angleC, p, p2, p3, f1, f2;
    double xA, yA, xB, yB, xC, yC;
    a = distance(t.t[0], t.t[1]);
    b = distance(t.t[1], t.t[2]);
    c = distance(t.t[2], t.t[0]);
    /*
    S = p * r
    p = (a + b + c) / 2;
    r = S / P = 2 * S / (a + b + c)
    */
    tmp.r = 2 * triangleArea(t) / (a + b +c);
    angleA = acos((b * b + c * c - a * a) / (2 * b * c));
    angleB = acos((a * a + c * c - b * b) / (2 * a * c));
    angleC = acos((a * a + b * b - c * c) / (2 * a * b));
    p = sin(angleA / 2);
    p2 = sin(angleB / 2);
    p3 = sin(angleC / 2);
    
    xA = t.t[0].x; yA = t.t[0].y;
    xB = t.t[1].x; yB = t.t[1].y;
    xC = t.t[2].x; yC = t.t[2].y;
    
    f1 = ((tmp.r / p2) * (tmp.r / p2) - (tmp.r / p) * (tmp.r / p) + 
         xA * xA - xB * xB + yA * yA - yB * yB) / 2;
    f2 = ((tmp.r / p3) * (tmp.r / p3) - (tmp.r / p) * (tmp.r / p) + 
         xA * xA - xC * xC + yA * yA - yC * yC) / 2;
    tmp.centre.x = (f1 * (yA - yC) - f2 * (yA - yB)) / 
                   ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB));
    tmp.centre.y = (f1 * (xA - xC) - f2 * (xA - xB)) / 
                   ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB));
    return tmp;   
}
