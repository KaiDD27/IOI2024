#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 100010
int a[maxn],belong[maxn],L[maxn],R[maxn],block[400][12][12],n,m;
//block[i][j][k]��ʾ��i���е�jλ����k�����ж��ٸ�
int ten[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

void build(){
    int t=sqrt(n);
    int num=n/t;
    if(n%t)  num++;
    for(int i=1;i<=num;i++){
        L[i]=(i-1)*t+1;//ÿ������� 
        R[i]=i*t;
    }
    R[num]=n;
    for(int i=1;i<=n;i++)
		belong[i]=(i-1)/t+1;//������ 
    for(int i=1;i<=n;i++){
        int temp=a[i];
        for(int j=1;j<=10;j++){//λ�������10λ1<=D<=10
            block[belong[i]][j][temp%10]++;//�飬λ��λ�ϵ��� 
            temp/=10;
        }
    }
}

int query(int l,int r,int d,int p){
    int ans=0;
    if(belong[l]==belong[r]){//����ͬһ��
        for(int i=l;i<=r;i++)//����ͳ�� 
            if((a[i]/ten[d])%10==p)
				ans++;
        return ans;
    }
    for(int i=belong[l]+1;i<belong[r];i++)//�ۼ��м�� 
		ans+=block[i][d][p];
    for(int i=l;i<=R[belong[l]];i++){//��˱����ۼ� 
        if((a[i]/ten[d])%10==p)
			ans++;
    }
    for(int i=L[belong[r]];i<=r;i++){//�Ҷ˱����ۼ�
        if((a[i]/ten[d])%10==p)
			ans++;
    }
    return ans;
}

void update(int x,int y){
    for(int i=1;i<=10;i++){//ԭ����ͳ�������� 
        block[belong[x]][i][a[x]%10]--;
        a[x]/=10;
    }
    a[x]=y;
    for(int i=1;i<=10;i++){//�µ�ͳ�������� 
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
        build();//���ֿ� 
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
