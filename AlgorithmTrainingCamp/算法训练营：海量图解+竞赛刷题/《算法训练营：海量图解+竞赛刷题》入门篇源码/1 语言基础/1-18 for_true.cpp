#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
	for(;;){//for语句省略了测试条件时，将认为条件为true。
        cout<<i<<endl;
        i++;
        if(i>n)
        	break;
    }
    return 0;
}
