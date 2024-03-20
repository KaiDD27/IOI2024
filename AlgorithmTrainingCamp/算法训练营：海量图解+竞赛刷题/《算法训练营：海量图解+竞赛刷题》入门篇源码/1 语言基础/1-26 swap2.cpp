#include<iostream>
using namespace std;

void swap(int &x,int &y){//引用参数
	int temp;
	temp=x;
	x=y;
	y=temp;
	cout<<"交换中"<<x<<"\t"<<y<<endl;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<endl; 
	cout<<"交换前"<<a<<"\t"<<b<<endl;
	swap(a,b);
	cout<<"交换后"<<a<<"\t"<<b<<endl;
	return 0;
} 
