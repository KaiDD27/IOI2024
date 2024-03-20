#include<cstdio>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
struct node{
    int l,r;
    ll val,lazy;
}t[N<<2];
int n,m,l,r;
ll x;
char c[2];

void build(int x,int l,int r){//建树
    t[x].l=l;t[x].r=r;
    if(l==r){
        scanf("%lld",&t[x].val);
        return;
    }
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    t[x].val=t[x*2].val+t[x*2+1].val;
}

void pushdown(int x){//下传标记
    if(t[x].lazy){
        t[x*2].lazy+=t[x].lazy;
        t[x*2].val+=t[x].lazy*(t[x*2].r-t[x*2].l+1);
        t[x*2+1].lazy+=t[x].lazy;
        t[x*2+1].val+=t[x].lazy*(t[x*2+1].r-t[x*2+1].l+1);
        t[x].lazy=0;
    }
}
void update(int x,int l,int r,ll num){//区间修改
    if(t[x].l==l&&t[x].r==r){
        t[x].val+=num*(t[x].r-t[x].l+1);
        t[x].lazy+=num;
        return;
    }
    pushdown(x);//下传懒标记 
    int mid=(t[x].l+t[x].r)>>1;
    if(r<=mid)
		update(x*2,l,r,num);
    else if(l>mid)
			update(x*2+1,l,r,num);
    	else update(x*2,l,mid,num),update(x*2+1,mid+1,r,num);
    t[x].val=t[x*2].val+t[x*2+1].val;
}

ll query(int x,int l,int r){//区间查询
    if(t[x].l==l&&t[x].r==r)
        return t[x].val;
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(r<=mid)
		return query(x*2,l,r);
    else if(l>mid)
			return query(x*2+1,l,r);
    	else return query(x*2,l,mid)+query(x*2+1,mid+1,r);    
}

int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%s %d %d",c,&l,&r);
        if(c[0]=='Q')
			printf("%lld\n",query(1,l,r));
        else{
            scanf("%lld",&x);
            update(1,l,r,x);
        }
    }
    return 0;
}
