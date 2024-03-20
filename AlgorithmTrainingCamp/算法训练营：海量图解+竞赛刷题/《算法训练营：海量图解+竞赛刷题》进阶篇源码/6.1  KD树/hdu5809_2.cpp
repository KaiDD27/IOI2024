#include<cstdio>//非存储型KD树+并查集
#include<queue>
#include<algorithm>
#define sq(x) (x)*(x)
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
PLN ans;
bool cmp(const Node a,const Node b){
    return a.x[idx]<b.x[idx];
}
 
struct KD_Tree{
	ll dis(Node p,Node q){
		ll ret=0;
	    for(int i=0;i<k;i++)
	        ret+=sq((ll)p.x[i]-q.x[i]);//坑点！注意类型转换 
	    return ret?ret:inf+1;	
	}
	
	void build(int l,int r,int dep){
	    if(l>r)
	        return;
	    int mid=(l+r)>>1;
	    idx=dep%k;
	    nth_element(a+l,a+mid,a+r+1,cmp);
	    build(l,mid-1,dep+1);
	    build(mid+1,r,dep+1);
	}

	void query(int l,int r,int dep,Node p){
	    if(l>r) return;
	    int mid=(l+r)>>1,dim=dep%k;	
	    PLN tmp=PLN(dis(a[mid],p),a[mid]);
	    if(tmp<ans)
	    	ans=tmp;
		ll rd=sq((ll)p.x[dim]-a[mid].x[dim]);
		if(p.x[dim]<a[mid].x[dim]){
			query(l,mid-1,dep+1,p);
	    	if(rd<=ans.first)//注意有=号
	    		query(mid+1,r,dep+1,p);
		}
		else{
			query(mid+1,r,dep+1,p);
	    	if(rd<=ans.first)
	    		query(l,mid-1,dep+1,p);
		}	
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
        KDT.build(0,n-1,0);
        for(int i=0;i<n;i++){
           	ans.first=inf;
			KDT.query(0,n-1,0,a[i]);
			Node tmp=ans.second;
            int u=find(a[i].id);
            int v=find(tmp.id);
            fa[u]=v;
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
