#include<cstdio>
#include<cstring>
using namespace std;
const int N=10010;
int q[N],t[N],f[N],dp[N],sumt[N],sumf[N];
int n,s;

int GetY(int k1,int k2){
	return dp[k2]-dp[k1];
}
 
int GetX(int k1,int k2){
	return sumt[k2]-sumt[k1];
}

int GetVal(int i,int j){
	return dp[j]+(s+sumt[i]-sumt[j])*sumf[i];
}

int main() {
    while(~scanf("%d",&n)){
        scanf("%d",&s);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&t[i],&f[i]);
        sumt[n+1]=sumt[n+1]=0;
        for(int i=n;i>=1;i--){
            sumt[i]=sumt[i+1]+t[i];
            sumf[i]=sumf[i+1]+f[i];
        }
        int head=0,tail=0;
        q[tail++]=n+1;
        dp[n+1]=0;
        for(int i=n;i>=1;i--) {
            while(head+1<tail && GetY(q[head],q[head+1])<=GetX(q[head],q[head+1])*sumf[i])
				head++;
            dp[i]=GetVal(i,q[head]);
            while(head+1<tail && GetY(q[tail-1],i)*GetX(q[tail-2],q[tail-1])<=GetY(q[tail-2],q[tail-1])*GetX(q[tail-1],i))
				tail--;
            q[tail++]=i;
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}
