#include<iostream>//һά���飬01�������� 
#include<cstring>
#include<algorithm>
using namespace std;
#define M 1005
int dp[M];//dp[j]��ʾ��������Ϊj�ı�����õ�����ֵ
int val[M],v[M];//val[i]��ʾ��i����Ʒ�ļ�ֵ��v[i]��ʾ��i����Ʒ�����

int main(){
    int t,N,V;//t������������N����Ʒ��V��ʾ����������
    cin>>t;
    while(t--){
    	memset(dp,0,sizeof(dp));
		cin>>N>>V;
    	for(int i=1;i<=N;i++)
    		cin>>val[i];
    	for(int i=1;i<=N;i++)
    		cin>>v[i];
	    for(int i=1;i<=N;i++)//����dp[j]
	        for(int j=V;j>=v[i];j--)//�Ƚϴ���Ʒ���벻���Ƿ���ʹ�����ڵļ�ֵ���
	            dp[j]=max(dp[j],dp[j-v[i]]+val[i]);
    	cout<<dp[V]<<endl;
	}
    return 0;
}
