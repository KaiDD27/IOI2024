#include<cstdio>
#include<cstring>
#define MAXN 1000010
using namespace std;
int a[MAXN],Min[MAXN],Max[MAXN],Q[MAXN],n,k;

void get_min(){
    int st=0,ed=0;
    Q[ed++]=1;
    Min[1]=a[1];
    for(int i=2;i<=n;i++){
        while(st<ed&&a[i]<a[Q[ed-1]])//删除队尾元素
            ed--;                  //插入队尾元素
        Q[ed++]=i;
        while(st<ed&&Q[st]<i-k+1)//删除队首过时元素
            st++;
        Min[i]=a[Q[st]];
    }
}

void get_max(){
	int st=0,ed=0;
    Q[ed++]=1;
    Max[1]=a[1];
    for(int i=2;i<=n;i++){
        while(st<ed&&(a[i]>a[Q[ed-1]]))
            ed--;
        Q[ed++]=i;
        while(st<ed&&Q[st]<i-k+1)
            st++;
        Max[i]=a[Q[st]];
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    get_min();
    get_max();
    for(int i=k;i<n;i++)
        printf("%d ",Min[i]);
    printf("%d\n",Min[n]);
    for(int i=k;i<n;i++)
        printf("%d ",Max[i]);
    printf("%d\n",Max[n]);
    return 0;
}
