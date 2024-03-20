#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int K=126-32;//ASCII 0-126,0-32�޷���ʾ 
bool flag[510];

struct node{
	node *fail;
	node *ch[K];
	int count,id;
	node(){
		fail=NULL;
		memset(ch,NULL,sizeof(ch));
		count=0;
		id=0;
	}
};
node *superRoot,*root;//���������� 

void init(){//��ʼ�� 
	superRoot=new node;
	root=new node;
	root->fail=superRoot;
	for(int i=0;i<K;i++)
		superRoot->ch[i]=root;
	superRoot->count=-1;
}

void insert(char* str,int id){//Trie�Ĳ���
    node *t=root;
    int len=strlen(str);
	for(int i=0;i<len;i++){
        int x=str[i]-33;//��33���±�ת��Ϊ0
        if(t->ch[x]==NULL)
            t->ch[x]=new node;
        t=t->ch[x];
    }
    t->count++;
    t->id=id;
}

void build_ac(){
	queue<node*> q;//���У�BFSʹ�� 
	q.push(root);
	while(!q.empty()){
		node *t;
		t=q.front();
		q.pop();
		for(int i=0;i<K;i++){
	        if(t->ch[i]){
	        	t->ch[i]->fail=t->fail->ch[i];
	        	q.push(t->ch[i]);
			}
	        else
			    t->ch[i]=t->fail->ch[i];
    	}
	}
}

bool query(char *str){
	memset(flag,false,sizeof(flag));
	node *t=root;
	bool ok=false;
    int len=strlen(str);
	for(int i=0;i<len;i++){
        int x=str[i]-33;
        t=t->ch[x];
        for(node *u=t;u->count!=-1;u=u->fail){
        	if(u->count==1){
        		ok=true;
        		flag[u->id]=true;
			}
			//u->count=-1;//�ӵ㣬��Ҫ���ֵ����ı䣬����Ӱ����һ����ƥ�� 
		}
	}
	return ok;	
}

int main(){
    int n,m;
    char str1[10010],str2[205];
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",str2);
        insert(str2,i);
    }
    build_ac();
    scanf("%d",&m);
    int cnt=0;
    for(int i=1;i<=m;i++){
        scanf("%s",str1);
        if(query(str1)){
        	cnt++;
        	printf("web %d:",i);
        	for(int j=1;j<=n;j++)
        		if(flag[j])
        			printf(" %d",j);
        	printf("\n");	
		}
    }
    printf("total: %d\n",cnt);
    return 0;
}
