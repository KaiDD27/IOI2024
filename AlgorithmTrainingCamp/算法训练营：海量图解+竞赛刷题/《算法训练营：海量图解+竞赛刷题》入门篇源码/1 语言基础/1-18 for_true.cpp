#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
	for(;;){//for���ʡ���˲�������ʱ������Ϊ����Ϊtrue��
        cout<<i<<endl;
        i++;
        if(i>n)
        	break;
    }
    return 0;
}
