#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxe=4e6+5;
struct Edge{
    int v,w,nxt,pre;
}edge[maxe],E[maxe];//原图，重构图 
int Head[maxn],head[maxn],rear,tot,tail[maxn];
int mark[maxn],sz[maxn];
int N,n,cnt,root,midedge,Max;

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

void Delete(int u,int i){//删除u结点的i号边 
    if(Head[u]==i)
		Head[u]=E[i].nxt;
    else
		E[E[i].pre].nxt=E[i].nxt;//跳过该边 
    if(tail[u]==i)//指向u结点的最后一条边，相当于尾指针 
		tail[u]=E[i].pre;
    else
		E[E[i].nxt].pre=E[i].pre;//双向链表修改前驱 
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

void get_pre(){//得到每条边的前驱,nxt是下一条边的编号，pre是上一条边的编号
    memset(tail,-1,sizeof(tail));
    for(int i=1;i<=N;i++){
        for(int j=Head[i];~j;j=E[j].nxt){
            E[j].pre=tail[i];
            tail[i]=j;//指向u结点的最后一条边，相当于尾指针
        }
    }
}

void rebuild(){//重构图
    INIT();//重构图初始化 
    N=n;
    for(int i=1;i<=N;i++)
		mark[i]=1;
    build(1,0);
    get_pre();//得到每条边的前驱 
    init();//原图初始化 
}
 
struct point{
    int u,dis;
    point() {}
    point(int _u,int _dis){
        u=_u;dis=_dis;
    }
    bool operator<(const point& _A)const{
        return dis<_A.dis;//优先队列的优先级 
    }
};

struct node{
    int rt,midlen,ans; //根节点，中心边的权值，答案(最长树链)
    int ls,rs;         //左右子树编号
    priority_queue<point>q;
}T[2*maxn];//注意：设为maxe会超时,节点个数为4N

void dfs_size(int u,int fa,int dis){//求解每个子树大小
    add(u,root,dis);//添加每个点到root的距离到距离树 
    if(mark[u])//如果是白点，则压入根节点root的队列，dis为u到根root的距离
		T[root].q.push(point(u,dis));//队列中保存白点及其到root的距离 
    sz[u]=1;
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v,w=E[i].w;
        if(v==fa) continue;
        dfs_size(v,u,dis+w);
        sz[u]+=sz[v];
    }
}

void dfs_midedge(int u, int code){//找中心边
    if(max(sz[u],sz[T[root].rt]-sz[u])<Max){
        Max=max(sz[u],sz[T[root].rt]-sz[u]);//sz[T[root].rt]为该子树结点总数 
        midedge=code;
    }
    for(int i=Head[u];~i;i=E[i].nxt){
        int v=E[i].v;
        if(i!=(code^1))
			dfs_midedge(v,i);
    }
}

void PushUP(int id){//更新id的ans 
    T[id].ans=-1;//初始为-1 
    while(!T[id].q.empty()&&mark[T[id].q.top().u]==0)//弹出黑点
		T[id].q.pop();
    int ls=T[id].ls, rs=T[id].rs; //ls为左儿子，rs为右儿子
    if(ls==0&&rs==0){ //根没有左右儿子
        if(mark[T[id].rt])//根为白结点 
			T[id].ans=0;
    }
	else{
        if(T[ls].ans>T[id].ans)//如果左儿子的结果大于根 
			T[id].ans=T[ls].ans;
        if(T[rs].ans>T[id].ans)//如果右儿子的结果大于根
			T[id].ans=T[rs].ans;
        if(!T[ls].q.empty()&&!T[rs].q.empty())//穿过中心边的
            T[id].ans=max(T[id].ans,T[ls].q.top().dis+T[rs].q.top().dis+T[id].midlen);
	}
}

void DFS(int id, int u){
    root=id; Max=N; midedge=-1;
    T[id].rt=u;
    dfs_size(u,0,0);//求解每个子树大小
    dfs_midedge(u,-1);//找中心边
    if(~midedge){
        //中心边的左右2点
        int p1=E[midedge].v;//p1:v midedge: u->v 
        int p2=E[midedge^1].v;//p2:u
        //中心边长度
        T[id].midlen=E[midedge].w;
        //左右子树
        T[id].ls=++cnt;
        T[id].rs=++cnt;
        //删除中心边
        Delete(p1,midedge^1);//删除p1结点的i号边 
        Delete(p2,midedge);
        DFS(T[id].ls,p1);
        DFS(T[id].rs,p2);
    }
    PushUP(id);//更新rt的ans 
}

void update(int u){//改变u的颜色 
    mark[u]^=1;//颜色取反 
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v,w=edge[i].w;
        if(mark[u]==1) //u为白结点加入v结点队列 
			T[v].q.push(point(u,w)); 
        PushUP(v);//更新v
    }
}

int main(){
	scanf("%d",&n);
    init();//原树初始化 
    int u,v,w;
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
		add(v,u,w);
    }
    rebuild();//重建树 
	DFS(cnt=1,1);//求解答案
    char op[2]; 
	int m,x;
    scanf("%d", &m);
    while(m--){
        scanf("%s",op);
        if(op[0]=='A'){//输出树中最远的两个白点距离 
            if(T[1].ans==-1)
				printf("They have disappeared.\n");
            else
				printf("%d\n",T[1].ans);
        }else{
            scanf("%d",&x);
            update(x);//改变x的颜色
        }
    }
    return 0;
}
