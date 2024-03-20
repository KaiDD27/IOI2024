#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=10005,maxe=100005;
const int inf=0x3f3f3f3f;
int n,m,x,cnt,rcnt;
int head[maxn],rhead[maxn],dis[maxn],rdis[maxn];
bool vis[maxn];//标记是否在队列中 
struct node{
	int to,next,w;
}e[maxe],re[maxe];

void add(node *e,int *head,int u,int v,int w,int &cnt){
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt++;
}

void spfa(node *e,int *head,int u,int *dis){
	queue<int>q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,maxn*sizeof(int));//数组做参数，不能用sizeof(dis)测量
	vis[u]=1;
	dis[u]=0;
	q.push(u);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];~i;i=e[i].next){
			if(dis[e[i].to]>dis[x]+e[i].w){
				dis[e[i].to]=dis[x]+e[i].w;
				if(!vis[e[i].to]){
					vis[e[i].to]=1;
					q.push(e[i].to);
				}
			}
		}
	}
}

int main(){
	cin>>n>>m>>x;
	cnt=rcnt=0;
	memset(head,-1,sizeof(head));	
	memset(rhead,-1,sizeof(rhead));	
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(e,head,u,v,w,cnt);
		add(re,rhead,v,u,w,rcnt);//反向图
	}
	spfa(e,head,x,dis);
	spfa(re,rhead,x,rdis);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]+rdis[i]);
	cout<<ans<<endl;
	return 0;
}
