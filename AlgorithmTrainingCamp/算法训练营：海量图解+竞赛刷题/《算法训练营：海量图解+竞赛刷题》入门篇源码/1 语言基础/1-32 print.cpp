#include<iostream>
using namespace std;
int a[100];
 
void print(int i){
	cout<<a[i]<<endl;
	if(i>0)
		print(i-1);	
	//cout<<a[i]<<endl;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	print(n-1);
	return 0;
} 
