#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string preorder,inorder;
void postorder(int l1,int l2,int n){//传下标 
	if(n<=0)
		return;
	int len=inorder.find(preorder[l1])-l2;//返回其位置 
	postorder(l1+1,l2,len);
	postorder(l1+len+1,l2+len+1,n-len-1);
	cout<<preorder[l1];
}

int main(){
	while(cin>>preorder>>inorder){
		int len=preorder.size();
		postorder(0,0,len);
		cout<<endl;
	}
	return 0;
 } 
