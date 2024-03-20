#include<cstdio>
#include<cstring>
#include<queue>
const int maxn=310;
using namespace std;
struct point{
	int x,y;
	int step;
};//����ĵ㣬����Ҫ�Ĳ��� 
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
//int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
bool vis[maxn][maxn];
int sx,sy,ex,ey,tx,ty,L;

int bfs(){
	if(sx==ex&&sy==ey) return 0;
	memset(vis,false,sizeof(vis));//��ʼ�� 
	queue<point>Q;//��������� 
	point start,node;
	start.x=sx;
	start.y=sy;
	start.step=0;//���г�ʼ�� 
	Q.push(start);//ѹ������
	int step,x,y;
	while(!Q.empty()){
		start=Q.front(),Q.pop();//ȡ���е�ͷԪ�أ�ͬʱ�����Ԫ�ص��� (���дӺ���ǰ�����Ƚ����ȳ�)
	    x=start.x;
	    y=start.y;
	    step=start.step;//�Ѷ���ͷԪ�ص�x,y,stepȡ�� 
	    for(int i=0;i<8;i++){//��չ 
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx==ex&&ty==ey) return step+1;
			if(tx>=0&&tx<L&&ty>=0&&ty<L&&!vis[tx][ty]){
		        node.x=tx;
		        node.y=ty;
		        node.step=step+1;
		        Q.push(node);//���������Ľ����� 
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
