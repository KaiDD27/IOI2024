#include<iostream>
using namespace std;

void print(){//ÎŞ²ÎÊı 
	for(int i=0;i<3;i++)
		cout<<"very good!"<<endl;
}

int main(){
	int n;
	cin>>n;
	if(n%10==0)
		print();
	return 0;
} 
