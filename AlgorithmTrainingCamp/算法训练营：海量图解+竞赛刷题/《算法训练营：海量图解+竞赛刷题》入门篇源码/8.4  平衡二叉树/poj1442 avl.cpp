#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n;
int num[200010],num1[200010];
typedef struct AVLNode{
   int data;
   int height,size,num;//�߶ȣ�������С������ظ����� 
   struct AVLNode *lchild;
   struct AVLNode *rchild;
}*AVLTree;

int Height(AVLTree T){//����߶�,��ֹΪ��ʱ��ֵ 
    if(T==NULL) return 0;
    return T->height;
}

int Size(AVLTree T){//�����С,��ֹΪ��ʱ��ֵ
    if(T==NULL) return 0;
    return T->size;
}

void updateHeight(AVLTree &T){//���¸߶� 
    T->height=max(Height(T->lchild),Height(T->rchild))+1;
	T->size=Size(T->lchild)+Size(T->rchild)+T->num;
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
        T->num=1;
        T->size=1;
        T->height=1;
        return T;
     }
    if(T->data==x){//���ҳɹ�
		T->num++;//������1���� 
		T->size++;//�ӵ㣡������ 
		return T;
	}
	if(x<T->data){//���뵽������
        T->lchild=Insert(T->lchild,x);//ע�����󷵻ؽ���ҽӵ�T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2){//����������ƽ�����߶ȴ����һ��
            if(x<T->lchild->data)//�ж���LL����LR
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

int Findkth(AVLTree T,int k){//�ҵ�kС 
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
		AVLTree root=NULL;//һ��Ҫ�ÿ�
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
