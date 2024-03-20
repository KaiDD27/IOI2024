#include<cstdio>
#include<algorithm>
#define lc tr[i].ch[0]
#define rc tr[i].ch[1]
#define Lc tr[j].ch[0]
#define Rc tr[j].ch[1]
#define mid (l+r>>1) //加括号
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
    if(l==r) return tr[j].num-tr[i].num;
	int ans=0;
    if(k<=mid) ans+=query(lc,Lc,l,mid,k);
    else{
    	ans+=tr[Lc].num-tr[lc].num;
    	ans+=query(rc,Rc,mid+1,r,k);
	}
	return ans;
}

int main(){
	int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
		int tot=unique(b+1,b+n+1)-b-1;//离散化
	    cnt=0,rt[0]=0; 
		for(int i=1;i<=n;i++)//建n棵权值线段树
	        update(rt[i],rt[i-1],1,tot,lower_bound(b+1,b+tot+1,a[i])-b);
		printf("Case %d:\n",cas);
		int l,r,h;
		while(m--){
			scanf("%d%d%d",&l,&r,&h);
			l++,r++;
			int k=upper_bound(b+1,b+tot+1,h)-b-1;
			if(k)
		    	printf("%d\n",query(rt[l-1],rt[r],1,tot,k));
		    else
		    	printf("0\n");//坑点！ 
		}
    }
    return 0;
}
