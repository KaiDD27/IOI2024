#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
 
int main(){
	map<string,int>mp;
	int cnt=0;
	string s;
	while(getline(cin,s)){
		mp[s]++;
		cnt++;
	}
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" ";
		printf("%.4f\n",100.0*(it->second)/cnt);
	}
	return 0;
}
