#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int MAXN=200200;
const int MAXE=400400;
const int INF=0x3f3f3f3f;
struct E{
	int v,w,next;
}edge[MAXE];
int head[MAXN],cnt,dp[MAXN],d[MAXN],val[MAXN],deg[MAXN];
int n,T;

void add(int u,int v,int w){
    edge[cnt].v=v;
	edge[cnt].w=w;
    edge[cnt].next=head[u];
	head[u]=cnt++;
}

void dfs1(int u,int fa){
	d[u]=0;
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		if(deg[v]==1) d[u]+=edge[i].w;
		else d[u]+=min(d[v],edge[i].w);
	}
}
 
void dfs2(int u,int fa){
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue;
		if(deg[u]==1) dp[v]=d[v]+edge[i].w;
		else dp[v]=d[v]+min(dp[u]-min(d[v], edge[i].w),edge[i].w);
		dfs2(v,u);
	}
}
 
void init(){
	memset(head,-1,sizeof(head));
	memset(d,0,sizeof(d));
	memset(dp,0,sizeof(dp));
	memset(deg,0,sizeof(deg));
	cnt=0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
			deg[u]++;
			deg[v]++;
		}
		dfs1(1,0);
		dp[1]=d[1];
		dfs2(1,0);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
