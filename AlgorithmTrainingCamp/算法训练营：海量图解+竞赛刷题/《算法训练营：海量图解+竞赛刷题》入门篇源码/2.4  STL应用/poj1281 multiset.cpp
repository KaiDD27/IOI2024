#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
bool vis[10005];
multiset<int>s;
int k;

void del(int p){
    if(s.empty()){
		printf("-1\n");
		return;
	}
	if(p==1){
        if(vis[k++])
			printf("%d\n",*s.begin());
        s.erase(*s.begin());
    }
    else{
        if(vis[k++])
			printf("%d\n",*s.rbegin());
        s.erase(*s.rbegin());
    }
}

int main(){
    char c;
    int m,n,x,p;
    while(~scanf("%d%d",&m,&n)){
		memset(vis,false,sizeof(vis));
		s.clear();
		for(int i=0;i<n;i++){
		    scanf("%d",&x);
		    vis[x]=true;
		}
		p=1;
		k=1;
		while(scanf("%c",&c)){
		    if(c=='e') break;
		    if(c=='a'){
		        scanf("%d",&x);
		        s.insert(x);
		    }
		    else if(c=='p'){
		        scanf("%d",&x);
		        p=x;
		    }
		    else if(c=='r')
    			del(p);       
		}
		printf("\n");
	}
    return 0;
}
