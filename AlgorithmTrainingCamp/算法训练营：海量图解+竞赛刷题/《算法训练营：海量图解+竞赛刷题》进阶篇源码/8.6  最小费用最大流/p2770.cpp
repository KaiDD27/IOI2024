#include<iostream>//53ms
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100;
const int M=10000;
int cnt;
int head[N],dist[N],pre[N];//dist[i]��ʾԴ�㵽��i��̾��룬pre[i]��¼ǰ��
bool vis[N];//�������
int maxflow,mincost;//maxflow ��ǰ���������mincost��ǰ��С����
string str[M];
map<string,int> maze;
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
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    memset(dist,0x3f,sizeof(dist));
    vis[s]=true;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];~i;i=E[i].next){
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){//�ɳڲ���
                dist[v]=dist[u]+E[i].cost;
                pre[v]=i;//��¼ǰ��
                if(!vis[v]){ //����v���ڶ���
                    q.push(v);  //���
                    vis[v]=true; //���
                }
            }
        }
    }
	return pre[t]!=-1;
}

int MCMF(int s,int t){ //minCostMaxFlow
    int d=0;//��������
    maxflow=mincost=0;
    while(SPFA(s,t)){//��ʾ�ҵ��˴�s��t�����·
        d=inf;
        for(int i=pre[t];~i;i=pre[E[i^1].v])
            d=min(d,E[i].cap-E[i].flow); //����С��������
        maxflow+=d; //���������
        for(int i=pre[t];~i;i=pre[E[i^1].v]){//�޸Ĳ������磬��������·����Ӧ�����������������䷴�������
            E[i].flow+=d;
            E[i^1].flow-=d;
        }
        mincost+=dist[t]*d; //dist[t]Ϊ��·���ϵ�λ��������֮�� ����С���ø���
	}
    return maxflow;
}

void print(int s,int t){
    int v;
    vis[s]=1;
    for(int i=head[s];~i;i=E[i].next){
    	if(!vis[v=E[i].v]&&((E[i].flow>0&&E[i].cost<=0)||(E[i].flow<0&&E[i].cost>=0))){
			print(v,t);
			if(v<=t)
				cout<<str[v]<<endl;
		}	
	}
}

int main(){
	int n,m;
    string str1,str2;
    cin>>n>>m;
    init();//��ʼ��
    maze.clear();
    for(int i=1;i<=n;i++){
		cin>>str[i];
		maze[str[i]]=i;
		if(i==1||i==n)
			adde(i,i+n,2,0);
		else
			adde(i,i+n,1,0);
    }
    for(int i=1;i<=m;i++){
        cin>>str1>>str2;
        int a=maze[str1],b=maze[str2];
        if(a<b){
			if(a==1&&b==n)
				adde(a+n,b,2,-1);
			else
				adde(a+n,b,1,-1);
        }
        else{
			if(b==1&&a==n)
				adde(b+n,a,2,-1);
			else
				adde(b+n,a,1,-1);
        }
    }
    if(MCMF(1,2*n)==2){//����
		cout<<-mincost<<endl;
		cout<<str[1]<<endl;
		memset(vis,0,sizeof(vis));//���ʱ�ǳ�ʼ��
		print(1,n);
		cout<<str[1]<<endl;
    }
    else
		cout<<"No Solution!"<<endl;
    return 0;
}
