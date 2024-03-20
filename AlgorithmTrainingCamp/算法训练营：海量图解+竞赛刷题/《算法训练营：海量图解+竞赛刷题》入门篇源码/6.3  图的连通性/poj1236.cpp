#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=105;
int head[maxn],belong[maxn],out[maxn],in[maxn];
int n,m,low[maxn],dfn[maxn];
bool ins[maxn];
stack<int>s;
int cnt=0,num=0,id=0;
struct Egde{
	int to,next;
}e[maxn*maxn];

void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void tarjan(int u){//求解有向图强连通分量
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
		id++;
		do{
			v=s.top();
			s.pop();
			belong[v]=id;
			ins[v]=false;
		}while(v!=u);
	}
}

int main(){
	//ios::sync_with_stdio(0);//syn加速
	cin>>n;
	for(int i=1;i<=n;i++){
		int v;
		while(cin>>v&&v)
			add(i,v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int u=1;u<=n;u++)
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(belong[u]!=belong[v]){
				in[belong[v]]++;
				out[belong[u]]++;
			}		
		}
	if(id==1){
		cout<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=id;i++){
		if(!in[i])
			ans1++;
		if(!out[i])
			ans2++;	
	}
	cout<<ans1<<endl;
	cout<<max(ans1,ans2)<<endl;
	return 0;
}
