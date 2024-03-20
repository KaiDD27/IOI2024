#include<iostream>
#include<algorithm>
using namespace std;
int n,k;

int dfs(int t){
	if(t<=n)
		return n-t;
	if(t%2)
		return min(dfs(t+1)+1,dfs(t-1)+1);
	else
		return min(dfs(t/2)+1,t-n);
}

int main(){
	while(cin>>n>>k){
		int ans=0;
		if(n==0){//特殊情况判断，很重要
			n=1;
			ans=1;
		}
		ans+=dfs(k);
		cout<<ans<<endl;
	}
	return 0;
}
