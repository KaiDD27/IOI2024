#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=405;//注意节点数牛+牛棚
const int M=40500;
int cnt;
int head[N],match[N];
bool vis[N];
struct Edge{
   int v,next;
}E[M<<1];//双边 

void init(){//初始化 
    memset(head,-1,sizeof(head));
    memset(match,0,sizeof(match));
    cnt=0;
}

void add(int u,int v){
    E[cnt].v=v;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

bool Find(int u){
	for(int i=head[u];~i;i=E[i].next){
		int v=E[i].v;
		if(!vis[v]){
			vis[v]=1;
			if(!match[v]||Find(match[v])){
				match[v]=u;
				return true;
			}
		}
    }
    return false;
}

int main(){
    int n,m,k,v;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
	        for(int j=1;j<=k;j++){
				scanf("%d",&v);
	        	add(i,n+v);
			}
    	}
    	int ans=0;
    	for(int i=1;i<=n;i++){
	        memset(vis,0,sizeof(vis));
	        if(Find(i))
	            ans++;
    	}
    	printf("%d\n",ans);
	}
    return 0;
}
