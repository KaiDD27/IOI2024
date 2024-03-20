#include<iostream>
#include<cstring>
using namespace std;
const int maxn=25000000+10;
short hash[maxn];//数组太大，不能用int（int型数组1677w左右），用short型数组
int a1,a2,a3,a4,a5;
 
int main()
{
    int ans,temp;
    while(cin>>a1>>a2>>a3>>a4>>a5)
    {
        ans=0;
        memset(hash,0,sizeof(hash));
        for(int i=-50;i<=50;i++)
            for(int j=-50;j<=50;j++)
			{
	            if(i==0||j==0)  continue;
				temp=(a1*i*i*i+a2*j*j*j)*(-1);
	            if(temp<0)
	                temp=temp+maxn;
	            hash[temp]++;
			}
        for(int i=-50;i<=50;i++)
            for(int j=-50;j<=50;j++)
                for(int k=-50;k<=50;k++)
            	{
	               if(i==0||j==0||k==0)  continue;
	               temp=a3*i*i*i+a4*j*j*j+a5*k*k*k;
	               if(temp<0)
	               		temp=temp+maxn;
	               if(hash[temp])
	                	ans=ans+hash[temp];
            	}
        cout<<ans<<endl;
    }
    return 0;
}
