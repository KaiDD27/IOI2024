#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=50;
int map[maxn][maxn],in[maxn],s[maxn];//邻接矩阵，入度，标记出现 
int ans[maxn];
string str,ord;//字符串，秩序 
int len,num;//字符串长度，秩序长度 

void dfs(int t){ //回溯法找所有的拓扑序列 
    if(t>=len){
    	for(int i=0;i<len;i++)
    		cout<<char(ans[i]+'a');
		cout<<endl; 
	}
	for(int i=0;i<26;i++){
    	if(!in[i]&&s[i]){
			s[i]--;
			for(int j=0;j<26;j++)
				if(map[i][j])
					in[j]--;
			ans[t]=i;
			dfs(t+1);
			for(int j=0;j<26;j++)//回溯还原现场 
				if(map[i][j])
					in[j]++;
			s[i]++;
		}
	}
}

int main(){
    while(getline(cin,str)){
    	memset(map,0,sizeof(map));
    	memset(in,0,sizeof(in));
    	memset(s,0,sizeof(s));
		len=str.length();
		int i,j=0;
		for(i=0;i<len;i++){
			if(str[i]!=' '){
				s[str[i]-'a']++;
				j++;
			}
		}
		len=j;
		getline(cin,ord);
		num=ord.length();
		for(i=0;i<num;i+=2){
			int u=ord[i]-'a';
			i+=2;
			int v=ord[i]-'a';
			map[u][v]=1;
			in[v]++;
		}
		dfs(0);
		cout<<endl;
	}
    return 0;
}
