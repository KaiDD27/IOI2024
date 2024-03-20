#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=2000+10;
int n,m,dp[maxn][maxn],w[30];
string s;

int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		char c;
		int k1,k2;
		cin>>c>>k1>>k2;
		w[c-'a']=min(k1,k2);
	}
	for(int i=m-1;i>=0;i--)
		for(int j=i+1;j<m;j++){
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1];
			else
				dp[i][j]=min(dp[i+1][j]+w[s[i]-'a'],dp[i][j-1]+w[s[j]-'a']);
		}
	cout<<dp[0][m-1]<<endl;
	return 0;
}
