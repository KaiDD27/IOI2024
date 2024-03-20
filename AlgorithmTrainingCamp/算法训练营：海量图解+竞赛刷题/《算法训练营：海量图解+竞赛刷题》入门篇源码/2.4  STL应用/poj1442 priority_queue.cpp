#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int>q1;
priority_queue<int,vector<int>,greater<int> >q2;
int a[30010];

int main(){
    int n,m,x;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
    int cnt=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        while(cnt<=x){
            if(!q1.empty()&&a[cnt]<q1.top()){
            	q2.push(q1.top());
            	q1.pop();
            	q1.push(a[cnt]);
			}
			else
				q2.push(a[cnt]);
            cnt++;
        }
        printf("%d\n",q2.top());
        q1.push(q2.top());
		q2.pop();
    }
    return 0;
}
