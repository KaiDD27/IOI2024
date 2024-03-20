#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=10005;
const int INF=0x3f3f3f;
int dp[M];//dp[j]��ʾ��������Ϊj�Ĵ�Ǯ����ֵ֮����Сֵ 
int val[M],w[M];//val[i]��ʾ��i��Ӳ�ҵ���ֵ��w[i]��ʾ��i��Ӳ�ҵ����� 

int main(){
    int t,E,F,W,N;//t������������E��F��ʾûװӲ�Һ�װ��Ӳ��֮�������,W������ֵ��Ӳ������ 
    cin>>t;
    while(t--){
		cin>>E>>F;
		W=F-E;
		cin>>N;
    	for(int i=0;i<N;i++)
    		cin>>val[i]>>w[i];
    	memset(dp,0x3f,sizeof(dp));
    	dp[0]=0;
	    for(int i=0;i<N;i++)//����dp[j]
	        for(int j=w[i];j<=W;j++)//�Ƚϴ�Ӳ�ҷ��벻���Ƿ���ʹ�ô�Ǯ������ֵ֮����С
	        	dp[j]=min(dp[j],dp[j-w[i]]+val[i]);
    	if(dp[W]<INF)
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
    return 0;
}
