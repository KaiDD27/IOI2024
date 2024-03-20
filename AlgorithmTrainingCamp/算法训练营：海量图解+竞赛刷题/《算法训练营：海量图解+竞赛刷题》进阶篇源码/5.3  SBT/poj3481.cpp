#include<cstdio>
using namespace std;
const int maxn=100005;
int n,cnt,root;//结点数，结点存储下标累计，树根 
struct node{
	int lc,rc;//左右孩子
	int val,num;//值,编号
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

void insert(int &p,int val,int num){
    if(!p){
        p=++cnt;
        tr[p].lc=tr[p].rc=0;
        tr[p].size=1;
        tr[p].val=val,tr[p].num=num;
    }
    else{
        tr[p].size++;
        if(val<tr[p].val) insert(tr[p].lc,val,num);
        else insert(tr[p].rc,val,num);
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

int getmin(){
    int p=root;
    while(tr[p].lc) p=tr[p].lc;
    printf("%d\n",tr[p].num);
    return tr[p].val;
}

int getmax(){
    int p=root;
    while(tr[p].rc) p=tr[p].rc;
    printf("%d\n",tr[p].num);
    return tr[p].val;
}

int main(){
    cnt=root=0;
    int op,num,val;
    while(~scanf("%d",&op),op){
        if(op==1){
            scanf("%d%d",&num,&val);
            insert(root,val,num);
        }else if(op==2){
            int maxval=getmax();
            remove(root,maxval);
        }
        else{
            int minval=getmin();
            remove(root,minval);
        }
    }
    return 0;
}
