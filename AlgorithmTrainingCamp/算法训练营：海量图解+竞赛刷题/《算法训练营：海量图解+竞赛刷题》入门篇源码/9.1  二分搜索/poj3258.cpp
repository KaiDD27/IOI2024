#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50050;
int L,n,m,dis[maxn];

bool judge(int x){ //�Ƴ�m��ʯͷ֮�������಻С��x
	int num=n-m; //����m��ʯͷ������num��ʯͷ��ѭ��num��
    int last=0; //��¼ǰһ���ѷ���ʯͷ�±�
    for(int i=0;i<num;i++){ //������Щʯͷ��Ҫʹ�����಻С��x
        int cur=last+1;
        while(cur<=n&&dis[cur]-dis[last]<x) //���ڵ�1����last����>=x��λ��
            cur++; //��cur�ۼ�λ�� 
        if(cur>n)
			return 0; //�������������д���n�ˣ�˵���Ų���
        last=cur; //����lastλ��
    }
    return 1;
}

int main(){
    cin>>L>>n>>m;
    if(n==m){
        cout<<L<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
		cin>>dis[i];
    dis[0]=0;//���ӿ�ʼ��
	dis[n+1]=L;//���ӽ�����
    sort(dis,dis+n+2);
    int left=0,right=L;
    while(right-left>1){
        int mid=(right+left)/2;
        if(judge(mid))
			left=mid;//����ŵÿ���˵��x�����Ը���
        else
			right=mid;
    }
    cout<<left<<endl;
    return 0;
}
