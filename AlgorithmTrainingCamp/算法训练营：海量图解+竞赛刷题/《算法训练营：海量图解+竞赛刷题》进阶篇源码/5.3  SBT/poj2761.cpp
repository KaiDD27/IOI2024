#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int maxm=50005;
int n,cnt,root;//结点数，结点存储下标累计，树根 
int a[maxn],ans[maxm];
struct node{//SBT树节点 
	int lc,rc;//左右孩子
	int val;//值
	int size;//子树大小 
}tr[maxn];

struct qnode{//查询节点 
	int l,r;//左右区间下标 
	int k;//第k小 
	int id;//查询序号 
	bool operator <(const qnode &b) const{
		return l<b.l;
	} 
}q[maxm];

void R_rotate(int &x){
    int y=tr[x].lc;
    tr[x].lc=tr[y].rc;
    tr[y].rc=x;
    tr[y].size=tr[x].size;
    tr[x].size=tr[tr[x].lc].size+tr[tr[x].rc].size+1;
    x=y;
}

void L_rotate(int &x){
    int y=tr[x].rc;
    tr[x].rc=tr[y].lc;
    tr[y].lc=x;
    tr[y].size=tr[x].size;
    tr[x].size=tr[tr[x].lc].size+tr[tr[x].rc].size+1;
    x=y;
}

void maintain(int &p,bool flag){
    if(!p) return;
	if(!flag){
        if(tr[tr[tr[p].lc].lc].size>tr[tr[p].rc].size)//LL
            R_rotate(p);
        else if(tr[tr[tr[p].lc].rc].size>tr[tr[p].rc].size)//LR
            L_rotate(tr[p].lc),
            R_rotate(p);
        else return;
    }
    else{
        if(tr[tr[tr[p].rc].rc].size>tr[tr[p].lc].size)//RR
            L_rotate(p);
        else if(tr[tr[tr[p].rc].lc].size>tr[tr[p].lc].size)//RL
            R_rotate(tr[p].rc),
            L_rotate(p);
        else return;
    }
    maintain(tr[p].lc,false);
    maintain(tr[p].rc,true);
    maintain(p,false);
    maintain(p,true);
}

void insert(int &p,int val){
    if(!p){
        p=++cnt;
        tr[p].lc=tr[p].rc=0;
        tr[p].size=1;
        tr[p].val=val;
    }
    else{
        tr[p].size++;
        if(val<tr[p].val) insert(tr[p].lc,val);
        else insert(tr[p].rc,val);
        maintain(p,val>=tr[p].val);
    }
}

int remove(int &p,int val){
	tr[p].size--;
    if((tr[p].val==val)||(tr[p].val>val&&!tr[p].lc)||(tr[p].val<val&&!tr[p].rc)){
    	int tmp=tr[p].val;
		if(!tr[p].lc||!tr[p].rc)//有一个儿子为空，直接用儿子代替
			p=tr[p].lc+tr[p].rc;
		else//找前驱，左子树最右节点
			tr[p].val=remove(tr[p].lc,tr[p].val+1);
    	return tmp;
	}else if(val<tr[p].val) return remove(tr[p].lc,val);
    else return remove(tr[p].rc,val);
}

int get_kth(int &p,int k){//求第k小数,select
    int s=tr[tr[p].lc].size+1;
    if(s==k) return tr[p].val;
    else if(s<k) return get_kth(tr[p].rc,k-s);
    else return get_kth(tr[p].lc,k);
}

int main(){
    int n,m;
    cnt=root=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
    	q[i].id=i;
	}
    sort(q+1,q+m+1);
    q[0].l=q[0].r=0;
	for(int i=1;i<=m;i++){
		for(int j=q[i-1].l;j<=q[i-1].r&&j<q[i].l;j++)
			if(j==0) continue;
			else remove(root,a[j]);
    	for(int j=q[i-1].r>=q[i].l?q[i-1].r+1:q[i].l;j<=q[i].r;j++)
			insert(root,a[j]);
		ans[q[i].id]=get_kth(root,q[i].k);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
