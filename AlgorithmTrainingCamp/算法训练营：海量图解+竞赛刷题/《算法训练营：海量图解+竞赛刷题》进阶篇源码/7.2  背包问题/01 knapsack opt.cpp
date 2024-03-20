#include<iostream>//01����һά�����Ż�
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn];//dp[j]��ʾ��ǰ�ѷ�������Ϊj�ı�����õ�����ֵ
int w[M],v[M];//w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
int x[M];  //x[i]��ʾ��i����Ʒ�Ƿ���뱳��
int n,W;//n��ʾn����Ʒ��W��ʾ����������

void opt1(int n,int W){
    for(int i=1;i<=n;i++)
        for(int j=W;j>0;j--)
			if(j>=w[i])//����Ʒ���������ڱ������������Ƚϴ���Ʒ���벻���Ƿ���ʹ�ñ����ڵļ�ֵ���
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
}

void opt2(int n,int W){
	for(int i=1;i<=n;i++)
		for(int j=W;j>=w[i];j--)//����ѭ�������ƣ�
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
}

void opt3(int n,int W){
	int sum[n];//sum[i]��ʾ��1...i����Ʒ����֮��
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+w[i];
	for(int i=1;i<=n;i++){
        int bound=max(w[i],W-(sum[n]-sum[i-1]));//w[i]��ʣ������ȡ���ֵ,sum[n]-sum[i-1]��ʾ��i...n����Ʒ����֮��
        for(int j=W;j>=bound;j--)
            //����Ʒ���������ڱ������������Ƚϴ���Ʒ���벻���Ƿ���ʹ�ñ����ڵļ�ֵ���
           dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	}
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
    opt1(n,W);
    //opt2(n,W);
    //opt3(n,W);
    cout<<"װ�뱳��������ֵΪ:"<<dp[W]<<endl;

    //����dp[]������
    for(int j=1;j<=W;j++)
        cout<<dp[j]<<"  ";
    cout<<endl;
    return 0;
}

