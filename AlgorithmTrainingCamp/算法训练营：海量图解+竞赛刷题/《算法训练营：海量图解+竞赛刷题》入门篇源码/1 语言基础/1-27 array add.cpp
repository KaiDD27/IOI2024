#include<iostream>
using namespace std;

int arrayadd(int a[],int n){//也可以使用*a
	int sum;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum;
} 

int main(){
	int n,s;
	int a[1000];//静态定义长度为1000的数组
	cin>>n;
	//int a=new int[n];//动态定义长度为n的数组
	for(int i=0;i<n;i++)
		cin>>a[i];
	s=arrayadd(a,n);
	cout<<s<<endl;
	return 0;
} 
