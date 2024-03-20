#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int sum=0;
typedef struct node{
    string word;
    struct node *l,*r;
	int cnt,height;
}*AVLTree;
AVLTree rt;
string w;
inline int Height(AVLTree T)//计算高度,防止为空时无值 
{
    if(T==NULL) return 0;
    return T->height;
}

void updateHeight(AVLTree &T)
{
    T->height=max(Height(T->l),Height(T->r))+1;
}

AVLTree LL_Rotation(AVLTree &T)//LL旋转
{
    AVLTree temp=T->l;
    T->l=temp->r;
    temp->r=T;
    updateHeight(T);//更新高度
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T)//RR旋转
{
    AVLTree temp=T->r;
    T->r=temp->l;
    temp->l=T;
    updateHeight(T);//更新高度
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T)//LR旋转
{
     T->l=RR_Rotation(T->l);
     return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T)//RL旋转
{
    T->r=LL_Rotation(T->r);
    return RR_Rotation(T);
}

AVLTree Insert(AVLTree &root,string s)
{
    if(root==NULL)
	{
		AVLTree p=new node;
        p->l=p->r=NULL;
        p->cnt=1;
       	p->word=s;
        root=p;
    }
    else if(s==root->word)
       		root->cnt++;
        else if(s<root->word)
        	{
				root->l=Insert(root->l,s);//注意插入后返回结果挂接到root->l
		        if(Height(root->l)-Height(root->r)==2)//插入后看是否平衡，如果不平衡显然是插入的那一边高度大
		        {                                         //沿着高度大的那条路径判断
		            if(s<root->l->word)//判断是LL还是LR,即插入的是lchild节点的lchild 还是rchild
		                root=LL_Rotation(root);
		            else
		                root=LR_Rotation(root);
		        }
			}
        	else
        	{
				root->r=Insert(root->r,s);//注意插入后返回结果挂接到root->l
		        if(Height(root->r)-Height(root->l)==2)//插入后看是否平衡，如果不平衡显然是插入的那一边高度大
		        {                                         //沿着高度大的那条路径判断
		            if(s>root->r->word)//判断是LL还是LR,即插入的是lchild节点的lchild 还是rchild
		                root=RR_Rotation(root);
		            else
		                root=RL_Rotation(root);
		        }
			}
	updateHeight(root);
    return root;
}

void midprint(AVLTree root)
{
    if(root!=NULL)
	{
        midprint(root->l);
        cout<<root->word;
        printf(" %.4lf\n",((double)root->cnt/(double)sum)*100);
        midprint(root->r);
    }
}

int main()
{
    rt=NULL;//一定要初始化 
	while(getline(cin,w))//注意:输入完回车，按ctrl+z，回车!! 
	{
		Insert(rt,w); 
        sum++;
    }
    midprint(rt);
    return 0;
}
