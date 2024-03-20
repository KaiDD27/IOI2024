#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1005,maxe=1000001;
const int inf=0x3f3f3f3f;
int T,n,m,w,cnt;
int head[maxn],dis[maxn];
bool vis[maxn];//标记是否已访问 
struct node{
	int to,next,w;
}e[maxe];

void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;	
	head[u]=cnt++;
}

void solve(int u){//dijkstra算法变形，求最小值最大的路径 
	priority_queue<pair<int,int> >q;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	dis[u]=inf;
	q.push(make_pair(dis[u],u));//最大值优先
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		if(vis[n])
			return;
		for(int i=head[x];~i;i=e[i].next){
			int v=e[i].to;
			if(vis[v])
				continue;
			if(dis[v]<min(dis[x],e[i].w)){//求最小值最大的
				dis[v]=min(dis[x],e[i].w);
				q.push(make_pair(dis[v],v));
			}
		}
	}
}

int main(){
	int p=1;
	cin>>T;
	while(T--){
		cnt=0;
		memset(head,-1,sizeof(head));
		cin>>n>>m;
		int u,v,w;
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			add(u,v,w);//两条边 
			add(v,u,w);
		}
		solve(1); 
		cout<<"Scenario #"<<p++<<":"<<endl;
		cout<<dis[n]<<endl<<endl;
	}
	return 0;
}
