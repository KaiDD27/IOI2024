#include<cstdio>//����������У�ʱ�临�Ӷ�O(n^2)
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int dp[maxn];//dp[i]��ʾ����a[i]��β����������г��� 
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
            if(a[j]<a[i])//��̬����ÿһ��Ԫ����Ϊ���һ��Ԫ�ص�����������еĳ���
                dp[i]=max(dp[i],dp[j]+1);
        if(dp[i]>ans)
            ans=dp[i];//�������ֵ
    }
    printf("%d\n",ans);
    return 0;
}
