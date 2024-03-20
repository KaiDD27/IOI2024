#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=55;
vector<long long>deep[maxn];
int main(){
	int n,x;
	while(cin>>n){
		for(int i=0;i<n;i++)
			deep[i].clear();
		int maxd=0;
		for(int i=0;i<n;i++){
			cin>>x;
			deep[x].push_back(0);
			maxd=max(maxd,x);//求最大深度 
		}
		long long temp=1;
		for(int i=maxd;i>0;i--){
			for(int j=0;j<deep[i].size();j++)
				if(!deep[i][j])
					deep[i][j]=temp;//将第i层最大的元素值赋值给i-1层没有权值的结点 
			sort(deep[i].begin(),deep[i].end());//第i层排序 
			for(int j=0;j<deep[i].size();j+=2)
				deep[i-1].push_back(deep[i][j]+deep[i][j+1]);//合并后放入上一层 
			temp=*(deep[i].end()-1);//取第i层的最后一个元素，即第i层最大的元素 
		 } 
		cout<<*deep[0].begin()<<endl;//输出树根的权值
	}
	return 0;
}
