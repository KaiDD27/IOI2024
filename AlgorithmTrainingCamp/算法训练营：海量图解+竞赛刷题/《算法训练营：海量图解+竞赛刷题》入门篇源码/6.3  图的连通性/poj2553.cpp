#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=5050;
int head[maxn],belong[maxn],out[maxn];
int n,m,cnt,num,id,low[maxn],dfn[maxn];
bool ins[maxn];//标记是否在栈内 
stack<int>s;
struct Egde{
	int to,next;
}e[maxn<<1];

void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void init(){
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(ins,false,sizeof(ins));
	memset(out,0,sizeof(out));
	memset(belong,0,sizeof(belong));
	cnt=0;
	num=0;
	id=1;
}

void tarjan(int u){
	low[u]=dfn[u]=++num;
	ins[u]=true;
	s.push(u);
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		int v;
		do{
			v=s.top();
			s.pop();
			belong[v]=id;
			ins[v]=false;
		}while(v!=u);
		id++;
	}
}

int main(){
	while((cin>>n)&&n){
		cin>>m;
		init();
		while(m--){
			int u,v;
			cin>>u>>v;
			add(u,v);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int u=1;u<=n;u++)
			for(int i=head[u];i;i=e[i].next){
				int v=e[i].to;
				if(belong[u]!=belong[v])
					out[belong[u]]++; 
			}
		int flag=1;
		for(int i=1;i<=n;i++)
			if(!out[belong[i]]){
				if(flag)
					flag=0;
				else
					cout<<" ";
				cout<<i;
			}		
		cout<<endl;
	}
	return 0;
}
