#include<iostream>
using namespace std;
const int maxn=1000;
int a[maxn],n;
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int d=1;//统计最大的位数
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
void radixsort(int data[], int n) //基数排序
{
    int d=maxbit(data,n); //求最大位数 
    int *tmp=new int[n]; //辅助数组 
    int *count=new int[10]; //计数器
    int i,j,k;
    int radix=1;
    for(i=1;i<=d;i++) //进行d次排序
    {
        for(j=0;j<10;j++)
            count[j]=0; //每次分配前清空计数器
        for(j=0;j<n;j++)
        {
            k=(data[j]/radix)%10; //取出个位数，然后是十位数，... 
            count[k]++; //统计每个桶中的记录数
        }
        for(j=1;j<10;j++)
            count[j]+=count[j-1]; //将tmp中的位置依次分配给每个桶
        for(j=n-1;j>=0;j--) //将所有桶中记录依次收集到tmp中
        {
            k=(data[j]/radix)%10;
            tmp[--count[k]]=data[j];
        }
        for(j=0;j<n;j++) //将临时数组的内容复制到data中
            data[j]=tmp[j];
        cout<<"第"<<i<<"次排序结果："<<endl; 
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
