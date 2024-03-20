#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110000;
int cnt,n,q,tot,pl;
int Pool[maxn*50];
int head[maxn],F[maxn],dis[20][maxn],cur[maxn],id[maxn],w[maxn];//id[]为节点序列 
int root,S,size[maxn],f[maxn];//f[]为删除u后，最大子树的大小  
bool vis[maxn];
int ans;
struct edge{
	int to,next;
}edge[maxn<<1];

struct BIT{//树状数组 
	int *C,n;
	void init(int T){//初始化 
		n=T;
		C=Pool+pl;
		pl+=n+1;
		for(int i=0;i<=n;i++)
			C[i]=0;
	}
	int que(int x){//查询前缀和 
		x++;
		int res=0;
		for(int i=x;i;i-=(i&-i))
			res+=C[i];
		return res;
	}
	void add(int x,int y){//点更新 
		x++;
		for(int i=x;i<=n;i+=(i&-i))
			C[i]+=y;
	} 
}C[4*maxn][2];//两个树状数组 

void init(){
	tot=cnt=pl=root=0;
	for(int i=1;i<=n;i++)
		vis[i]=head[i]=0;
	f[0]=S=n;
}

void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void getroot(int u,int fa){//求解重心
    size[u]=1;
	f[u]=0;//删除u后，最大子树的大小 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v]){
            getroot(v,u);
            size[u]+=size[v];
       		f[u]=max(f[u],size[v]);
        }
	}    
    f[u]=max(f[u],S-size[u]);//S为当前子树总结点数 
    if(f[u]<f[root])
		root=u;
}

void dfs(int dep,int idx,int u,int d,int fa){
	C[idx][0].add(dis[dep][u]=d,w[u]);  //将u节点的权值w[u]插入到第1个树状树状的dis[][]+1位置，dis[dep-1][u]表示u到当前层重心的距离 
	if(dep>1)                           //当前层次大于1，说明存在上一级重心 
		C[idx][1].add(dis[dep-1][u],w[u]);//将w[u]插入到第2个树状树状的dis[][]+1位置，dis[dep-1][u]表示u到上一层重心的距离 
    for(int i=head[u];i;i=edge[i].next){//u的每一个邻接点v 
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v])
    		dfs(dep,idx,v,d+1,u); //从v出发，深度优先遍历，距离+1 
    }
}

void solve(int u,int fa){//u为当前重心，fa为上一级重心 
	vis[u]=1;
	F[id[u]=++tot]=id[fa];//F[]表示上一级重心编号，id[u]表示u节点的编号
	cur[id[u]]=cur[id[fa]]+1;//cur[]表示当前节点所属重心的层次，等于上一级重心的层次+1 
	C[tot][0].init(S+1);//初始化第1个树状数组，0空间不用，因此节点数S+1 
	C[tot][1].init(S+1);//初始化第2个树状数组
	dfs(cur[id[u]],id[u],u,0,0);//从u开始深度优先遍历
	int tmp=S;
	for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(vis[v]) continue;
    	root=0;
    	S=size[u]>size[v]?size[v]:tmp-size[u];
    	getroot(v,u); //求以v为根的子树的重心 
    	solve(root,u); //递归求解 
	}
}

void query(int k,int x,int y){//查询答案 
    int d=max(-1,min(C[k][0].n-1,y-dis[cur[k]][x]));//C[k][0].n-1表示当前节点所属重心的节点数 
    ans+=C[k][0].que(d);//求第一个树状数组中小于等于d的前缀和 
    if(F[k]){//上一层重心的层次 
    	d=max(-1,min(C[k][1].n-1,y-dis[cur[k]-1][x]));//上一层重心 
    	ans-=C[k][1].que(d);//减去重复，第二个树状数组中小于等于d的前缀和 
    	query(F[k],x,y);//向上一层继续查找
	}
}

void update(int k,int x,int y){//点更新 
    C[k][0].add(dis[cur[k]][x],y);//更新第一个树状数组，dis[cur[k]][x]表示x到当前层重心的距离 
    if(F[k]){
    	C[k][1].add(dis[cur[k]-1][x],y);//更新第二个树状数组，dis[cur[k]-1][x]表示x到上一层重心的距离 
    	update(F[k],x,y);//向上一层更新 
	} 
}

int main(){
	int x,y;
	while(~scanf("%d%d",&n,&q)){
        init();
        char s[3];
        for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        getroot(1,0);
        solve(root,0);
        for(int i=1;i<=q;i++){
        	scanf("%s%d%d",s,&x,&y);
	        if(s[0]=='!'){
	        	update(id[x],x,y-w[x]);
	        	w[x]=y;
			}
	        else{
	        	ans=0;
	        	query(id[x],x,y);
	        	printf("%d\n",ans);
			}
		}
    }
    return 0;
}
