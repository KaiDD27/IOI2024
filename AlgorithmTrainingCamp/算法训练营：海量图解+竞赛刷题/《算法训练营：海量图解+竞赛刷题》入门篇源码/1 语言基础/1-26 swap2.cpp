#include<iostream>
using namespace std;

void swap(int &x,int &y){//���ò���
	int temp;
	temp=x;
	x=y;
	y=temp;
	cout<<"������"<<x<<"\t"<<y<<endl;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<endl; 
	cout<<"����ǰ"<<a<<"\t"<<b<<endl;
	swap(a,b);
	cout<<"������"<<a<<"\t"<<b<<endl;
	return 0;
} 
