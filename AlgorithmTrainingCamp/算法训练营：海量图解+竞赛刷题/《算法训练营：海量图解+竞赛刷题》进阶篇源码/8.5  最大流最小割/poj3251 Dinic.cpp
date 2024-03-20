#include<cstdio>//ISAP 1279ms,Dinic 1326ms,Dinic2 1248ms��ǰ���Ż�
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1010;
const int M=101010;
int cnt,tot;
int head[N],d[N],ans[N];
bool vis[N];
struct Edge{
   int v,next;
   int cap,flow;
}E[M<<1];//˫��

void init(){//��ʼ�� 
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

bool bfs(int s,int t){//�ֲ�
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

int dfs(int u,int flow,int t){//�ڷֲ�Ļ�����dfs 
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
        printf("Case %d: %d\n",++cas,tot-Dinic(s,t));
        tot=0;
        for(int i=0;i<2*m;i+=2){//ע����0~2m����������Ȩ�����ıߣ�ÿ����2 
            int u=E[i^1].v,v=E[i].v;
            if(d[u]&&!d[v])//���һ��bfs,d[]Ϊ�������S���� 
				ans[tot++]=i/2;
        }
        printf("%d",tot);
        for(int i=0;i<tot;i++)
			printf(" %d",ans[i]+1);
        printf("\n");
	}
    return 0 ;
}
