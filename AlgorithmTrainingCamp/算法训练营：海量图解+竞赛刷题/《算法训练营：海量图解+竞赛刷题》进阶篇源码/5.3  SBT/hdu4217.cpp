#include<cstdio>
using namespace std;
const int maxn=300005;
int n,cnt,root;//结点数，结点存储下标累计，树根 
struct node{
	int lc,rc;//左右孩子
	int val;//值
	int size;//子树大小 
 }tr[maxn];

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
    int T,n,m,k,tmp,cas=0;
    long long ans;
	scanf("%d",&T);
    while(T--){
    	ans=cnt=root=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			insert(root,i);
        while(m--){
            scanf("%d",&k);
            ans+=tmp=get_kth(root,k);
            remove(root,tmp);
        }
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
