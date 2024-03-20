#include<iostream>
#include<algorithm>
#include<cmath>//使用log函数

using namespace std;
const int maxn=40005;
int n,m,k,F[maxn][20];//n个结点，m个查询，F(i,j)表示i向上走2^j步的结点 
int head[maxn],dist[maxn],d[maxn],cnt;//头结点，距离，深度数组 
struct Edge
{
	int to,c,next;
 }e[maxn<<1];
 
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].c=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u)//求深度、距离、初始化F[v][0]
{
    for(int i=head[u];i;i=e[i].next)
	{
        int v=e[i].to;
        if(v==F[u][0])
			continue;
        d[v]=d[u]+1;//深度 
        dist[v]=dist[u]+e[i].c;//距离 
        F[v][0]=u; //F[v][0]存v的父节点
        dfs(v);
    }
}

void ST_create()//构造ST表 
{
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)//i先走2^(j-1)步到达F[i][j-1],再走2^(j-1)步
			F[i][j]=F[F[i][j-1]][j-1];
}

int LCA_st_query(int x,int y)//求区间x,y的最近公共祖先 
{
	if(d[x]>d[y])//保证x的深度小于等于y 
		swap(x,y);
	for(int i=k;i>=0;i--)//y向上走到与x同一深度 
		if(d[F[y][i]]>=d[x])
			y=F[y][i];
	if(x==y)
		return x;
	for(int i=k;i>=0;i--)//x,y一起向上走
		if(F[x][i]!=F[y][i])
			x=F[x][i],y=F[y][i];
	return F[x][0];//返回x的父亲 
}

int main()
{
	int x,y,T,lca;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		k=log2(n);//log(n)/log(2);
		for(int i=1;i<=n;i++)//初始化 
			head[i]=d[i]=dist[i]=0;
		cnt=0;
		for(int i=1;i<n;i++)//输入一棵树的n-1边
		{
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		d[1]=1;
		dfs(1);
		ST_create();//创建ST表
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			lca=LCA_st_query(x,y);
			cout<<dist[x]+dist[y]-2*dist[lca]<<endl;//输出x y的距离 
		}	
	}
	return 0;
}
