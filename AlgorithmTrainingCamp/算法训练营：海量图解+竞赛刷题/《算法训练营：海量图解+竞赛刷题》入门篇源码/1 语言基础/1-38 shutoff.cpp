#include<iostream>
#include<cstring>//memset������Ҫ�����ͷ�ļ� 
using namespace std;
bool a[1005];
int main(){
	int n,k;
	bool first=1;
	memset(a,0,sizeof(a));//��ʼ��a����ȫ��Ϊ0 
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) 
			if(j%i==0)
				a[j]=!a[j];
	for(int j=1;j<=n;j++){ 
		if(a[j]){
			if(first)//��һ��Ԫ�ز�����ո� 
				first=0;
			else
				cout<<" ";
			cout<<j;
		}
	}		 
    return 0;
}
