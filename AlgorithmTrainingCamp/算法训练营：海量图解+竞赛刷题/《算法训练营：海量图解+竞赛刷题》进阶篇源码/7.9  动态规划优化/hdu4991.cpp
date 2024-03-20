#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 123456789
#define ll __int64
using namespace std;
#define N 10005

ll a[N],b[N];
ll dp[N][105];
int n,m,len;

int lowbit(int x){
    return x&(-x);
}

void add(int i,int j,ll val){
    while(i<=len){
        dp[i][j]=(dp[i][j]+val)%mod;
        i+=lowbit(i);
    }
}

ll query(int i,int j){
    ll res=0;
    while(i>0){
        res=(res+dp[i][j])%mod;
        i-=lowbit(i);
    }
    return res;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            b[i]=a[i];
        }
		memset(dp,0,sizeof(dp));
        sort(b+1,b+n+1);
        len=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=n;i++){
            int pos=lower_bound(b+1,b+len+1,a[i])-b;
            add(pos,1,1);
            for(int j=2;j<=m;j++){
                int sum=query(pos-1,j-1);//ÇóÇ°×ººÍ 
                add(pos,j,sum);
            }
        }
        printf("%I64d\n",query(len,m));
    }
    return 0;
}
