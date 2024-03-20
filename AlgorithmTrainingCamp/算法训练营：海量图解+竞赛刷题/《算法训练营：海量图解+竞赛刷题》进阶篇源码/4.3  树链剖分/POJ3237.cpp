#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
int head[maxn],cnt=0,total=0;//头结点
int fa[maxn],dep[maxn];//父亲，深度 
int size[maxn],son[maxn],top[maxn];//子树结点总数，重儿子，所在重链顶端结点
int id[maxn],rev[maxn];//u对应的dfs序下标，下标对于的u 
int Max;
struct Edge{
	int u,v,w;
}a[maxn];

struct edge{
	int to,next;
}e[maxn<<1];
 
struct node{//结点
	int l,r,Max,Min,lazy;//l,r区间左右端点，区间最值 ,懒标记 
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

void dfs2(int u,int t){//求top,id
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
	tree[i].Max=tree[i].Min=tree[i].lazy=0;
	if(l==r) return;
	int mid=(l+r)/2;//划分点 
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
}

void push_up(int i){//上传
    tree[i].Max=max(tree[i<<1].Max,tree[(i<<1)|1].Max);
    tree[i].Min=min(tree[i<<1].Min,tree[(i<<1)|1].Min);
}

void push_down(int i){//下传
    if(tree[i].l==tree[i].r) return;
    if(tree[i].lazy){//下传给左右孩子，懒标记清零
        tree[i<<1].Max=-tree[i<<1].Max;
        tree[i<<1].Min=-tree[i<<1].Min;
        swap(tree[i<<1].Min,tree[i<<1].Max);
        tree[(i<<1)|1].Max=-tree[(i<<1)|1].Max;
        tree[(i<<1)|1].Min=-tree[(i<<1)|1].Min;
        swap(tree[(i<<1)|1].Max,tree[(i<<1)|1].Min);
        tree[i<<1].lazy^=1;
        tree[(i<<1)|1].lazy^=1;
        tree[i].lazy=0;
    }
}

void update(int i,int k,int val){//点更新，线段树的第k个值为val
    if(tree[i].l==k&&tree[i].r==k){
        tree[i].Max=val;
        tree[i].Min=val;
        tree[i].lazy=0;
        return;
    }
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(k<=mid) update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}

void update2(int i,int l,int r){//区间更新，线段树的区间[l,r]取反
    if(tree[i].l>=l&&tree[i].r<=r){
        tree[i].Max=-tree[i].Max;
        tree[i].Min=-tree[i].Min;
        swap(tree[i].Max,tree[i].Min);
        tree[i].lazy^=1;
        return;
    }
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=mid) update2(i<<1,l,r);
    if(r>mid) update2((i<<1)|1,l,r);
    push_up(i);
}

void query(int i,int l,int r){//查询线段树中[l,r]的最大值
    if(tree[i].l>=l&&tree[i].r<=r){//找到该区间
		Max=max(Max,tree[i].Max);
		return;
	} 
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=mid) query(i<<1,l,r);
    if(r>mid) query((i<<1)|1,l,r);
    push_up(i);
}

void ask(int u,int v){//求u,v之间的最值 
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

void Negate(int u,int v){//把u-v路径上的边的值取相反数 
	while(top[u]!=top[v]){//不在同一条重链上 
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		update2(1,id[top[u]],id[u]);//u顶端结点和u之间 
		u=fa[top[u]];
	}
	if(u==v) return; 
	if(dep[u]>dep[v])//在同一条重链上 
		swap(u,v); //深度小的结点为u
	update2(1,id[son[u]],id[v]);//注意是son[u] 
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&n);
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
        char op[10];
        int u,v;
        while(scanf("%s",op)==1){
            if(op[0]=='D')break;
            scanf("%d%d",&u,&v);
            if(op[0]=='Q'){
            	Max=-0x3f3f3f3f;
				ask(u,v);//查询u->v路径上边权的最大值
            	printf("%d\n",Max);
			}
            else if(op[0]=='C')
                update(1,id[a[u].v],v);//改变第u条边的值为v
            else Negate(u,v);//区间取反 
        }
    }
    return 0;
}
