#include<iostream>
using namespace std;

int main(){
    int month,season=0;
    cin>>month;
    if(3<=month&&month<=5)
        season=1;
    else if(6<=month&&month<=8)
           season=2;
        else if(9<=month&&month<=11)
               season=3;
            else if((1<=month&&month<=2)||(month==12))
                   season=4;
    switch(season){
	    case 1:
	        cout<<"����"<<endl;
	        break;
	    case 2:
	        cout<<"�ļ�"<<endl;
	        break;
	    case 3:
	        cout<<"�＾"<<endl;
	        break;
	    case 4:
	        cout<<"����"<<endl;
	        break;
	    default:cout<<"������·ݲ��ԣ�"<<endl;
    }
    return 0;
}
