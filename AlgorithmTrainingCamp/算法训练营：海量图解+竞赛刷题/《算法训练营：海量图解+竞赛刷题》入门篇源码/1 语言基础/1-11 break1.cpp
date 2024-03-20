#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i==5)
			break;
		cout<<i<<endl;
	}
	cout<<"This is a break test."; 
	return 0;
} 
