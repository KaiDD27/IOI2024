#include<iostream>
#include<algorithm>
const int N=1000005;
using namespace std;
double w[N],c; //�Ŷ�����������

int main(){
    int n,m;
    cin>>m;
    while(m--){//m���������� 
        cin>>c>>n;
		for(int i=0;i<n;i++){
			cin>>w[i]; //����ÿ����Ʒ����
		}
		sort(w,w+n); //���Ŷ�������������
		double tmp=0.0;
		int ans=0; // tmpΪ��װ�ص����ϵĹŶ�������ansΪ��װ�صĹŶ�����
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
