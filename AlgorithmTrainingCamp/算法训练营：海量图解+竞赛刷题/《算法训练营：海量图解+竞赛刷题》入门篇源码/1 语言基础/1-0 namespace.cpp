#include<iostream>
using namespace std;

namespace A{
  int  i=10;
}

namespace B{
	int  i=20;
	namespace C{//�����ռ�Ķ������Ƕ��
       int i=30;
	}
	int n=i+C::i;
}

int main(){
    cout<<A::i<<endl;   //����using namespace A;
    cout<<B::i<<endl;
    cout<<B::n<<endl;
    return 0;
}
