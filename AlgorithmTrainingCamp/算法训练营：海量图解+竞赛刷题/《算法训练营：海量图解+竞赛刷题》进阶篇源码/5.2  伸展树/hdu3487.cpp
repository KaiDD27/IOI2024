#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=300010;
const int inf=0x3f3f3f3f;
int n,cnt,root;//结点数，结点存储下标累计，树根 
char op[10];
bool flag;
struct node{
	int son[2];//左右孩子0,1
	int val,fa;//值，父亲 
	int size,rev;//大小，翻转标记 
}tr[maxn];

void Update(int x){
	tr[x].size=1;
	if(tr[x].son[0])
		tr[x].size+=tr[tr[x].son[0]].size;
	if(tr[x].son[1])
		tr[x].size+=tr[tr[x].son[1]].size;
}

void Pushdown(int x){
	if(tr[x].rev){//下传翻转标记 
		tr[x].rev^=1;
		swap(tr[x].son[0],tr[x].son[1]);
		if(tr[x].son[0])
			tr[tr[x].son[0]].rev^=1;
		if(tr[x].son[1])
			tr[tr[x].son[1]].rev^=1;
	}
}

int New(int father,int val){//生成新结点 
	tr[++cnt].fa=father;
	tr[cnt].val=val;
	tr[cnt].size=1;
	tr[cnt].rev=0;
	tr[cnt].son[0]=tr[cnt].son[1]=0;
	return cnt;
}

void Rotate(int x){//旋转
	Pushdown(x);
	int y=tr[x].fa,z=tr[y].fa;;
	int c=tr[y].son[0]==x;
	tr[y].son[!c]=tr[x].son[c];
	tr[tr[x].son[c]].fa=y;
	tr[x].fa=z;
	if(z)
		tr[z].son[tr[z].son[1]==y]=x;
	tr[x].son[c]=y;
	tr[y].fa=x;
	Update(y);
	Update(x);
}

void Splay(int x,int goal){//将x旋转为goal的儿子
    while(tr[x].fa!=goal){
        int y=tr[x].fa,z=tr[y].fa;
        if(z!=goal)
            (tr[z].son[0]==y)^(tr[y].son[0]==x)?Rotate(x):Rotate(y);
        Rotate(x);
    }
    if(!goal) root=x;//如果goal是0，则更新根为x
}

int Findk(int x,int k){
	while(1){
		Pushdown(x);
		int sn=tr[x].son[0]?tr[tr[x].son[0]].size+1:1;
		if(k==sn)
			return x;
		if(k>sn)
			k-=sn,x=tr[x].son[1];
		else
			x=tr[x].son[0];
	}
}

void Build(int l,int r,int &t,int fa){
	if(l>r)
		return;
	int mid=l+r>>1;
	t=New(fa,mid);
	Build(l,mid-1,tr[t].son[0],t);
	Build(mid+1,r,tr[t].son[1],t);
	Update(t);
}

void Init(){
	cnt=root=0;
	tr[0].son[0]=tr[0].son[1]=0;
	root=New(0,-inf);//创建虚结点1
	tr[root].son[1]=New(root,inf);//创建虚结点2
	tr[root].size=2;
	Build(1,n,tr[tr[root].son[1]].son[0],tr[root].son[1]);
	Update(tr[root].son[1]);
	Update(root);
}

void Cut(int l,int r,int c){//[l,r]区间切割,插入第c个之后 
	int x=Findk(root,l-1),y=Findk(root,r+1);
	Splay(x,0),Splay(y,x);
	int tmp=tr[y].son[0];
	tr[y].son[0]=0;//删除
	Update(y),Update(x);
	x=Findk(root,c),y=Findk(root,c+1);
	Splay(x,0),Splay(y,x);
	tr[y].son[0]=tmp;
	tr[tmp].fa=y;
	Update(y),Update(x);
}

void Flip(int l,int r){//[l,r]区间翻转
	int x=Findk(root,l-1),y=Findk(root,r+1);
	Splay(x,0),Splay(y,x);
	tr[tr[y].son[0]].rev^=1;//加翻转标记
}

void Print(int k){//中序遍历测试 
	Pushdown(k);
	if(tr[k].son[0])
		Print(tr[k].son[0]);
	if(tr[k].val!=-inf&&tr[k].val!=inf){
		if(flag)
			printf("%d",tr[k].val),flag=0;
		else
			printf(" %d",tr[k].val);
	}	
	if(tr[k].son[1])
		Print(tr[k].son[1]);
}

int main(){
	int m,a,b,c;
	while(~scanf("%d%d",&n,&m)){
		if(n==-1&&m==-1) break;
		Init();
		scanf("%d",&m);
		while(m--){
			scanf("%s",op);
			if(op[0]=='C') scanf("%d%d%d",&a,&b,&c),Cut(++a,++b,++c);
			else if(op[0]=='F') scanf("%d%d",&a,&b),Flip(++a,++b);	
		}
		flag=1;
		Print(root);
		printf("\n");
	}
	return 0;
}
