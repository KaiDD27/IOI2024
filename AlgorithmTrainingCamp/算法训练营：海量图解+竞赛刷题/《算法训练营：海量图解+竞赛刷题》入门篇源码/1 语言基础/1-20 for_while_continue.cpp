#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
	for(int i=1;i<=n;i++){
        if(i%3==0)
        	continue;//跳到循环更新处,执行i++ 
		cout<<i<<endl;
    }
	int i=1;
	while(i<=n){
		if(i%3==0)
        	continue;//跳到循环条件处执行i<=n 
		cout<<i<<endl;
		i++;
	}
	cout<<"This is a test.";
    return 0;
}
