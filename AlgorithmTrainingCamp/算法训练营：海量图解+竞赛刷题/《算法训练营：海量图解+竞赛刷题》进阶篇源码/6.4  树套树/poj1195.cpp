#include<cstdio>//Ïß¶ÎÊ÷+Ïß¶ÎÊ÷
#include<algorithm>
using namespace std;
const int maxn=1010;
struct node_y{
	int l,r;
	int sum;
};
struct node_x{
	int l,r;
	node_y s[maxn<<2];
}tr[maxn<<2];

void build_y(int i,int l,int r,int k){
	tr[k].s[i].l=l;
	tr[k].s[i].r=r;
	tr[k].s[i].sum=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build_y(i<<1,l,mid,k);
	build_y(i<<1|1,mid+1,r,k);
}

void build_x(int i,int l,int r,int ll,int rr){
	tr[i].l=l;
	tr[i].r=r;
	build_y(1,ll,rr,i);
	if(l==r) return;
	int mid=(l+r)>>1;
    build_x(i<<1,l,mid,ll,rr);
	build_x(i<<1|1,mid+1,r,ll,rr);
}

void update_y(int i,int y,int val,int k){
	tr[k].s[i].sum+=val;
	if(tr[k].s[i].l==tr[k].s[i].r) return;
	int mid=(tr[k].s[i].l+tr[k].s[i].r)>>1;
	if(y<=mid)
		update_y(i<<1,y,val,k);
	else
		update_y(i<<1|1,y,val,k);
}

void update_x(int i,int x,int y,int val){
	update_y(1,y,val,i);
	if(tr[i].l==tr[i].r) return;
	int mid=(tr[i].l+tr[i].r)>>1;
	if(x<=mid)
		update_x(i<<1,x,y,val);
	else
		update_x(i<<1|1,x,y,val);
}

int query_y(int i,int l,int r,int k){
	if(tr[k].s[i].l==l&&tr[k].s[i].r==r)
		return tr[k].s[i].sum;
	int mid=(tr[k].s[i].l+tr[k].s[i].r)>>1;
	if(r<=mid)
		return query_y(i<<1,l,r,k);
	else if(l>mid)
		return query_y(i<<1|1,l,r,k);
	else
		return query_y(i<<1,l,mid,k)+query_y(i<<1|1,mid+1,r,k);
}

int query_x(int i,int l,int r,int ll,int rr){
	if(tr[i].l==l&&tr[i].r==r)
		return query_y(1,ll,rr,i);
	int mid=(tr[i].l+tr[i].r)>>1;
	if(r<=mid)
		return query_x(i<<1,l,r,ll,rr);
	else if(l>mid)
		return query_x(i<<1|1,l,r,ll,rr);
	else
		return query_x(i<<1,l,mid,ll,rr)+query_x(i<<1|1,mid+1,r,ll,rr);
}

int main(){
	int i,j,n,m,k;
	while(~scanf("%d",&n)){
		if(n==0){
			scanf("%d",&m);
			build_x(1,0,m-1,0,m-1);
		}
		else if(n==1){
			int x,y;
			scanf("%d%d%d",&x,&y,&k);
			update_x(1,x,y,k);
		}
		else if(n==2){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n",query_x(1,x1,x2,y1,y2));
		}
		else
		   break;
	}
	return 0;
}
