#include<cstdio>//最长公共子序列，时间复杂度O(nm)
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
char s1[maxn];
char s2[maxn];
int dp[maxn][maxn];//dp[i][j]表示s1[1..i]和s2[1..j]的最长公共子序列长度

int main(){
    while(~scanf("%s%s",s1,s2)){
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(int i=0;i<=len1;i++) dp[i][0]=0;
        for(int j=0;j<=len2;j++) dp[0][j]=0;
        for(int i=1;i<=len1;i++) 
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
