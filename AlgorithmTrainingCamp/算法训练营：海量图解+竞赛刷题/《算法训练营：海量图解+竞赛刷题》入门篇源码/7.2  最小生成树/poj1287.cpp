#include<iostream>
#include<algorithm>
using namespace std;
int fa[55],n,m,cnt;
struct node{
	int u,v,cost;
}edge[3000];

bool cmp(node x,node y){//定义排序优先级 
	return x.cost<y.cost;//按权值升序 
} 

void add(int a,int b,int c){
	edge[cnt].u=a;
	edge[cnt].v=b;
	edge[cnt++].cost=c;
}

int find(int x){//并查集找祖宗 
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool merge(int a,int b){//集合合并
	int x=find(a);
	int y=find(b);
	if(x==y) return 0;
	fa[y]=x;
	return 1;		
}

int kruskal(){
	int sum=0;
	sort(edge,edge+m,cmp);
	for(int i=0;i<m;i++){
		if(merge(edge[i].u,edge[i].v)){
			sum+=edge[i].cost;
			if(--n==1)
				return sum;
		}
	}
	return 0;
}

int main(){
	int x,y,z;
	while(cin>>n&&n){	
		cnt=0;
		cin>>m;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=0;i<m;i++){
			cin>>x>>y>>z;
			add(x,y,z);
		}
		cout<<kruskal()<<endl;
	}
	return 0;
}
