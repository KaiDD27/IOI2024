#include<cstdio>//打表，cantor+BFS，hdu1043 93ms，poj1077 329ms 
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
const int N=362880+10;
const int dir[4][2]={-1,0,0,-1,1,0,0,1};//逆向推，正好相反
const char to_c[]="drul";
struct node{
    int a[9];
    int x;
};
node st;
int fac[10],vis[N],pre[N];
char ans[N];
queue<node>q;

int cantor(node s){//康托判重 
    int code=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)
			if(s.a[j]<s.a[i]) cnt++;
        code+=fac[8-i]*cnt;
    }
    return code;
}

void get_all_result(){
    int k_s,k_n;
	memset(vis,0,sizeof(vis));
    for(int i=0;i<9;i++)
    	st.a[i]=i;
    st.x=8;
	vis[cantor(st)]=1;
    q.push(st);
    while(!q.empty()){
        node t=q.front();
        q.pop();
        k_s=cantor(t);
        for(int i=0;i<4;i++){
			node nex=t;
            int row=t.x/3+dir[i][0];
			int col=t.x%3+dir[i][1];
			int newx=row*3+col;//转换为数字 
			if(row<0||row>2||col<0||col>2) continue;
            swap(nex.a[t.x],nex.a[newx]);
            nex.x=newx;
            k_n=cantor(nex);
            if(vis[k_n]) continue;
            vis[k_n]=1;
            q.push(nex);
            pre[k_n]=k_s;
            ans[k_n]=to_c[i];
        }  
    }
}

void getpath(int x){
    while(x!=0){//目标的cantor值为0 
        printf("%c",ans[x]);
        x=pre[x];
    }
    printf("\n");
}

int main(){
	fac[0]=1;
    for(int i=1;i<=9;i++) fac[i]=fac[i-1]*i;
    get_all_result();
    char str[10];
    node start;
	while(~scanf("%s",str)){
		if(str[0]=='x')
			start.x=0,start.a[0]=8;
		else
			start.a[0]=str[0]-'0'-1;
		for(int i=1;i<9;i++){
			scanf("%s",str);
			if(str[0]=='x')
				start.x=i,start.a[i]=8;
			else
				start.a[i]=str[0]-'0'-1;
		}
		int judge=cantor(start);
        if(!vis[judge]) 
			printf("unsolvable\n");
		else
			getpath(judge);
    }
    return 0;
}
