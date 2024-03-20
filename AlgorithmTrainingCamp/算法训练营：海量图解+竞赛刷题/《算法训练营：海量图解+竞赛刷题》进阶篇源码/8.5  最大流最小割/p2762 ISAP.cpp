#include<iostream>//32ms
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=10010;
const int M=10010;
int n,m,s,t,cnt,sum=0;
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

void readin() {	//建图 
	init();
	char c[N];
	scanf("%d%d",&n,&m);
	s=0,t=n+m+1;
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		sum+=v;
		adde(s,i,v);
		memset(c,0,sizeof(c));
		cin.getline(c,N);
		int ulen=0,num;
		while(sscanf(c+ulen,"%d",&num)==1) {
			adde(i,n+num,inf);
			if(num==0) ulen++;
			else while(num){
					num/=10;
					ulen++;
				}
			ulen++;
		}
	}
	for(int i=1;i<=m;i++){
		int v;
		scanf("%d",&v);
		adde(i+n,t,v);
	}
}

void print(){
	for(int i=1;i<=n;i++)//dfs，能够从源点沿着cap>flow到达节点都属于S集合 
		if(vis[i]) printf("%d ",i);
	printf("\n");
	for(int j=1;j<=m;j++)
		if(vis[j+n]) printf("%d ",j);
	printf("\n");
}

int main() {
	readin();
	int ans=ISAP(s,t,t+1);
	memset(vis,0,sizeof(vis));
    dfs(s);
	print();
	printf("%d\n",sum-ans);
	return 0;
}
