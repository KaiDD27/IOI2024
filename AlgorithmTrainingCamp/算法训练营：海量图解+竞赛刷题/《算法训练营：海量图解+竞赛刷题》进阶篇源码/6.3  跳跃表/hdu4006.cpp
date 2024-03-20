#include<cstdio>//G++可通过，C++出现Runtime Error(ACCESS_VIOLATION),最后检查出tot下标越界 
#include<cstdlib>
#include<ctime>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX_LEVEL=16;
using namespace std;
int total;//总节点数 
char ch; 
typedef struct Node{
	int val,sum[MAX_LEVEL];
	struct Node *forward[MAX_LEVEL];
}*Nodeptr;

Nodeptr head,updata[MAX_LEVEL];
int level,tot[MAX_LEVEL];

void Init(){
	level=0;
	head=new Node;
	for(int i=0;i<MAX_LEVEL;i++){
		head->forward[i]=NULL;
		head->sum[i]=0;
	}
	head->val=-INF;
}

int RandomLevel(){//按规则选择数据应该在哪层插入
	int lay=0;
	while(rand()%2&&lay<MAX_LEVEL-1)
		lay++;
	return lay;
}

int Find(int val){//查找最接近val的元素 
	Nodeptr p=head;
	tot[level]=0;
	for(int i=level;i>=0;i--){
		while(p->forward[i]&&p->forward[i]->val<val)
			tot[i]+=p->sum[i],p=p->forward[i];
		if(i>0)
			tot[i-1]=tot[i];//不判断会下标越界 
		updata[i]=p;//记录搜索过程中各级走过的最大节点位置 
	}
	return tot[0];//返回小于等于val的数量 
}

void Insert(int val){
	Nodeptr p,s;
	int lay=RandomLevel();
	if(lay>level){//要插入的层>现有层数
		for(int i=level+1;i<=lay;i++)
			head->sum[i]=total;
		level=lay;
	}
	Find(val); //查询
	s=new Node;//创建一个新节点 
	s->val=val;
	for(int i=0;i<MAX_LEVEL;i++){
		s->forward[i]=NULL;
		s->sum[i]=0;
	}
	for(int i=0;i<=lay;i++){//插入操作
		s->forward[i]=updata[i]->forward[i];
		updata[i]->forward[i]=s;
		s->sum[i]=updata[i]->sum[i]-(tot[0]-tot[i]);
        updata[i]->sum[i]-=s->sum[i]-1;
	}
	for(int i=lay+1;i<=level;i++)
		updata[i]->sum[i]++;
}

int Get_kth(int k){
    Nodeptr p=head;
	for(int i=level;i>=0;i--){
		while(p&&p->sum[i]<k)
			k-=p->sum[i],p=p->forward[i];
	}
	return p->forward[0]->val;
}

int main(){
    int n,k,val;
    srand((unsigned)time(0));
    while(~scanf("%d%d",&n,&k)){
    	Init();
    	total=0;
		for(int i=1;i<=n;i++){
			getchar();
			scanf("%c",&ch);
			if(ch=='I'){
				scanf("%d",&val);
				Insert(val);
				total++;
			}
			else printf("%d\n",Get_kth(total-k+1));
		}
    }
    return 0;
}
