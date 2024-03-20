#include<cstdio>//����������У�ʱ�临�Ӷ�O(nm)
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
char s1[maxn];
char s2[maxn];
int dp[maxn][maxn];//dp[i][j]��ʾs1[1..i]��s2[1..j]������������г���

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
