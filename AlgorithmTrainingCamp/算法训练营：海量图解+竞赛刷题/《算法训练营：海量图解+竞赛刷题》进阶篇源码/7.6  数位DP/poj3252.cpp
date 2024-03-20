#include<cstdio>
#include<cstring>
using namespace std;
int dp[40][40][40];
int dig[12];
/*��һ��������Round Numbers��������0�ĸ�����С��1�ĸ������ĸ����� 
  ״̬dp[pos][num0][num1]��
  posΪ��ǰ��λ��num0Ϊ��������0�ĸ�����num1Ϊ��������1�ĸ����� 
  lead��ʾǰ���㣻 
  limit��ʾ��λ���ơ�
*/
int dfs(int pos,int num0,int num1,bool lead,bool limit){//ǰ��0������ 
    if(pos==-1) return num0>=num1;
    if(!limit&&dp[pos][num0][num1]!=-1) return dp[pos][num0][num1];
    int len=limit?dig[pos]:1;
    int ans=0;
    for(int i=0;i<=len;i++){
        if(lead&&!i)//ǰ��0��ǰ��û��1
            ans+=dfs(pos-1,0,0,1,limit&&i==len);
        else//��ǰ��0����ǰ������1
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

void print(){//���dp���� 
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
