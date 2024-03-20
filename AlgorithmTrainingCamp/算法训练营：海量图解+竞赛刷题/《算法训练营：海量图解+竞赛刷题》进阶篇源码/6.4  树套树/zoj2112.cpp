#include<cstdio>//线段树+Treap
#include<cstring>
#include<ctime>
#include<algorithm>
#define ls t[x].ch[0]
#define rs t[x].ch[1]
using namespace std;
const int maxn=5e4+10;
int n,m;
int p[maxn];

struct node{//平衡树节点 
	int val,key,cnt,size;
	int ch[2];
}t[maxn*20];
int tot;//平衡树节点总数 

struct Treap{//平衡树 
	int root;
	void update(int x){
		t[x].size=t[ls].size+t[rs].size+t[x].cnt;
	}
	void rotate(int &x,bool c){
		int son=t[x].ch[c];
		t[x].ch[c]=t[son].ch[c^1];
		t[son].ch[c^1]=x;
		update(x),update(x=son);
	}
	void insert(int &x,int val){
		if(!x){
			x=++tot;
			t[x].cnt=t[x].size=1;
			t[x].key=rand(),t[x].val=val;
			return ;
		}
		t[x].size++;
		if(t[x].val==val) {t[x].cnt++;return;}
		bool c=val>t[x].val;
		insert(t[x].ch[c],val);
		if(t[x].key>t[t[x].ch[c]].key) rotate(x,c);
	}
	void delet(int &x,int val){
		if(!x) return ;
		if(t[x].val==val){
			if(t[x].cnt>1) {t[x].cnt--,t[x].size--;return ;}
			bool c=t[ls].key>t[rs].key;
			if(ls==0||rs==0) x=ls+rs;
			else rotate(x,c),delet(x,val);
		}
		else t[x].size--,delet(t[x].ch[t[x].val<val],val);
	}
	int rank(int x,int val){
		if(!x)return 0;
		if(t[x].val==val) return t[ls].size;
		if(t[x].val>val) return rank(ls,val);
		else return t[ls].size+t[x].cnt+rank(rs,val);
	}
}a[maxn<<2];//线段树每一个节点对应一棵平衡树 

void build(int x,int l,int r){//创建线段树 
	a[x].root=0;
	for(int i=l;i<=r;i++)
		a[x].insert(a[x].root,p[i]);//将区间[l,r]数据插入到平衡树中 
	if(l==r) return ;
	build(x<<1,l,l+r>>1);
	build(x<<1|1,(l+r>>1)+1,r);
}

int queryrank(int x,int l,int r,int ql,int qr,int k){//查询值为k的排名 
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr)
		return a[x].rank(a[x].root,k);//平衡树中查询排名
	int ans=0,mid=l+r>>1;
	ans+=queryrank(x<<1,l,mid,ql,qr,k);
	ans+=queryrank(x<<1|1,mid+1,r,ql,qr,k);
	return ans;
}

int queryval(int ql,int qr,int k){//查询排名为k的值
	int l=0,r=1e9,mid,ans=-1;//二分 
	while(l<=r){
		mid=l+r>>1;
		if(queryrank(1,1,n,ql,qr,mid)+1<=k) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}

void modify(int x,int l,int r,int pos,int k){//修改 
	if(pos<l||r<pos) return ;
	a[x].delet(a[x].root,p[pos]);//先从平衡树中删除 
	a[x].insert(a[x].root,k);//再将新值插入平衡树 
	if(l==r) return ;
	int mid=l+r>>1;
	modify(x<<1,l,mid,pos,k);
	modify(x<<1|1,mid+1,r,pos,k);
}

int main(){
	srand(time(0));
	int T; 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		memset(t,0,sizeof(t));
		tot=0;
		build(1,1,n);
		while(m--){
			char opt[3];
			int l,r,k;
			scanf("%s",opt);
			if(opt[0]=='C'){
				scanf("%d%d",&l,&k);
				modify(1,1,n,l,k);p[l]=k;
			}else{
				scanf("%d%d%d",&l,&r,&k);
				printf("%d\n",queryval(l,r,k));
			}
		}
	}
	return 0;
}
