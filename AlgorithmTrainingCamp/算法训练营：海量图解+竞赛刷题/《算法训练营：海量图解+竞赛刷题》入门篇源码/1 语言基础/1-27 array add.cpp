#include<iostream>
using namespace std;

int arrayadd(int a[],int n){//Ҳ����ʹ��*a
	int sum;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
} 

int main(){
	int n,s;
	int a[1000];//��̬���峤��Ϊ1000������
	cin>>n;
	//int a=new int[n];//��̬���峤��Ϊn������
	for(int i=0;i<n;i++)
		cin>>a[i];
	s=arrayadd(a,n);
	cout<<s<<endl;
	return 0;
} 
