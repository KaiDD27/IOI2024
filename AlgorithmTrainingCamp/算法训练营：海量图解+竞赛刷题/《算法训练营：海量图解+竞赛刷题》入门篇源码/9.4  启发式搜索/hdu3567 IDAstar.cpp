#include<cstdio>//深度每次增1，187ms，改进后109ms，增加康托判重反而耗时 
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
const char str[]={'d','l','r','u'};//保证字母序
int a[9],goal[9],m[9];
int depth,mindep;
char ans[1000005];

int h(){//启发函数，曼哈顿距离（行列差绝对值之和） 
	int cost=0;
	for(int i=0;i<9;i++){
		if(a[i])
			cost+=abs(i/3-m[a[i]]/3)+abs(i%3-m[a[i]]%3);
	}
	return cost;
}

bool dfs(int x,int d,int pre){
	int t=h();
	if(!t){
		printf("%d\n",d);
		ans[d]='\0';
		printf("%s\n",ans);
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
		ans[d]=str[i];
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
	int T,x,cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",ans);
		for(int i=0;i<9;i++){
			if(ans[i]=='X')//大写X！ 
				x=i,a[i]=0;
			else
				a[i]=ans[i]-'0';
		}
		scanf("%s",ans);
		for(int i=0;i<9;i++){
			if(ans[i]=='X')
				goal[i]=0;
			else
				goal[i]=ans[i]-'0';
			m[goal[i]]=i;//映射位置
		}
		printf("Case %d: ",++cas);
		IDAstar(x);
	}
	return 0;
}
