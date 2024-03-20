#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
LL dp[2][1<<24];//记录方案数 
int state[2][1<<24];//记录状态，S=state[pre][s]，pre为前一个格子标记，s为状态编号,S为状态 
int total[2];//记录状态总数 
int pre,now;
int endx,endy;//记录最后一个非障碍格子 
bool map[15][15];
int m,n;
LL ans;
const int HASH=40001;//坑点！！哈希值太小会超时！4位素数超时，m<=12,用5位数素数，如30007 
int Hash[HASH];//记录S对应的哈希值x的状态编号
 
void HashIn(int S,LL num){
	int x=S%HASH;
	while(~Hash[x]&&state[now][Hash[x]]!=S){//线性探测 
		x++;
		x%=HASH;
	}
	if(Hash[x]==-1){//未找到，加入hash表中 
		dp[now][total[now]]=num;
		state[now][total[now]]=S;
		Hash[x]=total[now];//记录状态编号
		total[now]++;
	}
	else//找到，累加方案数 
		dp[now][Hash[x]]+=num;
}
 
void init(){
	memset(map,0,sizeof(map));
	endx=-1;
	for(int i=0;i<n;i++){
		char str[200];
		scanf("%s",str);
		for(int j=0;j<m;j++){
			if(str[j]=='*')
				map[i][j]=0;
			else if(str[j]=='.'){
				map[i][j]=1;
				endx=i;
				endy=j;
			}
		}
	}
}
 
//位运算，取S按长度l的第p位
int getV(int S,int p,int l=2){//4进制，l=2；8进制，l=3
	return (S>>(p*l))&((1<<l)-1);
}
 
//位运算，设置S按长度l的第p位值为v
void setV(int& S,int p,int v,int l=2){
	S^=getV(S,p)<<(p*l);//第p位置0
	S|=v<<(p*l);//第p位置v 
}
 
void memsetnow(){//哈希表清空
	memset(Hash,-1,sizeof(Hash));
	total[now]=0;
}
 
void solve()
{
	init();
	if(endx==-1){
		puts("0");
		return;
	}
	pre=0,now=1;
	ans=0;
	memsetnow();//哈希表清空
	dp[pre][0]=1;
	state[pre][0]=0;
	total[pre]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			memsetnow();//哈希表清空
			for(int s=0;s<total[pre];s++){
				if(dp[pre][s]){
					LL num=dp[pre][s];
					int S=state[pre][s];
					int p=getV(S,j);
					int q=getV(S,j+1);
					if(map[i][j]==0){//有障碍，第一种情况 
						if(p==0&&q==0)
							HashIn(S,num);
						continue;
					}
					if(p==0&&q==0){//p、q均为0，第二种情况 
						if(map[i+1][j]&&map[i][j+1]){
							int nS=S;
							setV(nS,j,1);
							setV(nS,j+1,2);
							HashIn(nS,num);
						}
						continue;
					}
					if((p>0)^(q>0)){//p、q有一个为0，第三种情况 
						if(map[i+(p>0)][j+(q>0)])
							HashIn(S,num);
						if(map[i+(q>0)][j+(p>0)]){
							int nS=S;
							setV(nS,j,q);//p、q交换 
							setV(nS,j+1,p);
							HashIn(nS,num);
						}
						continue;
					}
					if(p==1&&q==1){//第四种情况，4.1 
						int find=1;
						for(int v=j+2;v<=m;v++){//向后搜q匹配的右括号),改为左括号 
							int k=getV(S,v);
							if(k==1)
								find++;
							else if(k==2)
								find--;
							if(find==0){
								int nS=S;
								setV(nS,j,0);//p、q置0 
								setV(nS,j+1,0);
								setV(nS,v,1);//改为左括号
								HashIn(nS,num);
								break;
							}
						}
						continue;
					}
					if(p==2&&q==2){//第四种情况，4.2 
						int find=1;
						for(int v=j-1;v>=0;v--){//向前搜p匹配的左括号(,改为右括号 
							int k=getV(S,v);
							if(k==2)
								find++;
							else if(k==1)
								find--;
							if(find==0){
								int nS=S;
								setV(nS,j,0);//p、q置0 
								setV(nS,j+1,0);
								setV(nS,v,2);//改为右括号
								HashIn(nS,num);
								break;
							}
						}
						continue;
					}
					if(p==2&&q==1){//第四种情况，4.3 
						int nS=S;
						setV(nS,j,0);//p、q置0 
						setV(nS,j+1,0);
						HashIn(nS,num);
						continue;
					}
					if(p==1&&q==2){//第四种情况，4.4 
						if(i==endx&&j==endy)//最后一个非障碍格子 
							ans+=num;
					}
				}	
			}
			swap(now,pre);
		}
		memsetnow();//哈希表清空
		for(int s=0;s<total[pre];s++)
			if(dp[pre][s]){
				LL num=dp[pre][s];
				int S=state[pre][s]<<2;//左移一格，四进制，一格用两位表示 
				HashIn(S,num);
			}
		swap(now,pre);
	}
	printf("%I64d\n",ans);
}
 
int main(){
	while(~scanf("%d%d",&n,&m)){
		solve();
	}
	return 0;
}
