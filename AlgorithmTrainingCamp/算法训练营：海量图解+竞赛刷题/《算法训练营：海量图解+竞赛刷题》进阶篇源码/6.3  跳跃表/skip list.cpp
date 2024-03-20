#include<cstdio>
#include<cstdlib>//rand()
#include<ctime>//time()
using namespace std;
const int INF=0x7fffffff;
const float P=0.5f;
const int MAX_LEVEL=16;
using namespace std;

typedef struct Node{
	int val;
	struct Node *forward[MAX_LEVEL];
}*Nodeptr;

Nodeptr head,updata[MAX_LEVEL];
int level;

void Init(){
	level=0;
	head=new Node;
	for(int i=0;i<MAX_LEVEL;i++)
		head->forward[i]=NULL;
	head->val=-INF;
}

int RandomLevel(){//�����������Ԫ�ظ߶� 
	int lay=0;
	//printf("%d\n",rand());
	//printf("%d\n",RAND_MAX);
	while((float)rand()/RAND_MAX<P&&lay<MAX_LEVEL-1)//rand()�������������Χ��0~RAND_MAX
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

void Insert(int val){
	Nodeptr p,s;
	int lay=RandomLevel();
	printf("lay=%d\n",lay);
	if(lay>level) //Ҫ����Ĳ� > ���в���
		level=lay;
	p=Find(val); //��ѯ 
	s=new Node;//����һ���½ڵ� 
	s->val=val;
	for(int i=0;i<MAX_LEVEL;i++)
		s->forward[i]=NULL;
	for(int i=0;i<=lay;i++){//�������
		s->forward[i]=updata[i]->forward[i];
		updata[i]->forward[i]=s;
	}
}

void Delete(int val){
	Nodeptr p=Find(val);
	if(p->forward[0]&&p->forward[0]->val==val){
		printf("%d\n",p->forward[0]->val);
		for(int i=level;i>=0;i--){//ɾ������ 
			if(updata[i]->forward[i]&&updata[i]->forward[i]->val==val)
				updata[i]->forward[i]=updata[i]->forward[i]->forward[i];
		}
		while(level>0&&!head->forward[level])//ɾ������ 
			level--;
	}
}

void print(int i){//���� 
	Nodeptr p=head->forward[i];
	if(!p) return;
	while(p){
		printf("%d  ",p->val);
		p=p->forward[i];
	}
	printf("\n");
}

void printall(){//�������в� 
	for(int i=level;i>=0;i--)
		printf("level %d:  ",i),print(i);	
}

void show(){
	printf("Please select:\n");
	printf("-----------------------------\n");
	printf("     1:  ����\n");
	printf("     2:  ɾ��\n");
	printf("     3:  ����\n");
	printf("     4:  ����\n");
	printf("     5:  �������в�\n");
	printf("     0:  �˳�\n");
	printf("-----------------------------\n");
}

int main(){
	//time�������ش�1970��1��1��0ʱ��ʼ��������ȥ������
	//��������srand((unsigned int)(time(NULL))�ķ�����������ͬ����������ӣ���Ϊÿһ�����г����ʱ���ǲ�ͬ��
	srand((unsigned int)time(0));
	Init();
	int n,x;
	show();
    while(~scanf("%d",&n),n){
        switch(n){
	        case 1:
	            scanf("%d",&x);
				Insert(x);break;
	        case 2:
	        	scanf("%d",&x);
	            Delete(x);break;
	        case 3:
	            scanf("%d",&x);
	            Nodeptr p;
				p=Find(x);
				if(p->forward[0]&&p->forward[0]->val==x)
					printf("find success!\n");
				else
					printf("find fail!\n");
				break;
	        case 4:
	            print(0);break;
	        case 5:
	            printall();break;  
        }
        show();
    }
	return 0;
}
