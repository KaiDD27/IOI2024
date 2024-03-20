#include<iostream>
using namespace std;
const int M=105;
int i,j,n,W;//n��ʾn����Ʒ��W��ʾ����������
double w[M],v[M];//w[i] ��ʾ��i����Ʒ��������v[i] ��ʾ��i����Ʒ�ļ�ֵ
bool x[M];  //x[i]��ʾ��i����Ʒ�Ƿ���뱳��
double cw;  //��ǰ����
double cp;  //��ǰ��ֵ
double bestp;  //��ǰ���ż�ֵ
bool bestx[M]; //��ǰ���Ž�

double Bound(int i){//�����Ͻ磨����װ����Ʒ��ֵ+ʣ����Ʒ���ܼ�ֵ��
    //ʣ����ƷΪ��i~n����Ʒ
    int rp=0;
    while(i<=n){//���μ���ʣ����Ʒ�ļ�ֵ
        rp+=v[i];
        i++;
    }
    return cp+rp;
}

void Backtrack(int t){//���������ռ�����t��ʾ��ǰ��չ����ڵ�t��
    if(t>n){//�Ѿ�����Ҷ�ӽ��
        for(j=1;j<=n;j++)
            bestx[j]=x[j];
        bestp=cp;//���浱ǰ���Ž�
        return ;
    }
    if(cw+w[t]<=W){//�������Լ������������������
        x[t]=1;
        cw+=w[t];
        cp+=v[t];
        Backtrack(t+1);
        cw-=w[t];
        cp-=v[t];
    }
    if(Bound(t+1)>bestp){//��������޽�����������������
        x[t]=0;
        Backtrack(t+1);
    }
}

void Knapsack(double W, int n){
    cw=0;//��ʼ����ǰ���뱳������Ʒ����Ϊ0
    cp=0; //��ʼ����ǰ���뱳������Ʒ��ֵΪ0
    bestp=0; //��ʼ����ǰ����ֵΪ0
    double sumw=0.0; //����ͳ��������Ʒ��������
    double sumv=0.0; //����ͳ��������Ʒ���ܼ�ֵ
    for(i=1;i<=n;i++){
        sumv+=v[i];
        sumw+=w[i];
    }
    if(sumw<=W){
        bestp=sumv;
        cout<<"���뱳������Ʒ����ֵΪ: "<<bestp<<endl;
        cout<<"���е���Ʒ�����뱳����";
        return;
    }
    Backtrack(1);
    cout<<"���뱳������Ʒ����ֵΪ: "<<bestp<<endl;
    cout<<"���뱳������Ʒ���Ϊ: ";
    for(i=1;i<=n;i++){ //������Ž�
        if(bestx[i]==1)
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"��������Ʒ�ĸ���n�ͱ���������W:";
    cin>>n>>W;
    cout<<"����������ÿ����Ʒ������w�ͼ�ֵv,�ÿո�ֿ�:"<<endl;
    for(i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    Knapsack(W,n);
    return 0;
}
/*��������
4 10
2 6
5 3
4 5
2 4
*/
