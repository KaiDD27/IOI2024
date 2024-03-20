#include<iostream>
using namespace std;
int main(){
	int n,fac=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		fac*=i;
	}
	cout<<"fac("<<n<<")="<<fac; 
	return 0;
} 
