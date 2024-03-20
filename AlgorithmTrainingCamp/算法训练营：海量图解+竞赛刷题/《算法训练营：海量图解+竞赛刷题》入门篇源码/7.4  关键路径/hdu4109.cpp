#include<iostream>
#include<algorithm>//max函数 
#include<cstring>
#include<stack>
using namespace std;
const int maxn=1005;
int map[maxn][maxn],in[maxn],topo[maxn],d[maxn];
int n,m;
stack<int>s;

void TopoSort(){//按拓扑排序求最长距离 
	int cnt=0;
    for(int i=0;i<n;i++)
        if(in[i]==0){
        	s.push(i);
        	d[i]=1;
		}   	
    while(!s.empty()){
		int u=s.top();
    	s.pop();
    	topo[cnt++]=u;
    	for(int v=0;v<n;v++){
    		 if(map[u][v]){
            	d[v]=max(d[v],d[u]+map[u][v]);
				if(--in[v]==0)
        			s.push(v);
			}
		}    		
	}
}

int main(){
    int u,v,w;
	while(cin>>n>>m){
    	memset(map,0,sizeof(map));
    	memset(in,0,sizeof(in));
    	memset(d,0,sizeof(d));
		for(int i=1;i<=m;i++){
	        cin>>u>>v>>w;
	        map[u][v]=w;
	        in[v]++;
		}
		TopoSort();
		int ans=0;
	    for(int i=0;i<n;i++)
			ans=max(ans,d[i]);
	    cout<<ans<<endl;
	}
    return 0;
}
