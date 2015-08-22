TPoint GetOtherPoint(TPoint pre, TPoint tmp)
{
    /*根据线段两端点的坐标求垂直平分线上除中点外的另一点*/
	double kx, ky;
	TPoint other, mid;
	mid.x = (pre.x + tmp.x) / 2;
	mid.y = (pre.y + tmp.y) / 2;
	kx = pre.x - tmp.x;
	ky = pre.y - tmp.y;
	if(fabs(kx) < eps){
		other.y = mid.y;
		other.x = 1.0;
		if(fabs(other.x - mid.x) < eps) other.x = 2.0;
	}
	else if(fabs(ky) < eps){
		other.x = mid.x;
		other.y = 1.0;
		if(fabs(other.y - mid.y) < eps) other.y = 2.0;
	}
	else {
		double k = -kx / ky;
		other.x = 1.0;
		if(fabs(other.x - mid.x) < eps) other.x = 2.0;
		other.y = mid.y + k * (other.x - mid.x);
	}
	return other;
}
