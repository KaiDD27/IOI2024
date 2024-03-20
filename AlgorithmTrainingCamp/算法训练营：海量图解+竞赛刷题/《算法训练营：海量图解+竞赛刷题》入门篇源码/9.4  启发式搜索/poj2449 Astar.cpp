#include<cstdio>//204ms 
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1005;
const int maxm=100005;
struct edge{
    int v,w,nxt;
}E[maxm],E2[maxm];
int cnt,head[maxn],cnt2,head2[maxn];

void add(int u,int v,int w){
    E[cnt].v=v;
    E[cnt].w=w;
    E[cnt].nxt=head[u];
    head[u]=cnt++;
    E2[cnt2].v=u;
    E2[cnt2].w=w;
    E2[cnt2].nxt=head2[v];
    head2[v]=cnt2++;
}

struct node{
    int v,d;
    node(){}
    node(int v,int d):v(v),d(d){}
    bool operator < (const node &b) const{
        return d>b.d;
    }
};

int n,m,k,dist[maxn];
bool vis[maxn];

void dijkstra(int s){
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[s]=0;
    priority_queue<node> que;
    que.push(node(s,0));
    while(!que.empty()){
        node p=que.top();
        que.pop();
        int u=p.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head2[u];~i;i=E2[i].nxt){
            int v=E2[i].v,w=E2[i].w;
            if(!vis[v]&&p.d+w<dist[v]) {
                dist[v]=p.d+w;
                que.push(node(v,dist[v]));
            }
        }
    }
}

struct point{
    int v,g,h;
    point(){}
    point(int v,int g,int h):v(v),g(g),h(h){}
    bool operator < (const point & b) const{
        return g+h>b.g+b.h;
    }
};

int times[maxn];

int Astar(int s,int t){
    if(dist[s]==inf) return -1;
    memset(times,0,sizeof(times));
    priority_queue<point> Q;
    Q.push(point(s,0,0));
    while(!Q.empty()){
        point p=Q.top();
        Q.pop();
        int u=p.v;
        times[u]++;
        if(times[u]==k&&u==t)
            return p.g+p.h;
        if(times[u]>k)
            continue;
        for(int i=head[u];~i;i=E[i].nxt)
            Q.push(point(E[i].v,p.g+E[i].w,dist[E[i].v]));
    }
    return -1;
}

int main(){
    int u,v,w,s,t;
    scanf("%d%d",&n,&m);
    cnt=cnt2=0;
    memset(head,-1,sizeof(head));
    memset(head2,-1,sizeof(head2));
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    scanf("%d%d%d",&s,&t,&k);
    if(s==t)//�ӵ㣡
        k++;
    dijkstra(t);
    printf("%d\n",Astar(s,t));
    return 0;
}
