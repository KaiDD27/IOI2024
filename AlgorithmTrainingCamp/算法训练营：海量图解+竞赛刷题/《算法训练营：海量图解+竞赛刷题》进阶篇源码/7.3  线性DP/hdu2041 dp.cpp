#include<cstdio>
#define MAXN 40
using namespace std;
typedef unsigned long long LL;
LL fn[MAXN+1];

LL solve1(int n){//³¬Ê±
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(n==3)
        return 2;
    else
        return solve1(n-2)+solve1(n-1);
}

void solve(){
	fn[1]=0;
	fn[2]=1;
	fn[3]=2;
    for(int i=4;i<=MAXN;i++)
        fn[i]=fn[i-2]+fn[i-1];
}
 
int main(){
    int n,m;
    solve();
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        printf("%lld\n",fn[m]);
        //printf("%lld\n",solve1(m));
    }
    return 0;
}
