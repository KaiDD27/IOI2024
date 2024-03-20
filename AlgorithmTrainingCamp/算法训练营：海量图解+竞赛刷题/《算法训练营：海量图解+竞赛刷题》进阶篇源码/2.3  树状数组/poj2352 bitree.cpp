#include<cstdio>
using namespace std;
#define maxn 32010
#define lowbit(x) (x)&(-x)
int ans[maxn],c[maxn];//等级统计，每个值的数量 
int n;

void add(int i,int val){//将第i个元素增加val，其后继也要增加
    while(i<=maxn){//是x点的范围，注意不是星星的个数n 
        c[i]+=val;
        i+=lowbit(i);//i的后继（父结点） 
    }
}

int sum(int i){//前缀和 
    int s=0;
    while(i>0){
        s+=c[i];
        i-=lowbit(i);//i的前驱
    }
    return s;
}

int main(){
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        x++;
        ans[sum(x)]++;
        add(x,1);//x的数量c[x]增1
    }
    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
	return 0;
}
