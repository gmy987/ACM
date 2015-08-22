#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
struct state{
    int x[10],y[10];//保存蛇每段身体的坐标
};
struct Node{
    int x,y,s,k;//x，y保存蛇头的坐标，
                //s为表示整个蛇身前后关系的二进制数字
                //k为走的距离
};
state snake;
int n,m,l,k;
bool vis[25][25][1<<15];
int gap[25][25];//记录障碍物的位置
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

//用0，1，2，3表示后一段身体在前一段的下，上，右，左
//每一种方向用2位的二进制数表示： 00，01，10，11
//则最多需要14位。
int encode ( state s )
{
    int st = 0;
    for( int i = l - 1 ; i > 0 ; i-- )
    {
        int x , y , now;
        x = s.x[i] - s.x[i-1];
        y = s.y[i] - s.y[i-1];
        if( x == 0 && y == 1 )
            now = 2;
        else if( x == 0 && y == -1 )
            now = 3;
        else if(x == 1 && y == 0)
            now = 0;
        else if( x == -1 && y == 0 )
            now = 1;
        st <<= 2;//每次向左移动两位
        st|=now;
    }
    return st;//返回一个14位的二进制数表示整条蛇的状态
}
state decode( int hx , int hy , int s )
{
    int direction;
    state pos;
    pos.x[0] = hx,pos.y[0] = hy;
    for( int i = 1 ; i < l ; i++ )
    {
        direction = 3;//11,任何数与11的&都为它本身
        direction &= s;//得到s的最后两位
        s >>= 2;//右移2位
        pos.x[i] = pos.x[i-1] + dir[direction][0];
        pos.y[i] = pos.y[i-1] + dir[direction][1];
    }
    return pos;
}
Node moves( Node s , int d )
{
    int mod = (1<<((l-1)*2))-1;
    int now , nx , ny , x, y;
    nx = s.x + dir[d][0];
    ny = s.y + dir[d][1];
    x=-dir[d][0],y = -dir[d][1];
    if( x==0 && y==1 )
        now = 2;
    else if( x == 0 && y == -1 )
        now = 3;
    else if( x == 1 && y == 0 )
        now = 0;
    else if ( x == -1 && y == 0 )
        now = 1;
    s.s <<= 2;//向左移动两位，以增加新的位置
    s.s|=now;
    s.s&=mod;//除去原来最左的两位
    s.x = nx , s.y = ny;
    return s;
}

bool judge( int x , int y , int s , Node pre )
{
    if ( x < 1 || y < 1 || x > n || y > m )
        return false;
    if( vis[x][y][s] == 1 ) return false;
    if(gap[x][y] == 1 ) return false;

    state ss = decode(pre.x,pre.y,pre.s);
    //判断蛇新到的地方是否与原来蛇身相撞
    for( int i = 0 ; i < l ; i++ )
        if(ss.x[i] == x && ss.y[i] == y)
            return false;
    return true;
}

int bfs()
{
    queue<Node> q;
    Node a;
    a.x = snake.x[0],a.y = snake.y[0];
    a.s = encode(snake);//将蛇身转化为二进制数字
    a.k = 0;
    q.push(a);
    vis[a.x][a.y][a.s] = 1;
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        Node tp;
        if( a.x == 1 && a.y == 1 )
            return a.k;
        for( int i = 0 ; i < 4 ; i++ )
        {
            tp = moves( a , i );
            tp.k = a.k + 1;
            if( !judge(tp.x,tp.y,tp.s,a)) continue;
            vis[tp.x][tp.y][tp.s] = 1;
            q.push(tp);
        }
    }
    return -1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int cnt = 1;
    while(~scanf("%d%d%d",&n,&m,&l)&&n&&m&&l)
    {
        if(!n&&!m&&!l) break;
        for( int i = 0 ; i < l ; i++ )
            scanf("%d%d",&snake.x[i],&snake.y[i]);
        memset(gap,0,sizeof(gap));
        scanf("%d",&k);
        int u,v;
        for( int i = 0 ; i < k ; i++ )
        {
            scanf("%d%d",&u,&v);
            gap[u][v] = 1;
        }
        memset(vis,0,sizeof(vis));
        printf("Case %d: %d\n",cnt++,bfs());
    }
    return 0;
}
