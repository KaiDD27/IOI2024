#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int head[maxn],cnt=0,total=0;//头结点
int fa[maxn],dep[maxn];//父亲，深度 
int size[maxn],son[maxn],top[maxn];//子树结点总数，重儿子，所在重链顶端结点
int id[maxn],rev[maxn];//u对应的dfs序下标，下标对于的u 
int Sum;
struct Edge{
	int u,v,w;
}a[maxn];
 
struct edge{
	int to,next;
}e[maxn<<1];
 
struct node{//结点
	int l,r,sum;//l,r区间左右端点，区间和值 
}tree[maxn<<2]; //树结点存储数组 

void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void init(){
    cnt=total=0;
    memset(head,0,sizeof(head));
    memset(son,0,sizeof(son));
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

void build(int i,int l,int r){//初始化线段树,i表示存储下标,区间[l,r]
	tree[i].l=l;
	tree[i].r=r;
	tree[i].sum=0;
	if(l==r) return;
	int mid=(l+r)/2;//划分点 
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
}

void update(int i,int k,int val){//点更新，线段树的第k个值为val
    if(tree[i].l==k&&tree[i].r==k){
        tree[i].sum=val;
        return;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(k<=mid) update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    tree[i].sum=tree[i<<1].sum+tree[(i<<1)|1].sum;
}

void query(int i,int l,int r){//查询线段树中[l,r]的和值
    if(tree[i].l>=l&&tree[i].r<=r){//找到该区间
		Sum+=tree[i].sum;
		return;
	} 
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=mid) query(i<<1,l,r);
    if(r>mid) query((i<<1)|1,l,r);
}

void ask(int u,int v){//求u,v之间的和值 
	while(top[u]!=top[v]){//不在同一条重链上
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		query(1,id[top[u]],id[u]);//u顶端结点和u之间 
		u=fa[top[u]];
	}
	if(u==v) return; 
	if(dep[u]>dep[v])//在同一条重链上 
		swap(u,v); //深度小的结点为u
	query(1,id[son[u]],id[v]);//注意是son[u] 
}

int main(){
    int n,q,s;
    init();
    scanf("%d%d%d",&n,&q,&s);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        add(a[i].u,a[i].v);
        add(a[i].v,a[i].u);
    }
    dep[1]=1;
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,total);//创建线段树
    for(int i=1;i<n;i++){
        if(dep[a[i].u]>dep[a[i].v])
            swap(a[i].u,a[i].v);
        update(1,id[a[i].v],a[i].w);
    }
	int opt,i,val,x;
	while(q--){
		scanf("%d",&opt);
        if(opt){
        	scanf("%d%d",&i,&val);
			update(1,id[a[i].v],val);//改变第i条边的值为val
		}
        else{
			scanf("%d",&x);
			Sum=0;
            ask(s,x);//查询s->x路径上边权的和值 
        	printf("%d\n",Sum);
        	s=x;//更新温迪的位置 
		}
    }
    return 0;
}
