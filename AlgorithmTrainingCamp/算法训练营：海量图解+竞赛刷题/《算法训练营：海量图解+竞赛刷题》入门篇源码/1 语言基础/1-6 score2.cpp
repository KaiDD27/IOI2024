#include<iostream>
using namespace std;

int main(){
	float score;
	cin>>score;
	if(score>=70)
		if(score<80) 
			cout<<"�е�"<<endl; 
		else if(score<90)
				cout<<"����"<<endl; 
			else
				cout<<"����"<<endl; 
	else if(score>=60)
			cout<<"����"<<endl; 
		else
			cout<<"������"<<endl; 
	return 0;
}
