#include<bits/stdc++.h>
#define REP(i,b,e) for(int i=(b);i<(e);i++)
using namespace std;
const int maxn=300+5;
int g[maxn][maxn],n,m;

bool solve(){
	REP(i,0,n)
		REP(j,0,n){
			bool flag1=false,flag2=false;
			REP(k,0,n){
				if(g[i][k]&&g[j][k])
					flag1=true;
				if(g[i][k]^g[j][k])
					flag2=true;
			}
			if(flag1&&flag2)
				return false;
		}
	return true;
}

int main(){
	int T,cnt=0,x,y;
	cin>>T;
	while(T--){
		memset(g,0,sizeof(g));//³õÊ¼»¯ÁÚ½Ó¾ØÕó 
		cin>>n>>m;
		REP(i,0,m){
			cin>>x>>y;
			g[x][y]=1;
		}
		if(solve())
			cout<<"Case #"<<++cnt<<": Yes"<<endl;
		else
			cout<<"Case #"<<++cnt<<": No"<<endl;
	}
	return 0;
}
