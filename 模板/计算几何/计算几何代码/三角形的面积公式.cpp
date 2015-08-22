//角形面积的计算 
//  S = ah / 2
//  S = absinC / 2
//  S = sqrt(p * (p - a) * (p - b) * (p - c)), p = (a + b + c) / 2
//  S = abc / R / 4

double triangleArea(TPoint t[])
{
    return fabs((t[1].x - t[0].x) * (t[2].y - t[0].y)
              - (t[2].x - t[0].x) * (t[1].y - t[0].y)) / 2;
}
