#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int n,a,b,c;
	cin>>n>>b>>c;
	a=n++;
	b*=10;
	c/=10;
	cout<<a<<setw(5)<<b<<setw(5)<<c<<endl; 
	return 0;
}

