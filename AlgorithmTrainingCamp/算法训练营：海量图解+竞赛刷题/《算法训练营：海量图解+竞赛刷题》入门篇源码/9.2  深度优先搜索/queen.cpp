//program 5-4
#include<iostream>
#include<cmath>   //�����ֵ������Ҫ�����ͷ�ļ�
#define M 105
using namespace std;

int n;//n��ʾn���ʺ�
int x[M];  //x[i]��ʾ��i���ʺ�����ڵ�i�е�x[i]��
long long countn;    //countn��ʾn�ʺ�������н�ĸ���

bool Place(int t) //�жϵ�t���ʺ��ܷ�����ڵ�i��λ��
{
    bool ok=true;
    for(int j=1;j<t;j++)   //�жϸ�λ�õĻʺ��Ƿ���ǰ��t-1���Ѿ����õĻʺ��ͻ
    {
       if(x[t]==x[j]||t-j==fabs(x[t]-x[j]))//�ж��С��Խ����Ƿ��ͻ
       {
           ok=false;
           break;
       }
    }
    return ok;
}

void Backtrack(int t)
{
    if(t>n)  //�����ǰλ��Ϊn,���ʾ�Ѿ��ҵ��������һ����
    {
        countn++;
        for(int i=1; i<=n;i++) //��ӡѡ���·��
          cout<<x[i]<<" ";
        cout<<endl;
        cout<<"----------"<<endl;
    }
    else
        for(int i=1;i<=n;i++) //�ֱ��ж�n����֧,�ر�ע��i��Ҫ����Ϊȫ�ֱ���,����ݹ����������
        {
            x[t]=i;
            if(Place(t))
                Backtrack(t+1); //�������ͻ�Ļ�������һ�е�����
        }
}

int main()
{
    cout<<"������ʺ�ĸ��� n:";
    cin>>n;
    countn=0;
    Backtrack(1);
    cout <<"�𰸵ĸ����ǣ�"<<countn<< endl;
    return 0;
}
