#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,n,m;
    cin>>T;
    for(int i=0;i<T;i++){
       	queue<int> q;
    	vector<int> a,b;
		int k=0,x;
		cin>>n>>m;
        for(int j=0;j<n;j++){
        	cin>>x;
			a.push_back(x);
			b.push_back(x); 
			q.push(j);
		}
		sort(b.begin(),b.end(),greater<int>());//½µÐò 
		int w=0;
		int max=0;
		while(!q.empty()){
        	max=b[w];
        	int t=q.front();
			if(a[t]<max){
				q.pop();
				q.push(t);
			}
			else{
				if(t==m){
					cout<<++k<<endl;
					break;
			    }
			    else{
			    	q.pop();
					k++;
					w++;
				}
			}
		}				
    }
    return 0;	  
}
