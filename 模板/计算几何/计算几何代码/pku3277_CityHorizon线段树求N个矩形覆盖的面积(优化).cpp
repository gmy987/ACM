/*
/*
�����������Ŀ�뵽����ǰ����һ����N�����θ��ǵ���������Ŀ�� 
��ʱ����ɢ�����Ȱ� 2n �� x ��������ȥ�أ�Ȼ���ٰ�����ˮƽ��
��Ҫ��¼�Ǿ����ϱ߻����±ߣ��� y ��������������ÿһС��
���� (x[i], x[i + 1]) ɨ�����е�ˮƽ�߶Σ������Щˮƽ�߶���
С�����ڸ��ǵ�������ܵ�ʱ�临�Ӷ��� O(n^2)������ǰ�Ĵ��뽻
��һ�³�ʱ�ˡ�Ȼ�󿴵���Ҷ����߶����Ż����Һ�ɵ������׼��
Ԥ�Ƚ�һ�����ڵ�Ϊ1-1000000000���߶���������������ȫ����ʵ��
Ȼ����뵽��ʱ���߶����������Ͳ�����չ���еĽڵ㡣 
*/
/*
�߶����Ĳ��������
1�� ��Ҫ���������͵�ǰ�ڵ��������ͬ�߽��и��²�ֹͣ���²��� 
2�� ������ͬ�������Ӧ�Ĳ��룬�ڽ����ӽڵ�ʱ�������ӽڵ�ͬʱ������
	������һ���ڵ������������ǰ�ڵ��yֵΪ0�� 
�ڵ����
1������ǰ�ڵ�û�������������ж�yֵ�Ƿ���ڵ�ǰ�ڵ��yֵ��������
   Ӧ�ĸ��¡�
2����������������Ӧ�������ڸ���ʱע��ɾ������������� 
*/
/*
//�ϲ��ڵ��Լ�˺ܶ�ʱ�� 
һЩ����Ϊ���Լ��ٵ�ʱ��ļ�֦��ȴ�����˺ܶ�ʱ�� 
*/
/*
�տ�һ��ţд��
�������߶����ǰ���x���±꣬���ܹ�ֻ��40000���㣬�±�����80000��
�����Ϳ���ֱ�ӽ���һ���߶��������ᳬ�������ǰ���x������ֵ������
�߶�����������maxx - minx�ܴ��ʱ������߶��������ĺܴ󣬼�ʹ
���ϵ�ɾ���ϲ��ڵ���ʱ����Ҳ�ǲ����ܵġ� 
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
