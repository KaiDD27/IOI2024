#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int K=126-32;//ASCII 0-126,0-32无法显示 
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
node *superRoot,*root;//超根，树根 

void init(){//初始化 
	superRoot=new node;
	root=new node;
	root->fail=superRoot;
	for(int i=0;i<K;i++)
		superRoot->ch[i]=root;
	superRoot->count=-1;
}

void insert(char* str,int id){//Trie的插入
    node *t=root;
    int len=strlen(str);
	for(int i=0;i<len;i++){
        int x=str[i]-33;//第33个下标转化为0
        if(t->ch[x]==NULL)
            t->ch[x]=new node;
        t=t->ch[x];
    }
    t->count++;
    t->id=id;
}

void build_ac(){
	queue<node*> q;//队列，BFS使用 
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
			//u->count=-1;//坑点，不要对字典树改变，否则影响下一个串匹配 
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
