#include<iostream>//��ȫ���� 
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn];//dp[j]��ʾ��ǰ�ѷ�������Ϊj�ı�����õ�����ֵ
int w[M],v[M];//w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
int n,W;//n��ʾn����Ʒ��W��ʾ����������

void comp_knapsack(int n,int W){//��ȫ����
    for(int i=1;i<=n;i++)
		for(int j=w[i];j<=W;j++)//����ѭ�������ƣ�
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
}

int main(){
    cout<<"��������Ʒ�ĸ��� n:";
    cin>>n;
    cout<<"�����뱳��������W:";
    cin>>W;
    cout<<"����������ÿ����Ʒ������w�ͼ�ֵv,�ÿո�ֿ�:";
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for(int j=1;j<=W;j++)//��ʼ����0��Ϊ0
        dp[j]=0;
    comp_knapsack(n,W);
    cout<<"װ�뱳��������ֵΪ:"<<dp[W]<<endl;
    //����dp[]������
    for(int j=1;j<=W;j++)
        cout<<dp[j]<<"  ";
    cout<<endl;
    return 0;
}
