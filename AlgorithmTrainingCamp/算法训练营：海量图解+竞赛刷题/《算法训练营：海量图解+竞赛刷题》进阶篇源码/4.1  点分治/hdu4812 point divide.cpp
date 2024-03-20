#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")
#define inf 0x3f3f3f3f
#define P 1000003
#define ll long long
using namespace std;
const int maxn=100005;
ll inv[P+5],mp[P+5];//inv存储逆元,mp将乘积映射到节点 
ll val[maxn],d[maxn],dep[maxn];//节点的值，节点到树根的乘积，乘积序列
int cnt,n,k,top,head[maxn],id[maxn];//id[]为节点序列 
int root,S,size[maxn],f[maxn];//f[]为删除u后，最大子树的大小  
bool vis[maxn];
int ans1,ans2;
struct edge{
	int to,next;
}edge[maxn*2];

void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void get_inv(){//求1..P-1的逆元 
	inv[1]=1;
	for(int i=2;i<P;i++)
		inv[i]=((-P/i)*inv[P%i]%P+P)%P;
}

void getroot(int u,int fa){//获取重心
    size[u]=1;
	f[u]=0;//删除u后，最大子树的大小 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v]){
            getroot(v,u);
            size[u]+=size[v];
       		f[u]=max(f[u],size[v]);
        }
	}    
    f[u]=max(f[u],S-size[u]);//S为当前子树总结点数 
    if(f[u]<f[root])
		root=u;
}

void getdep(int u,int fa){//获取乘积 
    dep[++top]=d[u];//保存乘积序列 
    id[top]=u;//保存节点 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
    	if(v!=fa&&!vis[v]){
    		d[v]=(d[u]*val[v])%P;//乘积MOD P 
            getdep(v,u);
		}
    }
}

void query(int x,int id){//积，节点编号 
    x=inv[x]*val[root]*k%P;//求另一顶点的积 
    int y=mp[x];//映射到编号 
    if(y==0) return;
    if(y>id) swap(y,id);//保证id>y 
    if(y<ans1||(y==ans1&&id<ans2))//更新答案为最小编号 
        ans1=y,ans2=id;
}

void solve(int u){ //获取答案
    vis[u]=true;
    mp[val[u]]=u;//值映射到编号 
    for(int i=head[u];i;i=edge[i].next){
    	int v=edge[i].to;
		if(!vis[v]){
			top=0;//先求以v为根的子树 
			d[v]=val[v]*val[u]%P;//当前节点值为初值 
			getdep(v,u);
            for(int j=1;j<=top;j++)//查询完毕再把这些积映射，以便下一个子树查询 
				query(dep[j],id[j]);//第一个子树查询时，只有树根有映射，由此保证不会在一棵子树内部查询，因为这些节点还没有映射 
            for(int j=1;j<=top;j++)
                if(!mp[dep[j]]||mp[dep[j]]>id[j])//0或id[j]比原来的值映射小 
					mp[dep[j]]=id[j];
        }
    }
	mp[val[u]]=0;//刚才赋值的mp[]清零，用memset超时 
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]){
            top=0;
			d[v]=(val[u]*val[v])%P;
            getdep(v,u);
            for(int j=1;j<=top;j++)
                mp[dep[j]]=0;
        }
	}
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
        if(!vis[v]){
            root=0;
			S=size[v];
            getroot(v,0);
            solve(root);
        }
	}
}

int main(){
	int u,v;
	get_inv();//求1..P-1的逆元 
	while(~scanf("%d%d",&n,&k)){
        memset(vis,0,sizeof(vis));
        cnt=0;
		ans1=ans2=inf;
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        root=0;S=n;f[0]=n+1;
        getroot(1,0);
        solve(root);
        if(ans1==inf)
			printf("No solution\n");
        else
			printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
