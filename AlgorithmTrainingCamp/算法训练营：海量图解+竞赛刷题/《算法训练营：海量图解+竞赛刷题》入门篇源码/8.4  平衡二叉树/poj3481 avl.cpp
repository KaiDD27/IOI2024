#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int maxval,minval;
typedef struct AVLNode{
   int data,num;
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

AVLTree Insert(AVLTree &T,int num,int x){//插入x 
    if(T==NULL){ //如果为空，创建新结点
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
        T->num=num;
        T->data=x;
        T->height=1;
        return T;
    }
    if(T->data==x) return T;//查找成功，什么也不做，查找失败时才插入
    if(x<T->data){//插入到左子树
        T->lchild=Insert(T->lchild,num,x);//注意插入后返回结果挂接到T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2){ //如果不平衡插入高度大的那一边
            if(x<T->lchild->data)//判断是LL还是LR
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }
    else{//插入到右子树
        T->rchild=Insert(T->rchild,num,x);
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

AVLTree adjust(AVLTree &T){//删除结点后，需要判断是否还是平衡，如果不平衡，就要调整
    if(T==NULL) return NULL;
    if(Height(T->lchild)-Height(T->rchild)==2){//沿着高度大的那条路径判断
        if(Height(T->lchild->lchild)>=Height(T->lchild->rchild))
            T=LL_Rotation(T);
        else
            T=LR_Rotation(T);
    }
    if(Height(T->rchild)-Height(T->lchild)==2){//沿着高度大的那条路径判断
        if(Height(T->rchild->rchild)>=Height(T->rchild->lchild))
            T=RR_Rotation(T);
        else
            T=RL_Rotation(T);
    }
    updateHeight(T);
    return T;
}

AVLTree Delete(AVLTree &T,int x){//删除x 
    if(T==NULL) return NULL;
    if(T->data==x){//如果找到删除节点
        if(T->rchild==NULL){//如果该节点的右孩子为NULL,那么直接删除
            AVLTree temp=T;
            T=T->lchild;
            delete temp;
        }
        else{//否则，找直接后继（右子树的最左孩子）
			AVLTree temp;
			temp=T->rchild;
			while(temp->lchild)//找右子树的最左孩子
				temp=temp->lchild;
			T->num=temp->num;//替换数据 
			T->data=temp->data;//替换数据 
			T->rchild=Delete(T->rchild,T->data);
			updateHeight(T);
        }
        return T;
    }
    if(T->data>x)//调节删除节点后可能涉及的节点
        T->lchild=Delete(T->lchild,x);
    if(T->data<x)
        T->rchild=Delete(T->rchild,x);
    updateHeight(T);
	T=adjust(T);
    return T;
}

void printmax(AVLTree T){//找优先级最大的结点编号 
	while(T->rchild){
		T=T->rchild;
	}
	cout<<T->num<<endl;
	maxval=T->data;
}

void printmin(AVLTree T){//找优先级最低的结点编号 
	while(T->lchild){
		T=T->lchild;
	}
	cout<<T->num<<endl;
	minval=T->data;
}

int main(){
    AVLTree root=NULL;//一定要置空 
	int n,num,val;
	while(~scanf("%d",&n),n){//注意使用cin超时 
		switch(n){
			case 1:
				scanf("%d%d",&num,&val);
				Insert(root,num,val);
				break;
			case 2:
				if(!root)
					cout<<0<<endl;
				else{
					printmax(root);
					Delete(root,maxval);
				}
				break;
			case 3:
				if(!root)
					cout<<0<<endl;
				else{
					printmin(root);
					Delete(root,minval);
				}
				break;
		}
	}
    return 0;
}
