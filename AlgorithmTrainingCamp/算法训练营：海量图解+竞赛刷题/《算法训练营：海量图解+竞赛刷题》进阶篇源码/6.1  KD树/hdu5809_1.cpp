#include<cstdio>//存储型KD树+优先队列+并查集 
#include<queue>
#include<algorithm>
#define sq(x) (x)*(x)
//#define sq(x) (x)*(x)//宏定义默认是int,计算时需要类型转换，否则数据量大会溢出
//也可以使用函数实现ll sq(ll x) {return x*x;}
const int N=100010;
typedef long long ll;
const ll inf=1e18;
using namespace std;
int idx,n,q,k=2,fa[N];
 
struct Node{
    int x[2],id;
    bool operator < (const Node &u) const{
        for(int i=0;i<k;i++)
            if(x[i]!=u.x[i]) return x[i]<u.x[i];
        return 0;
    }
}a[N];
 
typedef pair<ll,Node> PLN;
priority_queue<PLN> que;
 
bool cmp(const Node a,const Node b){
    return a.x[idx]<b.x[idx];
}
 
struct KD_Tree{
    int sz[N<<2];
	Node kd[N<<2];
    ll dis(Node p,Node q){
		ll ret=0;
	    for(int i=0;i<k;i++)
	        ret+=sq((ll)p.x[i]-q.x[i]);//坑点！注意类型转换 
	    return ret?ret:inf;	
	}
	
	void build(int i,int l,int r,int dep){
        if(l>r) return;
        int mid=(l+r)>>1;
        idx=dep%k;
		sz[i]=1;
        sz[i<<1]=sz[i<<1|1]=0;
        nth_element(a+l,a+mid,a+r+1,cmp);
        kd[i]=a[mid];
        build(i<<1,l,mid-1,dep+1);
        build(i<<1|1,mid+1,r,dep+1);
    }
 
	void query(int rt,int m,int dep,Node p){
	    if(!sz[rt]) return;
	    PLN tmp=PLN(dis(kd[rt],p),kd[rt]);
	    int lc=rt<<1,rc=rt<<1|1,dim=dep%k,flag=0;
	    if(p.x[dim]>=kd[rt].x[dim])
			swap(lc,rc);
	    if(sz[lc])
			query(lc,m,dep+1,p);
	    if(que.size()<m)
			que.push(tmp),flag=1;
	    else{
	        if(tmp<que.top())
				que.pop(),que.push(tmp);
	        if(sq((ll)p.x[dim]-kd[rt].x[dim])<=que.top().first)//注意有=号,可能有多个点有相同距离 
				flag=1;
	    }
	    if(sz[rc]&&flag)
			query(rc,m,dep+1,p);
	}
}KDT;
 
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
 
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].x[0],&a[i].x[1]);
            a[i].id=fa[i]=i;
        }
        KDT.build(1,0,n-1,0);
        for(int i=0;i<n;i++){
            KDT.query(1,1,0,a[i]);
            Node tmp=que.top().second;
            int u=find(a[i].id);
            int v=find(tmp.id);
            fa[u]=v;
            while(!que.empty()) que.pop();
        }
        printf("Case #%d:\n",++cas);
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y); x--; y--;//编号从0开始 
            puts(find(x)==find(y)?"YES":"NO");
        }
    }
    return 0;
}
