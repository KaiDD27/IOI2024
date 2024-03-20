#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=110;
const int M=10100;
int n,m;
int cnt;
int head[N],pre[N],h[N],g[N];
int num[N];
int input[N][20],output[N][20];
int vis[N][N];
struct Edge{
   int v,next;
   int cap,flow;
}E[M<<1];//双边

void init(){//初始化 
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof vis);
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

bool check(int x,int y){
    return x==y||y==2;
}

bool ck1(int d){ //没有1
    for(int i=1;i<=n;i++)
        if(input[d][i]==1) return false;
    return true;
}

bool ck2(int d){ //全1
    for(int i=1;i<=n;i++)
        if(output[d][i]!=1) return false;
    return true;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=m;i++){
            scanf("%d",&num[i]);
            for(int j=1;j<=n;j++)
                scanf("%d",&input[i][j]);
            for(int j=1;j<=n;j++)
                scanf("%d",&output[i][j]);
        }
        init();
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++){
                if(i==j) continue;
                bool flag=true;
                for(int k=1;k<=n;k++)
                    if(!check(output[i][k],input[j][k])){
                        flag=false;
                        break;
                    }
                if(flag){
                    adde(i+m,j,num[i]);
                    vis[i+m][j]=1;
                }
            }
        for(int i=1;i<=m;i++){
            adde(i,i+m,num[i]);//拆点
            if(ck1(i)) adde(0,i,num[i]);
            if(ck2(i)) adde(i+m,2*m+1,num[i]);
        }
        printf("%d",ISAP(0,2*m+1,2*m+2));
        int cnt=0;
        for(int i=1;i<=m;i++)
            for(int j=head[i+m];~j;j=E[j].next)
                if(vis[i+m][E[j].v]&&E[j].flow>0) cnt++;//连接数 
        printf(" %d\n",cnt);
        for(int i=1;i<=m;i++)
            for(int j=head[i+m];~j;j=E[j].next)
                if(vis[i+m][E[j].v]&&E[j].flow>0)
                    printf("%d %d %d\n",i,E[j].v,E[j].flow);//机器A B flow 
    }
	return 0;
}
