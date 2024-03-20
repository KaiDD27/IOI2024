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
inline int Height(AVLTree T)//����߶�,��ֹΪ��ʱ��ֵ 
{
    if(T==NULL) return 0;
    return T->height;
}

void updateHeight(AVLTree &T)
{
    T->height=max(Height(T->l),Height(T->r))+1;
}

AVLTree LL_Rotation(AVLTree &T)//LL��ת
{
    AVLTree temp=T->l;
    T->l=temp->r;
    temp->r=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree RR_Rotation(AVLTree &T)//RR��ת
{
    AVLTree temp=T->r;
    T->r=temp->l;
    temp->l=T;
    updateHeight(T);//���¸߶�
    updateHeight(temp);
    return temp;
}

AVLTree LR_Rotation(AVLTree &T)//LR��ת
{
     T->l=RR_Rotation(T->l);
     return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T)//RL��ת
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
				root->l=Insert(root->l,s);//ע�����󷵻ؽ���ҽӵ�root->l
		        if(Height(root->l)-Height(root->r)==2)//������Ƿ�ƽ�⣬�����ƽ����Ȼ�ǲ������һ�߸߶ȴ�
		        {                                         //���Ÿ߶ȴ������·���ж�
		            if(s<root->l->word)//�ж���LL����LR,���������lchild�ڵ��lchild ����rchild
		                root=LL_Rotation(root);
		            else
		                root=LR_Rotation(root);
		        }
			}
        	else
        	{
				root->r=Insert(root->r,s);//ע�����󷵻ؽ���ҽӵ�root->l
		        if(Height(root->r)-Height(root->l)==2)//������Ƿ�ƽ�⣬�����ƽ����Ȼ�ǲ������һ�߸߶ȴ�
		        {                                         //���Ÿ߶ȴ������·���ж�
		            if(s>root->r->word)//�ж���LL����LR,���������lchild�ڵ��lchild ����rchild
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
    rt=NULL;//һ��Ҫ��ʼ�� 
	while(getline(cin,w))//ע��:������س�����ctrl+z���س�!! 
	{
		Insert(rt,w); 
        sum++;
    }
    midprint(rt);
    return 0;
}
