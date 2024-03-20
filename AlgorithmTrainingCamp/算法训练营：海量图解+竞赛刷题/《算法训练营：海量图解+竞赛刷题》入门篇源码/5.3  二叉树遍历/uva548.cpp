#include<iostream>
#include<sstream>
using namespace std;
const int maxn=10000+5;
int inorder[maxn],postorder[maxn],lch[maxn],rch[maxn];
int n,minv,minsum;

int createtree(int l1,int l2,int m){//由遍历序列创建二叉树 
	if(m<=0)
		return 0;
	int root=postorder[l2+m-1];
	int len=0;
	while(inorder[l1+len]!=root)//计算左子树长度
		len++;
	lch[root]=createtree(l1,l2,len);
	rch[root]=createtree(l1+len+1,l2+len,m-len-1);
	return root;
}

bool readline(int *a){//读入遍历序列，中间有空格
	string line;
	if(!getline(cin,line))
		return false;
	stringstream s(line);
	n=0;
	int x;
	while(s>>x)
		a[n++]=x;
	return n>0;
 } 

void findmin(int v,int sum){
	sum+=v;
	if(!lch[v]&&!rch[v])//叶子 
		if(sum<minsum||(sum==minsum&&v<minv)){
			minv=v;
			minsum=sum;
		}
	if(lch[v])//v有左子树 
		findmin(lch[v],sum);
	if(rch[v])//v有右子树 
		findmin(rch[v],sum);
}
int main(){
	while(readline(inorder)){//读入中序序列 
		readline(postorder);//读入后序序列
		createtree(0,0,n);
		minsum=0x7fffffff;
		findmin(postorder[n-1],0);
		cout<<minv<<endl;
	}
	return 0;
} 
