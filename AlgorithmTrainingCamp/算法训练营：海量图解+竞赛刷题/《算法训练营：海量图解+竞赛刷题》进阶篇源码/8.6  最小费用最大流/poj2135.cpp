#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
const int M=20005;
int cnt;
int head[N],dist[N],pre[N];//dist[i]��ʾԴ�㵽��i��̾��룬pre[i]��¼ǰ��
bool vis[N];//�������
int maxflow;//�����
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
                    q.push(v);   //���
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
    int n,m,u,v,w;
    while(~scanf("%d %d",&n,&m)){
        init();
        adde(0,1,2,0);//����Դ��0 
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            adde(u,v,1,w);
            adde(v,u,1,w);
        }
        adde(n,n+1,2,0);//���ӻ��n+1 
        printf("%d\n",MCMF(0,n+1));
    }
    return 0;
}
