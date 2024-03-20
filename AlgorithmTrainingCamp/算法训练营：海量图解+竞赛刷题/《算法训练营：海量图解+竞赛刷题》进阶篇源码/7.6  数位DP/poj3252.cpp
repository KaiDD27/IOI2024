#include<cstdio>
#include<cstring>
using namespace std;
int dp[40][40][40];
int dig[12];
/*求一个区间内Round Numbers（二进制0的个数不小于1的个数）的个数。 
  状态dp[pos][num0][num1]；
  pos为当前数位，num0为二进制中0的个数，num1为二进制中1的个数； 
  lead表示前导零； 
  limit表示数位限制。
*/
int dfs(int pos,int num0,int num1,bool lead,bool limit){//前导0，限制 
    if(pos==-1) return num0>=num1;
    if(!limit&&dp[pos][num0][num1]!=-1) return dp[pos][num0][num1];
    int len=limit?dig[pos]:1;
    int ans=0;
    for(int i=0;i<=len;i++){
        if(lead&&!i)//前导0，前面没有1
            ans+=dfs(pos-1,0,0,1,limit&&i==len);
        else//非前导0，即前面已有1
            ans+=dfs(pos-1,num0+(i==0),num1+(i==1),0,limit&&i==len);
    }
    if(!limit)
		dp[pos][num0][num1]=ans;
    return ans;
}

int solve(int x){
    int pos=0;
    while(x){
        dig[pos++]=x%2;
        x/=2;
    }
    return dfs(pos-1,0,0,1,1);
}

void print(){//输出dp数组 
	printf("           ");
	for(int j=0;j<=2;j++)
		printf("%-5d",j);
	printf("\n");
	for(int i=0;i<=9;i++){
    	printf("i=%d  ",i);
		for(int j=0;j<=2;j++){
			printf("j=%d  ",j);
			for(int k=0;k<=2;k++)
				printf("%-5d",dp[i][j][k]);
		}		
		printf("\n");
	}
}

int main()
{
    int a,b;
	memset(dp,-1,sizeof(dp));
    while(~scanf("%d%d",&a,&b)){//5 10
    	memset(dp,-1,sizeof(dp));
    	//printf("%d\n",solve(b));
    	//print();
    	//memset(dp,-1,sizeof(dp));
    	//printf("%d\n",solve(a));
    	//print();
        printf("%d\n",solve(b)-solve(a-1));
    }
    return 0;
}
