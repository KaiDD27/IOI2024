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

AVLTree Empty(AVLTree &T)//删除树
{
    if(T==NULL) return NULL;
    Empty(T->lchild);
    Empty(T->rchild);
    delete T;
    return NULL;
}

inline int Height(AVLTree T)//计算高度
{
    if(T==NULL) return 0;
    return T->height;
}

void updateHeight(AVLTree &T)
{
     T->height=max(Height(T->lchild),Height(T->rchild))+1;
}

AVLTree LL_Rotation(AVLTree &T)//LL旋转
{
    AVLTree temp=T->lchild;
    T->lchild=temp->rchild;
    temp->rchild=T;
    updateHeight(T);//更新高度
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T)//RR旋转
{
    AVLTree temp=T->rchild;
    T->rchild=temp->lchild;
    temp->lchild=T;
    updateHeight(T);//更新高度
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T)//LR旋转
{
     T->lchild=RR_Rotation(T->lchild);
     return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T)//RL旋转
{
    T->rchild=LL_Rotation(T->rchild);
    return RR_Rotation(T);
}

AVLTree Insert(AVLTree &T,int x)
{
    if(T==NULL) //如果为空，创建新结点
    {
        T=new AVLNode;
        T->lchild=T->rchild=NULL;
        T->data=x;
        T->height=1;
        return T;
     }
    if(T->data==x) return T;//查找成功，什么也不做，查找失败时才插入
    if(x<T->data)//插入到左子树
    {
        T->lchild=Insert(T->lchild,x);//注意插入后饭后结果挂接到T->lchild
        if(Height(T->lchild)-Height(T->rchild)==2)//插入后看是否平衡，如果不平衡显然是插入的那一边高度大
        {                                         //沿着高度大的那条路径判断
            if(x<T->lchild->data)//判断是LL还是LR,即插入的是lchild节点的lchild 还是rchild
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }
    else//插入到右子树
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

AVLTree adjust(AVLTree &T)//删除结点后，需要判断是否还是平衡，如果不平衡，就要调整
{
    if(T==NULL) return NULL;
    if(Height(T->lchild)-Height(T->rchild)==2)//沿着高度大的那条路径判断
    {
        if(Height(T->lchild->lchild)>=Height(T->lchild->rchild))
            T=LL_Rotation(T);
        else
            T=LR_Rotation(T);
    }
    if(Height(T->rchild)-Height(T->lchild)==2)//沿着高度大的那条路径判断
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
    if(T->data==x)//如果找到删除节点
    {
        if(T->rchild==NULL)//如果该节点的右孩子为NULL,那么直接删除
        {
            AVLTree temp=T;
            T=T->lchild;
            delete temp;
        }
        else//否则，将其右子树的最左孩子作为这个节点，并且递归删除这个节点的值
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

    if(T->data>x)//调节删除节点后可能涉及的节点
        T->lchild=Delete(T->lchild,x);
    if(T->data<x)
        T->rchild=Delete(T->rchild,x);
    updateHeight(T);
	T=adjust(T);
    return T;
}

void Preorder(AVLTree T)//前序遍历方便看树的结果
{
    if(T==NULL) return ;
    cout<<T->data<<"\t"<<T->height<<endl;
    Preorder(T->lchild);
    Preorder(T->rchild);
}

 void Inorder(AVLTree T)//中序遍历方便看树的结果
{
    if(T==NULL) return ;
    Inorder(T->lchild);
    cout<<T->data<<"\t"<<T->height<<endl;
    Inorder(T->rchild);
}

 void Posorder(AVLTree T)//后序遍历方便看树的结果
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
