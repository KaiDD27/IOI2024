#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[20];
int dp[20][2];
//dp[pos][sta]��ʾ��ǰ��posλ��sta״̬�����������ĸ�����sta��ʾǰһλ�Ƿ���6��ֻ��0��1����״̬
int dfs(int pos,bool sta,bool limit){
    if(pos==0) return 1;
    if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
    int len=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=len;i++){
        if(sta&&i==2)continue;
        if(i==4) continue;//���Ǳ�֤ö�ٺϷ���
        ans+=dfs(pos-1,i==6,limit&&i==len);
    }
    if(!limit) dp[pos][sta]=ans;
    return ans;
}

int solve(int x){//���[0..x]֮�����������ĸ��� 
    int pos=0;
    while(x){
        a[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,1);//���������0���˴���1����
}

void print(){//���dp���� 
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
    while(~scanf("%d%d",&a,&b),a+b){//����24 386
		//printf("%d\n",solve(a));
		//print();
    	//printf("%d\n",solve(b));
    	//print();
		printf("%d\n",solve(b)-solve(a-1));
    }
    return 0;
}
