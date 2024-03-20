#include<cstdio>
#include<cstring>
using namespace std;
int dp[15][15];
int num[15];

void init(){//预处理 
    dp[0][0]=1;
    for(int i=1;i<=9;i++)
        for(int j=0;j<=9;j++){
            if(j==4)
                dp[i][j]=0;
            else
                for(int k=0;k<=9;k++){
                    if(j==6&&k==2)
                        continue;
                    dp[i][j]+=dp[i-1][k];
                }
        }
}

int solve(int x){//求解[1..x]之间满足条件的个数 
    int ans=0,cnt=0;
    while(x)
        num[++cnt]=x%10,x/=10;
    num[cnt+1]=0;
    for(int i=cnt;i>=1;i--){//高位向低位计算 
        for(int j=0;j<num[i];j++)
            if(j==4||(j==2&&num[i+1]==6))
            	continue;
            else
				ans+=dp[i][j];
        if(num[i]==4||(num[i]==2&&num[i+1]==6)){
			ans--;//减1，例如4，统计0，1 ，2，3共4个其实只有3个满足（不包括0） 
				 //例如3，统计0，1 ，2共3个满足，0相当于统计了3本身 
            break;
    	}
    }
    return ans;
}

void print(){//输出初始化处理后的dp数组 
	printf("  j=\t");
	for(int j=0;j<=9;j++)
		printf("%-10d",j);
	printf("\n");
	for(int i=1;i<=9;i++){
    	printf("i=%d\t",i);
		for(int j=0;j<=9;j++)
			printf("%-10d",dp[i][j]);	
		printf("\n");
	}
}

int main(){
    int n,m;
    memset(dp,0,sizeof dp);
    init();//初始化处理 
    //print();//输出dp数组 
    while(~scanf("%d%d",&m,&n),n+m){//测试 1 24  62 386
    	//printf("%d\n",solve(n));
    	//printf("%d\n",solve(m));
        printf("%d\n",solve(n)-solve(m-1));
	}
    return 0;
}
