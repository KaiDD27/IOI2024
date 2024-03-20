#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500000+100;
const int inf=0x3f3f3f3f;
int n,m;

struct segment{
    int l,r;
    int v;
}seg[3*maxn];

void build(int rt,int l,int r){
    seg[rt].l=l;seg[rt].r=r;
    if(l==r){
        int val=inf;
        if(l==1) val=0;
        seg[rt].v=val;
        return ;
    }
    int lc=rt<<1,rc=rt<<1|1;
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    seg[rt].v=min(seg[lc].v,seg[rc].v);
}

int query(int rt,int l,int r){
    if(seg[rt].l==l&&seg[rt].r==r)
        return seg[rt].v;
    int lc=rt<<1,rc=rt<<1|1;
	int mid=(seg[rt].l+seg[rt].r)>>1;
    if(r<=mid)
        return query(lc,l,r);
    else if(l>mid)
        return query(rc,l,r);
    else
        return min(query(lc,l,mid),query(rc,mid+1,r));
}

void update(int rt,int i,int val){
    if(seg[rt].l==seg[rt].r&&seg[rt].l==i){
        seg[rt].v=val;
        return ;
    }
    int lc=rt<<1,rc=rt<<1|1;
    int mid=(seg[rt].l+seg[rt].r)>>1;
    if(i<=mid)
        update(lc,i,val);
    else
        update(rc,i,val);
    seg[rt].v=min(seg[lc].v,seg[rc].v);
}

int main() {
    int s,t;
	while(~scanf("%d%d",&n,&m)){
        build(1,1,n);
        for(int i=0;i<m;i++){
            scanf("%d%d",&s,&t);
            int v1=query(1,s,t)+1;
            int v2=query(1,t,t);
            update(1,t,min(v1,v2));
        }
        printf("%d\n",query(1,n,n));
    }
    return 0;
}
