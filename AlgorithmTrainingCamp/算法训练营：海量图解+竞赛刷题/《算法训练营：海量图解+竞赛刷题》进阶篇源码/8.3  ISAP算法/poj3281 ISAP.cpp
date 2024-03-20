#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=410;
const int M=20500;
int cnt;
int head[N],pre[N],h[N],g[N];
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

void set_h(int t,int n){//标高 
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
    set_h(t,n);
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

int main(){
    int n,f,d,k,x,y;
	scanf("%d%d%d",&n,&f,&d);
	int s=0,t=f+2*n+d+1;
	init();
	for(int i=1;i<=f;i++)//源点到食物连边 
        adde(s,i,1);
    for(int i=1;i<=n;i++)//牛到牛拆点连边 
        adde(f+i,f+n+i,1);  
    for(int i=1;i<=d;i++)//饮料到汇点连边 
        adde(f+2*n+i,t,1);
    for(int i=1;i<=n;i++){
    	scanf("%d%d",&x,&y);
    	for(int j=1;j<=x;j++){//食物到牛入点连边 
        	scanf("%d",&k);
			adde(k,f+i,1);
		}
		for(int j=1;j<=y;j++){//牛出点到饮料连边 
        	scanf("%d",&k);
			adde(f+n+i,f+2*n+k,1);
		}
	}
	printf("%d\n",ISAP(s,t,t+1));
	return 0;
}
