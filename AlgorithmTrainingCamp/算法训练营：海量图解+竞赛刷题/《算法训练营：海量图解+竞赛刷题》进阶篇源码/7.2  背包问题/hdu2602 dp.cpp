#include<iostream>//��ά���飬01�������� 
#include<cstring>
#include<algorithm>
using namespace std;
#define M 1005
int c[M][M];//c[i][j] ��ʾǰi����Ʒ��������Ϊj�ı�����õ�����ֵ
int val[M],v[M];//val[i]��ʾ��i����Ʒ�ļ�ֵ��v[i]��ʾ��i����Ʒ�����

int main(){
    int t,N,V;//N����Ʒ��V��ʾ����������
    cin>>t;
    while(t--){
		cin>>N>>V;
    	for(int i=1;i<=N;i++)
    		cin>>val[i];
    	for(int i=1;i<=N;i++)
    		cin>>v[i];
    	for(int i=0;i<=N;i++)
    		c[i][0]=0;
    	for(int j=0;j<=V;j++)
    		c[0][j]=0;
	    for(int i=1;i<=N;i++)//����c[i][j]
	        for(int j=0;j<=V;j++)//�����������Ϊ0
	            if(j<v[i]) //����Ʒ��������ڱ������������򲻷Ŵ���Ʒ
	                c[i][j]=c[i-1][j];
	            else    //����Ƚϴ���Ʒ���벻���Ƿ���ʹ�����ڵļ�ֵ���
	                c[i][j]=max(c[i-1][j],c[i-1][j-v[i]]+val[i]);
    	cout<<c[N][V]<<endl;
	}
    return 0;
}
