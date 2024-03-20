#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=10010,maxe=50010;
int n,m,cnt;
int head[maxn]; //链式前向星头 
int in[maxn],topo[maxn]; //入度,拓扑序列 
int ve[maxn]; //事件vi的最早发生时间
int vl[maxn]; //事件vi的最迟发生时间
stack<int>s;
struct node{
	int to,next,w;
}e[maxe];

void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	e[cnt++].w=w;
}

bool TopoSort(){//拓扑排序
	int cnt=0;
    for(int i=0;i<n;i++)
        if(in[i]==0)
        	s.push(i);
    while(!s.empty()){
		int u=s.top();
    	s.pop();
    	topo[cnt++]=u;
    	for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to;
            if(--in[v]==0)
        		s.push(v);
		}      
	}
	if(cnt<n) return 0;//该有向图有回路
	return 1;
}

bool CriticalPath(){//关键路径 
    if(TopoSort()){
        cout<<"拓扑序列为："<<endl;
        for(int i=0;i<n;i++)//输出拓扑序列
            cout<<topo[i]<<"\t";
        cout<<endl;
    }
    else{
    	cout<<"该图有环，无拓扑序列！"<<endl;
    	return 0;
	} 
    for(int i=0;i<n;i++)//初始化最早发生时间为0
		ve[i]=0;
    //按拓扑次序求每个事件的最早发生时间
    for(int j=0;j<n;j++){
		int u=topo[j];  //取得拓扑序列中的顶点
		for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to,w=e[i].w;
            if(ve[v]<ve[u]+w)
        		ve[v]=ve[u]+w;
		} 
    }
    for(int i=0;i<n;i++) //初始化每个事件的最迟发生时间为ve[n]
		vl[i]=ve[n-1];
    for(int j=n-1;j>=0;j--){//按逆拓扑序求每个事件的最迟发生时间
		int u=topo[j];  //取得拓扑序列中的顶点
		for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to,w=e[i].w;
            if(vl[u]>vl[v]-w)
        		vl[u]=vl[v]-w;
		}
    }
    cout<<"事件的最早发生时间和最迟发生时间："<<endl;
	for(int i=0;i<n;i++)
       cout<<ve[i]<<"\t"<<vl[i]<<endl;
	cout<<"关键活动路径为:"<<endl;
    for(int u=0;u<n;u++){ //每次循环针对vi为活动开始点的所有活动
		for(int i=head[u];~i;i=e[i].next){
    		int v=e[i].to,w=e[i].w;
            int e=ve[u];    //计算活动<vi, vj>的最早开始时间e
			int l=vl[v]-w; //计算活动<vi, vj>的最迟开始时间l
			if(e==l)   //若为关键活动，则输出<vi, vj>
				cout<<"<"<<u<<","<<v<<">"<<endl;
		}
	}
	return 1;
}

int main(){
    int u,v,w;
	cin>>n>>m;
	memset(head,-1,sizeof(head));
    memset(in,0,sizeof(in));
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        in[v]++;
    }
    CriticalPath();
    return 0;
}
/*测试数据 
6 8
0 1 2
0 2 15
1 3 10
1 4 19
2 1 4
2 4 11
3 5 6
4 5 5
*/

