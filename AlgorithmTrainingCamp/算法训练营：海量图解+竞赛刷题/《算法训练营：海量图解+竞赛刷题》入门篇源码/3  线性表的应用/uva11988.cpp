#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
	int len=s.length();
	list<char> text;
	list<char>::iterator it=text.begin();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='[')
			it=text.begin();
		else if(s[i]==']')
				it=text.end();
			else
			{
				it=text.insert(it,s[i]);
				it++;
			}		
	}
	for(it=text.begin();it!=text.end();it++)
		cout<<*it;
	s.clear();
	cout<<endl;
 } 

int main()
{
	string s;
	while(cin>>s)
		solve(s);
	return 0;
 } 
