#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=110;
const int M=10100;
int cnt;
int head[N],d[N],a[1010],belong[1010];
struct Edge{
   int v,next;
   int cap,flow;
}E[M<<1];//双边

void init(){//初始化 
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int c){
    E[cnt].v=v;
    E[cnt].cap=c;
    E[cnt].flow=0;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

void adde(int u,int v,int c){
    add(u,v,c);
    add(v,u,0);
}

bool bfs(int s,int t){//分层
    memset(d,0,sizeof(d));
    queue<int>q;
    d[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=E[i].next){
        	int v=E[i].v;
        	if(!d[v]&&E[i].cap>E[i].flow){
                d[v]=d[u]+1;
				q.push(v);
				if(v==t)  return 1;
			}	
		}
    }
    return 0;
}

int dfs(int u,int flow,int t){//在分层的基础上dfs 
    if(u==t) return flow;
	int rest=flow;
    for(int i=head[u];~i&&rest;i=E[i].next){
    	int v=E[i].v;
    	if(d[v]==d[u]+1&&E[i].cap>E[i].flow){
            int k=dfs(v,min(rest,E[i].cap-E[i].flow),t);
			if(!k) d[v]=0;
			E[i].flow+=k;
			E[i^1].flow-=k;
			rest-=k;
		}	
	}
	return flow-rest;
}

int Dinic(int s,int t){
	int maxflow=0;
	while(bfs(s,t)){
		maxflow+=dfs(s,inf,t);
	}
	return maxflow;
}

int main(){
    int m,n,k,x,w,d;
    scanf("%d%d",&m,&n);
    init();
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){//n个客户 
        scanf("%d",&k);//钥匙数 
        w=0;
        for(int j=1;j<=k;j++){
            scanf("%d",&x);
            if(belong[x]==0) 
                w+=a[x];
            else
                adde(belong[x],i,inf);
            belong[x]=i;//标记x猪圈的第一个客户 
        }
        adde(0,i,w);
        scanf("%d",&d);
        adde(i,n+1,d);
    }
    printf("%d\n",Dinic(0,n+1));
    return 0; 
}
