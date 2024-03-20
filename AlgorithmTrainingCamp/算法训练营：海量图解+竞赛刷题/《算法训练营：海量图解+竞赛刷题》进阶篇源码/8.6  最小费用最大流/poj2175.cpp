#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=205;
const int M=40410;
int cnt;
int head[N],dist[N],pre[N];//dist[i]��ʾԴ�㵽��i��̾��룬pre[i]��¼ǰ��
bool vis[N];//�������
int G[N][N],q[N],num[N],shelter[N];
struct node{
	int x,y,p;
}a[N],b[N];

struct Edge{
   int v,next;
   int cap,flow,cost;
}E[M<<1];

void init(){//��ʼ�� 
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int c,int cost,int flow){
    E[cnt].v=v;
    E[cnt].cap=c;
    E[cnt].flow=flow;
    E[cnt].cost=cost;
    E[cnt].next=head[u];
    head[u]=cnt++;
}

void adde(int u,int v,int c,int cost,int flow){
    add(u,v,c,cost,flow);
    add(v,u,0,-cost,-flow);
}

int negative_loop(int s,int t){
    int f,r,top=-1;
    f=0;r=-1;
    memset(num,0,sizeof(num));
    memset(dist,0,sizeof(dist));
    memset(vis,true,sizeof(vis));//inq��bool���͵����飬ÿ��Ԫ��ռ1�ֽڣ����Կ�������
    memset(pre,-1,sizeof(pre));
    for(int i=s;i<=t;i++)
        q[++r]=i;
    while(f<=r){
        int u=q[r--];//ջʽд����r--�ĳ�f++���Ƕ����ˣ�����Ҫ����������
        vis[u]=false;//ʵ�ʲ����У���ջ�ȶ����жϸ�ȦЧ�ʸ���
        for(int i=head[u];~i;i=E[i].next){
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){//�ɳڲ���
                dist[v]=dist[u]+E[i].cost;
                pre[v]=i; //��¼ǰ��
                if(!vis[v]){ //����v���ڶ���
                    q[++r]=v;
                    vis[v]=true; //���
                    if(++num[v]>t+1)
                    	return v;
                }
			}
		} 
    }
    return -1;
}

int dis(node p1,node p2){//�����پ���+1 
    return abs(p1.x-p2.x)+abs(p1.y-p2.y)+1;
}

int main(){
    int n,m,s,t,p;
    scanf("%d%d",&n,&m);
    s=0,t=n+m+1;
    init();
    for(int i=0;i<n;i++){//�����¥λ������ 
	    scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].p);
	    adde(s,i+1,a[i].p,0,a[i].p);//Դ�㵽��¥������a[i].p������0������a[i].p
	}
	for(int j=0;j<m;j++)//������ն�λ������ 
	    scanf("%d%d%d",&b[j].x,&b[j].y,&b[j].p);
    memset(shelter,0,sizeof(shelter));
	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++){
    		scanf("%d",&p);
    		shelter[j]+=p;
    		adde(i+1,n+j+1,inf,dis(a[i],b[j]),p);//��¥�����ն�,����inf���������������پ���+1������p
		}
	for(int j=0;j<m;j++)
        adde(n+j+1,t,b[j].p,0,shelter[j]);//���ն�����㣬����b[i].p������0������shelter[i]
	int k=negative_loop(s,t);
	if(k!=-1){
		printf("SUBOPTIMAL\n");
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		for(int i=pre[k];!vis[E[i].v];i=pre[E[i^1].v]){//��ǰ�Ҹ��� 
			vis[E[i].v]=true;
			k=E[i].v;
		}
		for(int i=pre[k];;i=pre[E[i^1].v]){//�ڸ���������1������ 
			E[i].flow++;
			E[i^1].flow--;
			if(E[i^1].v==k) break;
		}
		for(int i=0;i<cnt;i++){
            if(E[i^1].v>0&&E[i^1].v<=n&&E[i].v>n&&E[i].v<=n+m)
 				G[E[i^1].v-1][E[i].v-n-1]=E[i].flow;
        }
        for(int i=0;i<n;i++){//������ 
            for(int j=0;j<m;j++){
                if(j) printf(" ");
                printf("%d",G[i][j]);
            }
            printf("\n");
        }
	}
	else
		printf("OPTIMAL\n");
    return 0;
}
