#include<bits/stdc++.h>
using namespace std;
const int N=100000+5,M=200000+5,inf=0x7fffffff;
int n,m,cnt;
int head[N],dis[N];
bool vis[N];
queue<int>q1,q2,q3;
struct Edge{
	int to,c,next;
}e[M];

void add(int u,int v,int c){//添加一条边 
// 	e[++cnt].to=v;
//	e[cnt].c=c;
//	e[cnt].next=head[u];
	e[++cnt]=(Edge){v,c,head[u]};
 	head[u]=cnt;
}

void bfs1(){//逆向标高求最短距离 
	int u,v;
	memset(vis,false,sizeof(vis));
	dis[n]=0;
	q1.push(n);
	vis[n]=true;
	while(!q1.empty()){
		u=q1.front();
		q1.pop();
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next){
			v=e[i].to;
			if(vis[v])
				continue;
			dis[v]=dis[u]+1;
			q1.push(v);
			vis[v]=true;
		}
	}
}

void bfs2(){
	int u,v,minc,c;
	bool first=true;
	memset(vis,false,sizeof(vis));
	vis[1]=true;
	for(int i=head[1];i;i=e[i].next)//1号结点所有邻接点 
		if(dis[e[i].to]==dis[1]-1){//高度减1的邻接点
			q1.push(e[i].to);
			q2.push(e[i].c);
		}
	while(!q1.empty()){
		minc=inf;
		while(!q1.empty()){
			v=q1.front();
			q1.pop();
			c=q2.front();
			q2.pop();
			if(c<minc){
				while(!q3.empty())//发现更小队列清空 
					q3.pop();
				minc=c;
			}
			if(c==minc)
				q3.push(v);
		}
		if(first)
			first=false;
		else
			cout<<" ";
		cout<<minc;
		while(!q3.empty()){//所有等于最小色号的结点 
			u=q3.front();
			q3.pop();
			if(vis[u])
				continue;
			vis[u]=true;
			for(int i=head[u];i;i=e[i].next){//扩展每一个结点 
				v=e[i].to;
				if(dis[v]==dis[u]-1){
					q1.push(v);
					q2.push(e[i].c);
				}
			}
		}		
	}
}

int main(){
	int u,v,c;
	while(cin>>n>>m){
		memset(head,0,sizeof(head));
		cnt=0;
		for(int i=1;i<=m;i++){
			cin>>u>>v>>c;
			add(u,v,c);
			add(v,u,c); 
		}
		bfs1();
		cout<<dis[1]<<endl;
		bfs2();
		cout<<endl;
	 } 
	return 0;
}
