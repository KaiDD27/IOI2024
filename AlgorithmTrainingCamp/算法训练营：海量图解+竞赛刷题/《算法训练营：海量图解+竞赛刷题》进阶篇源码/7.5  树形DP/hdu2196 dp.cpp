#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000+10;
int dp[MAXN][3];
int idx[MAXN];
struct Edge{
    int v,w,next;
}edge[MAXN<<1];
int cnt,head[MAXN];

void add(int u,int v,int w){
    edge[cnt].v=v;
	edge[cnt].w=w;
    edge[cnt].next=head[u];
	head[u]=cnt++;
}

void dfs1(int u,int fa){
    int mx1=0,mx2=0;//最大值，次大值 
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        int c=dp[v][0]+edge[i].w;
        if(mx1<=c) mx2=mx1,mx1=c,idx[u]=v;
        else if(mx2<c) mx2=c;
    }
    dp[u][0]=mx1;
	dp[u][1]=mx2;
}

void dfs2(int u,int fa){
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        if(idx[u]==v)
			dp[v][2]=max(dp[u][1]+edge[i].w,dp[u][2]+edge[i].w);
        else
			dp[v][2]=max(dp[u][0]+edge[i].w,dp[u][2]+edge[i].w);
        dfs2(v,u);
    }
}

int main(){
    int n,a,b;
    while(~scanf("%d",&n)){
        cnt=0;
        memset(head,-1,sizeof(head));
        for(int i=2;i<=n;i++){
            scanf("%d%d",&a,&b);
            add(i,a,b); add(a,i,b);
        }
        memset(dp,0,sizeof(dp));
        dfs1(1,1);
        dfs2(1,1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
