#include<bits/stdc++.h>
using namespace std;
const int MX=2e5+5;
const int MXE=4e6+5;//距离图需要边数多，加了10倍 
const int inf=0x3f3f3f3f;
struct Edge{
    int v,w,nxt,pre;
}edge[MXE],E[MXE];//原图，重构图 
int Head[MX],head[MX],rear,tot,tail[MX];
int mark[MX],sz[MX];
int N,n,cnt,root,midedge,Max;
int white;//初始化没有白点

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

void Delete(int u,int i){//删除中心边 
    if(Head[u]==i)
		Head[u]=E[i].nxt;
    else
		E[E[i].pre].nxt=E[i].nxt;
    if(tail[u]==i)
		tail[u]=E[i].pre;
    else
		E[E[i].nxt].pre=E[i].pre;
}

void build(int u,int fa){ //保证每个点的度不超过2
    int father=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v,w=edge[i].w;
        if(v==fa)continue;
        if(father==0){//还没有增加子节点，直接连上
            ADD(u,v,w);
			ADD(v,u,w);
            father=u;
        }
		else{ //已经有一个子节点，则创建一个新节点，把v连在新节点上     
            mark[++N]=0;//虚节点，标记为黑色 
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
		mark[i]=0;//标记黑色 
    build(1,0);//重建树
    get_pre();//保存每条边的前驱，为删除中心边做准备 
    init();//将原图置空，为创建距离树做准备
}
 
struct point{
    int u, dis;
    point() {}
    point(int _u, int _dis){
        u=_u;dis=_dis;
    }
    bool operator<(const point& _A)const{
        return dis>_A.dis;//距离从小到大，优先队列 
    }
};

struct node{
    int rt,midlen; //根节点，中心边
    int ls,rs;     //左右子树编号
    priority_queue<point>q;//保存子树中每个白节点到根的距离 
}T[2*MX];
 
void dfs_size(int u,int fa,int dir){//创建距离树，入队，求新树每个子树大小
    add(u,root,dir);//创建距离树 
    //如果是白点，则压入根节点root的优先队列，dist为u到根的距离
    if(mark[u])//白点 
		T[root].q.push(point(u,dir));
    sz[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v,w=E[i].w;
        if(v==fa) continue;
        dfs_size(v,u,dir+w);
        sz[u]+=sz[v];
    }
}

void dfs_midedge(int u, int code){//找中心边
    if(max(sz[u],sz[T[root].rt]-sz[u])<Max){
        Max=max(sz[u],sz[T[root].rt]-sz[u]);
        midedge=code;
    }
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v;
        if(i!=(code^1))//反向边 
			dfs_midedge(v,i);
    }
}

void PushUP(int id){//更新
    while(!T[id].q.empty()&&!mark[T[id].q.top().u])
		T[id].q.pop();//弹出黑点
}

void DFS(int id, int u){//递归求解
    root=id; Max=N; midedge=-1;
    T[id].rt=u;
    dfs_size(u,0,0);
    dfs_midedge(u,-1);
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
        DFS(T[id].ls,p1);
        DFS(T[id].rs,p2);
    }
}

void update(int u){//u节点变色 
    mark[u]^=1;//变色
    if(mark[u])
    	white++;
    else
    	white--;
    for(int i=head[u];~i;i=edge[i].nxt){//距离图的邻接点 
        int v=edge[i].v,w=edge[i].w;
        if(mark[u])	
			T[v].q.push(point(u,w));
        PushUP(v);//更新
    }
}

int query(int u){//查询离u最近的白点的距离
	int mn=inf,temp=0;
	for(int i=head[u];~i;i=edge[i].nxt){//距离图的邻接点 
        int id=edge[i].v,w=edge[i].w;
        int ls=T[id].ls, rs=T[id].rs; //ls为左儿子，rs为右儿子
		if(!T[ls].q.empty()) //穿过中心边
			mn=min(mn,T[ls].q.top().dis+temp+T[id].midlen);
        if(!T[rs].q.empty()) //穿过中心边
        	mn=min(mn,T[rs].q.top().dis+temp+T[id].midlen);
		temp=w;
    }
    return mn;
}

int main(){
	scanf("%d",&n);
    init();
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v,1);add(v,u,1);//无边权,设为1 
    }
    rebuild();//重建树  
    DFS(cnt=1,1);//边分治递归
    int opt,m; 
	white=0;//初始化没有白点
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&opt,&u);
        if(opt==1){
			if(!white)
            	printf("-1\n");
            else if(mark[u]) //u为白色 
            	printf("0\n");
			else
				printf("%d\n",query(u));
        }
		else
			update(u);
    }
    return 0;
}
