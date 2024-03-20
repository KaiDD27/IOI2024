#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
LL dp[2][1<<20];//��¼������ 
int state[2][1<<20];//��¼״̬��S=state[pre][s]��preΪǰһ�����ӱ�ǣ�sΪ״̬���,SΪ״̬ 
int total[2];//��¼״̬���� 
int pre,now;
int endx,endy;//��¼���һ�����ϰ����� 
bool map[15][15];
char str[200];
int m,n;
LL ans;
const int HASH=4001;//�ӵ㣡����ϣֵ̫��ᳬʱ������m<=10,��4λ����������3007,5λ����ʱ�����  
int Hash[HASH];//��¼S��Ӧ�Ĺ�ϣֵx��״̬���
 
void HashIn(int S,LL num){
	int x=S%HASH;
	while(~Hash[x]&&state[now][Hash[x]]!=S){//����̽�� 
		x++;
		x%=HASH;
	}
	if(Hash[x]==-1){//δ�ҵ�������hash���� 
		dp[now][total[now]]=num;
		state[now][total[now]]=S;
		Hash[x]=total[now];//��¼״̬���
		total[now]++;
	}
	else//�ҵ����ۼӷ����� 
		dp[now][Hash[x]]+=num;
}
 
void init(){
	memset(map,0,sizeof(map));
	endx=-1;
	for(int i=0;i<n;i++){
		scanf("%s",str);
		for(int j=0;j<m;j++){
			if(str[j]=='.'){
				map[i][j]=1;
				endx=i;
				endy=j;
			}
			else
				map[i][j]=0;
		}
	}
	if(map[n-1][0]==0||map[n-1][m-1]==0)//���һ�е���ǻ��ҽǲ��ɴ�
		endx=endy=-1;
	else{
		endx=n+1;
		endy=m-1;
	}
	for(int j=0;j<m;j++){//�������У���һ����β���У����������У��ڶ��о����� 
		map[n][j]=0;
		map[n+1][j]=1;
	}
	map[n][0]=map[n][m-1]=1;
	n+=2;//ע��  ���ｫ��������  ��������ʹ��
}
 
//λ���㣬ȡS������l�ĵ�pλ
int getV(int S,int p,int l=2){//4���ƣ�l=2��8���ƣ�l=3
	return (S>>(p*l))&((1<<l)-1);
}
 
//λ���㣬����S������l�ĵ�pλֵΪv
void setV(int& S,int p,int v,int l=2){
	S^=getV(S,p)<<(p*l);//��pλ��0
	S|=v<<(p*l);//��pλ��v 
}
 
void memsetnow(){//��ϣÿ���ú���� 
	memset(Hash,-1,sizeof(Hash));
	total[now]=0;
}
 
void solve(){
	init();
	if(endx==-1){
		puts("0");
		return;
	}
	pre=0,now=1;
	ans=0;
	memsetnow();
	dp[pre][0]=1;
	state[pre][0]=0;
	total[pre]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			memsetnow();
			for(int s=0;s<total[pre];s++){//sΪ״̬��� 
				if(dp[pre][s]){
					LL num=dp[pre][s];
					int S=state[pre][s];
					int p=getV(S,j);
					int q=getV(S,j+1);
					if(map[i][j]==0){//���ϰ� 
						if(p==0&&q==0)
							HashIn(S,num);
						continue;
					}
					if(p==0&&q==0){//p��q��Ϊ0����һ����� 
						if(map[i+1][j]&&map[i][j+1]){
							int nS=S;
							setV(nS,j,1);
							setV(nS,j+1,2);
							HashIn(nS,num);
						}
						continue;
					}
					if((p>0)^(q>0)){//p��q��һ��Ϊ0���ڶ������ 
						if(map[i+(p>0)][j+(q>0)])
							HashIn(S,num);
						if(map[i+(q>0)][j+(p>0)]){
							int nS=S;
							setV(nS,j,q);//p��q���� 
							setV(nS,j+1,p);
							HashIn(nS,num);
						}
						continue;
					}
					if(p==1&&q==1){//�����������3.1 
						int find=1;
						for(int v=j+2;v<=m;v++){//�����qƥ���������),��Ϊ������ 
							int k=getV(S,v);
							if(k==1)
								find++;
							else if(k==2)
								find--;
							if(find==0){
								int nS=S;
								setV(nS,j,0);//p��q��0 
								setV(nS,j+1,0);
								setV(nS,v,1);//��Ϊ������
								HashIn(nS,num);
								break;
							}
						}
						continue;
					}
					if(p==2&&q==2){//�����������3.2 
						int find=1;
						for(int v=j-1;v>=0;v--){//��ǰ��pƥ���������(,��Ϊ������ 
							int k=getV(S,v);
							if(k==2)
								find++;
							else if(k==1)
								find--;
							if(find==0){
								int nS=S;
								setV(nS,j,0);//p��q��0 
								setV(nS,j+1,0);
								setV(nS,v,2);//��Ϊ������
								HashIn(nS,num);
								break;
							}
						}
						continue;
					}
					if(p==2&&q==1){//�����������3.3 
						int nS=S;
						setV(nS,j,0);//p��q��0 
						setV(nS,j+1,0);
						HashIn(nS,num);
						continue;
					}
					if(p==1&&q==2){//�����������3.4 
						if(i==endx&&j==endy)//���һ�����ϰ����� 
							ans+=num;
					}
				}	
			}
			swap(now,pre);
		}
		memsetnow();
		for(int s=0;s<total[pre];s++)
			if(dp[pre][s]){
				LL num=dp[pre][s];
				int S=state[pre][s]<<2;//����һ�� 
				HashIn(S,num);
			}
		swap(now,pre);
	}
	printf("%I64d\n",ans);
}
 
int main(){
	while(~scanf("%d%d",&n,&m),n+m){
		if(n==1&&m==1){//ֻ��һ�����⴦��
	        scanf("%s",str);
	        if(str[0]=='.') printf("1\n");
	        else printf("0\n");
	        continue;
	    }else if(m==1){//ֻ��һ�ж��е����
	        int ok=1;
	        for(int i=0;i<n;i++){
				scanf("%s",str);
	            if(str[0]=='.'&&i<n-1)
	                ok=0;
	        }
	        if(str[0]=='#')
	            ok=0;
	        printf("%d\n",ok);
	        continue;
		}
		solve();
	} 
	return 0;
}
