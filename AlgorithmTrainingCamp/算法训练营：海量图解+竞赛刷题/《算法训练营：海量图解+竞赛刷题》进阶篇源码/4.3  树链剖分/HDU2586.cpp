#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=40005;
int n,m;//n个结点，m个查询
int head[maxn],dist[maxn],cnt;//头结点，距离
int fa[maxn],dep[maxn];//父亲，深度 
int size[maxn],son[maxn],top[maxn];//子树结点总数，重儿子，所在重链顶端结点 
struct Edge{
	int to,c,next;
}e[maxn<<1];
 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs1(int u,int f){//求dep,fa,size,son,dist
    size[u]=1;
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==f)//父节点 
			continue;
        dep[v]=dep[u]+1;//深度 
        fa[v]=u;
        dist[v]=dist[u]+e[i].c;//距离 
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]])
        	son[u]=v;
    }
}

void dfs2(int u){//求top
	if(u==son[fa[u]])
		top[u]=top[fa[u]];
	else
		top[u]=u;
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v!=fa[u])
        	dfs2(v);
	}
}

int LCA(int u,int v){//求区间u,v的最近公共祖先 
	while(top[u]!=top[v]){//不在同一条重链上
		if(dep[top[u]]>dep[top[v]])
			u=fa[top[u]];
		else
			v=fa[top[v]];
	}
	return dep[u]>dep[v]?v:u;//返回深度小的结点 
}

int main(){
	int x,y,T,lca;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)//初始化 
			head[i]=dep[i]=dist[i]=son[i]=0;
		cnt=0;
		for(int i=1;i<n;i++){//输入一棵树的n-1边
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		dep[1]=1;
		dfs1(1,0);
		dfs2(1);
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			lca=LCA(x,y);
			cout<<dist[x]+dist[y]-2*dist[lca]<<endl;//输出x y的距离 
		}	
	}
	return 0;
}
