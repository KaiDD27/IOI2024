#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[300];

int main(){
    int len,i,n;
    while(~scanf("%s",s)){
        len=strlen(s);
        sort(s,s+len);
        printf("%s\n",s);
        while(next_permutation(s,s+len))
            printf("%s\n",s);
    }
    return 0;
}
