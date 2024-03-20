#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000+5;
int n,m,head[maxn],cnt;;
int low[maxn],dfn[maxn],degree[maxn],num;
struct Edge{
	int to,next;
}e[maxn<<1];

void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;	
}

void tarjan(int u,int fa){//求边双连通分量
	dfn[u]=low[u]=++num;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)
			continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
}

void init(){
	memset(head,0,sizeof(head));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(degree,0,sizeof(degree));
	cnt=num=0;
}

int main(){
	while(cin>>n>>m){
		init();
		int u,v;
		while(m--){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		tarjan(1,0);
		for(int u=1;u<=n;u++)
			for(int i=head[u];i;i=e[i].next){
				int v=e[i].to;
				if(low[u]!=low[v])
					degree[low[u]]++;
			}
		int leaf=0;
		for(int i=1;i<=n;i++)
			if(degree[i]==1)
				leaf++;
		cout<<(leaf+1)/2<<endl;
	}
	return 0;
}

