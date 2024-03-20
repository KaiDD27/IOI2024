#include<iostream>
using namespace std;

namespace A{
  int  i=10;
}

namespace B{
	int  i=20;
	namespace C{//命名空间的定义可以嵌套
       int i=30;
	}
	int n=i+C::i;
}

int main(){
    cout<<A::i<<endl;   //或者using namespace A;
    cout<<B::i<<endl;
    cout<<B::n<<endl;
    return 0;
}
