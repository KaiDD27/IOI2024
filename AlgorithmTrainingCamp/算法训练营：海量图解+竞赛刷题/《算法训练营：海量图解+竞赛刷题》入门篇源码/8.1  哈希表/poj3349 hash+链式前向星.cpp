#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
const int P=100007;
int head[P],cnt;
int snow[maxn][6];
int n;
struct node{
	int to,next;
}e[maxn];

void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}

void addhash(int val,int i){//���±�i��ӵ�ֵΪval�������� 
	e[++cnt].to=i;
	e[cnt].next=head[val];
	head[val]=cnt;
}

int cmp(int a,int b){
    int i,j;
	for(i=0;i<6;i++){
        if(snow[a][0]==snow[b][i]){
        	for(j=1;j<6;j++)//˳ʱ�� 
        		if(snow[a][j]!=snow[b][(j+i)%6])
        			break;
			if(j==6) return 1;
			for(j=1;j<6;j++)//��ʱ�� 
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
    for(int j=head[key];j;j=e[j].next){
        if(cmp(i,e[j].to))
        	return 1;
    }
    addhash(key,i);
    return 0;
}

int main(){
    scanf("%d",&n);
    int flag=0;
    int sum,key;
    for(int i=0;i<n;i++){
    	for(int j=0;j<6;j++)
        	scanf("%d",&snow[i][j]);
		if(find(i)){
			flag=1;
			break;//������������������continue�������� 
		}
	}		
    if(flag)
        puts("Twin snowflakes found.");
    else
        puts("No two snowflakes are alike.");
    return 0;
}
