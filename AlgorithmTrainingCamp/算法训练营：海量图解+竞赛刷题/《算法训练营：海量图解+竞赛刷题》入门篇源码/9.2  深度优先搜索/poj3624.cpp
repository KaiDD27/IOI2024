#include<cstdio>//�����Ż���tle 
#include<algorithm>
using namespace std;
const int maxn=3500;
int w[maxn],v[maxn];//��������ֵ
int n,m;//����������
int cw,cp; //��ǰ��������ǰ��ֵ
int bestp; //��ǰ���ż�ֵ
struct goods{
    int id; //���
    double d;//��λ������ֵ
}a[maxn];

bool cmp(goods a,goods b){//������Ʒ��λ������ֵ�ɴ�С����
    return a.d>b.d;
}

double Bound(int i){//��ǰ�������ܼ�ֵcp��ʣ�����������ɵ�����ֵ
    int cleft=m-cw;//ʣ�౳������
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
    if(cw+w[a[t].id]<=m){//Լ��
        cw+=w[a[t].id];
        cp+=v[a[t].id];
        Backtrack(t+1);
        cw-=w[a[t].id];
        cp-=v[a[t].id];
    }
	if(Bound(t+1)>1.0*bestp)//�޽� 
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
