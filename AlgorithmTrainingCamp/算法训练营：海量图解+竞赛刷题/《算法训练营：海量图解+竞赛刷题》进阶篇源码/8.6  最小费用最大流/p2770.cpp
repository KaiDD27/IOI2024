#include<iostream>//53ms
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100;
const int M=10000;
int cnt;
int head[N],dist[N],pre[N];//dist[i]表示源点到点i最短距离，pre[i]记录前驱
bool vis[N];//标记数组
int maxflow,mincost;//maxflow 当前最大流量，mincost当前最小费用
string str[M];
map<string,int> maze;
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
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    memset(dist,0x3f,sizeof(dist));
    vis[s]=true;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];~i;i=E[i].next){
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){//松弛操作
                dist[v]=dist[u]+E[i].cost;
                pre[v]=i;//记录前驱
                if(!vis[v]){ //顶点v不在队内
                    q.push(v);  //入队
                    vis[v]=true; //标记
                }
            }
        }
    }
	return pre[t]!=-1;
}

int MCMF(int s,int t){ //minCostMaxFlow
    int d=0;//可增流量
    maxflow=mincost=0;
    while(SPFA(s,t)){//表示找到了从s到t的最短路
        d=inf;
        for(int i=pre[t];~i;i=pre[E[i^1].v])
            d=min(d,E[i].cap-E[i].flow); //找最小可增流量
        maxflow+=d; //更新最大流
        for(int i=pre[t];~i;i=pre[E[i^1].v]){//修改残余网络，增加增广路上相应弧的容量，并减少其反向边容量
            E[i].flow+=d;
            E[i^1].flow-=d;
        }
        mincost+=dist[t]*d; //dist[t]为该路径上单位流量费用之和 ，最小费用更新
	}
    return maxflow;
}

void print(int s,int t){
    int v;
    vis[s]=1;
    for(int i=head[s];~i;i=E[i].next){
    	if(!vis[v=E[i].v]&&((E[i].flow>0&&E[i].cost<=0)||(E[i].flow<0&&E[i].cost>=0))){
			print(v,t);
			if(v<=t)
				cout<<str[v]<<endl;
		}	
	}
}

int main(){
	int n,m;
    string str1,str2;
    cin>>n>>m;
    init();//初始化
    maze.clear();
    for(int i=1;i<=n;i++){
		cin>>str[i];
		maze[str[i]]=i;
		if(i==1||i==n)
			adde(i,i+n,2,0);
		else
			adde(i,i+n,1,0);
    }
    for(int i=1;i<=m;i++){
        cin>>str1>>str2;
        int a=maze[str1],b=maze[str2];
        if(a<b){
			if(a==1&&b==n)
				adde(a+n,b,2,-1);
			else
				adde(a+n,b,1,-1);
        }
        else{
			if(b==1&&a==n)
				adde(b+n,a,2,-1);
			else
				adde(b+n,a,1,-1);
        }
    }
    if(MCMF(1,2*n)==2){//流量
		cout<<-mincost<<endl;
		cout<<str[1]<<endl;
		memset(vis,0,sizeof(vis));//访问标记初始化
		print(1,n);
		cout<<str[1]<<endl;
    }
    else
		cout<<"No Solution!"<<endl;
    return 0;
}
