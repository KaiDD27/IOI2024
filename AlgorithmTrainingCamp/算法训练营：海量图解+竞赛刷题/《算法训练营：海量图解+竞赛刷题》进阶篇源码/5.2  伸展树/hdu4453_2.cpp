#include<cstdio>//第二种方法,箭头指向的元素可以在中间位置
#include<algorithm>
using namespace std;
const int maxn=200100;
const int inf=0x3f3f3f3f;
int n,cnt,root;//结点数，结点存储下标累计，树根
int pos,sum;//当前箭头位置，数字数量 
int a[maxn];
char op[10];
struct node{
	int son[2];//左右孩子0,1
	int val,fa;//值，父亲 
	int size,add,rev;//大小，加标记，翻转标记
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
	if(tr[x].add){//下传加标记 
		if(tr[x].son[0]){
			tr[tr[x].son[0]].add+=tr[x].add;
			tr[tr[x].son[0]].val+=tr[x].add;
		}
		if(tr[x].son[1]){
			tr[tr[x].son[1]].add+=tr[x].add;
			tr[tr[x].son[1]].val+=tr[x].add;
		}	
		tr[x].add=0;//清除标记 
	}
}

int New(int father,int val){//生成新结点 
	tr[++cnt].fa=father;
	tr[cnt].val=val;
	tr[cnt].size=1;
	tr[cnt].add=tr[cnt].rev=0;
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

void Insert(int pos,int val){//插入值val 
	int x=Findk(root,pos),y=Findk(root,pos+1);
	Splay(x,0),Splay(y,x);
	tr[y].son[0]=New(y,val);
	Update(y),Update(x);
}

void Delete(int pos){//删除 
	int x=Findk(root,pos-1),y=Findk(root,pos+1);
	Splay(x,0),Splay(y,x);
	tr[y].son[0]=0;
	Update(y),Update(x);
}

void Build(int l,int r,int &t,int fa){
	if(l>r)
		return;
	int mid=l+r>>1;
	t=New(fa,a[mid]);
	Build(l,mid-1,tr[t].son[0],t);
	Build(mid+1,r,tr[t].son[1],t);
	Update(t);
}

//void Print(int k){//中序遍历测试 
//	Pushdown(k);
//	if(tr[k].son[0])
//		Print(tr[k].son[0]);
//	printf("k:%d  val:%d   size:%d   rev:%d\n",k,tr[k].val,tr[k].size,tr[k].rev);
//	if(tr[k].son[1])
//		Print(tr[k].son[1]);
//}

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

void Add(int l,int r,int val){//[l,r]区间加上val 
	int x=Findk(root,l-1),y=Findk(root,r+1);
	Splay(x,0);
	Splay(y,x);
	tr[tr[y].son[0]].val+=val;
	tr[tr[y].son[0]].add+=val;
	Update(y),Update(x);
}

void Reverse(int l,int r){//[l,r]区间翻转
	int x=Findk(root,l-1),y=Findk(root,r+1);
	Splay(x,0),Splay(y,x);
	tr[tr[y].son[0]].rev^=1;//加翻转标记 
}

void Cut(int l,int r,int c){//[l,r]区间切割,插入第c个之后 
	int x=Findk(root,l-1),y=Findk(root,r+1);
	Splay(x,0),Splay(y,x);
	int tmp=tr[y].son[0];
	tr[y].son[0]=0;//删除
	Update(y),Update(x);
	pos-=r-1;//切割掉前面部分后，位次改变 
	c-=r-1;
	x=Findk(root,c),y=Findk(root,c+1);
	Splay(x,0),Splay(y,x);
	tr[y].son[0]=tmp;
	tr[tmp].fa=y;
	Update(y),Update(x);
}

void Query(int pos){//查询 
	int x=Findk(root,pos);
	printf("%d\n",tr[x].val);
} 

int main(){
	int m,k1,k2;
	int cas=0,x;
    while(~scanf("%d%d%d%d",&n,&m,&k1,&k2)){
        if(n==0) break;
        printf("Case #%d:\n",++cas);
        for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
        Init();
        //Print(root);
        pos=2,sum=n;
        for(int i=1;i<=m;i++){
            scanf("%s",op);
            switch(op[0]){
            	case 'a':
					scanf("%d",&x);
					if(pos+k2-1<=sum+1)
						Add(pos,pos+k2-1,x);
					else{//分两个区间 
						Add(2,pos+k2-1-sum,x);
						Add(pos,sum+1,x);
					}
                	break;
				case 'r':
					if(pos+k1-1>sum+1)
						Cut(2,pos+k1-1-sum,sum+1);//把前面区间切割下来，插入到sum+1元素之后，然后反转
					Reverse(pos,pos+k1-1);
					break;
				case 'i':
                	scanf("%d",&x);
                	sum+=1;
                	Insert(pos,x);
                	break;
				case 'd':
					Delete(pos);
					if(pos==sum+1) pos=2;
					sum-=1;
					break;			
				case 'm':
            		scanf("%d",&x);
                	if(x==1){if(pos==2) pos=sum+1;else pos-=1;}
                	else{if(pos==sum+1) pos=2;else pos+=1;}
                	break;
				case 'q':
					Query(pos);
					break;	
			}
        }
    }
	return 0;
}
