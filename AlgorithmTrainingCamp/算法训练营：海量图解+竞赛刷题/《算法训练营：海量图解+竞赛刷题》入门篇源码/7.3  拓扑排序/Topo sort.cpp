#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=105;
int map[maxn][maxn],indegree[maxn],topo[maxn];
int n,m;
stack<int>s;

bool TopoSort(){ //Õÿ∆À≈≈–Ú
	int cnt=0;
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
        	s.push(i);
    while(!s.empty()){
		int u=s.top();
    	s.pop();
    	topo[cnt++]=u;
    	for(int j=0;j<n;j++)
            if(map[u][j])
            	if(--indegree[j]==0)
        			s.push(j);	
	}
	if(cnt<n) return 0;
	return 1;
}

int main(){
    cin>>n>>m;
    memset(map,0,sizeof(map));
    memset(indegree,0,sizeof(indegree));
	for(int i=0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	map[u][v]=1;
    	indegree[v]++;
	}
	TopoSort();
	for(int i=0;i<n-1;i++)
		cout<<topo[i]<<" ";
	cout<<topo[n-1]<<endl;
    return 0;
}
/*≤‚ ‘ ˝æ›
6 8
0 1
0 2
0 3
2 1
2 4
3 4
5 3
5 4
*/ 
