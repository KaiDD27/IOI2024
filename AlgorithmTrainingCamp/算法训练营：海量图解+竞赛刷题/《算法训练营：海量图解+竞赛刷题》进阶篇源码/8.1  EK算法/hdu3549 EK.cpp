#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=20;
const int M=1005;
int cnt;
int head[N],pre[N];
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

bool bfs(int s,int t){
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    queue<int>q;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=E[i].next){
        	int v=E[i].v;
        	if(!vis[v]&&E[i].cap>E[i].flow){
                vis[v]=1;
                pre[v]=i;//���±� 
				q.push(v);
				if(v==t)  return 1;//�ҵ�һ��������·
			}	
		}
    }
    return 0;
}

int EK(int s,int t){
    int maxflow=0;
    while(bfs(s,t)){
    	int v=t,d=inf;
    	while(v!=s){//�ҿ�����
            int i=pre[v];
			d=min(d,E[i].cap-E[i].flow);
			v=E[i^1].v;
        }
		maxflow+=d;
		v=t;
        while(v!=s){//�ؿ�����·����
            int i=pre[v];
			E[i].flow+=d;
			E[i^1].flow-=d;
			v=E[i^1].v;
        }
    }
    return maxflow;
}

int main(){
    int T,n,m,u,v,w,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
	        scanf("%d%d%d",&u,&v,&w);
	        add(u,v,w);
			add(v,u,0);
    	}
    	printf("Case %d: %d\n",cas++,EK(1,n));
	}
    return 0;
}
