#include<iostream>
using namespace std;

int Partition(int r[],int low,int high){//���ֺ���
    int i=low,j=high,pivot=r[low];//��׼Ԫ��
    while(i<j){
        while(i<j&&r[j]>pivot) j--;//����ɨ��
        if(i<j)
            swap(r[i++],r[j]);      //r[i]��r[j]������i+1������1λ
        while(i<j&&r[i]<=pivot) i++;//����ɨ��
        if(i<j)
            swap(r[i],r[j--]);    //r[i]��r[j]���� ��j-1������1λ
    }
    return i;//���ػ�׼Ԫ��λ��
}

int Partition2(int r[],int low,int high){//���ֺ����Ż� 
    int i=low,j=high,pivot=r[low];//��׼Ԫ��
    while(i<j){
        while(i<j&&r[j]>pivot) j--;//����ɨ��
        while(i<j&&r[i]<=pivot) i++;//����ɨ��
        if(i<j)
            swap(r[i++],r[j--]); //r[i]��r[j]����
    }
    if(r[i]>pivot){
        swap(r[i-1],r[low]);  //r[i-1]��r[low]����
        return i-1;      //���ػ�׼Ԫ��λ��
    }
    swap(r[i],r[low]);//r[i]��r[low]����
    return i;//���ػ�׼Ԫ��λ��
}

void QuickSort(int r[],int low,int high){//�������� 
    if(low<high){
        int mid=Partition(r,low,high); //����
        QuickSort(r,low,mid-1);   //������ݹ����
        QuickSort(r,mid+1,high);  //������ݹ����
    }
}

int main(){
    int a[100];
    int i,N;
    cout<<"��������Ҫ��������ݵĸ�����";
    cin>>N;
    cout<<"������Ҫ��������ݣ�";
    for(i=0;i<N;i++)
        cin>>a[i];
    cout<<endl;
    QuickSort(a,0,N-1);
    cout<<"����������Ϊ��"<<endl;
    for(i=0;i<N;i++)
        cout<<a[i]<<" " ;
    cout<<endl;
    return 0;
}
