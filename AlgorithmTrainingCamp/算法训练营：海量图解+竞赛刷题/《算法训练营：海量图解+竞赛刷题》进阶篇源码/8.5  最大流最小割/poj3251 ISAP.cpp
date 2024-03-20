#include<cstdio>//ISAP 1279ms,Dinic 1326ms,Dinic2 1248ms
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1010;
const int M=101010;
int cnt,tot;
int head[N],ans[N],pre[N],h[N],g[N];
bool vis[N];
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

void set_h(int t){//标高 
    queue<int> q;
    memset(h,-1,sizeof(h));
    memset(g,0,sizeof(g));
    h[t]=0;
    q.push(t);
    while(!q.empty()){
		int u=q.front();q.pop();
		++g[h[u]];//高度为h[u]的节点个数
		for(int i=head[u];~i;i=E[i].next){
			int v=E[i].v;
			if(h[v]==-1){
				h[v]=h[u]+1;
				q.push(v);
			}
        }
    }
}

int ISAP(int s,int t,int n){
    set_h(t);
    int ans=0,u=s,d;
    while(h[s]<n){
        int i=head[u];
        if(u==s)
           d=inf;
        for(;~i;i=E[i].next){
			int v=E[i].v;
			if(E[i].cap>E[i].flow&&h[u]==h[v]+1){
				u=v;
                pre[v]=i;
                d=min(d,E[i].cap-E[i].flow);
                if(u==t){
					while(u!=s){
						int j=pre[u];
						E[j].flow+=d;
						E[j^1].flow-=d;
						u=E[j^1].v;
					}
					ans+=d;
					d=inf;
                }
                break;
            }
        }
        if(i==-1){
			if(--g[h[u]]==0)
				break;
			int hmin=n-1;
			for(int j=head[u];~j;j=E[j].next)
				if(E[j].cap>E[j].flow)
					hmin=min(hmin,h[E[j].v]);
			h[u]=hmin+1;
			++g[h[u]];
			if(u!=s)
				u=E[pre[u]^1].v;
        }
    }
    return ans;
}

void dfs(int u){
    for(int i=head[u];~i;i=E[i].next){
        int v=E[i].v;
        if(!vis[v]&&E[i].cap>E[i].flow){
		    vis[v]=1;
        	dfs(v);
    	}
    }
}

int main(){
	int T,n,m,f,u,v,w,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&f);
        int s=1,t=n+1;
		init();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            adde(u,v,w);
        }
        int tot=0;
        for(int i=1;i<=f;i++){
            scanf("%d%d",&u,&w);
            tot+=w;
            adde(u,t,w);
        }
        printf("Case %d: %d\n",++cas,tot-ISAP(s,t,t));
        memset(vis,0,sizeof(vis));
        vis[s]=true;
        dfs(s);
        tot=0;
        for(int i=0;i<2*m;i+=2){
            int u=E[i^1].v,v=E[i].v;
            if(vis[u]&&!vis[v])
				ans[tot++]=i/2;
        }
        printf("%d",tot);
        for(int i=0;i<tot;i++)
			printf(" %d",ans[i]+1);
        printf("\n");
	}
    return 0 ;
}
