#include<cstdio>//回溯法，m叉树 
#include<cmath>
using namespace std;
int n,ans;
int x[15],s[15];

bool check(int t){
	for(int j=1;j<t;j++){
		if((x[t]==x[j])||(t-j==abs(x[t]-x[j])))
			return false;
	}
	return true;
}

void Backtrack(int t){
	if(t>n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		x[t]=i;
		if(check(t))
			Backtrack(t+1);
	}
}

int main(){
	for(int i=1;i<=10;i++){//先预处理，否则超时 
		ans=0;
		n=i;
		Backtrack(1);
		s[i]=ans;
	}
	while(~scanf("%d",&n),n){
		printf("%d\n",s[n]);
	}
	return 0;
}
