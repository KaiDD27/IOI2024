#include<cstdio>
#include<algorithm>
#define lc tr[i].ch[0]
#define rc tr[i].ch[1]
#define Lc tr[j].ch[0]
#define Rc tr[j].ch[1]
#define mid (l+r>>1) //º”¿®∫≈
const int maxn=100005;
using namespace std;
int n,m,a[maxn],b[maxn];
int cnt,rt[maxn];
struct node{
    int num,ch[2];
}tr[maxn*20];

void update(int &i,int j,int l,int r,int k){
    i=++cnt;
	tr[i]=tr[j];
	++tr[i].num;
    if(l==r) return;
    if(k<=mid) update(lc,Lc,l,mid,k);
    else update(rc,Rc,mid+1,r,k);
}

int query(int i,int j,int l,int r,int k){
    if(l==r) return l;
	int s=tr[Lc].num-tr[lc].num;
    if(k<=s) return query(lc,Lc,l,mid,k);
    else return query(rc,Rc,mid+1,r,k-s);
}

int main(){
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
		b[i]=a[i];
	} 
    sort(b+1,b+n+1);
	int tot=unique(b+1,b+n+1)-b-1;
    cnt=0,rt[0]=0;
	for(int i=1;i<=n;i++)
        update(rt[i],rt[i-1],1,tot,lower_bound(b+1,b+tot+1,a[i])-b);
	int x,y,k;
	while(m--){
		scanf("%d%d%d",&x,&y,&k);
	    printf("%d\n",b[query(rt[x-1],rt[y],1,tot,k)]);
	} 
    return 0;
}
