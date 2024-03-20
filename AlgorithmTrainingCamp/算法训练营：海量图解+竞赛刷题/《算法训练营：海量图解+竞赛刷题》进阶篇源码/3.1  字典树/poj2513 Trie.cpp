#include<cstdio>//TrieTree+MergeSet+EulerPath
#include<cstring>
using namespace std;
const int maxn=500010;
const int maxz=26;//��ͬ�ַ�������Сд��ĸ26
int trie[maxn][maxz];
bool end[maxn];//��ǽ���
int n,tot;//�ַ�����,�±� 
int color=0;//��ɫ���ָ�룬����Ϊ��ɫ�ܸ���
int degree[maxn],col[maxn]; //���Ķ�������ɫ�� 
int fa[maxn];//���ȣ������Ϻ� 

void Init(){
	memset(end,false,sizeof(end));
	memset(degree,0,sizeof(degree));
	memset(col,0,sizeof(col));
	tot=1;
}

int Find(int x){//������
	if(fa[x]!=x)
		fa[x]=Find(fa[x]);
	return fa[x];
}

void Union(int a,int b){//�ϲ�����
	int pa=Find(a);
	int pb=Find(b);
	fa[pb]=pa;
}

int Insert(char *s){//���ַ���s���뵽�ֵ����� 
	int i=0,p=1;
    while(s[i]!='\0'){
    	int ch=s[i++]-'a';//ת��������
		if(!trie[p][ch]) 
			trie[p][ch]=++tot;//��¼�±� 
		p=trie[p][ch];
	}
	if(end[p])//��ɫ�����Ѵ���
		return col[p];  //��������ɫ�� 
	else{//���򴴽�����
		end[p]=true;
		col[p]=++color;
		return col[p];
	} 
}
 
int main(){
    Init();
	for(int i=1;i<maxn;i++)//�ӵ㣡�� ����дi<=maxn������𰸴��ܿռ�Ϊmaxn 
		fa[i]=i;
	char a[11],b[11];
    while(~scanf("%s %s",a,b)){
		int i=Insert(a);
		int j=Insert(b);//�õ�a��b��ɫ�ı��
        degree[i]++;
        degree[j]++;//��¼a��b��ɫ���ֵĴ���(�ܶ���)
		Union(i,j);
	}
	int s=Find(1);  //��ͼΪ��ͨͼ����sΪ���н�������
	int num=0;  //����Ϊ�����Ľ�����
	for(int i=1;i<=color;i++){
		if(degree[i]%2==1)
			num++;
		if(num>2||Find(i)!=s){//���ڶ�����ȣ�ͼΪɭ�֣�����ͨ
			printf("Impossible\n");
			return 0;
		}	
	}
	if(num==0||num==2) //û����ȶ����ǡ��������ȶ���
		printf("Possible\n");
	else
		printf("Impossible\n");
	return 0;
}
