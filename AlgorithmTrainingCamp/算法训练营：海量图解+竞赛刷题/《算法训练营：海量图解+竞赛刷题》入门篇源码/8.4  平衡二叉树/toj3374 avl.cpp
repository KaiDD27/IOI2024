#include<iostream>
using namespace std;

typedef struct AVLNode{
   int data;
   int height;
   struct AVLNode *lchild;
   struct AVLNode *rchild;
}*AVLTree;

int Height(AVLTree T){//����߶�
	if(T==NULL) return 0;
    return T->height;
}

void updateHeight(AVLTree &T){//���¸߶� 
    T->height=max(Height(T->lchild),Height(T->rchild))+1;
}

AVLTree LL_Rotation(AVLTree &T){//LL��ת
    AVLTree temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T){//RR��ת
    AVLTree temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T){//LR��ת
    T->lchild=RR_Rotation(T->lchild);
    return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T){//RL��ת
    T->rchild=LL_Rotation(T->rchild);
    return RR_Rotation(T);
}

AVLTree Insert(AVLTree &T,int x){
    if(T==NULL){ //���Ϊ�գ������½��
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
        T->data=x;
        T->height=1;
        return T;
     }
    if(T->data==x) return T;//���ҳɹ���ʲôҲ����������ʧ��ʱ�Ų���
    if(x<T->data){//���뵽������
        T->lchild=Insert(T->lchild,x);//ע�����󷵻ؽ���ҽӵ�T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2){//������Ƿ�ƽ�⣬�����ƽ�����߶ȴ��һ�� 
            if(x<T->lchild->data)//�ж���LL����LR,���������lchild�ڵ��lchild ����rchild
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }
    else{//���뵽������
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
    AVLTree root=NULL;//һ��Ҫ�ÿ� 
	int n,val;
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>val;
        Insert(root,val);
    }
	cout<<root->data<<endl;
    return 0;
}
