#include<cstdio>
using namespace std;
const int maxn=100005;
int n,cnt,root;//����������洢�±��ۼƣ����� 
struct node{
	int son[2];//���Һ���0,1
	int val,fa;//ֵ������ 
}tr[maxn];

void init(){
	cnt=root=0;
	tr[0].son[0]=tr[0].son[1]=0;
}

void print(int rt){//�����������
	if(!rt) return;
	if(tr[rt].son[0])
		print(tr[rt].son[0]);
	printf("val: %d lc: %d rc: %d\n",tr[rt].val,tr[tr[rt].son[0]].val,tr[tr[rt].son[1]].val);
	if(tr[rt].son[1])
		print(tr[rt].son[1]);
}

int New(int father,int val){//�����½�� 
	tr[++cnt].fa=father;
	tr[cnt].val=val;
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

void Splay(int x,int goal){//˫����չ����x��תΪgoal�Ķ���
    while(tr[x].fa!=goal){
        int y=tr[x].fa,z=tr[y].fa;
        if(z!=goal)
            (tr[z].son[0]==y)^(tr[y].son[0]==x)?Rotate(x):Rotate(y);
        Rotate(x);
    }
    if(!goal) root=x;//���goal��0������¸�Ϊx
}

//void Splay(int x,int goal){//������չ����x��תΪgoal�Ķ���
//	while(tr[x].fa!=goal)
//		Rotate(x);
//	if(!goal)
//		root=x;
//}

void Insert(int val){//����ֵval 
	int x;
	for(x=root;tr[x].son[tr[x].val<val];x=tr[x].son[tr[x].val<val]);//��λ��
	tr[x].son[tr[x].val<val]=New(x,val);
	Splay(tr[x].son[tr[x].val<val],0);//�²�������ת���� 
}

bool Find(int val){//����ֵval 
	int x=root;
	while(x){
		if(tr[x].val==val){
			Splay(x,0);//x��ת����
			return 1;
		}
		if(tr[x].son[tr[x].val<val])
			x=tr[x].son[tr[x].val<val];
		else{//����ʧ�� 
			Splay(x,0);//x��ת����
			return 0;
		}
	}
}

void Findmax(){//�����ֵ���
	int x=root;
	if(x){
		while(tr[x].son[1])
			x=tr[x].son[1];
		Splay(x,0);//x��ת����
	}
}

void Findmin(){//����Сֵ��� 
	int x=root;
	if(x){
		while(tr[x].son[0])
			x=tr[x].son[0];
		Splay(x,0);//x��ת����
	}	
}

bool Split(int val,int &t1,int &t2){
	if(Find(val)){//���ҳɹ�
		t1=tr[root].son[0];
		t2=tr[root].son[1];
		root=t1;
		tr[t1].fa=tr[t2].fa=0;
		return 1;
	}
	return 0;
}

void Join(int t1,int t2){
	if(t1){
		Findmax();//����t1�����ֵ
		tr[root].son[1]=t2;
		tr[t2].fa=root;
	}
	else
		root=t2;
}

void Delete(int val){//ɾ��ֵval
	int t1=0,t2=0;
	if(Split(val,t1,t2))
		Join(t1,t2);
}

int main(){
	int num,val;
	init();
	while(scanf("%d",&n),n){
		switch(n){
			case 1:
				scanf("%d",&val);
				Insert(val);
				print(root);
				puts(" ");
				break;
			case 2:
				Findmax();
				printf("%d\n",tr[root].val);
				break;
			case 3:
				Findmin();
				printf("%d\n",tr[root].val);
				break;
			case 4:
				scanf("%d",&val);
				Delete(val);
				print(root);
				puts(" ");
				break;	
		}	
	}
	return 0;
}
