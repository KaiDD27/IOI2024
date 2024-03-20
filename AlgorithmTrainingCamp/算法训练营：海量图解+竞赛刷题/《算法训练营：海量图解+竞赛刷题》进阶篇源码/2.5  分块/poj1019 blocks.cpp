#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
typedef long long LL;
const int maxn=40000;
LL a[maxn],sum[maxn];//a[i]为第i组的长度，sum[i]为前i(包括i)组的总长度

int main(){
    int i,j;
    sum[0]=a[0]=0;
    for(i=1;i<maxn;i++){
        a[i]=a[i-1]+(int)log10((double)i)+1;
        sum[i]=sum[i-1]+a[i];
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        i=0;
        while(sum[i]<n) i++;  //确定n在第i组
        int pos=n-sum[i-1];  //确定n在第i组的第pos个位置
        int len=0,k=0;
        while(len<pos){
            k++;
            len+=(int)log10((double)k)+1;
        }
        printf("%d\n", k/(int)pow(10.0,len-pos)%10);
    }
    return 0 ;
}
