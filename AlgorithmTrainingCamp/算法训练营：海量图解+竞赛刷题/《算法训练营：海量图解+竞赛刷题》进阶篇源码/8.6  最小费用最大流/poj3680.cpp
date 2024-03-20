#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=410;
const int M=1010;
int cnt;
int head[N],dist[N],pre[N];//dist[i]表示源点到点i最短距离，pre[i]记录前驱
bool vis[N];
int a[N],b[N],c[N],maxflow;
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
                    q.push(v);//入队
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
	int n,k,T,num[N];
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&k);
		int m=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			num[m++]=a[i];
			num[m++]=b[i];
		}
		sort(num,num+m);//排序 
		m=unique(num,num+m)-num;//去重 
		int s=0,t=m+1;
//		adde(s,1,k,0);//源点到1引一条边，容量为k,费用为0 
//		adde(m,t,k,0);//m到汇引一条边，容量为k,费用为0
//		上面两条包含在下面for语句中
		for(int i=0;i<=m;i++)
			adde(i,i+1,k,0);//i到i+1引一条边，容量为k,费用为0 
		for(int i=0;i<n;i++){
			int u=lower_bound(num,num+m,a[i])-num+1;//离散化 
			int v=lower_bound(num,num+m,b[i])-num+1;
			adde(u,v,1,-c[i]);//a[i]到b[i]引一条边，容量为1,费用为-c[i] 
		}
		printf("%d\n",-MCMF(s,t));
	}
	return 0;
}
