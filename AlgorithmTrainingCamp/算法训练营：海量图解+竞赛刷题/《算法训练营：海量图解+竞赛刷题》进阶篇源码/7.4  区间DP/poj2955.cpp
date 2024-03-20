#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[105][105];
char s[105];
 
bool match(int l,int r){
    if(s[l]=='('&&s[r]==')') return 1;
    if(s[l]=='['&&s[r]==']') return 1;
    return 0;
}
 
int main(){
    while(~scanf("%s",s)&&s[0]!='e'){
        int len=strlen(s);
        memset(dp,0,sizeof(dp));
        for(int d=1;d<len;d++){
            for(int i=0;i+d<len;i++){
                int j=i+d;
                if(match(i,j))
                    dp[i][j]=dp[i+1][j-1]+2;
                for(int k=i;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);  
            }
        }
        printf("%d\n", dp[0][len-1]);
    }
    return 0;
}
