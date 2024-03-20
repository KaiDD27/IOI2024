#include<cstdio>//TrieTree+MergeSet+EulerPath
#include<cstring>
using namespace std;
const int maxn=500010;
const int maxz=26;//不同字符个数，小写字母26
int trie[maxn][maxz];
bool end[maxn];//标记结束
int n,tot;//字符串数,下标 
int color=0;//颜色编号指针，最终为颜色总个数
int degree[maxn],col[maxn]; //结点的度数，颜色号 
int fa[maxn];//祖先，即集合号 

void Init(){
	memset(end,false,sizeof(end));
	memset(degree,0,sizeof(degree));
	memset(col,0,sizeof(col));
	tot=1;
}

int Find(int x){//找祖先
	if(fa[x]!=x)
		fa[x]=Find(fa[x]);
	return fa[x];
}

void Union(int a,int b){//合并集合
	int pa=Find(a);
	int pb=Find(b);
	fa[pb]=pa;
}

int Insert(char *s){//将字符串s插入到字典树中 
	int i=0,p=1;
    while(s[i]!='\0'){
    	int ch=s[i++]-'a';//转换成数字
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//记录下标 
		p=trie[p][ch];
	}
	if(end[p])//颜色单词已存在
		return col[p];  //返回其颜色号 
	else{//否则创建单词
		end[p]=true;
		col[p]=++color;
		return col[p];
	} 
}
 
int main(){
    Init();
	for(int i=1;i<maxn;i++)//坑点！！ 不能写i<=maxn，否则答案错，总空间为maxn 
		fa[i]=i;
	char a[11],b[11];
    while(~scanf("%s %s",a,b)){
		int i=Insert(a);
		int j=Insert(b);//得到a、b颜色的编号
        degree[i]++;
        degree[j]++;//记录a、b颜色出现的次数(总度数)
		Union(i,j);
	}
	int s=Find(1);  //若图为连通图，则s为所有结点的祖先
	int num=0;  //度数为奇数的结点个数
	for(int i=1;i<=color;i++){
		if(degree[i]%2==1)
			num++;
		if(num>2||Find(i)!=s){//存在多个祖先，图为森林，不连通
			printf("Impossible\n");
			return 0;
		}	
	}
	if(num==0||num==2) //没有奇度顶点或恰好两个奇度顶点
		printf("Possible\n");
	else
		printf("Impossible\n");
	return 0;
}
