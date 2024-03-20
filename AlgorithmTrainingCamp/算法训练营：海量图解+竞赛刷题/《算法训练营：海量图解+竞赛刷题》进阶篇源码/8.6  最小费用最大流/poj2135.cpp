#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
const int M=20005;
int cnt;
int head[N],dist[N],pre[N];//dist[i]表示源点到点i最短距离，pre[i]记录前驱
bool vis[N];//标记数组
int maxflow;//最大流
struct Edge{
   int v,next;
   int cap,flow,cost;
}E[M<<1];

void init(){//初始化 
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int c,int cost){
    E[cnt].v=v;
    E[cnt].cap=c;
    E[cnt].flow=0;
    E[cnt].cost=cost;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

void adde(int u,int v,int c,int cost){
    add(u,v,c,cost);
    add(v,u,0,-cost);
}

bool SPFA(int s,int t){//求最短费用路的SPFA
    queue<int> q;
    memset(vis,false,sizeof(vis));//访问标记初始化
    memset(pre,-1,sizeof(pre)); //前驱初始化
    memset(dist,0x3f,sizeof(dist));
    vis[s]=true; //顶点入队vis要做标记
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false; //队头元素出队，消除标记
        for(int i=head[u];~i;i=E[i].next){
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){//松弛操作
                dist[v]=dist[u]+E[i].cost;
                pre[v]=i; //记录前驱
                if(!vis[v]){ //顶点v不在队内
                    q.push(v);   //入队
                    vis[v]=true; //标记
                }
            }
        }
    }
    return pre[t]!=-1;
}

int MCMF(int s,int t){
    int d=0;//可增流量
    int mincost=0;//maxflow当前最大流量，mincost当前最小费用
    while(SPFA(s,t)){
        d=inf;
        for(int i=pre[t];~i;i=pre[E[i^1].v])//找最小可增流量
            d=min(d,E[i].cap-E[i].flow); 
        for(int i=pre[t];~i;i=pre[E[i^1].v]){//修改残余网络，增加增广路上相应弧的容量，并减少其反向边容量
            E[i].flow+=d;
            E[i^1].flow-=d;
        }
		maxflow+=d; //更新最大流
        mincost+=dist[t]*d;//dist[t]为该路径上单位流量费用之和 ，最小费用更新
	}
    return mincost;
}

int main(){
    int n,m,u,v,w;
    while(~scanf("%d %d",&n,&m)){
        init();
        adde(0,1,2,0);//增加源点0 
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            adde(u,v,1,w);
            adde(v,u,1,w);
        }
        adde(n,n+1,2,0);//增加汇点n+1 
        printf("%d\n",MCMF(0,n+1));
    }
    return 0;
}
