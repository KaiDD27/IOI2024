#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct AVLNode{
   int data;
   int height;
   struct AVLNode *lchild;
   struct AVLNode *rchild;
}*AVLTree;

AVLTree Empty(AVLTree &T)//ɾ����
{
    if(T==NULL) return NULL;
    Empty(T->lchild);
    Empty(T->rchild);
    delete T;
    return NULL;
}

inline int Height(AVLTree T)//����߶�
{
    if(T==NULL) return 0;
    return T->height;
}

void updateHeight(AVLTree &T)
{
     T->height=max(Height(T->lchild),Height(T->rchild))+1;
}

AVLTree LL_Rotation(AVLTree &T)//LL��ת
{
    AVLTree temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T)//RR��ת
{
    AVLTree temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T)//LR��ת
{
     T->lchild=RR_Rotation(T->lchild);
     return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T)//RL��ת
{
    T->rchild=LL_Rotation(T->rchild);
    return RR_Rotation(T);
}

AVLTree Insert(AVLTree &T,int x)
{
    if(T==NULL) //���Ϊ�գ������½��
    {
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
        T->data=x;
        T->height=1;
        return T;
     }
    if(T->data==x) return T;//���ҳɹ���ʲôҲ����������ʧ��ʱ�Ų���
    if(x<T->data)//���뵽������
    {
        T->lchild=Insert(T->lchild,x);//ע�����󷹺����ҽӵ�T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2)//������Ƿ�ƽ�⣬�����ƽ����Ȼ�ǲ������һ�߸߶ȴ�
        {                                         //���Ÿ߶ȴ������·���ж�
            if(x<T->lchild->data)//�ж���LL����LR,���������lchild�ڵ��lchild ����rchild
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }
    else//���뵽������
    {
        T->rchild=Insert(T->rchild,x);
        if(Height(T->rchild)-Height(T->lchild)==2)
        {
            if(x>T->rchild->data)
                T=RR_Rotation(T);
            else
                T=RL_Rotation(T);
        }
    }
    updateHeight(T);
    return T;
}

AVLTree adjust(AVLTree &T)//ɾ��������Ҫ�ж��Ƿ���ƽ�⣬�����ƽ�⣬��Ҫ����
{
    if(T==NULL) return NULL;
    if(Height(T->lchild)-Height(T->rchild)==2)//���Ÿ߶ȴ������·���ж�
    {
        if(Height(T->lchild->lchild)>=Height(T->lchild->rchild))
            T=LL_Rotation(T);
        else
            T=LR_Rotation(T);
    }
    if(Height(T->rchild)-Height(T->lchild)==2)//���Ÿ߶ȴ������·���ж�
    {
        if(Height(T->rchild->rchild)>=Height(T->rchild->lchild))
            T=RR_Rotation(T);
        else
            T=RL_Rotation(T);
    }
    updateHeight(T);
    return T;
}

AVLTree Delete(AVLTree &T,int x)
{
    if(T==NULL) return NULL;
    if(T->data==x)//����ҵ�ɾ���ڵ�
    {
        if(T->rchild==NULL)//����ýڵ���Һ���ΪNULL,��ôֱ��ɾ��
        {
            AVLTree temp=T;
            T=T->lchild;
            delete temp;
        }
        else//���򣬽�������������������Ϊ����ڵ㣬���ҵݹ�ɾ������ڵ��ֵ
        {
           AVLTree temp;
           temp=T->rchild;
           while(temp->lchild)
              temp=temp->lchild;
           T->data=temp->data;
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

void Preorder(AVLTree T)//ǰ��������㿴���Ľ��
{
    if(T==NULL) return ;
    cout<<T->data<<"\t"<<T->height<<endl;
    Preorder(T->lchild);
    Preorder(T->rchild);
}

 void Inorder(AVLTree T)//����������㿴���Ľ��
{
    if(T==NULL) return ;
    Inorder(T->lchild);
    cout<<T->data<<"\t"<<T->height<<endl;
    Inorder(T->rchild);
}

 void Posorder(AVLTree T)//����������㿴���Ľ��
{
    if(T==NULL) return ;
    Posorder(T->lchild);
    Posorder(T->rchild);
    cout<<T->data<<"\t"<<T->height<<endl;
}

void show(AVLTree T)
{
    Preorder(T);
    cout<<endl;
    Inorder(T);
    cout<<endl;
    Posorder(T);
}

AVLTree CreateAVL(AVLTree &T)
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        T=Insert(T,x);
    }
    return T;
}
int main()
{
    int x;
    AVLTree root=NULL;
    root=Empty(root);
    CreateAVL(root);
    show(root);
    cin>>x;
    root=Delete(root,x);
    show(root);
    return 0;
}
