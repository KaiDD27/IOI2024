#include<cstdio> //线段树+线段树
#include<algorithm>
using namespace std;
const int maxn=810;
const int inf=0x3f3f3f3f;
int T,n,q,maxs,mins,x,y,l,xa,xb,ya,yb;

struct node{
	int Max,Min;//没有存储l,r 
}tr[maxn<<2][maxn<<2];

void push_up(int i,int k){
    tr[k][i].Max=max(tr[k][i<<1].Max,tr[k][i<<1|1].Max);
    tr[k][i].Min=min(tr[k][i<<1].Min,tr[k][i<<1|1].Min);    
}

void build_y(int i,int k,int l,int r,int flag) {
    int mid,val;
    if(l==r){
        if(flag==1) {
            scanf("%d",&val);
            tr[k][i].Max=tr[k][i].Min=val;
        }else{
            tr[k][i].Max=max(tr[k<<1][i].Max,tr[k<<1|1][i].Max);
            tr[k][i].Min=min(tr[k<<1][i].Min,tr[k<<1|1][i].Min);
        }
        return;
    }    
    mid=(l+r)>>1;
    build_y(i<<1,k,l,mid,flag);
    build_y(i<<1|1,k,mid+1,r,flag);
    push_up(i,k);
}

void build_x(int i,int l,int r) {
    if(l==r){
        build_y(1,i,1,n,1);//第一种创建方式 
        return;
    }
    int mid=(l+r)>>1;
    build_x(i<<1,l,mid);
    build_x(i<<1|1,mid+1,r);
    build_y(1,i,1,n,2);//第二种创建方式
}

void modify_y(int i,int k,int l,int r,int val,int flag) {
    if(l==r){
        if(flag==1) tr[k][i].Max=tr[k][i].Min=val;
        else{
            tr[k][i].Max=max(tr[k<<1][i].Max,tr[k<<1|1][i].Max);
            tr[k][i].Min=min(tr[k<<1][i].Min,tr[k<<1|1][i].Min);
        }
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=y) modify_y(i<<1,k,l,mid,val,flag);
    else modify_y(i<<1|1,k,mid+1,r,val,flag);
    push_up(i,k);
}

void modify_x(int i,int l,int r,int val) {
    if(l==r){
        modify_y(1,i,1,n,val,1);
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=x) modify_x(i<<1,l,mid,val);
    else modify_x(i<<1|1,mid+1,r,val);
    modify_y(1,i,1,n,val,2);
}

void query_y(int i,int k,int l,int r,int ll,int rr){
    if(ll<=l&&rr>=r){
		maxs=max(maxs,tr[k][i].Max);
        mins=min(mins,tr[k][i].Min);
        return;
	}
    int mid=(l+r)>>1;
    if(ll<=mid) query_y(i<<1,k,l,mid,ll,rr);
    if(rr>mid) query_y(i<<1|1,k,mid+1,r,ll,rr);
}

void query_x(int i,int l,int r,int ll,int rr){
    if(ll<=l&&rr>=r){
    	query_y(1,i,1,n,ya,yb);
    	return;
	}
    int mid=(l+r)>>1;
    if(ll<=mid) query_x(i<<1,l,mid,ll,rr);
    if(rr>mid) query_x(i<<1|1,mid+1,r,ll,rr);
}

int main(){  
	scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        build_x(1,1,n);
        printf("Case #%d:\n",i);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&x,&y,&l);
            xa=max(1,x-l/2);
            xb=min(n,x+l/2);
            ya=max(1,y-l/2);
            yb=min(n,y+l/2);
            maxs=-inf,mins=inf;
            query_x(1,1,n,xa,xb);
            int tmp=(maxs+mins)/2;
            printf("%d\n",tmp);
            modify_x(1,1,n,tmp);
        }        
    }
    return 0;
}
