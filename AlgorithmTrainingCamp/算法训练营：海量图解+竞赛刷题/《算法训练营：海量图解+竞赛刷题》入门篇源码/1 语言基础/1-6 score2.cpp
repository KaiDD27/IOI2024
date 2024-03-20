#include<iostream>
using namespace std;

int main(){
	float score;
	cin>>score;
	if(score>=70)
		if(score<80) 
			cout<<"中等"<<endl; 
		else if(score<90)
				cout<<"良好"<<endl; 
			else
				cout<<"优秀"<<endl; 
	else if(score>=60)
			cout<<"及格！"<<endl; 
		else
			cout<<"不及格！"<<endl; 
	return 0;
}
