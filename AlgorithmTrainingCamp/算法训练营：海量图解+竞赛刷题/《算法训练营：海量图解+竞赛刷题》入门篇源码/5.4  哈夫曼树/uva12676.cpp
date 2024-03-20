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
			maxd=max(maxd,x);//�������� 
		}
		long long temp=1;
		for(int i=maxd;i>0;i--){
			for(int j=0;j<deep[i].size();j++)
				if(!deep[i][j])
					deep[i][j]=temp;//����i������Ԫ��ֵ��ֵ��i-1��û��Ȩֵ�Ľ�� 
			sort(deep[i].begin(),deep[i].end());//��i������ 
			for(int j=0;j<deep[i].size();j+=2)
				deep[i-1].push_back(deep[i][j]+deep[i][j+1]);//�ϲ��������һ�� 
			temp=*(deep[i].end()-1);//ȡ��i������һ��Ԫ�أ�����i������Ԫ�� 
		 } 
		cout<<*deep[0].begin()<<endl;//���������Ȩֵ
	}
	return 0;
}
