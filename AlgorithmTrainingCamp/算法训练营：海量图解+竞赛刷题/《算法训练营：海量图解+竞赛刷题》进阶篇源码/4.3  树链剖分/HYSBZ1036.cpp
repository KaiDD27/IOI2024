#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=30005;
int n,m;//n个结点，m个查询
int head[maxn],cnt=0,total=0;//头结点
int fa[maxn],dep[maxn];//父亲，深度 
int size[maxn],son[maxn],top[maxn];//子树结点总数，重儿子，所在重链顶端结点
int w[maxn];//权值
int id[maxn],rev[maxn];//u对应的dfs序下标，下标对于的u 
int Max,Sum;
struct edge{
	int to,next;
}e[maxn<<1];
 
struct node{//结点
	int l,r,mx,sum;//l,r表示区间左右端点，mx表示区间[l,r]的最值 
}tree[maxn*4]; //树结点存储数组 

int readin(){//注意：本题c++读入会超时 
	char c;
	int sign=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')
			sign=-1;
	int res=c-'0';
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-'0';
	return res*sign;
}

void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs1(int u,int f){//求dep,fa,size,son
    size[u]=1;
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==f)//父节点 
			continue;
        dep[v]=dep[u]+1;//深度 
        fa[v]=u;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]])
        	son[u]=v;
    }
}

void dfs2(int u,int t){//求top,id,rev
	top[u]=t;
	id[u]=++total;//u对应的dfs序下标 
	rev[total]=u;//dfs序下标对应的结点u 
	if(!son[u])
		return;
	dfs2(son[u],t);//沿着重儿子dfs 
	for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v!=fa[u]&&v!=son[u])
        	dfs2(v,v);
	}
}

void build(int k,int l,int r){//创建线段树,k表示存储下标,区间[l,r]
	tree[k].l=l;
	tree[k].r=r;
	if(l==r){
		tree[k].mx=tree[k].sum=w[rev[l]];
		return;
	}
	int mid,lc,rc;
	mid=(l+r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标 
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//结点的最大值等于左右孩子最值的最大值 		
	tree[k].sum=tree[lc].sum+tree[rc].sum;//结点的和值等于左右子树和值 
}

void query(int k,int l,int r){//求区间[l..r]的最值、和值 
	if(tree[k].l>=l&&tree[k].r<=r){//找到该区间
		Max=max(Max,tree[k].mx);
		Sum+=tree[k].sum;
		return;
	} 
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标
	if(l<=mid)
		query(lc,l,r);//到左子树查询 
	if(r>mid)
		query(rc,l,r);//到右子树查询
}

void ask(int u,int v){//求u,v之间的最值或和值 
	while(top[u]!=top[v]){//不在同一条重链上
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		query(1,id[top[u]],id[u]);//u顶端结点和u之间 
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])//在同一条重链上 
		swap(u,v); //深度小的结点为u
	query(1,id[u],id[v]);
}

void update(int k,int i,int val){//u对应的下标i，将其值修改更新为val
	if(tree[k].l==tree[k].r&&tree[k].l==i){//找到i
		tree[k].mx=tree[k].sum=val;
		return;
	}
	int mid,lc,rc;
	mid=(tree[k].l+tree[k].r)/2;//划分点 
	lc=k*2;  //左孩子存储下标 
	rc=k*2+1;//右孩子存储下标
	if(i<=mid)
		update(lc,i,val);//到左子树修改更新 
	else
		update(rc,i,val);//到右子树修改更新
	tree[k].mx=max(tree[lc].mx,tree[rc].mx);//返回时修改更新最值
	tree[k].sum=tree[lc].sum+tree[rc].sum;//返回时修改更新和值
}

int main(){
	int x,y;
	char str[10];
	n=readin();
	for(int i=1;i<n;i++){
		x=readin();
		y=readin();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		cin>>w[i];
	dep[1]=1;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,total);//创建线段树
	m=readin();
	for(int i=1;i<=m;i++){
		scanf("%s",str);
		x=readin();
		y=readin();
		if(str[0]=='C')
			update(1,id[x],y);
		else{
			Sum=0;
			Max=-0x3f3f3f3f;
			ask(x,y);
			if(str[1]=='M')
				printf("%d\n",Max);
			else
				printf("%d\n",Sum);	
		}	
	}
	return 0;
}
