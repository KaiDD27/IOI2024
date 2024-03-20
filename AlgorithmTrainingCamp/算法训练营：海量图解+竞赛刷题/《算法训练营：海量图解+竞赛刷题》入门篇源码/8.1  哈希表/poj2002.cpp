#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
const int H=10007;
int sx[N],sy[N];
struct Node{
	int x,y,next;
}node[N];

int n,cur,hashTable[H];
long ans;
 
void initHash(){
	for(int i=0;i<H;i++)
		hashTable[i]=-1;
	cur=0;
	ans=0;
}
 
void insertHash(int x,int y){
	int h=(x*x+y*y)%H;
	node[cur].x=x;
	node[cur].y=y;
	node[cur].next=hashTable[h];
	hashTable[h]=cur++;
}
 
bool searchHash(int x,int y){
	int h=(x*x+y*y)%H;
	int next=hashTable[h];
	while(next!=-1){
		if(x==node[next].x&&y==node[next].y)
			return true;
		next=node[next].next;
	}
	return false;
}
 
int main(){
	int xx,yy,x1,y1,x2,y2;
	while(~scanf("%d",&n)&&n){
		initHash();
		for(int i=0;i<n;i++){
			scanf("%d%d",&sx[i],&sy[i]);
			insertHash(sx[i],sy[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				xx=sx[i]-sx[j],yy=sy[i]-sy[j];
				x1=sx[i]-yy,y1=sy[i]+xx;
				x2=sx[j]-yy,y2=sy[j]+xx;
				if(searchHash(x1,y1)&&searchHash(x2,y2))
					ans++;
				x1=sx[i]+yy,y1=sy[i]-xx;
				x2=sx[j]+yy,y2=sy[j]-xx;
				if(searchHash(x1,y1)&&searchHash(x2,y2))
					ans++;
			}
		}
		printf("%ld\n", ans>>=2);
	}
	return 0;
}
