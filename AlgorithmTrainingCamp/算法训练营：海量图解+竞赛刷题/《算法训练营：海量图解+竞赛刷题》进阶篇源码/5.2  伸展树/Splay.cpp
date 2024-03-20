#include<cstdio>
using namespace std;
const int maxn=100005;
int n,cnt,root;//结点数，结点存储下标累计，树根 
struct node{
	int son[2];//左右孩子0,1
	int val,fa;//值，父亲 
}tr[maxn];

void init(){
	cnt=root=0;
	tr[0].son[0]=tr[0].son[1]=0;
}

void print(int rt){//中序遍历测试
	if(!rt) return;
	if(tr[rt].son[0])
		print(tr[rt].son[0]);
	printf("val: %d lc: %d rc: %d\n",tr[rt].val,tr[tr[rt].son[0]].val,tr[tr[rt].son[1]].val);
	if(tr[rt].son[1])
		print(tr[rt].son[1]);
}

int New(int father,int val){//生成新结点 
	tr[++cnt].fa=father;
	tr[cnt].val=val;
	tr[cnt].son[0]=tr[cnt].son[1]=0;
	return cnt;
}

void Rotate(int x){//旋转
	int y=tr[x].fa,z=tr[y].fa;;
	int c=(tr[y].son[0]==x);
	tr[y].son[!c]=tr[x].son[c];
	tr[tr[x].son[c]].fa=y;
	tr[x].fa=z;
	if(z)
		tr[z].son[tr[z].son[1]==y]=x;
	tr[x].son[c]=y;
	tr[y].fa=x;
}

void Splay(int x,int goal){//双层伸展，将x旋转为goal的儿子
    while(tr[x].fa!=goal){
        int y=tr[x].fa,z=tr[y].fa;
        if(z!=goal)
            (tr[z].son[0]==y)^(tr[y].son[0]==x)?Rotate(x):Rotate(y);
        Rotate(x);
    }
    if(!goal) root=x;//如果goal是0，则更新根为x
}

//void Splay(int x,int goal){//单层伸展，将x旋转为goal的儿子
//	while(tr[x].fa!=goal)
//		Rotate(x);
//	if(!goal)
//		root=x;
//}

void Insert(int val){//插入值val 
	int x;
	for(x=root;tr[x].son[tr[x].val<val];x=tr[x].son[tr[x].val<val]);//找位置
	tr[x].son[tr[x].val<val]=New(x,val);
	Splay(tr[x].son[tr[x].val<val],0);//新插入结点旋转到根 
}

bool Find(int val){//查找值val 
	int x=root;
	while(x){
		if(tr[x].val==val){
			Splay(x,0);//x旋转到根
			return 1;
		}
		if(tr[x].son[tr[x].val<val])
			x=tr[x].son[tr[x].val<val];
		else{//查找失败 
			Splay(x,0);//x旋转到根
			return 0;
		}
	}
}

void Findmax(){//找最大值结点
	int x=root;
	if(x){
		while(tr[x].son[1])
			x=tr[x].son[1];
		Splay(x,0);//x旋转到根
	}
}

void Findmin(){//找最小值结点 
	int x=root;
	if(x){
		while(tr[x].son[0])
			x=tr[x].son[0];
		Splay(x,0);//x旋转到根
	}	
}

bool Split(int val,int &t1,int &t2){
	if(Find(val)){//查找成功
		t1=tr[root].son[0];
		t2=tr[root].son[1];
		root=t1;
		tr[t1].fa=tr[t2].fa=0;
		return 1;
	}
	return 0;
}

void Join(int t1,int t2){
	if(t1){
		Findmax();//查找t1的最大值
		tr[root].son[1]=t2;
		tr[t2].fa=root;
	}
	else
		root=t2;
}

void Delete(int val){//删除值val
	int t1=0,t2=0;
	if(Split(val,t1,t2))
		Join(t1,t2);
}

int main(){
	int num,val;
	init();
	while(scanf("%d",&n),n){
		switch(n){
			case 1:
				scanf("%d",&val);
				Insert(val);
				print(root);
				puts(" ");
				break;
			case 2:
				Findmax();
				printf("%d\n",tr[root].val);
				break;
			case 3:
				Findmin();
				printf("%d\n",tr[root].val);
				break;
			case 4:
				scanf("%d",&val);
				Delete(val);
				print(root);
				puts(" ");
				break;	
		}	
	}
	return 0;
}
