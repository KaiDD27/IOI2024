#include<cstdio>//ʹ��scanf����94ms,ʹ��cin����907ms 
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=110;
const int M=10100;
int cnt;
int head[N],d[N];
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
    int n,np,nc,m,u,v,w;
	char ch;
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m)){
        init();
        for(int i=1;i<=m;i++){//"%*6c"���Ǻſ������Ϊ��ֵ�����ַ�������ʾ�ӻ�������ȡ6���ַ������ǲ���ֵ(Ҳ����˵����д������������)�� 
			scanf("%*1s%d%*1s%d%*1s%d",&u,&v,&w);//%*1s��ʾ���Ե�һ���ַ����͵�������
            adde(u,v,w);
        }
        for(int i=1;i<=np;i++){
			scanf("%*1s%d%*1s%d",&v,&w); 
            adde(n+1,v,w);
        }
        for(int i=1;i<=nc;i++){
            scanf("%*1s%d%*1s%d",&u,&w); 
            adde(u,n+2,w);
        }
        printf("%d\n",Dinic(n+1,n+2));
    }
    return 0;
}
