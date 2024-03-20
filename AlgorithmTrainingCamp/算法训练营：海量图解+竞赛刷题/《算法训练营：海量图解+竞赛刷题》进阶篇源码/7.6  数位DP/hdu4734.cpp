#include<cstdio>
#include<cstring>
using namespace std;
const int N=50000;
int dig[25],a,b;
int dp[11][N];
//dp[pos][j]表示当前第pos位，小于等于j的个数
int dfs(int pos,int fa,bool limit){
    if(pos==-1) return fa>=0;
    if(fa<0) return 0;
    if(!limit&&dp[pos][fa]!=-1) return dp[pos][fa];
    int len=limit?dig[pos]:9;
    int ans=0;
    for(int i=0;i<=len;i++)
        ans+=dfs(pos-1,fa-i*(1<<pos),limit&&i==len);
    if(!limit) dp[pos][fa]=ans;
    return ans;
}

int f(int n){
    int ans=0,len=1;
    while(n){
        ans+=n%10*len;
        len*=2;
        n/=10;
    }
    return ans;
}

int solve(int x){//求解小于f(a)满足条件的个数 
    int pos=0;
    while(x){
        dig[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,f(a),1);
}

int main(){
	int T,cas=1;
	scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
	while(T--){
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",cas++,solve(b));
	}
    return 0;
}
