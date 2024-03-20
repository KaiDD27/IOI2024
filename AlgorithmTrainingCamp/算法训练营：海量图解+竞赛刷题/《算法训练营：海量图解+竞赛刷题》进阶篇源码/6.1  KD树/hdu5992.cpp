#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
#define sq(x) (x)*(x)
typedef long long ll;
const int maxn=200000+10;
using namespace std;

int idx;
struct Node{
    int x[3];
    int id; //输入序号 
    bool operator<(const Node &b)const{
        return x[idx]<b.x[idx];
    }
}a[maxn],kd[maxn<<2];
int sz[maxn<<2];
typedef pair<ll,Node> PLN;
PLN res;

void build(int rt,int l,int r,int dep){
    if(l>r) return;
    sz[rt]=1;
    sz[rt<<1]=sz[rt<<1|1]=0;
    idx=dep%2;//注意只按二维建树 
    int mid=(l+r)>>1;
    nth_element(a+l,a+mid,a+r+1);
    kd[rt]=a[mid];
    build(rt<<1,l,mid-1,dep+1);
    build(rt<<1|1,mid+1,r,dep+1);
}

ll dis(int rt,Node p){//求距离二维
    return sq((ll)p.x[0]-kd[rt].x[0])+sq((ll)p.x[1]-kd[rt].x[1]);
}

void query(int rt,Node p,int dep){
    if(!sz[rt]) return;
	PLN cur=PLN(dis(rt,p),kd[rt]);
	int lc=rt<<1,rc=rt<<1|1,dim=dep%2,flag=0;
    if(p.x[dim]>=kd[rt].x[dim])
        swap(lc,rc);
    if(sz[lc])
        query(lc,p,dep+1);
    if(res.first==-1){//第一个
        if(cur.second.x[2]<=p.x[2])
            res=cur;
        flag=1;
    }
    else{
        if(cur.second.x[2]<=p.x[2]&&(cur.first<res.first||(cur.first==res.first&&cur.second.id<res.second.id)))
        	res=cur;
        if((ll)sq(kd[rt].x[dim]-p.x[dim])<=res.first)
            flag=1;
    }
    if(sz[rc]&&flag)
        query(rc,p,dep+1);
}

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            for(int j=0;j<3;++j)
                scanf("%d",&a[i].x[j]);
            a[i].id=i;
        }
        build(1,0,n-1,0);
        while(m--){
            Node p,ans;
            for(int i=0;i<3;++i)
                scanf("%d",&p.x[i]);
            res.first=-1;
            query(1,p,0);
            ans=res.second;
            printf("%d %d %d\n",ans.x[0],ans.x[1],ans.x[2]);
        }
    }
    return 0;
}
