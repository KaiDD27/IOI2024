#include<cstdio>
using namespace std;
const int maxn=100005;
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

int find_v(int p,int val){
	if(!p||tr[p].val==val) return p;
	if(val<tr[p].val) return find_v(tr[p].lc,val);
	else return find_v(tr[p].rc,val);
}

void remove(int &p,int val){
    if(!p) return;
	tr[p].size--;
    if(tr[p].val==val){
    	if(!tr[p].lc||!tr[p].rc)
			p=tr[p].lc+tr[p].rc;//有一个儿子为空，直接用儿子代替
		else{//找后继，右子树最左节点 
			int temp=tr[p].rc;
			while(tr[temp].lc)
			  temp=tr[temp].lc;
			tr[p].val=tr[temp].val;
			remove(tr[p].rc,tr[temp].val);
    	}
	}else if(val<tr[p].val) remove(tr[p].lc,val);
    else remove(tr[p].rc,val);
}

int remove2(int &p,int val){//如果没找到会删除前驱 
	tr[p].size--;
    if((tr[p].val==val)||(tr[p].val>val&&!tr[p].lc)||(tr[p].val<val&&!tr[p].rc)){
    	int tmp=tr[p].val;
		if(!tr[p].lc||!tr[p].rc)//有一个儿子为空，直接用儿子代替
			p=tr[p].lc+tr[p].rc;
		else//找前驱，左子树最右节点
			tr[p].val=remove2(tr[p].lc,tr[p].val+1);
    	return tmp;
	}else if(val<tr[p].val) return remove2(tr[p].lc,val);
    else return remove2(tr[p].rc,val);
}

int get_min(){
    int p=root;
    while(tr[p].lc) p=tr[p].lc;
    return tr[p].val;
}

int get_max(){
    int p=root;
    while(tr[p].rc) p=tr[p].rc;
    return tr[p].val;
}

int get_pre(int &p,int q,int val){//求val的前驱
    if(!p) return tr[q].val;
    if(tr[p].val<val)
        return get_pre(tr[p].rc,p,val);
    else return get_pre(tr[p].lc,q,val);
}
 
int get_next(int &p,int q,int val){//求val的后继
    if(!p) return tr[q].val;
    if(tr[p].val>val)
        return get_next(tr[p].lc,p,val);
    else return get_next(tr[p].rc,q,val);
}

int get_rank(int &p,int val){//求val的排名
    if(val<tr[p].val)
        return get_rank(tr[p].lc,val);
    else if(val>tr[p].val)
        return get_rank(tr[p].rc,val)+tr[tr[p].lc].size+1;
    return tr[tr[p].lc].size+1;
}

int get_kth(int &p,int k){//求第k小数,select
    int s=tr[tr[p].lc].size+1;
    if(s==k) return tr[p].val;
    else if(s<k) return get_kth(tr[p].rc,k-s);
    else return get_kth(tr[p].lc,k);
}

void in_order(int p){
	if(!p) return;
	in_order(tr[p].lc);
	printf("%d %d %d %d \n",tr[p].val,tr[p].size,tr[tr[p].lc].val,tr[tr[p].rc].val);
	in_order(tr[p].rc);
}

void show(){
	printf("Please select:\n");
	printf("-----------------------------\n");
	printf("     1:  插入\n");
	printf("     2:  删除\n");
	printf("     3:  查找\n");
	printf("     4:  最小值\n");
	printf("     5:  最大值\n");
	printf("     6:  前驱\n");
	printf("     7:  后继\n");
	printf("     8:  排名\n");
	printf("     9:  第K小\n");
	printf("    10:  输出\n");
	printf("     0:  退出\n");
	printf("-----------------------------\n");
}

int main(){
    root=cnt=0;
    int n,x,tmp;
    show();
    while(~scanf("%d",&n),n){
        switch(n){
	        case 1:
	            scanf("%d",&x);
				insert(root,x);break;
	        case 2:
	        	scanf("%d",&x);
	            remove(root,x);break;
	        case 3:
	            scanf("%d",&x);
				if(find_v(root,x))
					printf("find success!\n");
				else
					printf("find fail!\n");break;
	        case 4:
	            printf("%d\n",get_min());break;
	        case 5:
	            printf("%d\n",get_max());break;
	        case 6:
	        	scanf("%d",&x);
	            printf("%d\n",get_pre(root,0,x));break;
	        case 7:
	        	scanf("%d",&x);
	            printf("%d\n",get_next(root,0,x));break;
	        case 8:
	        	scanf("%d",&x);
	            printf("%d\n",get_rank(root,x));break;
	        case 9:
	        	scanf("%d",&x);
	            printf("%d\n",get_kth(root,x));break;
	        case 10:
	            in_order(root);break;
        }
        show();
    }
    return 0;
}
