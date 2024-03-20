#include<cstdio>//逐层伸展 
using namespace std;
const int maxn=100005;
int n,cnt,root;//结点数，结点存储下标累计，树根 
struct node{
	int son[2];//左右孩子0,1
	int val,fa;//值，父亲 
	int num;//编号 
}tr[maxn];

void Init(){
	cnt=root=0;
	tr[0].son[0]=tr[0].son[1]=0;
}

int New(int father,int val,int num){//生成新结点 
	tr[++cnt].fa=father;
	tr[cnt].val=val;
	tr[cnt].num=num;
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

void Splay(int x,int goal){
	while(tr[x].fa!=goal)
		Rotate(x);
	if(!goal)
		root=x;
}

void Insert(int val,int num){//插入值val
	int x;
	for(x=root;tr[x].son[tr[x].val<val];x=tr[x].son[tr[x].val<val]);
	tr[x].son[tr[x].val<val]=New(x,val,num);
	Splay(tr[x].son[tr[x].val<val],0);
}

void Delete(int x){//删除x 
	if(x==root){
		if(!tr[x].son[0]&&!tr[x].son[1])
			Init();
		else{
			int t=tr[x].son[0]?0:1;
			tr[tr[x].son[t]].fa=0;
			root=tr[x].son[t];
		}
	}
	else{
		int y=tr[x].fa;
		int t=(tr[y].son[1]==x);
		tr[y].son[t]=tr[x].son[!t];
		tr[tr[x].son[!t]].fa=y;
		Splay(y,0);
	}
}

void Printmax(){//找优先级最大的结点编号
	int x=root;
	if(x){
		while(tr[x].son[1])
			x=tr[x].son[1];
		printf("%d\n",tr[x].num);
		Delete(x);
	}
	else
		puts(0);
}

void Printmin(){//找优先级最低的结点编号 
	int x=root;
	if(x){
		while(tr[x].son[0])
			x=tr[x].son[0];
		printf("%d\n",tr[x].num);
		Delete(x);
	}
	else
		puts(0);	
}

int main(){
	int num,val;
	Init();
	while(scanf("%d",&n),n){
		switch(n){
			case 1:
				scanf("%d%d",&num,&val);
				Insert(val,num);
				break;
			case 2:
				Printmax();
				break;
			case 3:
				Printmin();
				break;
		}	
	}
	return 0;
}
