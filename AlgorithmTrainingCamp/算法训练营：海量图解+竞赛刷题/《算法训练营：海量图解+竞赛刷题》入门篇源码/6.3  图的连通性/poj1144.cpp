#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
int n,root,head[maxn],cnt,low[maxn],dfn[maxn],num;
bool cut[maxn];
struct Edge{
	int to,next;
}e[maxn*maxn];

void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;	
}

void tarjan(int u){
	dfn[u]=low[u]=++num;
	int flag=0;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				flag++;
				if(u!=root||flag>1)//u不是根或者u是根但至少有两个子结点
					cut[u]=true; 			
			}
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
}

void init(){
	memset(head,0,sizeof(head));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(cut,false,sizeof(cut));
	cnt=num=0;
}

int main(){ 
	while(cin>>n&&n){
		init(); 
		int u,v;
		while(cin>>u&&u){
			while(1){
				char c=getchar();
				if(c=='\n')
					break;
				cin>>v;
				add(u,v);
				add(v,u);
			}
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i]){
				root=i;
				tarjan(i);
			}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(cut[i])
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}
