#include<iostream>
using namespace std;

typedef struct AVLNode{
   int data;
   int height;
   struct AVLNode *lchild;
   struct AVLNode *rchild;
}*AVLTree;

int Height(AVLTree T){//计算高度
	if(T==NULL) return 0;
    return T->height;
}

void updateHeight(AVLTree &T){//更新高度 
    T->height=max(Height(T->lchild),Height(T->rchild))+1;
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
        T->height=1;
        return T;
     }
    if(T->data==x) return T;//查找成功，什么也不做，查找失败时才插入
    if(x<T->data){//插入到左子树
        T->lchild=Insert(T->lchild,x);//注意插入后返回结果挂接到T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2){//插入后看是否平衡，如果不平衡插入高度大的一边 
            if(x<T->lchild->data)//判断是LL还是LR,即插入的是lchild节点的lchild 还是rchild
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

int main(){
    AVLTree root=NULL;//一定要置空 
	int n,val;
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>val;
        Insert(root,val);
    }
	cout<<root->data<<endl;
    return 0;
}
