#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=10010,maxe=50010;
int n,m,cnt;
int head[maxn],dis[maxn];//链式前向星头，距离 
int pre[maxn],in[maxn],out[maxn];//前驱，入度，出度 
bool inq[maxn];//标记是否在队列中 
struct node{
	int to,next,w;
}e[maxe];

void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	e[cnt].w=w;	
}

void spfa(int u){
	queue<int>q;
	q.push(u);
	inq[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].to;
			if(dis[y]<dis[x]+e[i].w||(dis[y]==dis[x]+e[i].w&&x<pre[y])){
				dis[y]=dis[x]+e[i].w;
				pre[y]=x;
				if(!inq[y]){
					q.push(y);
					inq[y]=1;
				}
			}
		}
	}
}

int main(){
	int u,v,w,s,t;
	while(cin>>n>>m){
		memset(head,0,sizeof(head));
	    memset(dis,0,sizeof(dis));
	    memset(inq,0,sizeof(inq));
	    memset(in,0,sizeof(in));
	    memset(out,0,sizeof(out));
	    memset(pre,-1,sizeof(pre));
	    cnt=0;
	    for(int i=0;i<m;i++){
	        cin>>u>>v>>w;
	        add(v,u,w);
	        out[v]++;
	        in[u]++;
	    }
	    for(int i=1;i<=n;i++){
	        if(in[i]==0) s=i;
	        if(out[i]==0) t=i;
	    }
	    spfa(s);
	    cout<<dis[t]<<endl;
	    int k=t;
	    while(pre[k]!=-1){
	        cout<<k<<" "<<pre[k]<<endl;
	        k=pre[k];
	    }
	}
	return 0;
}
