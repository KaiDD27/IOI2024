#include<iostream>//1..n��ȫ����
#define MX 50
using namespace std;
int x[MX];  //�����
int n;

void myarray(int t){
    if(t>n){
        for(int i=1;i<=n;i++) // �������
            cout<<x[i]<<" ";
        cout<<endl;

        return ;
    }
    for(int i=t;i<=n;i++){  // ö��
       swap(x[t],x[i]);  // ����
       myarray(t+1);  // ��������
       swap(x[t],x[i]); // �ָ�
    }
}

int main(){
    cout<<"�������е�Ԫ�ظ���n(��1..n������):"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++) //��ʼ��
       x[i]=i;
    myarray(1);
    return 0;
}
