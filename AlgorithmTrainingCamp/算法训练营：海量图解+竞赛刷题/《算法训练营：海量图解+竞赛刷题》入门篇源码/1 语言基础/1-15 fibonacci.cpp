#include<iostream>
using namespace std;
long long f[100+5];
int main(){
	f[1]=1,f[2]=1;
	for(int i=3;i<=100;i++){
		f[i]=f[i-1]+f[i-2];
	}
	cout<<"f[100]="<<f[100]; 
	return 0;
} 
