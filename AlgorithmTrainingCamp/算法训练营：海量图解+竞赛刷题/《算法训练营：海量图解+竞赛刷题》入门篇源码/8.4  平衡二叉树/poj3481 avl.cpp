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

AVLTree Insert(AVLTree &T,int num,int x){//����x 
    if(T==NULL){ //���Ϊ�գ������½��
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
        T->num=num;
        T->data=x;
        T->height=1;
        return T;
    }
    if(T->data==x) return T;//���ҳɹ���ʲôҲ����������ʧ��ʱ�Ų���
    if(x<T->data){//���뵽������
        T->lchild=Insert(T->lchild,num,x);//ע�����󷵻ؽ���ҽӵ�T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2){ //�����ƽ�����߶ȴ����һ��
            if(x<T->lchild->data)//�ж���LL����LR
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }
    else{//���뵽������
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

AVLTree adjust(AVLTree &T){//ɾ��������Ҫ�ж��Ƿ���ƽ�⣬�����ƽ�⣬��Ҫ����
    if(T==NULL) return NULL;
    if(Height(T->lchild)-Height(T->rchild)==2){//���Ÿ߶ȴ������·���ж�
        if(Height(T->lchild->lchild)>=Height(T->lchild->rchild))
            T=LL_Rotation(T);
        else
            T=LR_Rotation(T);
    }
    if(Height(T->rchild)-Height(T->lchild)==2){//���Ÿ߶ȴ������·���ж�
        if(Height(T->rchild->rchild)>=Height(T->rchild->lchild))
            T=RR_Rotation(T);
        else
            T=RL_Rotation(T);
    }
    updateHeight(T);
    return T;
}

AVLTree Delete(AVLTree &T,int x){//ɾ��x 
    if(T==NULL) return NULL;
    if(T->data==x){//����ҵ�ɾ���ڵ�
        if(T->rchild==NULL){//����ýڵ���Һ���ΪNULL,��ôֱ��ɾ��
            AVLTree temp=T;
            T=T->lchild;
            delete temp;
        }
        else{//������ֱ�Ӻ�̣��������������ӣ�
			AVLTree temp;
			temp=T->rchild;
			while(temp->lchild)//����������������
				temp=temp->lchild;
			T->num=temp->num;//�滻���� 
			T->data=temp->data;//�滻���� 
			T->rchild=Delete(T->rchild,T->data);
			updateHeight(T);
        }
        return T;
    }
    if(T->data>x)//����ɾ���ڵ������漰�Ľڵ�
        T->lchild=Delete(T->lchild,x);
    if(T->data<x)
        T->rchild=Delete(T->rchild,x);
    updateHeight(T);
	T=adjust(T);
    return T;
}

void printmax(AVLTree T){//�����ȼ����Ľ���� 
	while(T->rchild){
		T=T->rchild;
	}
	cout<<T->num<<endl;
	maxval=T->data;
}

void printmin(AVLTree T){//�����ȼ���͵Ľ���� 
	while(T->lchild){
		T=T->lchild;
	}
	cout<<T->num<<endl;
	minval=T->data;
}

int main(){
    AVLTree root=NULL;//һ��Ҫ�ÿ� 
	int n,num,val;
	while(~scanf("%d",&n),n){//ע��ʹ��cin��ʱ 
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
