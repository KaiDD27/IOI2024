#include<iostream>//25ms
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=10010;
const int M=10010;
int n,m,s,t,cnt,sum=0;
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

void readin(){//��ͼ 
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
		while(sscanf(c+ulen,"%d",&num)==1){//ulenΪ�Ѷ�ȡ����
			adde(i,n+num,inf);
			if(num==0) ulen++;
			else while(num){
					num/=10;
					ulen++;
				}
			ulen++;//���Ͽո�
		}
	}
	for(int i=1;i<=m;i++){
		int v;
		scanf("%d",&v);
		adde(i+n,t,v);
	}
}

void print(){
	for(int i=1;i<=n;i++)//���һ��bfs���ܹ���Դ������cap>flow����õ��ֲ�Ľڵ㶼����S���� 
		if(d[i]) printf("%d ",i);
	printf("\n");
	for(int j=1;j<=m;j++)
		if(d[j+n]) printf("%d ",j);
	printf("\n");
}

int main() {
	readin();
	int ans=Dinic(s,t);
	print();
	printf("%d\n",sum-ans);
	return 0;
}
