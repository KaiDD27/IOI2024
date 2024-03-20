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
int head[N],dist[N],pre[N];//dist[i]表示源点到点i最短距离，pre[i]记录前驱
bool vis[N];//标记数组
int G[N][N],q[N],num[N],shelter[N];
struct node{
	int x,y,p;
}a[N],b[N];

struct Edge{
   int v,next;
   int cap,flow,cost;
}E[M<<1];

void init(){//初始化 
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
    memset(vis,true,sizeof(vis));//inq是bool类型的数组，每个元素占1字节，所以可以这样
    memset(pre,-1,sizeof(pre));
    for(int i=s;i<=t;i++)
        q[++r]=i;
    while(f<=r){
        int u=q[r--];//栈式写法，r--改成f++就是队列了，队列要将数组扩大。
        vis[u]=false;//实际测试中，用栈比队列判断负圈效率更高
        for(int i=head[u];~i;i=E[i].next){
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){//松弛操作
                dist[v]=dist[u]+E[i].cost;
                pre[v]=i; //记录前驱
                if(!vis[v]){ //顶点v不在队内
                    q[++r]=v;
                    vis[v]=true; //标记
                    if(++num[v]>t+1)
                    	return v;
                }
			}
		} 
    }
    return -1;
}

int dis(node p1,node p2){//曼哈顿距离+1 
    return abs(p1.x-p2.x)+abs(p1.y-p2.y)+1;
}

int main(){
    int n,m,s,t,p;
    scanf("%d%d",&n,&m);
    s=0,t=n+m+1;
    init();
    for(int i=0;i<n;i++){//读入大楼位置人数 
	    scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].p);
	    adde(s,i+1,a[i].p,0,a[i].p);//源点到大楼，容量a[i].p，费用0，流量a[i].p
	}
	for(int j=0;j<m;j++)//读入防空洞位置人数 
	    scanf("%d%d%d",&b[j].x,&b[j].y,&b[j].p);
    memset(shelter,0,sizeof(shelter));
	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++){
    		scanf("%d",&p);
    		shelter[j]+=p;
    		adde(i+1,n+j+1,inf,dis(a[i],b[j]),p);//大楼到防空洞,容量inf，费用两者曼哈顿距离+1，流量p
		}
	for(int j=0;j<m;j++)
        adde(n+j+1,t,b[j].p,0,shelter[j]);//防空洞到汇点，容量b[i].p，费用0，流量shelter[i]
	int k=negative_loop(s,t);
	if(k!=-1){
		printf("SUBOPTIMAL\n");
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		for(int i=pre[k];!vis[E[i].v];i=pre[E[i^1].v]){//往前找负环 
			vis[E[i].v]=true;
			k=E[i].v;
		}
		for(int i=pre[k];;i=pre[E[i^1].v]){//在负环中增加1个流量 
			E[i].flow++;
			E[i^1].flow--;
			if(E[i^1].v==k) break;
		}
		for(int i=0;i<cnt;i++){
            if(E[i^1].v>0&&E[i^1].v<=n&&E[i].v>n&&E[i].v<=n+m)
 				G[E[i^1].v-1][E[i].v-n-1]=E[i].flow;
        }
        for(int i=0;i<n;i++){//输出结果 
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
