#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[20];
int dp[20][2];
//dp[pos][sta]表示当前第pos位，sta状态下满足条件的个数，sta表示前一位是否是6，只有0和1两种状态
int dfs(int pos,bool sta,bool limit){
    if(pos==0) return 1;
    if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
    int len=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=len;i++){
        if(sta&&i==2)continue;
        if(i==4) continue;//都是保证枚举合法性
        ans+=dfs(pos-1,i==6,limit&&i==len);
    }
    if(!limit) dp[pos][sta]=ans;
    return ans;
}

int solve(int x){//求解[0..x]之间满足条件的个数 
    int pos=0;
    while(x){
        a[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,1);//如果不包括0，此处减1即可
}

void print(){//输出dp数组 
	printf("  j=\t");
	for(int j=0;j<=1;j++)
		printf("%-10d",j);
	printf("\n");
	for(int i=1;i<=9;i++){
    	printf("i=%d\t",i);
		for(int j=0;j<=1;j++)
			printf("%-10d",dp[i][j]);	
		printf("\n");
	}
}

int main(){
    int a,b;
    memset(dp,-1,sizeof dp);
    while(~scanf("%d%d",&a,&b),a+b){//测试24 386
		//printf("%d\n",solve(a));
		//print();
    	//printf("%d\n",solve(b));
    	//print();
		printf("%d\n",solve(b)-solve(a-1));
    }
    return 0;
}
