#include<cstdio>//IDA*优化，hdu1043 优化前202ms，优化后124ms，poj1077 0ms 
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=362880+10;
const int dir[4][2]={1,0,0,1,-1,0,0,-1};
const char to_c[]="drul";
int a[9];
int depth,mindep;
char ans[N];

bool check(){
    int cnt=0;
    for(int i=0;i<9;i++){
        if(a[i]==8) continue;
        for(int j=i+1;j<9;j++)
            if(a[j]<a[i]) cnt++;
    }
	if(cnt%2) return 0;
    return 1; 
}

int h(){//启发函数，欧氏距离（行列差绝对值之和） 
	int cost=0;
	for(int i=0;i<9;i++){
		if(a[i]!=8)
			cost+=abs(i/3-a[i]/3)+abs(i%3-a[i]%3);
	}
	return cost;
}

bool dfs(int x,int d,int pre){
	int t=h();
	if(!t){
		ans[d]='\0';
		return 1;
	}
	if(d+t>depth){
		mindep=min(mindep,d+t);
		return 0;
	}
	for(int i=0;i<4;i++){
		int row=x/3+dir[i][0];
		int col=x%3+dir[i][1];
		int newx=row*3+col;//转换为数字 
		if(row<0||row>2||col<0||col>2||newx==pre) continue;
		swap(a[newx],a[x]);
		ans[d]=to_c[i];
		if(dfs(newx,d+1,x)) return 1;
		swap(a[newx],a[x]);
	}
	return 0;
}

void IDAstar(int x){
	depth=h();
	while(1){
		mindep=inf;
		if(dfs(x,0,-1))
			break;
		depth=mindep;
	}
}

int main(){
	int x;
	while(~scanf("%s",ans)){
		if(ans[0]>'0'&&ans[0]<'9')
			a[0]=ans[0]-'0'-1;
		else if(ans[0]=='x')
			x=0,a[0]=8;
		for(int i=1;i<9;i++){
			scanf("%s",ans);
			if(ans[0]>'0'&&ans[0]<'9')
				a[i]=ans[0]-'0'-1;
			else if(ans[0]=='x')
				x=i,a[i]=8;
		}
		if(!check()){
			printf("unsolvable\n");
			continue;
		}	
		IDAstar(x);
		printf("%s\n",ans);
	}
	return 0;
}
