#include<bits/stdc++.h>
using namespace std;

int main()
{
	char c;
	stack<char> s;
	while(cin>>c&&c!='@')
	{
		if(c=='(')
			s.push(c);
		if(c==')')
		{
			if(!s.empty())
				s.pop();
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}	
		}
			
	}
	if(s.empty())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
 } 
