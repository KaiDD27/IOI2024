#include<iostream>
using namespace std;
const int maxn=1000;
int a[maxn],n;
int maxbit(int data[], int n) //���������������ݵ����λ��
{
    int d=1;//ͳ������λ��
    int p=10;
    for(int i=0;i<n;i++)
    {
        while(data[i]>=p)
        {
            p*=10;
            ++d;
        }
    }
    return d;
}
void radixsort(int data[], int n) //��������
{
    int d=maxbit(data,n); //�����λ�� 
    int *tmp=new int[n]; //�������� 
    int *count=new int[10]; //������
    int i,j,k;
    int radix=1;
    for(i=1;i<=d;i++) //����d������
    {
        for(j=0;j<10;j++)
            count[j]=0; //ÿ�η���ǰ��ռ�����
        for(j=0;j<n;j++)
        {
            k=(data[j]/radix)%10; //ȡ����λ����Ȼ����ʮλ����... 
            count[k]++; //ͳ��ÿ��Ͱ�еļ�¼��
        }
        for(j=1;j<10;j++)
            count[j]+=count[j-1]; //��tmp�е�λ�����η����ÿ��Ͱ
        for(j=n-1;j>=0;j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k=(data[j]/radix)%10;
            tmp[--count[k]]=data[j];
        }
        for(j=0;j<n;j++) //����ʱ��������ݸ��Ƶ�data��
            data[j]=tmp[j];
        cout<<"��"<<i<<"����������"<<endl; 
        for(int i=0;i<n;i++)
			cout<<data[i]<<"\t";
		cout<<endl;
        radix=radix*10;
    }
    delete[]tmp;
    delete[]count;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	radixsort(a,n);
	return 0;
}
