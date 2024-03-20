#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int cmp(char a,char b){//'A'<'a'<'B'<'b'<...<'Z'<'z'
	if(tolower(a)!=tolower(b))
 		return tolower(a)<tolower(b);
	else
		return a<b;
}
int main(){
	char ch[20];
	int n;
	cin>>n;
	while(n--){
		scanf("%s",ch);
		sort(ch,ch+strlen(ch),cmp);
		do{
			printf("%s\n",ch);
		}while(next_permutation(ch,ch+strlen(ch),cmp));
	}
	return 0;
}
