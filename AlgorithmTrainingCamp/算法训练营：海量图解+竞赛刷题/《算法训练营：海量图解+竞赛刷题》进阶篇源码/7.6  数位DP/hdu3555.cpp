#include<cstdio>//�����49�ĸ���
#include<cstring>
using namespace std;
typedef long long LL;//ע�⣡��������������Ϊll 
const int N=30;
int dig[N];
LL dp[N][2],z[N],n;
//dp[pos][sta]��ʾ��ǰ��posλ��sta״̬�����������ĸ�����sta��ʾǰһλ�Ƿ���4��ֻ��0��1����״̬
LL dfs(int pos,bool sta,bool limit){//�����49�ĸ���
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

LL solve(LL x){//���[1..x]֮�����������ĸ��� 
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
