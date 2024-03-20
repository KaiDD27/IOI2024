#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100009;
bool vis[MAXN];
int d[MAXN];
int n,k;

void solve(){
    queue<int> q;
    vis[n]=1;
	d[n]=0;
    q.push(n);
    while(!q.empty()){
        int u=q.front();
		q.pop();
        if(u==k){
            cout<<d[k]<<endl;
            return;
        }
        int x;
        x=u+1;
        if(x>=0&&x<=100000&&!vis[x]){
            d[x]=d[u]+1;
            vis[x]=1;
            q.push(x);
        }
        x=u-1;
        if(x>=0&&x<=100000&&!vis[x]){
            d[x]=d[u]+1;
            vis[x]=1;
            q.push(x);
        }
        x=u*2;
        if(x>=0&&x<=100000&&!vis[x]){
            d[x]=d[u]+1;
            vis[x]=1;
            q.push(x);
        }
    }
}

int main(){
	while(cin>>n>>k){
		if(k<=n){
			cout<<n-k<<endl;
			continue;
		}
		solve();
	}
	return 0;
}
