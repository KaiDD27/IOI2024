#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=80010;
int fa[maxn],head[maxn],qhead[maxn],dis[maxn];
bool vis[maxn];
int id,iq;
struct Node{//图中的边E和查询QE用统一结构体
    int to;
    int next;
    int lca;//图中lca表示u、v的边权，查询中lca代表查询u、v的最短距离 
}E[maxn],QE[maxn];
 
int find(int x){
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}
 
void LCA(int u){
    fa[u]=u;
    vis[u]=true;
    for(int i=head[u];i!=-1;i=E[i].next){
        int v=E[i].to;
		if(!vis[v]){
            dis[v]=dis[u]+E[i].lca;
            LCA(v);
            fa[v]=u;
        }
    }
    for(int i=qhead[u];i!=-1;i=QE[i].next){
        int v=QE[i].to;
		if(vis[v]){
            QE[i].lca=dis[u]+dis[v]-2*dis[find(v)];
            QE[i^1].lca=QE[i].lca;
        }
    }
}

void add1(int u,int v,int w){
	E[id].to=v;
    E[id].lca=w;
    E[id].next=head[u];
    head[u]=id++;
}

void add2(int u,int v){
	QE[iq].to=v;
    QE[iq].next=qhead[u];
    qhead[u]=iq++;
}

void init(){
    memset(fa,0,sizeof(fa));
    memset(head,-1,sizeof(head));
    memset(qhead,-1,sizeof(qhead));
    memset(vis,false,sizeof(vis));
    memset(E,0,sizeof(E));
    memset(QE,0,sizeof(QE));
    memset(dis,0,sizeof(dis));
    id=iq=0;
}

int main(){
    int N,M,K,u,v,w;
    char s;
    while(~scanf("%d%d",&N,&M)){
        init();
		for(int i=0;i<M;i++){   //%*c：读入一个字符，但忽略它（即不赋值给任何变量）
            scanf("%d%d%d %c",&u,&v,&w,&s);//%c前面的空格用来屏蔽空白符
            add1(u,v,w);
            add1(v,u,w);
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d%d",&u,&v);
        	add2(u,v);//查询也用链式前向星存储
        	add2(v,u);
        }
        LCA(1);
        for(int i=0;i<iq;i+=2)
            printf("%d\n",QE[i].lca);
    }
    return 0;
}
