#include<cstdio>//˫����չ 
using namespace std;
const int maxn=100005;
int n,cnt,root;//����������洢�±��ۼƣ����� 
struct node{
	int son[2];//���Һ���0,1
	int val,fa;//ֵ������ 
	int num;//��� 
 }tr[maxn];

void Init(){
	cnt=root=0;
	tr[0].son[0]=tr[0].son[1]=0;
}

int New(int father,int val,int num){//�����½�� 
	tr[++cnt].fa=father;
	tr[cnt].val=val;
	tr[cnt].num=num;
	tr[cnt].son[0]=tr[cnt].son[1]=0;
	return cnt;
}

void Rotate(int x){//��ת
	int y=tr[x].fa,z=tr[y].fa;;
	int c=(tr[y].son[0]==x);
	tr[y].son[!c]=tr[x].son[c];
	tr[tr[x].son[c]].fa=y;
	tr[x].fa=z;
	if(z)
		tr[z].son[tr[z].son[1]==y]=x;
	tr[x].son[c]=y;
	tr[y].fa=x;
}

void Splay(int x,int goal){//��x��תΪgoal�Ķ���
    while(tr[x].fa!=goal){
        int y=tr[x].fa,z=tr[y].fa;
        if(z!=goal)
            (tr[z].son[0]==y)^(tr[y].son[0]==x)?Rotate(x):Rotate(y);
        Rotate(x);
    }
    if(!goal) root=x;//���goal��0������¸�Ϊx
}

void Insert(int val,int num){//����ֵval 
	int x;
	for(x=root;tr[x].son[tr[x].val<val];x=tr[x].son[tr[x].val<val]);
	tr[x].son[tr[x].val<val]=New(x,val,num);
	Splay(tr[x].son[tr[x].val<val],0);
}

void Delete(int x){//ɾ��x 
	if(x==root){
		if(!tr[x].son[0]&&!tr[x].son[1])
			Init();
		else{
			int t=tr[x].son[0]?0:1;
			tr[tr[x].son[t]].fa=0;
			root=tr[x].son[t];
		}
	}
	else{
		int y=tr[x].fa;
		int t=(tr[y].son[1]==x);
		tr[y].son[t]=tr[x].son[!t];
		tr[tr[x].son[!t]].fa=y;
		Splay(y,0);
	}
}

void Printmax(){//�����ȼ����Ľ����
	int x=root;
	if(x){
		while(tr[x].son[1])
			x=tr[x].son[1];
		printf("%d\n",tr[x].num);
		Delete(x);
	}else
		puts(0);
}

void Printmin(){//�����ȼ���͵Ľ����
	int x=root;
	if(x){
		while(tr[x].son[0])
			x=tr[x].son[0];
		printf("%d\n",tr[x].num);
		Delete(x);
	}else
		puts(0);	
}

int main(){
	int num,val;
	Init();
	while(scanf("%d",&n),n){
		switch(n){
			case 1:
				scanf("%d%d",&num,&val);
				Insert(val,num);
				break;
			case 2:
				Printmax();
				break;
			case 3:
				Printmin();
				break;
		}	
	}
	return 0;
}
