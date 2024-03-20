#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int sum=0;
typedef struct node{
    string word;
    struct node *l,*r;
	int cnt;
}*nodeptr;
nodeptr rt;
string w;

void insertBST(nodeptr &root,string s){//���ַ���s���뵽����������root�� 
    if(root==NULL){
		nodeptr p=new node;
        p->l=p->r=NULL;
        p->cnt=1;
       	p->word=s;
        root=p;
    }
    else if(s==root->word)
       		root->cnt++;
        else if(s<root->word)
            	insertBST(root->l,s);
        	else
        		insertBST(root->r,s);
}

void midprint(nodeptr root){//������� 
    if(root!=NULL){
        midprint(root->l);
        cout<<root->word;
        printf(" %.4lf\n",((double)root->cnt/(double)sum)*100);
        midprint(root->r);
    }
}

int main(){
    rt=NULL;//һ��Ҫ��ʼ�� 
	while(getline(cin,w)){//������س�����ctrl+z���س�
		insertBST(rt,w); 
        sum++;
    }
    midprint(rt);
    return 0;
}
