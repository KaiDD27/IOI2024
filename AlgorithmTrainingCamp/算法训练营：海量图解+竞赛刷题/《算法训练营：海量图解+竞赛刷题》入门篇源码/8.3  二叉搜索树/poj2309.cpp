#include<iostream>
using namespace std;

int lowbit(int n){
	return n&(-n);
}

int main(){
	int T,n,k;
	cin>>T;
	while(T--){
		cin>>n;
		k=lowbit(n)-1;
		cout<<n-k<<" "<<n+k<<endl;
	}
	return 0;
}
