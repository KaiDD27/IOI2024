#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
const int N=805;
int n,m,step;
char mp[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	int x,y;
	node(){}
	node(int x_,int y_){x=x_;y=y_;}
}gg,mm,zz[2];
queue<node> q[2];

bool check(int x,int y){
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='X') return false;
	for(int i=0;i<2;i++)
		if(abs(x-zz[i].x)+abs(y-zz[i].y)<=2*step) return false;
	return true;
}

int bfs(int t,int num,char st,char ed){
	queue<node> que=q[t];
	for(int k=0;k<num;k++){
		while(!que.empty()){
			node now=que.front();
			que.pop();
			q[t].pop();
			if(!check(now.x,now.y)) continue; 
			for(int j=0;j<4;j++){
				int fx=now.x+dir[j][0];
				int fy=now.y+dir[j][1];				
				if(!check(fx,fy)||mp[fx][fy]==st) continue;
				if(mp[fx][fy]==ed)
					return true;
				mp[fx][fy]=st;
				q[t].push(node(fx,fy));
			}
		}
		que=q[t];
	}
	return false;
}

int solve(){
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	q[0].push(mm);
	q[1].push(gg);
	step=0;
	while(!q[0].empty()&&!q[1].empty()){
		step++;
		if(bfs(0,3,'M','G')||bfs(1,1,'G','M'))
			return step;
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",mp[i]);
		int cnt=0;
		for(int i=0;i<n;i++){//找出男/女/鬼的位置
			for(int j=0;j<m;j++){
				if(mp[i][j]=='Z')
					zz[cnt].x=i,zz[cnt++].y=j;
				if(mp[i][j]=='M') mm.x=i,mm.y=j;
				if(mp[i][j]=='G') gg.x=i,gg.y=j;
			}
		}
		printf("%d\n",solve());
	} 
	return 0;
}
