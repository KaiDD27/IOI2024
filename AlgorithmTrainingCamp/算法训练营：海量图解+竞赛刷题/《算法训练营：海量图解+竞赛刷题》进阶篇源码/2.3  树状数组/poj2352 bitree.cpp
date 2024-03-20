#include<cstdio>
using namespace std;
#define maxn 32010
#define lowbit(x) (x)&(-x)
int ans[maxn],c[maxn];//�ȼ�ͳ�ƣ�ÿ��ֵ������ 
int n;

void add(int i,int val){//����i��Ԫ������val������ҲҪ����
    while(i<=maxn){//��x��ķ�Χ��ע�ⲻ�����ǵĸ���n 
        c[i]+=val;
        i+=lowbit(i);//i�ĺ�̣�����㣩 
    }
}

int sum(int i){//ǰ׺�� 
    int s=0;
    while(i>0){
        s+=c[i];
        i-=lowbit(i);//i��ǰ��
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
        add(x,1);//x������c[x]��1
    }
    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
	return 0;
}
