#include<bits/stdc++.h>
using namespace std;
const int maxsize=1000+5;
int n,B[maxsize];

int main(){
    while(cin>>n&&n){
        while(1){
			int i=1,j=1;
			cin>>B[1];
			if(!B[1])
				break;
	        for(int i=2;i<=n;i++)
	        	cin>>B[i];
	        stack<int>s;
	        while(i<=n){
	            if(i==B[j]){
	                i++;
	                j++;
	            }
	            else
	                s.push(i++);
	            while(!s.empty()&&s.top()==B[j]){
					j++;
					s.pop();
				}
			}
			if(j<=n)
				cout<<"No"<<endl;
	        else
				cout<<"Yes"<<endl;
		}
		cout<<endl;
    }
    return 0;
}
