#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i%2==0)
			continue;	
		cout<<i<<"\n";
	}
	cout<<"This is a continue test."; 
	return 0;
} 
