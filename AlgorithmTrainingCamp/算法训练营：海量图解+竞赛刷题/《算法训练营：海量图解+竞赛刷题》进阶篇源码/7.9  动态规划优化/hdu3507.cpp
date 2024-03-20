#include<cstdio>
using namespace std;
const int MAXN=5e5+5;
int s[MAXN],q[MAXN],dp[MAXN];
int n,m;

int GetY(int k1,int k2){
	return dp[k2]+s[k2]*s[k2]-(dp[k1]+s[k1]*s[k1]);
}

int GetX(int k1,int k2){
	return s[k2]-s[k1];
}

int GetVal(int i,int j){
    return dp[j]+(s[i]-s[j])*(s[i]-s[j])+m;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        s[0]=0;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i]);
            s[i]+=s[i-1];
        }
        int head=0,tail=0;
        q[tail++]=0;
        for(int i=1;i<=n;i++) {
            while(head+1<tail&&GetY(q[head],q[head+1])<=2*s[i]*GetX(q[head],q[head+1]))
                head++;
            dp[i]=GetVal(i,q[head]);
            while(head+1<tail&&GetY(q[tail-1],i)*GetX(q[tail-2],q[tail-1])<=GetY(q[tail-2],q[tail-1])*GetX(q[tail-1],i))
                tail--;
            q[tail++]=i;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
