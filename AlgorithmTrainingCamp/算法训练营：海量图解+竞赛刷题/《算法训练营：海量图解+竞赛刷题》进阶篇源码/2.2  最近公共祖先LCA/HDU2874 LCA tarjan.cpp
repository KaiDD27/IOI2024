#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e4+10;
const int maxq=1e6+10;
struct Node{//边结构体 
	int to;//邻接点 
	int w;//边权 
	int next;//下一条边的下标 
}e[maxn<<1];
int ehead[maxn],dis[maxn],fa[maxn],ecnt,vis[maxn];
struct Query{//边结构体 
	int to;
	int id;//查询的编号 
	int next;
}qe[maxq<<1];
int qhead[maxn],ans[maxq],qcnt;
int n,m,c;
 
void init(){
	ecnt=qcnt=0;
	memset(ehead,-1,sizeof(ehead));
	memset(qhead,-1,sizeof(qhead));
	memset(vis,-1,sizeof(vis));
}
 
void add1(int u,int v,int w){
	e[ecnt].to=v;
	e[ecnt].w=w;
	e[ecnt].next=ehead[u];
	ehead[u]=ecnt++;
}
 
void add2(int u,int v,int id){
	qe[qcnt].id=id;
	qe[qcnt].to=v;
	qe[qcnt].next=qhead[u];
	qhead[u]=qcnt++;
}
 
int Find(int x){
	if(x!=fa[x])
		fa[x]=Find(fa[x]);
	return fa[x];
}
 
void LCA(int u,int deep,int root){
	fa[u]=u;
	dis[u]=deep;
	vis[u]=root;
	for(int i=ehead[u];~i;i=e[i].next){
		int v=e[i].to;
		if(vis[v]==-1){
			LCA(v,deep+e[i].w,root);
			fa[v]=u;
		}
	}
	for(int i=qhead[u];~i;i=qe[i].next){
		int v=qe[i].to;
		if(vis[v]==root)
			ans[qe[i].id]=dis[v]+dis[u]-2*dis[Find(v)];
	}
}
 
 
int main(){
	while(~scanf("%d%d%d",&n,&m,&c)){
		int u,v,w;
		init();
		while(m--){
			scanf("%d%d%d",&u,&v,&w);
			add1(u,v,w);
			add1(v,u,w);	
		}
		for(int i=0;i<c;i++){
			scanf("%d%d",&u,&v);
			ans[i]=-1;
			add2(u,v,i);
			add2(v,u,i);
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==-1)
				LCA(i,0,i);
		}
		for(int i=0;i<c;i++){
			if(ans[i]==-1) printf("Not connected\n");
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
} 
