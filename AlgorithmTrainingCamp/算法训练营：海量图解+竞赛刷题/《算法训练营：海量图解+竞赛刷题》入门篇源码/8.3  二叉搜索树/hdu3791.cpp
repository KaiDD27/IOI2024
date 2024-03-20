#include<cstdio>
#include<cstring>
using namespace std;
int cnt;
char a[15],b[15],c[15];
typedef struct node{
    int num;
    node *lc,*rc;
}*nodeptr;
nodeptr root;

void Insert(nodeptr &t,int x){//��x���뵽����������t�� 
    nodeptr p;
    if(t==NULL){
        p=new node;
        p->lc=NULL;
        p->rc=NULL;
        p->num=x;	
        t=p;
	} 
	else{
        if(x<=t->num)
            Insert(t->lc,x);//���뵽������ 
        else
            Insert(t->rc,x);//���뵽������ 
    }
}

void preorder(nodeptr t,char b[]){//������� 
    if(t){
        b[cnt++]=t->num+'0';
        preorder(t->lc,b);
        preorder(t->rc,b);
    }
}

int main(){
    int n;
    while(scanf("%d",&n),n){
        cnt=0;
        root=NULL;
        scanf("%s",a);
        for(int i=0;a[i]!='\0';i++)
            Insert(root,a[i]-'0');
        preorder(root,b);
        b[cnt]='\0';
        while(n--){
            cnt=0;
            root=NULL;
            scanf("%s",a);
            for(int i=0;a[i]!='\0';i++)
                Insert(root,a[i]-'0');
            preorder(root,c);
            c[cnt]='\0';
            if(strcmp(b,c)==0)//c++�ַ���������==�Ƚ� 
				printf("YES\n");
 			else
			 	printf("NO\n");
        }
    }
    return 0;
}
