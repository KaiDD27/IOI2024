#include<cstdio>//求包含49的个数
#include<cstring>
using namespace std;
typedef long long LL;//注意！！本题数据类型为ll 
const int N=30;
int dig[N];
LL dp[N][2],z[N],n;
//dp[pos][sta]表示当前第pos位，sta状态下满足条件的个数，sta表示前一位是否是4，只有0和1两种状态
LL dfs(int pos,bool sta,bool limit){//求包含49的个数
    if(!pos) return 0;
    if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
    int len=limit?dig[pos]:9;
    LL ans=0;
    for(int i=0;i<=len;i++){
        if(sta&&i==9)
        	ans+=limit?n%z[pos-1]+1:z[pos-1];
        else
        	ans+=dfs(pos-1,i==4,limit&&i==len);
    }
    if(!limit) dp[pos][sta]=ans;
    return ans;
}

LL solve(LL x){//求解[1..x]之间满足条件的个数 
    int pos=0;
    while(x){
        dig[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,1);
}

int main(){
    memset(dp,-1,sizeof(dp));
    z[0]=1;
	for(int i=1;i<N;i++)
		z[i]=z[i-1]*10;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		printf("%I64d\n",solve(n));
	}
    return 0;
}
