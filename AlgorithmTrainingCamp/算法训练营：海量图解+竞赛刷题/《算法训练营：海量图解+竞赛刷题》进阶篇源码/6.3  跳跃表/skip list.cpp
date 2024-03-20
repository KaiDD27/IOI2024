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

int RandomLevel(){//随机产生插入元素高度 
	int lay=0;
	//printf("%d\n",rand());
	//printf("%d\n",RAND_MAX);
	while((float)rand()/RAND_MAX<P&&lay<MAX_LEVEL-1)//rand()产生的随机数范围是0~RAND_MAX
		lay++;	
	return lay;
}

Nodeptr Find(int val){//查找最接近val的元素 
	Nodeptr p=head;
	for(int i=level;i>=0;i--){
		while(p->forward[i]&&p->forward[i]->val<val)
			p=p->forward[i];
		updata[i]=p;//记录搜索过程中各级走过的最大节点位置 
	}
	return p; 
}

void Insert(int val){
	Nodeptr p,s;
	int lay=RandomLevel();
	printf("lay=%d\n",lay);
	if(lay>level) //要插入的层 > 现有层数
		level=lay;
	p=Find(val); //查询 
	s=new Node;//创建一个新节点 
	s->val=val;
	for(int i=0;i<MAX_LEVEL;i++)
		s->forward[i]=NULL;
	for(int i=0;i<=lay;i++){//插入操作
		s->forward[i]=updata[i]->forward[i];
		updata[i]->forward[i]=s;
	}
}

void Delete(int val){
	Nodeptr p=Find(val);
	if(p->forward[0]&&p->forward[0]->val==val){
		printf("%d\n",p->forward[0]->val);
		for(int i=level;i>=0;i--){//删除操作 
			if(updata[i]->forward[i]&&updata[i]->forward[i]->val==val)
				updata[i]->forward[i]=updata[i]->forward[i]->forward[i];
		}
		while(level>0&&!head->forward[level])//删除空链 
			level--;
	}
}

void print(int i){//遍历 
	Nodeptr p=head->forward[i];
	if(!p) return;
	while(p){
		printf("%d  ",p->val);
		p=p->forward[i];
	}
	printf("\n");
}

void printall(){//遍历所有层 
	for(int i=level;i>=0;i--)
		printf("level %d:  ",i),print(i);	
}

void show(){
	printf("Please select:\n");
	printf("-----------------------------\n");
	printf("     1:  插入\n");
	printf("     2:  删除\n");
	printf("     3:  查找\n");
	printf("     4:  遍历\n");
	printf("     5:  遍历所有层\n");
	printf("     0:  退出\n");
	printf("-----------------------------\n");
}

int main(){
	//time函数返回从1970年1月1日0时开始到现在逝去的秒数
	//可以利用srand((unsigned int)(time(NULL))的方法，产生不同的随机数种子，因为每一次运行程序的时间是不同的
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
