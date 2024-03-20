#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100010;
const int P=100007;
vector<int> hash[P];
int snow[maxn][6];
int n;
int cmp(int a,int b){
	int i,j;
	for(i=0;i<6;i++){
        if(snow[a][0]==snow[b][i]){
        	for(j=1;j<6;j++)//顺时针 
        		if(snow[a][j]!=snow[b][(j+i)%6])
        			break;
			if(j==6) return 1;
			for(j=1;j<6;j++)//逆时针 
        		if(snow[a][6-j]!=snow[b][(j+i)%6])
        			break;
			if(j==6) return 1;        			
		}
    }
    return 0;
}

bool find(int i){
	int key,sum=0;
    for(int j=0;j<6;j++) 
        sum+=snow[i][j];
    key=sum%P;
    for(int j=0;j<hash[key].size();j++){
        if(cmp(i,hash[key][j]))
        	return 1;
    }
    hash[key].push_back(i);
    return 0;
}

int main(){
    int flag=0;
    int sum,key;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	for(int j=0;j<6;j++)
        	scanf("%d",&snow[i][j]);
		if(find(i)){
			flag=1;
			break;//如果多组测试用例，则continue继续读入 
		}
	}		
    if(flag)
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");
    return 0;
}
