#include<cstdio>
#include<queue>
#include<algorithm>
#define sq(x) (x)*(x)
#define N 50010
typedef long long ll;
using namespace std;
int n,k,t,m,idx;

struct Node{
    int x[5];
    bool operator < (const Node &b) const{
        return x[idx]<b.x[idx];
    }
}a[N];
 
typedef pair<ll,Node> PLN;
priority_queue<PLN> que;

struct KD_Tree{
    int sz[N<<2];
	Node kd[N<<2];
    void build(int rt,int l,int r,int dep){
        if(l>r) return;
        int mid=(l+r)>>1;
        idx=dep%k;
		sz[rt]=1;
        sz[rt<<1]=sz[rt<<1|1]=0;
        nth_element(a+l,a+mid,a+r+1);
        kd[rt]=a[mid];
        build(rt<<1,l,mid-1,dep+1);
        build(rt<<1|1,mid+1,r,dep+1);
    }
 
    void query(int rt,int m,int dep,Node p){
        if(!sz[rt]) return;
        PLN tmp=PLN(0,kd[rt]);
        for(int j=0;j<k;j++)
            tmp.first+=sq((ll)tmp.second.x[j]-p.x[j]);
        int lc=rt<<1,rc=rt<<1|1,dim=dep%k,flag=0;
        if(p.x[dim]>=kd[rt].x[dim])
			swap(lc,rc);
        if(sz[lc])
			query(lc,m,dep+1,p);
        if(que.size()<m)
			que.push(tmp),flag=1;
        else{
            if(tmp.first<que.top().first)//大顶堆，保存最邻近的m个点 
				que.pop(),que.push(tmp);
            if(sq((ll)p.x[dim]-kd[rt].x[dim])<que.top().first)
				flag=1;
        }
        if(sz[rc]&&flag)
			query(rc,m,dep+1,p);
    }
}KDT;
 
int main(){
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
                scanf("%d",&a[i].x[j]);
        KDT.build(1,0,n-1,0);
        scanf("%d",&t);
        while(t--){
            Node p;
            for(int i=0;i<k;i++)
                scanf("%d",&p.x[i]);
            scanf("%d",&m);
            KDT.query(1,m,0,p);
			Node tmp[15];
            for(int i=0;!que.empty();que.pop())//大顶堆暂存到数组，逆序输出 
                tmp[++i]=que.top().second;
            printf("the closest %d points are:\n",m);
            for(int i=m;i>0;i--){//逆序输出
                printf("%d",tmp[i].x[0]);
                for(int j=1;j<k;j++)
                    printf(" %d",tmp[i].x[j]);
                puts("");
            }
        }
    }
    return 0;
}
