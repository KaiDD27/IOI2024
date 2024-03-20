#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=505,maxe=100001;
const int inf=0x3f3f3f3f;
int T,n,m,w,cnt;
int head[maxn],dis[maxn],sum[maxn];
bool vis[maxn];//标记是否在队列中 
struct node{
	int to,next,c;
}e[maxe];

void add(int u,int v,int c){
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].c=c;	
	head[u]=cnt++;
}

bool spfa(int u){
	queue<int>q;
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	vis[u]=1;
	dis[u]=0;
	sum[u]++;
	q.push(u);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];~i;i=e[i].next){
			if(dis[e[i].to]>dis[x]+e[i].c){
				dis[e[i].to]=dis[x]+e[i].c;
				if(!vis[e[i].to]){
					if(++sum[e[i].to]>=n)
						return false;
					vis[e[i].to]=1;
					q.push(e[i].to);
				}
			}
		}
	}
	return true;
}

bool solve(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		if(dis[i]==inf)//如果已经到达该点没找到负环，则不需要再从该点找 
			if(!spfa(i))
				return 1;
	return 0;
}

int main(){
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n>>m>>w;
		memset(head,-1,sizeof(head));
		int u,v,t;
		for(int i=1;i<=m;i++){
			cin>>u>>v>>t;
			add(u,v,t);//两条边 
			add(v,u,t);
		}
		for(int i=1;i<=w;i++){
			cin>>u>>v>>t;
			add(u,v,-t);//一条边 
		}
		if(solve())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
