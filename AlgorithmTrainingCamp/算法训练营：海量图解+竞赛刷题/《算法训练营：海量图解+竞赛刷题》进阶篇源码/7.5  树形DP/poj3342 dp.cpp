#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
const int N=200+10;
int dp[N][2],f[N][2],n;
vector<int>E[N];

void dfs(int u){
   	dp[u][0]=0;
	dp[u][1]=1;
	for(int i=0;i<E[u].size();i++){
		int v=E[u][i];
		dfs(v);
		if(dp[v][0]==dp[v][1]){
			dp[u][0]+=dp[v][0];
			f[u][0]=0;
		}else if(dp[v][0]>dp[v][1]){
			dp[u][0]+=dp[v][0];
			if(!f[v][0]) f[u][0]=0;
		}
		else{
			dp[u][0]+=dp[v][1];
			if(!f[v][1]) f[u][0]=0;
		}
		dp[u][1]+=dp[v][0];
		if(!f[v][0]) f[u][1]=0;
	}
}

int main(){
	int n,k;
	string s1,s2;
	map<string,int>mp;
	while(cin>>n&&n){//n为0时结束 
		mp.clear();
		for(int i=0;i<=n;i++)//尽量不要使用memset清0的办法，尽管也可以用 
			E[i].clear();
		memset(f,1,sizeof(f));
		k=1;
		cin>>s1;
		mp[s1]=k++;
		E[0].push_back(mp[s1]);//增加超根 
		for(int i=1;i<=n-1;i++){
			cin>>s1>>s2;
			if(mp[s1]==0)
				mp[s1]=k++;
			if(mp[s2]==0)
				mp[s2]=k++;
			E[mp[s2]].push_back(mp[s1]);
		}
	    dfs(0);
	    printf("%d ",dp[0][0]);
	    if(f[0][0])
	    	printf("Yes\n");
		else
			printf("No\n");	
    }
    return 0;
}
