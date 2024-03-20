#include<cstdio>//不加优化会tle 
#include<algorithm>
using namespace std;
const int maxn=3500;
int w[maxn],v[maxn];//重量，价值
int n,m;//数量，容量
int cw,cp; //当前重量，当前价值
int bestp; //当前最优价值
struct goods{
    int id; //序号
    double d;//单位重量价值
}a[maxn];

bool cmp(goods a,goods b){//按照物品单位重量价值由大到小排序
    return a.d>b.d;
}

double Bound(int i){//当前背包的总价值cp＋剩余容量可容纳的最大价值
    int cleft=m-cw;//剩余背包容量
    double brp=cp*1.0;
    while(i<=n&&w[a[i].id]<=cleft){
        cleft-=w[a[i].id];
        brp+=1.0*v[a[i].id];
        i++;
    }
    if(i<=n)
        brp+=cleft*a[i].d;
    return brp;
}

void Backtrack(int t){
    if(t>n){
        bestp=cp;
        return;
    }
    if(cw+w[a[t].id]<=m){//约束
        cw+=w[a[t].id];
        cp+=v[a[t].id];
        Backtrack(t+1);
        cw-=w[a[t].id];
        cp-=v[a[t].id];
    }
	if(Bound(t+1)>1.0*bestp)//限界 
       Backtrack(t+1);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=n;i++){
        a[i].id=i;
        a[i].d=1.0*v[i]/w[i];
    }
    sort(a+1,a+n+1,cmp);
    Backtrack(1);
    printf("%d\n",bestp);
    return 0;
}
