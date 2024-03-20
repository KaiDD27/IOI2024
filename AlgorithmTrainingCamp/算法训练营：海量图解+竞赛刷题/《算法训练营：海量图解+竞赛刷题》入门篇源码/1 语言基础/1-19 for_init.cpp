#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
	for(int i=1;i<=n;i++){//for语句可以用初始化语句声明一个局部变量，while语句不可以。
        cout<<i<<endl;
    }
    return 0;
}
