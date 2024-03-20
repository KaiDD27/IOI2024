#include<cstdio>//IDAstar 657ms
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,depth;
int ex[15];

bool dfs(int d){
	if(ex[d]==n) return 1;
	if(d>=depth) return 0;//后面会搜索d+1层 
	if(ex[d]<<(depth-d)<n) return 0;
	for(int i=0;i<=d;i++){
        ex[d+1]=ex[d]+ex[i];//乘法
        if(dfs(d+1)) return 1;
        ex[d+1]=abs(ex[d]-ex[i]);//除法
        if(dfs(d+1)) return 1;
    }
    return 0;
}

void IDAstar(){
	ex[0]=1;
	for(depth=0;;depth++){
		if(dfs(0)){
	        printf("%d\n",depth);
	        break;
	    }
	}
}

int main(){
    while(~scanf("%d",&n),n){
		IDAstar();
    }
    return 0;
}
