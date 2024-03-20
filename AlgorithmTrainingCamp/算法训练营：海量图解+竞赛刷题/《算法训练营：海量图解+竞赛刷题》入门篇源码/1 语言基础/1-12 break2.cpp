#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"i="<<i<<"\n";
		for(int j=1;j<=n;j++){
			if(j==5)
				break;
			cout<<j<<" ";	
		}		
		cout<<"\n";
	}
	cout<<"This is a break test."; 
	return 0;
} 
