#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define N 100010
using namespace std;
ll a[N],sum[N],add[N];
int L[N],R[N],d;
int pos[N];
int n,m,t,l,r;
char op[3];

void build(){
	t=sqrt(n*1.0);//float sqrt (float),double sqrt (double),double long sqrt(double long)
			 //注意没有sqrt(int)，但是返回值可以为int
			 //也可以选择G++提交,否则int型做参数会提示编译问题 
    int num=n/t;
    if(n%t)  num++;
    for(int i=1;i<=num;i++){
        L[i]=(i-1)*t+1;//每块的左右 
        R[i]=i*t;
    }
    R[num]=n;
    for(int i=1;i<=num;i++)
		for(int j=L[i];j<=R[i];j++){
        	pos[j]=i;//表示属于哪个块
        	sum[i]+=a[j];//计算每块和值
		}
} 

void change(int l,int r,long long d){//区间[l,r]加上d 
    int p=pos[l],q=pos[r];//读所属块 
    if(p==q){//在一块中
        for(int i=l;i<=r;i++)//暴力修改 
			a[i]+=d;
        sum[p]+=d*(r-l+1);//修改和值 
    }
    else{
        for(int i=p+1;i<=q-1;i++)//中间完全覆盖块打懒标记 
			add[i]+=d;
        for(int i=l;i<=R[p];i++)//左端暴力修改 
			a[i]+=d;
        sum[p]+=d*(R[p]-l+1);
        for(int i=L[q];i<=r;i++)//右端暴力修改
			a[i]+=d;
        sum[q]+=d*(r-L[q]+1);
    }
}

ll query(int l,int r){
    int p=pos[l],q=pos[r];
    ll ans=0;
    if(p==q){//在一块中
        for(int i=l;i<=r;i++)//累加 
			ans+=a[i];
        ans+=add[p]*(r-l+1);//计算懒标记 
    }
    else{
        for(int i=p+1;i<=q-1;i++)//累加中间块 
        	ans+=sum[i]+add[i]*(R[i]-L[i]+1);
        for(int i=l;i<=R[p];i++)//左端暴力累加
			ans+=a[i];
        ans+=add[p]*(R[p]-l+1);
        for(int i=L[q];i<=r;i++)//右端暴力累加
			ans+=a[i];
        ans+=add[q]*(r-L[q]+1);
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(); 
    for(int i=1;i<=m;i++){
        scanf("%s %d %d",op,&l,&r);
        if(op[0]=='C'){
            scanf("%d",&d);
            change(l,r,d);
        }
        else
			printf("%lld\n",query(l,r));
    }
    return 0;
}
