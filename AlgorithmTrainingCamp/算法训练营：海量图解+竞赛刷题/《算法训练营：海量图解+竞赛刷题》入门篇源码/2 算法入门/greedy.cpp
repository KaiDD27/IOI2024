#include<iostream>
#include<algorithm>
const int N=1000005;
using namespace std;
double w[N],c; //古董的重量数组

int main(){
    int n,m;
    cin>>m;
    while(m--){//m个测试用例 
        cin>>c>>n;
		for(int i=0;i<n;i++){
			cin>>w[i]; //输入每个物品重量
		}
		sort(w,w+n); //按古董重量升序排序
		double tmp=0.0;
		int ans=0; // tmp为已装载到船上的古董重量，ans为已装载的古董个数
		for(int i=0;i<n;i++){
		    tmp+=w[i];
		    if(tmp<=c)
		        ans++;
		    else
		        break;
		}
		cout<<ans<<endl;
    }
    return 0;
}
