#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int INF=0x7fffffff;
const int MAX_LEVEL=16;
using namespace std;
int n,Min,ans,add,k,total;//�������ޣ��뿪��˾Ա����
char ch[5]; 
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

int RandomLevel(){ //������ѡ������Ӧ�����Ĳ����
	int lay=0;
	while(rand()%2&&lay<MAX_LEVEL-1)
		lay++;
	return lay;
}

int Find(int val){//������ӽ�val��Ԫ�� 
	Nodeptr p=head;
	tot[level]=0;
	for(int i=level;i>=0;i--){
		while(p->forward[i]&&p->forward[i]->val<val)
			tot[i]+=p->sum[i],p=p->forward[i];
		if(i>0)
			tot[i-1]=tot[i];
		updata[i]=p;//��¼���������и����߹������ڵ�λ�� 
	}
	return tot[0];//����С��val������ 
}

void Insert(int val){
	Nodeptr p,s;
	int lay=RandomLevel();
	if(lay>level){//Ҫ����Ĳ�>���в���
		for(int i=level+1;i<=lay;i++)
			head->sum[i]=total;
		level=lay;
	}
	Find(val); //��ѯ
	s=new Node;//����һ���½ڵ� 
	s->val=val;
	for(int i=0;i<MAX_LEVEL;i++){
		s->forward[i]=NULL;
		s->sum[i]=0;
	}
	for(int i=0;i<=lay;i++){//�������
		s->forward[i]=updata[i]->forward[i];
		updata[i]->forward[i]=s;
		s->sum[i]=updata[i]->sum[i]-(tot[0]-tot[i]);
        updata[i]->sum[i]-=s->sum[i]-1;
	}
	for(int i=lay+1;i<=level;i++)
		updata[i]->sum[i]++;
}

int Delete(int val){
    int sum=Find(val);
    for(int i=0;i<=level;i++){
		head->forward[i]=updata[i]->forward[i];
        head->sum[i]=updata[i]->sum[i]-(tot[0]-tot[i]);
    }
	while(level>0&&!head->forward[level])//ɾ������ 
		level--;
    return sum;
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
    srand((unsigned)time(0));
	Init();
	scanf("%d%d",&n,&Min);
    ans=add=total=0;
    for(int i=0;i<n;i++){
		scanf("%s%d",ch,&k);
        if(ch[0]=='I'&&k>=Min) Insert(k-add),total++;
        else if(ch[0]=='A') add+=k;
        else if(ch[0]=='S'){
            add-=k;
			int sum=Delete(Min-add);
			ans+=sum;
			total-=sum;
        }
        else if(ch[0]=='F'){
			if(k>total) puts("-1");
            else printf("%d\n",Get_kth(total-k+1)+add);
    	} 
	}
    printf("%d\n",ans);
    return 0;
}
