#include<iostream>
#include<algorithm>
#include<cmath>//使用log函数
using namespace std;
const int maxn=40005;
int n,m,tot,F[maxn<<1][20];//F(i,j)表示区间[i，i+2^j-1]的最值，区间长度为2^j
int head[maxn],dist[maxn],pos[maxn],seq[maxn<<1],dep[maxn<<1],cnt;//头结点
bool vis[maxn];
struct Edge{
	int to,c,next;
}e[maxn<<1];
 
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u,int d){//dfs序
	vis[u]=true;
	pos[u]=++tot;//u首次出现的下标 
	seq[tot]=u;//dfs遍历序列
	dep[tot]=d;//深度
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to,w=e[i].c;
		if(vis[v])
			continue;
		dist[v]=dist[u]+w;
		dfs(v,d+1);
		seq[++tot]=u;//dfs遍历序列
		dep[tot]=d;//深度
	}
}

void ST_create(){
	for(int i=1;i<=tot;i++)//初始化 
		F[i][0]=i;//记录下标，不是最小深度 
	int k=log2(tot);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=tot-(1<<j)+1;i++)//tot-2^j+1
			if(dep[F[i][j-1]]<dep[F[i+(1<<(j-1))][j-1]])
				F[i][j]=F[i][j-1];
			else
				F[i][j]=F[i+(1<<(j-1))][j-1];
}

int RMQ_query(int l,int r){//求区间[l..r]的最值
	int k=log2(r-l+1);
	if(dep[F[l][k]]<dep[F[r-(1<<k)+1][k]])
		return 	F[l][k];
	else
		return 	F[r-(1<<k)+1][k];//返回深度最小的结点下标 
}

int LCA(int x,int y){//求x，y的最近公共祖先
	int l=pos[x],r=pos[y];//读取第一次出现的下标
	if(l>r)
		swap(l,r);
	return seq[RMQ_query(l,r)];//返回结点 
} 

void print(){
	for(int i=1;i<=tot;i++)
		cout<<seq[i]<<" ";
	cout<<endl;
}
/*
1
9 8
1 3 2
1 2 3
2 5 1
2 4 6
4 6 2
5 7 5
6 9 7
6 8 8
输出 1 2 4 6 8 6 9 6 4 2 5 7 5 2 1 3 1
6 5
输出 9
*/
int main(){
	int x,y,T,lca;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)//初始化 
			head[i]=vis[i]=dist[i]=0;
		cnt=0,tot=0;
		for(int i=1;i<n;i++){//输入一棵树的n-1边
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		dfs(1,1);
		print();
		ST_create();//创建ST表
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			lca=LCA(x,y);
			cout<<dist[x]+dist[y]-2*dist[lca]<<endl;//输出x y的距离 
		}	
	}
	return 0;
}
