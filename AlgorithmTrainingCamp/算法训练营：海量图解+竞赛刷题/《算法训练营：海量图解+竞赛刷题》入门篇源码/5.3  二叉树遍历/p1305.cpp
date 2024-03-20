#include<iostream>
#include<string>
using namespace std;
int n,root,l[100],r[100];
string s;

void preorder(int t){
	if(t!='*'-'a'){
		cout<<char(t+'a');
		preorder(l[t]);
		preorder(r[t]);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(!i)
			root=s[0]-'a';
		l[s[0]-'a']=s[1]-'a';
		r[s[0]-'a']=s[2]-'a';
	}
	preorder(root);
	return 0;
} 
