#include<cstdio>//最长上升子序列，时间复杂度O(n^2)
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int dp[maxn];//dp[i]表示从以a[i]结尾的最长上升序列长度 
int a[maxn];

int main(){
    int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    int ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i]=1;
		for(int j=1;j<i;j++)
            if(a[j]<a[i])//动态更新每一个元素作为最后一个元素的所构造的序列的长度
                dp[i]=max(dp[i],dp[j]+1);
        if(dp[i]>ans)
            ans=dp[i];//更新最大值
    }
    printf("%d\n",ans);
    return 0;
}
