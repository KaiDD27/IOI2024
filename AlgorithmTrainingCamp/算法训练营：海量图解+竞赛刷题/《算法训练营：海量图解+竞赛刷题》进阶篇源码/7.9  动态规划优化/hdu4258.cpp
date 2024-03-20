#include<cstdio>
using namespace std;
#define ll long long
const int MAXN=1e6+5;
ll a[MAXN],dp[MAXN];
int q[MAXN];
int n,c;

ll GetY(int k1,int k2){
	return dp[k2]+a[k2+1]*a[k2+1]-(dp[k1]+a[k1+1]*a[k1+1]);
}

ll GetX(int k1,int k2){
	return a[k2+1]-a[k1+1];
}

ll GetVal(int i,int j){
    return dp[j]+(a[i]-a[j+1])*(a[i]-a[j+1])+c;
}

int main(){
    while(~scanf("%d%d",&n,&c),n+c){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
		dp[0]=0;
        int head=0,tail=0;
        q[tail++]=0;
        for(int i=1;i<=n;i++) {
            while(head+1<tail&&GetY(q[head],q[head+1])<=2*a[i]*GetX(q[head],q[head+1]))
                head++;
            dp[i]=GetVal(i,q[head]);
            while(head+1<tail&&GetY(q[tail-1],i)*GetX(q[tail-2],q[tail-1])<=GetY(q[tail-2],q[tail-1])*GetX(q[tail-1],i))
                tail--;
            q[tail++]=i;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
