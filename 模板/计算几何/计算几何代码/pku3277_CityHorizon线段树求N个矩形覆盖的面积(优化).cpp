/*
/*
看到了这个题目想到了以前做的一个求N个矩形覆盖的面积这个题目， 
当时是离散化，先把 2n 个 x 坐标排序去重，然后再把所有水平线
段要记录是矩形上边还是下边）按 y 坐标排序。最后对于每一小段
区间 (x[i], x[i + 1]) 扫描所有的水平线段，求出这些水平线段在
小区间内覆盖的面积。总的时间复杂度是 O(n^2)。把以前的代码交
了一下超时了。然后看到大家都用线段树优化。我很傻，我先准备
预先建一个根节点为1-1000000000的线段树，但是这样完全不现实。
然后就想到临时建线段树，这样就不用扩展所有的节点。 
*/
/*
线段树的插入与更新
1。 若要插入的区间和当前节点的区间相同边进行更新并停止向下插入 
2。 若不相同则进行相应的插入，在建立子节点时，左右子节点同时建立，
	并且若一个节点存在子树，则当前节点的y值为0。 
节点更新
1。若当前节点没有左右子树则判断y值是否大于当前节点的y值，并作相
   应的更新。
2。其他情况则更新相应子树，在更新时注意删除多余的子树。 
*/
/*
//合并节点节约了很多时间 
一些不认为可以减少的时间的剪枝切却减少了很多时间 
*/
/*
刚看一大牛写的
他建立线段树是按照x的下标，而总共只有40000个点，下标最多就80000个
这样就可以直接建立一个线段树而不会超。而我是按照x的坐标值来建立
线段树，这样当maxx - minx很大的时候，这棵线段树将会变的很大，即使
不断的删除合并节点在时间上也是不可能的。 
*/

*/

#include <stdio.h>
#include <iostream>

using namespace std;

struct SEG
{
	int x;	
	int num, sORe;
}seg[80005];

struct Rect
{
	int x1, x2, y;
}rect[40005];

struct TreeNode
{
	int l, r, y;
	int lchild, rchild;
}tree[400000];
int treel;

int x[80005];
__int64 ans;


int cmp(struct SEG a, struct SEG b)
{
	return a.x < b.x;
}

int BuildNode(int l, int r)
{
	tree[treel].l = l;
	tree[treel].r = r;
	tree[treel].y = 0;
	tree[treel].lchild = -1;
	tree[treel].rchild = -1;
	treel++;
	return treel - 1;	
}

void BuildTree(int root)
{
	if(tree[root].l + 1 < tree[root].r)
	{
		int mid = (tree[root].l + tree[root].r) / 2;
		tree[root].lchild = BuildNode(tree[root].l, mid);
		tree[root].rchild = BuildNode(mid, tree[root].r);
		BuildTree(tree[root].lchild);
		BuildTree(tree[root].rchild);
	}
}

void insert(int root, int x1, int x2, int y)
{
	if(root < 0 || tree[root].y >= y) return ;
	if(tree[root].l == x1 && tree[root].r == x2)
	{
		//if(y > tree[root].y) 
		tree[root].y = y;
		return ;
	}
	int mid = (tree[root].l + tree[root].r) / 2;
	if(x2 <= mid) insert(tree[root].lchild, x1, x2, y);
	else if(x1 >= mid) insert(tree[root].rchild, x1, x2, y);
	else 
	{
		insert(tree[root].lchild, x1, mid, y);
		insert(tree[root].rchild, mid, x2, y);
	}
}

void Traverse(int root, int maxy)
{
	if(tree[root].y > maxy) maxy = tree[root].y;
	if(tree[root].lchild < 0 || tree[root].rchild < 0)
	{
		//printf("%d\n", tree[root].r - tree[root].l);
		ans += (__int64)(x[tree[root].r] - x[tree[root].l]) * (__int64)maxy;
		return;	
	}
	Traverse(tree[root].lchild, maxy);
	Traverse(tree[root].rchild, maxy);	
}

int main()
{
	//freopen("horizon.9.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	int n, x1, x2, y, segl, rectl;
	while(scanf("%d", &n) != EOF)
	{
		segl = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d%d", &rect[i].x1, &rect[i].x2, &rect[i].y);
			seg[segl].x = rect[i].x1;
			seg[segl].num = i;
			seg[segl++].sORe = 0;
			seg[segl].x = rect[i].x2;
			seg[segl].num = i;
			seg[segl++].sORe = 1;
		}	
		sort(seg, seg + segl, cmp);
		x[0] = seg[0].x;
		if(seg[0].sORe) rect[seg[0].num].x2 = 0;
		else rect[seg[0].num].x1 = 0;
		rectl = 0;
		for(int i = 1;i < segl;i++)
		{
			if(seg[i].x > seg[i - 1].x)
			{
				rectl++;
				x[rectl] = seg[i].x;
			}
			if(seg[i].sORe) rect[seg[i].num].x2 = rectl;
			else rect[seg[i].num].x1 = rectl;
		}
		tree[0].l = 0;
		tree[0].r = rectl;
		tree[0].y = 0;
		tree[0].lchild = -1;
		tree[0].rchild = -1;
		treel = 1;
		BuildTree(0);
		for(int i = 0;i < n;i++)
		{
			insert(0, rect[i].x1, rect[i].x2, rect[i].y);
		}
		ans = 0;
		Traverse(0, 0);
		printf("%I64d\n", ans);
	}
	return 0;
}
