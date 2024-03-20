#include<iostream>
using namespace std;
#define maxn 105
int a[maxn]; 
int main(){
	int n=0,x;
	while(cin>>x){//ctrl+z,»Ø³µ£¬½áÊø
		a[n++]=x;
	}
	for(int i=n-1;i>=0;i--)
		cout<<a[i]<<endl;
    return 0;
}
