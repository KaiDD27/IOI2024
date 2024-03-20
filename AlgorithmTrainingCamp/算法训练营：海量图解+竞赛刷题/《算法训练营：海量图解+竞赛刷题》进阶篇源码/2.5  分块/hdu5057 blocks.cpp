#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 100010
int a[maxn],belong[maxn],L[maxn],R[maxn],block[400][12][12],n,m;
//block[i][j][k]表示第i块中第j位上是k的数有多少个
int ten[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

void build(){
    int t=sqrt(n);
    int num=n/t;
    if(n%t)  num++;
    for(int i=1;i<=num;i++){
        L[i]=(i-1)*t+1;//每块的左右 
        R[i]=i*t;
    }
    R[num]=n;
    for(int i=1;i<=n;i++)
		belong[i]=(i-1)/t+1;//所属块 
    for(int i=1;i<=n;i++){
        int temp=a[i];
        for(int j=1;j<=10;j++){//位数最多有10位1<=D<=10
            block[belong[i]][j][temp%10]++;//块，位，位上的数 
            temp/=10;
        }
    }
}

int query(int l,int r,int d,int p){
    int ans=0;
    if(belong[l]==belong[r]){//属于同一块
        for(int i=l;i<=r;i++)//暴力统计 
            if((a[i]/ten[d])%10==p)
				ans++;
        return ans;
    }
    for(int i=belong[l]+1;i<belong[r];i++)//累加中间块 
		ans+=block[i][d][p];
    for(int i=l;i<=R[belong[l]];i++){//左端暴力累加 
        if((a[i]/ten[d])%10==p)
			ans++;
    }
    for(int i=L[belong[r]];i<=r;i++){//右端暴力累加
        if((a[i]/ten[d])%10==p)
			ans++;
    }
    return ans;
}

void update(int x,int y){
    for(int i=1;i<=10;i++){//原来的统计数减少 
        block[belong[x]][i][a[x]%10]--;
        a[x]/=10;
    }
    a[x]=y;
    for(int i=1;i<=10;i++){//新的统计数增加 
        block[belong[x]][i][y%10]++;
        y/=10;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(block,0,sizeof(block));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
        build();//划分块 
        char s[5];
        while(m--){
            scanf("%s",s);
            if(s[0]=='S'){
                int x,y;
                scanf("%d%d",&x,&y);
                update(x,y);
            }
            else{
                int l,r,d,p;
                scanf("%d%d%d%d",&l,&r,&d,&p);
                printf("%d\n",query(l,r,d,p));
            }
        }
    }
    return 0;
}
