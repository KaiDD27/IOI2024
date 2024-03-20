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
	        cout<<"春季"<<endl;
	        break;
	    case 2:
	        cout<<"夏季"<<endl;
	        break;
	    case 3:
	        cout<<"秋季"<<endl;
	        break;
	    case 4:
	        cout<<"冬季"<<endl;
	        break;
	    default:cout<<"输入的月份不对！"<<endl;
    }
    return 0;
}
