/*
凸包( Convex Hull )
凸包是对平面是上的某个点集而言的，凸包是一个最小凸多边形，满足点集
中的所有点都在该凸多边形内（或在该多边形的边上）。
通常，我们采用Graham扫描法来求点集的凸包。首先，排序选出点集中最左下
角点（先取y坐标最小的点，若有多个再在其中取x坐标最小的点），设该点为p0；
然后，将其余的按以p0为中心的极角坐标逆时针排序，多于相同极角的点只保留
距离p0最远的一个，这样就可以得到一个点的序列p1,p2, p2.....,pn;接下来，
将p0, p1, p2压入栈，一次处理pi（i >= 2 && i <= n），不断让栈顶的元素出
栈，直到栈顶的下一个元素，栈顶元素，以及pi构成的折线不拐向左侧，将pi压
入栈中；最后栈中的元素即为所求的凸包的顶点序列  
*/ 
/*
腾讯公司不会以QQ聊天形式通知中奖，请谨防中奖陷阱。

  蓝点.rcu 13:23:13
  嗯～～O(n^2)的应该没有问题
  ¤海子⊙   13:23:36
  谢谢你，
  ¤海子⊙   13:23:41
  说我听听
  蓝点.rcu 13:23:51
  这样子，先弄出一条直线～～这条直线穿过两个点。
  蓝点.rcu 13:24:05
  外层循环用来枚举跳过的点数。
  蓝点.rcu 13:24:19
  （跳过的方向是顺时针或者逆时针）
  ¤海子⊙   13:24:46
  这是O（n^3）
  蓝点.rcu 13:24:56
  你等我说完。
  向内的一层循环，枚举起始点，
  蓝点.rcu 13:25:32
  最后的那一点，不要再加循环进行枚举。
  蓝点.rcu 13:25:57
  利用峰值原则和起始点进行同步调整。
  蓝点.rcu 13:26:11
  峰值原则是这样的……
  蓝点.rcu 13:26:33
  就是 rotating calipers 的一个方面。
  蓝点.rcu 13:26:41
  先简化情况。
  ¤海子⊙   13:26:42
  峰值原则是什么
  蓝点.rcu 13:28:57
  假设最大三角形有两个点相邻
  （两个点不相临的情况在上述算法中用枚举处理掉了）
  以这两个点为底边，如果对另外一点进行扫描，则三角形高的最大值只可能有一个（可能出现多次，但是出现的这几次必定相邻，否则就不是凸包了）。
  蓝点.rcu 13:29:50
  
	蓝点.rcu 13:29:57
	这种情况可能发生
	蓝点.rcu 13:30:21
	上方的三点作为顶点都可以使得面积最大
	¤海子⊙   13:30:44
	上方的三点作为顶点面积不是零吗
	¤海子⊙   13:31:02
	哦，知道了，底边
	蓝点.rcu 13:31:11
	不是，是以下面的边为底边，以上面三点任何一点为另外顶点
	蓝点.rcu 13:31:16
	
	  ¤海子⊙   13:31:31
	  这不是凸包吧
	  蓝点.rcu 13:31:35
	  这种情况不可能出现。
	  因为这不是凸包
	  蓝点.rcu 13:32:33
	  峰值原则 1：
	  如果以固定的为底边，则三角形面积最大值至少出现一次，而且如果出现多次，则必连续出现。
	  ¤海子⊙   13:32:59
	  哦，这个好理解，凸包的性质
	  ¤海子⊙   13:34:23
	  哦，两层循环就是枚举底边的两个顶点？
	  蓝点.rcu 13:34:24
	  嗯，然后，还有一点，我忘记如何证明了，底边进行步进旋转的同时，峰值出现的位置沿着底边旋转的方向单调增加
	  蓝点.rcu 13:34:41
	  两层循环其实就是枚举顶点
	  ¤海子⊙   13:34:57
	  是枚举底边的两个顶点？
	  蓝点.rcu 13:35:07
	  但是根据峰值原则的这一条，外层必须用来枚举跳点个数
	  蓝点.rcu 13:35:12
	  其实就是枚举两个顶点
	  
		蓝点.rcu 13:35:21
		但是枚举的顺序是要严格小心的
		¤海子⊙   13:35:48
		枚举跳点个数，跳点是什么
		蓝点.rcu 13:36:23
		就是三角形底边两顶点之间跳过的凸包上的点的数量
		蓝点.rcu 13:37:39
		如此呢～～就可以旋转了～～
		¤海子⊙   13:37:44
		哦，我理解一下
		蓝点.rcu 13:38:00
		就是这样的：外层控制底边，内层控制旋转。
		蓝点.rcu 13:38:20
		千万不要多加一层哈～～那样就成(n^3)了……
		¤海子⊙   13:38:49
		哦，是呀，
		蓝点.rcu 13:39:06
		我想想……应该可以继续优化……
		¤海子⊙   13:39:12
		谢谢你啊，我理解一下，
		蓝点.rcu 13:39:17
		嗯，不客气～～
		¤海子⊙   13:39:23
		是呀，有O（n）的
		蓝点.rcu 13:40:44
		那我想想哈～
		¤海子⊙   13:40:50
		
		  ¤海子⊙   13:47:04
		  外层循环枚举跳点个数，内层循环枚举起始点，然后找峰值点
		  ¤海子⊙   13:47:21
		  峰值点是有什么规律吗
		  蓝点.rcu 13:47:36
		  随着底边的旋转方向单调旋转
		  蓝点.rcu 13:47:46
		  所以就可以降为(N^2)
		  蓝点.rcu 13:47:50
		  嗯我知道O(n)大概是怎么回事了……
		  ¤海子⊙   13:47:58
		  哦，这么快
		  蓝点.rcu 13:48:03
		  等我想清楚哈……
		  ¤海子⊙   13:48:11
		  哦，好，我把这个想想
		  蓝点.rcu 13:56:49
		  嗯，知道了……还是峰值原则～～
		  蓝点.rcu 13:57:07
		  首先三点重合。
		  蓝点.rcu 13:57:30
		  然后呢，推动一下，推成连续的三点。
		  蓝点.rcu 13:57:39
		  初始化完毕。
		  蓝点.rcu 13:58:18
		  固定，尾点推动无论如何不能超过首点的起始位置。
		  蓝点.rcu 13:59:38
		  之后呢，就可以玩了，推动尾点，使得面积达到峰值，然后，推动中点，使得面积达到峰值，继而推动首点，使得面积达到峰值、
		  蓝点.rcu 13:59:49
		  然后推动尾点……如此下去……
		  蓝点.rcu 14:00:04
		  直到尾点达到首点的初始位置。
		  蓝点.rcu 14:01:31
		  三个点，都只能转一圈，而且，每一次顺序推进操作，至少使得尾点向前推动一次，因此，最多执行n次，在每一次中，单调推动三个点，常数复杂度。
		  蓝点.rcu 14:01:42
		  于是整个算法复杂度为O(n)……
		  蓝点.rcu 14:01:46
		  我懒得证明了……
		  蓝点.rcu 14:01:56
		  *_*
		  在忙一个工程……
		  ¤海子⊙   14:07:57
		  不好意思，我刚才出去了一下
		  蓝点.rcu 14:07:58
		  您好，我现在有事不在，一会儿再和您联系
		  ¤海子⊙   14:08:29
		  哦，你在忙一个工程啊，好，谢谢你啊
		  蓝点.rcu 14:08:30
		  您好，我现在有事不在，一会儿再和您联系
		  蓝点.rcu 14:14:22
		  嗯～～不客气～～
		  你是黄冈人哈？
		  ¤海子⊙   14:14:29
		  是呀，
		  ¤海子⊙   14:14:35
		  你也是？
		  蓝点.rcu 14:15:08
		  我是北方人啦～不过～～
		  呵呵～～我女朋友是黄冈中学的。
		  ¤海子⊙   14:15:42
		  这么强，黄冈高中？
		  ¤海子⊙   14:15:48
		  我是垃圾学校出来的
		  蓝点.rcu 14:17:08
		  嗯，她高中是黄冈中学的～～
		  
			呵呵～～不管啦～～
			现在过得好才是王道 ～～
			¤海子⊙   14:17:15
			呵呵，
			¤海子⊙   14:17:38
			你忙吧，以后多指教我啊，谢谢你，你真是个好人
			
			  
*/
//Rotating Calipers algorithm


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxNode 50005

int stack[MaxNode];
int top;
double max;

typedef struct TPoint
{
    int x;
    int y;
}TPoint;
TPoint point[MaxNode];

void swap(TPoint point[], int i, int j)
{
    TPoint tmp;
    tmp = point[i];
    point[i] = point[j];
    point[j] = tmp;
}

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double distance(TPoint p1, TPoint p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    double k = multi(*c, *d, point[0]);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, point[0]) >= distance(*d, point[0]))  
	        return 1;
    else return -1;   
}

void grahamScan(int n)
{ 
    //Graham扫描求凸包
    int i, u; 
    
    //将最左下的点调整到p[0]的位置
    u = 0;
    for(i = 1;i <= n - 1;i++){
        if((point[i].y < point[u].y) || 
		     (point[i].y == point[u].y && point[i].x  < point[u].x))
			u = i;      
    } 
    swap(point, 0, u);
    
    //将平p[1]到p[n - 1]按按极角排序，可采用快速排序
    qsort(point + 1, n - 1, sizeof(point[0]), cmp);
    
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++){
        while(multi(point[i], point[stack[top]], point[stack[top - 1]]) >= 0){
			top--;
			if(top == 0) break;
        }
        top++;
        stack[top] = i;
    }
}

int main()
{    
    double triangleArea(int i, int j, int k);
    void PloygonTriangle();
    int i, n;
    while(scanf("%d", &n) && n != -1){
        for(i = 0;i < n;i++)
			scanf("%d%d", &point[i].x, &point[i].y);
        if(n <= 2){
			printf("0.00\n");
            continue;      
        }
        if(n == 3){
            printf("%.2lf\n", triangleArea(0, 1, 2));
            continue; 
        }
        grahamScan(n);
        PloygonTriangle();	
        printf("%.2lf\n", max);    
    }
    return 0;
}

void PloygonTriangle()
{
    double triangleArea(int i, int j, int k);
    int i, j , k;
    double area, area1;
    max = -1;
	for(i = 0;i <= top - 2;i++){ 
		k = -1;
		for(j = i + 1; j <= top - 1;j++){ 
			if(k <= j) k= j + 1;
			area = triangleArea(stack[i], stack[j], stack[k]);
			if(area > max) max = area;
			while(k + 1 <= top){
				area1= triangleArea(stack[i], stack[j], stack[k + 1]);
				if(area1 < area) break;
				if(area1 > max) max = area1;
				area = area1;
				k++;
			}
		}
	}
}

double triangleArea(int i, int j, int k)
{
    //已知三角形三个顶点的坐标，求三角形的面积 
    double l = fabs(point[i].x * point[j].y + point[j].x * point[k].y 
		+ point[k].x * point[i].y - point[j].x * point[i].y 
		- point[k].x * point[j].y - point[i].x * point[k].y) / 2;  
    return l;
}

