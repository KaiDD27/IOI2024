#include<cstdio>
#include<set>
using namespace std;
int n,m,x;
set<int> sum;

int main(){
    while(~scanf("%d%d",&n,&m)){
        sum.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            sum.insert(x);
        }
        for(int j=0;j<m;j++){
            scanf("%d", &x);
            sum.insert(x);
		}
        for(set<int>::iterator it=sum.begin();it!=sum.end();it++){
            if(it!=sum.begin())
            	printf(" ");
            printf("%d",*it);
        }
        printf("\n");
    }
    return 0;
}
