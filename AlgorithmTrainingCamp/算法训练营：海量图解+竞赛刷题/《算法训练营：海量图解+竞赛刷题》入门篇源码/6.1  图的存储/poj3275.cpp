#include<iostream>
#include<bitset>
using namespace std;
const int maxn=1000+5;
bitset<maxn>p[maxn];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i][i]=1;
	while(m--){
		int u,v;
		cin>>u>>v;
		p[u][v]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(p[i][k])
				p[i]|=p[k];
	int ans=0;
    for(int i=1;i<=n;i++)
        ans+=p[i].count();
    cout<<n*(n-1)/2-ans+n<<endl;
    return 0;	
}
