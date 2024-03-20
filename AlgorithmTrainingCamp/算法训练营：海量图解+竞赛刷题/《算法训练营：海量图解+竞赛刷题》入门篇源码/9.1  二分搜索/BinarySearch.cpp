#include<iostream>
#include<algorithm>
using namespace std;
const int M=100;
int x,n,i;
int s[M];

int BinarySearch(int s[],int n,int x){//���ֲ��ҷǵݹ��㷨
   int low=0,high=n-1;  //lowָ����������ĵ�һ��Ԫ�أ�highָ��������������һ��Ԫ��
   while(low<=high){
       int middle=(low+high)/2;  //middleΪ���ҷ�Χ���м�ֵ
       if(x==s[middle])  //x���ڲ��ҷ�Χ���м�ֵ���㷨����
          return middle;
       else if(x>s[middle]) //x���ڲ��ҷ�Χ���м�Ԫ�أ������벿�ֲ���
              low=middle+1;
            else            //xС�ڲ��ҷ�Χ���м�Ԫ�أ�����Ұ벿�ֲ���
              high=middle-1;
    }
    return -1;
}

int recursionBS(int s[],int x,int low,int high){ //���ֲ��ҵݹ��㷨
    //lowָ������ĵ�һ��Ԫ�أ�highָ����������һ��Ԫ��
    if(low>high)              //�ݹ��������
        return -1;
    int middle=(low+high)/2; //����middleֵ(���ҷ�Χ���м�ֵ)
    if(x==s[middle])        //x����s[middle]�����ҳɹ����㷨����
        return middle;
    else if(x<s[middle]) //xС��s[middle]�����ǰ�벿�ֲ���
            return recursionBS(s,x,low,middle-1);
        else            //x����s[middle]����Ӻ�벿�ֲ���
            return recursionBS(s,x,middle+1,high);
}

int main(){
    cout<<"�������е�Ԫ�ظ���nΪ��";
    cin>>n;
    cout<<"���������������е�Ԫ�أ�";
    for(i=0;i<n;i++)
       cin>>s[i];
    sort(s,s+n); //���ֲ��ҵ����б���������ģ����������Ҫ������
    cout<<"����������Ϊ��";
    for(i=0;i<n;i++)
       cout<<s[i]<<" ";
    cout<<endl;
    cout<<"������Ҫ���ҵ�Ԫ�أ�";
    cin>>x;
    //i=BinarySearch(s,n,x);
    i=recursionBS(s,x,0,n-1);
    if(i==-1)
		cout<<"��������û��Ҫ���ҵ�Ԫ��"<<endl;
    else
		cout<<"Ҫ���ҵ�Ԫ���ڵ�"<<i+1<<"λ"<<endl;//λ����±��1
    return 0;
}
