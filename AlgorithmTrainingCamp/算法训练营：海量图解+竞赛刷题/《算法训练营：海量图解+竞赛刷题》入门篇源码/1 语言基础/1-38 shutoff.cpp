#include<iostream>
#include<cstring>//memset函数需要引入该头文件 
using namespace std;
bool a[1005];
int main(){
	int n,k;
	bool first=1;
	memset(a,0,sizeof(a));//初始化a数组全部为0 
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) 
			if(j%i==0)
				a[j]=!a[j];
	for(int j=1;j<=n;j++){ 
		if(a[j]){
			if(first)//第一个元素不输出空格 
				first=0;
			else
				cout<<" ";
			cout<<j;
		}
	}		 
    return 0;
}
