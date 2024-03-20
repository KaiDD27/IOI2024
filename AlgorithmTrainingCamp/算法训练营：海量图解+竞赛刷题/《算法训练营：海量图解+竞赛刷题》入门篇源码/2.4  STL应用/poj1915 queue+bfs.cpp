#include<cstdio>
#include<cstring>
#include<queue>
const int maxn=310;
using namespace std;
struct point{
	int x,y;
	int step;
};//到达的点，和需要的步数 
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
//int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
bool vis[maxn][maxn];
int sx,sy,ex,ey,tx,ty,L;

int bfs(){
	if(sx==ex&&sy==ey) return 0;
	memset(vis,false,sizeof(vis));//初始化 
	queue<point>Q;//定义个队列 
	point start,node;
	start.x=sx;
	start.y=sy;
	start.step=0;//队列初始化 
	Q.push(start);//压进队列
	int step,x,y;
	while(!Q.empty()){
		start=Q.front(),Q.pop();//取队列的头元素，同时把这个元素弹出 (队列从后往前进，先进的先出)
	    x=start.x;
	    y=start.y;
	    step=start.step;//把队列头元素的x,y,step取出 
	    for(int i=0;i<8;i++){//扩展 
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx==ex&&ty==ey) return step+1;
			if(tx>=0&&tx<L&&ty>=0&&ty<L&&!vis[tx][ty]){
		        node.x=tx;
		        node.y=ty;
		        node.step=step+1;
		        Q.push(node);//满足条件的进队列 
		        vis[tx][ty]=true;
			}
	    }
	}
}

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
		scanf("%d",&L);
		scanf("%d%d",&sx,&sy);
		scanf("%d%d",&ex,&ey);
		printf("%d\n",bfs());
    }
    return 0; 
}
