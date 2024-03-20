#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int n;
	int ge,shi,bai;
	cin>>n;
	ge=n%10;
	shi=(n/10)%10;
	bai=(n/100)%10;
	cout<<ge<<setw(2)<<shi<<setw(2)<<bai<<endl; 
	return 0;
}

