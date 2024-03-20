#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string tree[1000001];
int n=0,ans=0;

int cmp(string a,string b){
	return a<b;
}

int main(){
	while(getline(cin,tree[n]))
		n++;
	sort(tree,tree+n,cmp);
	for(int i=0;i<n;i++){
		ans++;
		if(tree[i+1]!=tree[i]){
			cout<<tree[i];//string类型，不要使用printf 
			printf(" %0.4lf\n",(ans*100.0)/(n*1.0));
			ans=0;
		}
	}
	return 0;
}
