#include<iostream>
#include<string>
#include<map>
using namespace std;
int T,m,num;
string place,name;

int main(){
    cin>>T;
    while(T--){
		map<string,map<string,int> >mp; //��άmap��ע��ո�
		cin>>m;
		for(int i=0;i<m;i++){
           cin>>name>>place>>num;
           mp[place][name]+=num;
		}
		map<string,map<string,int> >::iterator iter1;
		map<string,int>::iterator iter2;
		for(iter1=mp.begin();iter1!=mp.end();iter1++){ //��һ�ؼ���
			cout<<iter1->first<<endl;
			for(iter2=iter1->second.begin();iter2!=iter1->second.end();iter2++) //�ڶ��ؼ���
				cout<<"   |----"<<iter2->first<<"("<<iter2->second<<")"<<endl;
		}
       if(T) cout<<endl;
    }
    return 0;
}
