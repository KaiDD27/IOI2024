#include<cstdio>//�󲻰���49�ĸ���ans(������0)��Ȼ��n-ans
#include<cstring>
using namespace std;
typedef long long LL;//ע�⣡��������������Ϊll 
const int N=30;
int dig[N];
LL dp[N][2],n;
//dp[pos][sta]��ʾ��ǰ��posλ��sta״̬�����������ĸ�����sta��ʾǰһλ�Ƿ���4��ֻ��0��1����״̬
LL dfs(int pos,bool sta,bool limit){//�󲻰���49�ĸ���
    if(!pos) return 1;//����0 
    if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
    int len=limit?dig[pos]:9;
    LL ans=0;
    for(int i=0;i<=len;i++){
        if(sta&&i==9)
        	continue;
        ans+=dfs(pos-1,i==4,limit&&i==len);
    }
    if(!limit) dp[pos][sta]=ans;
    return ans;
}

LL solve(LL x){//���[1..x]֮�䲻����49�ĸ��� 
    int pos=0;
    while(x){
        dig[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,1)-1;//��ȥ0 
}

int main(){
    memset(dp,-1,sizeof(dp));
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		printf("%I64d\n",n-solve(n));
	}
    return 0;
}
