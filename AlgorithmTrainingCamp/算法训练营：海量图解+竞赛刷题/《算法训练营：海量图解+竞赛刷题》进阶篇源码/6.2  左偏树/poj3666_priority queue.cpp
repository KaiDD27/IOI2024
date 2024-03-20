#include<cstdio>
#include<queue>
using namespace std;

int main(){
    int n,x;
	scanf("%d%d",&n,&x);
	priority_queue<int>q;
	q.push(x);
    int ans=0;
    for(int i=1;i<n;i++){
    	scanf("%d",&x);
        q.push(x);
        if(q.top()>x){
        	ans+=q.top()-x;
        	q.pop();
        	q.push(x);
		}
	}
    printf("%d\n",ans);
    return 0;
}
