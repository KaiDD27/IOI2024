#include<cstdio>
#include<algorithm>
using namespace std;
const int N=30;
const int inf=0x3f3f3f3f;
int n,m,minv[N],mins[N],best;

void init(){
    minv[0]=mins[0]=0;
    for(int i=1;i<22;i++){
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }
}

void dfs(int dep,int sumv,int sums,int r,int h){
    if(!dep){
        if(sumv==n&&sums<best) best=sums;
        return ;
    }
    if(sumv+minv[dep]>n||sums+mins[dep]>best||sums+2*(n-sumv)/r>best) return;
    for(int i=r;i>=dep;i--){
        if(dep==m) sums=i*i;
        int maxh=min((n-sumv-minv[dep-1])/(i*i),h);
        for(int j=maxh;j>=dep;j--)
            dfs(dep-1,sumv+i*i*j,sums+2*i*j,i-1,j-1);
    }
}

int main(){
    init();
    while(~scanf("%d%d",&n,&m)){
        best=inf;
        dfs(m,0,0,n,n);
        printf("%d\n",best==inf?0:best); 
    }
    return 0;
}
