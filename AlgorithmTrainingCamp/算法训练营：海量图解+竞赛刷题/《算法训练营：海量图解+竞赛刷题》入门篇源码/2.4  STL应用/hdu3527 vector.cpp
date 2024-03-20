#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> x,y,z,ans;

int main(){
    int a,b,c;
	string s;
    while(cin>>a>>b>>c){
        x.clear(),y.clear(),z.clear(),ans.clear();
        for(int i=0;i<a;i++){
            cin>>s;
            x.push_back(s);
        }
        for(int i=0;i<b;i++){
            cin>>s;
            y.push_back(s);
        }
        for(int i=0;i<c;i++){
            cin>>s;
            z.push_back(s);
        }
        for(int i=0;i<b;i++){//判断第二个字符串在第一个中出现，没在第三个中出现的	
            if(find(x.begin(),x.end(),y[i])!=x.end())
            	if(find(z.begin(),z.end(),y[i])==z.end())
            		ans.push_back(y[i]);
        }
        if(!ans.size())
        	cout<<"No enemy spy\n";
        else{
            for(int i=0;i<ans.size();i++){
                if(i!=0)
                	cout<<" ";
                cout<<ans[i];
            }
        	cout<<endl;
        }
    }
    return 0;
}
