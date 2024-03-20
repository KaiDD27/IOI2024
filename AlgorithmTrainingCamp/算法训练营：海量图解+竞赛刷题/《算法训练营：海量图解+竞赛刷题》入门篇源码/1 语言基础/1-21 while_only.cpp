#include<iostream>
using namespace std;
int main(){
    int n,count;
    cin>>n;
	while(n>1){
        if(n%2==1)
			n=3*n+1;
		else
			n=n/2;
		cout<<n<<endl;	 
        count++;
    }
    cout<<"count="<<count<<endl;
    return 0;
}
