#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int INF=0x7fffffff;
const int MAX_LEVEL=16;
using namespace std;

typedef struct Node{
	int num,val;
	struct Node *forward[MAX_LEVEL];
}*Nodeptr;

Nodeptr head,updata[MAX_LEVEL];
int level,max_k,min_k;

void Init(){
	level=0;
	max_k=-INF;
	min_k=INF;
	head=new Node;
	for(int i=0;i<MAX_LEVEL;i++)
		head->forward[i]=NULL;
	head->val=-INF;
}

int RandomLevel(){ //������ѡ������Ӧ�����Ĳ����
	int lay=0;
	while(rand()%2&&lay<MAX_LEVEL-1)
		lay++;
	return lay;
}

Nodeptr Find(int val){//������ӽ�val��Ԫ�� 
	Nodeptr p=head;
	for(int i=level;i>=0;i--){
		while(p->forward[i]&&p->forward[i]->val<val)
			p=p->forward[i];
		updata[i]=p;//��¼���������и����߹������ڵ�λ�� 
	}
	return p; 
}

void Insert(int num,int val){
	if(val>max_k) max_k=val;
	if(val<min_k) min_k=val;
	Nodeptr p,s;
	int lay=RandomLevel();
	if(lay>level) //Ҫ����Ĳ� > ���в���
		level=lay;
	p=Find(val); //��ѯ 
	s=new Node;//����һ���½ڵ� 
	s->num=num;
	s->val=val;
	for(int i=0;i<MAX_LEVEL;i++)
		s->forward[i]=NULL;
	for(int i=0;i<=lay;i++){//�������
		s->forward[i]=updata[i]->forward[i];
		updata[i]->forward[i]=s;
	}
}

void Delete(bool flag){//flag=0��ʾɾ����Сֵ��1��ʾɾ�����ֵ
	int d;
	if(flag) d=max_k;
	else d=min_k;
	if(d==-INF||d==INF){//˵����û�в���Ԫ��
		printf("0\n");
		return;
	}
	Nodeptr p=Find(d);
	if(p->forward[0]&&p->forward[0]->val==d){
		printf("%d\n",p->forward[0]->num);
		if(p->val==-INF&&!p->forward[0]->forward[0])//ɾ��Ψһ�ڵ� 
			max_k=-INF,min_k=INF;
		else{
			if(flag) max_k=p->val;
			else min_k=p->forward[0]->forward[0]->val;
		}
		for(int i=level;i>=0;i--){//ɾ������ 
			if(updata[i]->forward[i]&&updata[i]->forward[i]->val==d)
				updata[i]->forward[i]=updata[i]->forward[i]->forward[i];
		}	
	}
}

int main(){
	srand((unsigned)time(0));
	Init();
	int op,num,val;
	while(~scanf("%d",&op),op){
		if(op==1){
			scanf("%d%d",&num,&val);
			Insert(num,val);
		}
		else if(op==2)
			Delete(1);
		else 
			Delete(0);
	}
	return 0;
}
