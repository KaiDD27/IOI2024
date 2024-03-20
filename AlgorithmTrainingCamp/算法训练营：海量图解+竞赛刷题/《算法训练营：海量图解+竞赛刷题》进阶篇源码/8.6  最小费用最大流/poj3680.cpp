#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=410;
const int M=1010;
int cnt;
int head[N],dist[N],pre[N];//dist[i]��ʾԴ�㵽��i��̾��룬pre[i]��¼ǰ��
bool vis[N];
int a[N],b[N],c[N],maxflow;
struct Edge{
   int v,next;
   int cap,flow,cost;
}E[M<<1];

void init(){//��ʼ�� 
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int c,int cost){
    E[cnt].v=v;
    E[cnt].cap=c;
    E[cnt].flow=0;
    E[cnt].cost=cost;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

void adde(int u,int v,int c,int cost){
    add(u,v,c,cost);
    add(v,u,0,-cost);
}

bool SPFA(int s,int t){//����̷���·��SPFA
    queue<int> q;
    memset(vis,false,sizeof(vis));//���ʱ�ǳ�ʼ��
    memset(pre,-1,sizeof(pre)); //ǰ����ʼ��
    memset(dist,0x3f,sizeof(dist));
    vis[s]=true; //�������visҪ�����
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false; //��ͷԪ�س��ӣ��������
        for(int i=head[u];~i;i=E[i].next){
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){//�ɳڲ���
                dist[v]=dist[u]+E[i].cost;
                pre[v]=i; //��¼ǰ��
                if(!vis[v]){ //����v���ڶ���
                    q.push(v);//���
                    vis[v]=true; //���
                }
            }
        }
    }
    return pre[t]!=-1;
}

int MCMF(int s,int t){
    int d=0;//��������
    int mincost=0;//maxflow��ǰ���������mincost��ǰ��С����
    while(SPFA(s,t)){
        d=inf;
        for(int i=pre[t];~i;i=pre[E[i^1].v])//����С��������
            d=min(d,E[i].cap-E[i].flow); 
        for(int i=pre[t];~i;i=pre[E[i^1].v]){//�޸Ĳ������磬��������·����Ӧ�����������������䷴�������
            E[i].flow+=d;
            E[i^1].flow-=d;
        }
		maxflow+=d; //���������
        mincost+=dist[t]*d;//dist[t]Ϊ��·���ϵ�λ��������֮�� ����С���ø���
	}
    return mincost;
}

int main(){
	int n,k,T,num[N];
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&k);
		int m=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			num[m++]=a[i];
			num[m++]=b[i];
		}
		sort(num,num+m);//���� 
		m=unique(num,num+m)-num;//ȥ�� 
		int s=0,t=m+1;
//		adde(s,1,k,0);//Դ�㵽1��һ���ߣ�����Ϊk,����Ϊ0 
//		adde(m,t,k,0);//m������һ���ߣ�����Ϊk,����Ϊ0
//		������������������for�����
		for(int i=0;i<=m;i++)
			adde(i,i+1,k,0);//i��i+1��һ���ߣ�����Ϊk,����Ϊ0 
		for(int i=0;i<n;i++){
			int u=lower_bound(num,num+m,a[i])-num+1;//��ɢ�� 
			int v=lower_bound(num,num+m,b[i])-num+1;
			adde(u,v,1,-c[i]);//a[i]��b[i]��һ���ߣ�����Ϊ1,����Ϊ-c[i] 
		}
		printf("%d\n",-MCMF(s,t));
	}
	return 0;
}
