#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=40005;
int n,m;
int head[maxn],dis[maxn],cnt;//头结点,距离 
int fa[maxn],ans[maxn];
bool vis[maxn];
vector<int>query[maxn],query_id[maxn];//查询及编号 
struct Edge{
	int to,c,next;
}e[maxn<<1];
 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void add_query(int x,int y,int id){
	query[x].push_back(y);
	query_id[x].push_back(id);
	query[y].push_back(x);
	query_id[y].push_back(id);
}

int find(int x){//并查集找祖宗
	if(x!=fa[x])
		fa[x]=find(fa[x]);
	return fa[x];
}

void tarjan(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to,w=e[i].c;
		if(vis[v])
			continue;
		dis[v]=dis[u]+w;
		tarjan(v);
		fa[v]=u;
	}
	for(int i=0;i<query[u].size();i++){//u相关的所有查询
		int v=query[u][i];
		int id=query_id[u][i];
		if(vis[v]){
			int lca=find(v);
			ans[id]=dis[u]+dis[v]-2*dis[lca];
		}
	}
}

int main(){
	int x,y,T,lca;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){//初始化
			head[i]=vis[i]=dis[i]=0;
			fa[i]=i;
			query[i].clear();
			query_id[i].clear();
		}	
		cnt=0;
		for(int i=1;i<n;i++){//输入一棵树的n-1边
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x==y)
				ans[i]=0;
			else
				add_query(x,y,i);
		}
		tarjan(1);
		for(int i=1;i<=m;i++)		
			cout<<ans[i]<<endl;//输出x y的距离 	
	}
	return 0;
}
