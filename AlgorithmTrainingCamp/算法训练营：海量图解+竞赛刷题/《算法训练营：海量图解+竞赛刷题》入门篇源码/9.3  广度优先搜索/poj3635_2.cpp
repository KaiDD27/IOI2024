#include<cstdio>//加dp[][]优化 
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1005;
const int maxm=20005;

struct edge{
    int v,w,next;
}edge[maxm];

struct node{
    int u,vol,cost;
    node(int u_,int vol_,int cost_){u=u_,vol=vol_,cost=cost_;}
    bool operator < (const node &a) const{
        return cost>a.cost;
    }
};
int head[maxn];
bool vis[maxn][105];
int dp[maxn][105];//dp[i][j]表示在顶点i，当前油量为j时的最小花费。
int n,m,V,st,ed,cnt,price[maxn];

void add(int u,int v,int w){
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

int bfs(){
    memset(vis,0,sizeof(vis));
    memset(dp,0x3f,sizeof(dp));
    priority_queue<node>Q;
    Q.push(node(st,0,0));
    dp[st][0]=0;
    while(!Q.empty()){
        node cur=Q.top();
        Q.pop();
        int u=cur.u,vol=cur.vol,cost=cur.cost;
        vis[u][vol]=1;
        if(u==ed) return cost;
        if(vol<V&&!vis[u][vol+1]&&dp[u][vol]+price[u]<dp[u][vol+1]){
        	dp[u][vol+1]=dp[u][vol]+price[u];
        	Q.push(node(u,vol+1,cost+price[u]));
		}  
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].v,w=edge[i].w;
            if(vol>=w&&!vis[v][vol-w]&&cost<dp[v][vol-w]){
            	dp[v][vol-w]=cost;
            	Q.push(node(v,vol-w,cost));
			}
        }
    }
    return -1;
}

int main(){
    int u,v,w;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++) scanf("%d",&price[i]);
        cnt=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w),add(v,u,w);
        }
        int q;
		scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&V,&st,&ed);
            int ans=bfs();
			if(ans==-1) puts("impossible");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
