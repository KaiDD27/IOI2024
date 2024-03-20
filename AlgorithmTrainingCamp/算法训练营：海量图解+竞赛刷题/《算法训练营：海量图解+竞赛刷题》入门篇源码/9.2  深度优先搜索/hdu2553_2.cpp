#include<cstdio>//回溯法，排列树 
#include<cmath>
#include<algorithm>
using namespace std;
int n,ans;
int x[15],s[15];

bool check(int t){
	for(int j=1;j<t;j++){
		if(t-j==abs(x[t]-x[j]))
			return false;
	}
	return true;
}

void Backtrack(int t){
	if(t>n){
		ans++;
		return;
	}
	for(int i=t;i<=n;i++){
		swap(x[t],x[i]);
		if(check(t))
			Backtrack(t+1);
		swap(x[t],x[i]);
	}
}

int main(){
	for(int i=1;i<=10;i++){//先预处理，否则超时 
		ans=0;
		n=i;
		for(int j=1;j<=10;j++)
			x[j]=j;
		Backtrack(1);
		s[i]=ans;
	}
	while(~scanf("%d",&n),n){
		printf("%d\n",s[n]);
	}
	return 0;
}
