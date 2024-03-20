#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
int num[200010],num1[200010];
typedef struct AVLNode{
   int data;
   int height,size,num;//高度，子树大小，结点重复个数 
   struct AVLNode *lchild;
   struct AVLNode *rchild;
}*AVLTree;

int Height(AVLTree T){//计算高度,防止为空时无值 
    if(T==NULL) return 0;
    return T->height;
}

int Size(AVLTree T){//计算大小,防止为空时无值
    if(T==NULL) return 0;
    return T->size;
}

void updateHeight(AVLTree &T){//更新高度 
    T->height=max(Height(T->lchild),Height(T->rchild))+1;
	T->size=Size(T->lchild)+Size(T->rchild)+T->num;
}

AVLTree LL_Rotation(AVLTree &T){//LL旋转
    AVLTree temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    updateHeight(T);//更新高度
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T){//RR旋转
    AVLTree temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    updateHeight(T);//更新高度
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T){//LR旋转
    T->lchild=RR_Rotation(T->lchild);
    return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T){//RL旋转
    T->rchild=LL_Rotation(T->rchild);
    return RR_Rotation(T);
}

AVLTree Insert(AVLTree &T,int x){
    if(T==NULL){ //如果为空，创建新结点
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
		T->data=x;
        T->num=1;
        T->size=1;
        T->height=1;
        return T;
     }
    if(T->data==x){//查找成功
		T->num++;//数量增1即可 
		T->size++;//坑点！！！！ 
		return T;
	}
	if(x<T->data){//插入到左子树
        T->lchild=Insert(T->lchild,x);//注意插入后返回结果挂接到T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2){//插入后如果不平衡插入高度大的那一边
            if(x<T->lchild->data)//判断是LL还是LR
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }
    else{//插入到右子树
        T->rchild=Insert(T->rchild,x);
        if(Height(T->rchild)-Height(T->lchild)==2){
            if(x>T->rchild->data)
                T=RR_Rotation(T);
            else
                T=RL_Rotation(T);
        }
    }
    updateHeight(T);
    return T;
}

int Findkth(AVLTree T,int k){//找第k小 
	int t;
	if(!T)
		return 0;
	if(T->lchild)
		t=T->lchild->size;
	else
		t=0;
	if(k<t+1)
		return Findkth(T->lchild,k);
	else if(k>t+T->num)
			return Findkth(T->rchild,k-(t+T->num));
		else return T->data;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		AVLTree root=NULL;//一定要置空
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&num1[i]);
		int t=1;
		int k=1;
		while(t<=m){
			while(k<=num1[t]){
				Insert(root,num[k++]);
			}
			int ans=Findkth(root,t++);
			printf("%d\n",ans);
		}
	}
    return 0;
}
