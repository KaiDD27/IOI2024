#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;//或者简单粗暴，节点开4倍，边数开4倍
const int MX=4e4+5;//数组开的小了，一直runtime error！！！ 
const int MXE=4e4+5;//加上虚拟节点，重建树共2N个节点，边数4N 
        //T树每条中心边也是一个节点，共4N个节点，静态链表不需要存边 
struct Edge{
    int v,w,nxt,pre;
}edge[MXE],E[MXE];//原图，重构图 
int Head[MX],head[MX],tail[MX],tot,rear,Max;
int sz[MX],mark[MX];//子树大小，标记虚实节点 
int N,n,k,cnt,root,midedge;
int ans;

void init(){//原图初始化 
    memset(head,-1,sizeof(head));
    tot=0;
}

void INIT(){//重构图初始化
    memset(Head,-1,sizeof(Head));
    rear=0;//下标从零开始 
}

void add(int u,int v,int w){
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}

void ADD(int u,int v,int w){
    E[rear].v=v;
    E[rear].w=w;
    E[rear].nxt=Head[u];
    Head[u]=rear++;
}

void Delete(int u,int i){
    if(Head[u]==i)
		Head[u]=E[i].nxt;
    else
		E[E[i].pre].nxt=E[i].nxt;
    if(tail[u]==i)
		tail[u]=E[i].pre;
    else
		E[E[i].nxt].pre=E[i].pre;
}

void build(int u,int fa){//保证每个点的度不超过2
    int father=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v,w=edge[i].w;
        if(v==fa)continue;
        if(father==0){//还没有增加子节点，直接连上
            ADD(u,v,w);
			ADD(v,u,w);
            father=u;
        }
		else{//已经有一个子节点，则创建一个新节点，把v连在新节点上      
            mark[++N]=0; 
			ADD(N,father,0);
			ADD(father,N,0);
            father=N;
            ADD(v,father,w);
			ADD(father,v,w); 
        }
		build(v,u);
    }
}

void get_pre(){//求每条边的前驱，为删除中心边做准备 
    memset(tail,-1,sizeof(tail));
    for(int i=1;i<=N;i++){//nxt是下一条边的编号，pre是上一条边的编号
        for(int j=Head[i];~j;j=E[j].nxt){
            E[j].pre=tail[i];
            tail[i]=j;
        }
    }
}

void rebuild(){//重建树
    INIT();//重建树初始化 
    N=n;
    for(int i=1;i<=N;i++)
		mark[i]=1;
    build(1,0);//重建树
    get_pre();//保存每条边的前驱，为删除中心边做准备 
}

struct node{
    int rt,midlen; //根节点，中心边
    int ls,rs;     //左右子树编号
}T[MX];

int q[2][MX],len[2];//保存左右子树中每个实节点到根的距离，len[]为数组下标 

void dfs_size(int u,int fa,int dir,int flag){//创建距离树，入队，求新树每个子树大小
	if(mark[u])
		q[flag][len[flag]++]=dir;//子树所有实节点到根的距离入队 
    sz[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v,w=E[i].w;
        if(v==fa) continue;
        dfs_size(v,u,dir+w,flag);
        sz[u]+=sz[v];
    }
}

void dfs_midedge(int u,int code){//找中心边
    if(max(sz[u],sz[T[root].rt]-sz[u])<Max){
        Max=max(sz[u],sz[T[root].rt]-sz[u]);
        midedge=code;
    }
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v;
        if(i!=(code^1))
			dfs_midedge(v,i);
    }
}

void solve(int ls,int rs,int midlen){//查询距离不超过k的节点数 
	sort(q[0],q[0]+len[0]);
	sort(q[1],q[1]+len[1]);
	for(int i=0,j=len[1]-1;i<len[0];i++){
		while(j>=0&&q[0][i]+q[1][j]+midlen>k)
			j--;
		ans+=j+1;
	}
}

int getmide(int id,int u,int flag){//求解中心边，距离 
	Max=N;midedge=-1;
    root=id;T[id].rt=u;
    len[flag]=0;
    dfs_size(u,0,0,flag);
	dfs_midedge(u,-1);
	return midedge;
}

void DFS(int id,int midedge,int flag){//递归求解
    if(~midedge){
        //中心边的左右2点
        int p1=E[midedge].v;
        int p2=E[midedge^1].v;
        //中心边长度
        T[id].midlen=E[midedge].w;
        //左右子树
        T[id].ls=++cnt;
        T[id].rs=++cnt;
        //删除中心边
        Delete(p1,midedge^1);
        Delete(p2,midedge);
        int t1=getmide(T[id].ls,p1,0);
        int t2=getmide(T[id].rs,p2,1);
        solve(T[id].ls,T[id].rs,T[id].midlen);
        DFS(T[id].ls,t1,0);
    	DFS(T[id].rs,t2,1);
    }
}

int main(){
	while(scanf("%d%d",&n,&k),n+k){
		init();
		int u,v,w;
		for(int i=1;i<n;i++){
		    scanf("%d%d%d",&u,&v,&w);
		    add(u,v,w);
			add(v,u,w); 
		}
		ans=0;
		if(n>1){
			rebuild();//重建
			root=1; 
		    T[root].rt=1;//T树根
		    len[0]=0;//距离数组长度 
		    cnt=1;//T树节点编号 
		    int t=getmide(1,1,0);//得到中心边 
			DFS(1,t,0);//边分治递归
		}
        printf("%d\n",ans);
	}
    return 0;
}
