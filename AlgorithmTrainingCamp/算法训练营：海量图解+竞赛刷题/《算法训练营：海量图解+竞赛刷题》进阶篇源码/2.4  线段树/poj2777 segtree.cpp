#include<cstdio>
#include<cstring>
#define lc ((rt)<<1)
#define rc ((rt)<<1|1)
#define maxn 100010
int ans[50];

struct node{
    int l,r,color;
}tree[maxn*4];

void build(int rt,int l,int r){//创建线段树 
    tree[rt].l=l; tree[rt].r=r;
	if(rt!=1) tree[rt].color=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(lc,l,mid); build(rc,mid+1,r);
}

void lift_up(int rt){//颜色统一 
    if(tree[lc].color==tree[rc].color)
		tree[rt].color=tree[lc].color;
}

void push_down(int rt){//颜色下传 
    if(tree[rt].color){
        tree[lc].color=tree[rc].color=tree[rt].color;
        tree[rt].color=0;
    }
}

void modify(int rt,int l,int r,int c){//修改 
    if (tree[rt].l==l&&tree[rt].r==r){
        tree[rt].color=c;
        return;
    }
    push_down(rt);
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(r<=mid) modify(lc,l,r,c);
    else if(l>mid) modify(rc,l,r,c);
	else {modify(lc,l,mid,c);modify(rc,mid+1,r,c);}
    lift_up(rt);
}

void query(int rt,int l,int r){//查询 
    if(tree[rt].color){
        ans[tree[rt].color]=true;
        return;
    }
    int mid=(tree[rt].l+tree[rt].r)>>1;;
    if(r<=mid) query(lc,l,r);
    else if(l>mid) query(rc,l,r);
    else {query(lc,l,mid);query(rc,mid+1,r);}
}

int main(){
    int n,t,o;
    scanf("%d%d%d",&n,&t,&o);
    tree[1].color=1;
    build(1,1,n);
    for(int i=0;i<o;i++){
        char ch;
        scanf("\n%c",&ch);
        int l,r;
        if(ch=='C'){
            int c;
            scanf("%d%d%d",&l,&r,&c);
            modify(1,l,r,c);
        }
        else{
            memset(ans,0,sizeof(ans));
            scanf("%d%d",&l,&r);
            query(1,l,r);
            int tot=0;
            for(int k=1;k<=t;k++)
				if(ans[k])
					tot++;
            printf("%d\n",tot);
        }
    }
    return 0;
}
