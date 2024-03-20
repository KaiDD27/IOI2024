#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int K=26;
struct node
{
	node *fail;
	node *ch[K];
	int count;
	node()
	{
		fail=NULL;
		memset(ch,NULL,sizeof(ch));
		count=0;
	}
};
node *superRoot,*root;//超根，树根 

void init()//初始化 
{
	superRoot=new node;
	root=new node;
	root->fail=superRoot;
	for(int i=0;i<K;i++)
		superRoot->ch[i]=root;
	superRoot->count=-1;
}

void insert(char* str)//Trie的插入 
{
    node *t=root;
    int len=strlen(str);
	for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        if(t->ch[x]==NULL)
            t->ch[x]=new node;
        t=t->ch[x];
    }
    t->count++;
}

void build_ac()
{
	queue<node*> q;//队列，BFS使用 
	q.push(root);
	while(!q.empty())
	{
		node *t;
		t=q.front();
		q.pop();
		for(int i=0;i<K;i++)
    	{
	        if(t->ch[i])
	        {
	        	t->ch[i]->fail=t->fail->ch[i];
	        	q.push(t->ch[i]);
			}
	        else
			    t->ch[i]=t->fail->ch[i];
    	}
	}
}

int query(char *str)
{
	int ans=0;
	node *t=root;
    int len=strlen(str);
	for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        t=t->ch[x];
        for(node *u=t;u->count!=-1;u=u->fail)
        {
        	ans+=u->count;
        	u->count=-1;
		}
	}
	return ans;	
}

int main()
{
    int T, n;
    char str1[1000010],str2[55];
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s", str2);
            insert(str2);
        }
        build_ac();
        scanf("%s",str1);
        printf("%d\n",query(str1));
    }
    return 0;
}
