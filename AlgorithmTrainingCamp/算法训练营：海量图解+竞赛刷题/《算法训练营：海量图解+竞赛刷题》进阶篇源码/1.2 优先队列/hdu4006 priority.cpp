#include<iostream>
#include<cstdio>
#include<functional>//�ṩ�ȽϺ���greater<int> 
#include<queue>
using namespace std;

int main(){
    int i,n,k,num;
    char c;
    priority_queue<int,vector<int>,greater<int> >q;//С���� 
    while(~scanf("%d%d",&n,&k)){
        while(q.size())//��ʼ������Ϊ�� 
			q.pop();             
        for(i=1;i<=n;i++){
	        cin>>c;
	        if(c=='I'){
	            scanf("%d",&num);
	            if(q.size()<k) //����Ԫ�ظ���С��k
	            	q.push(num);
	            else if(q.top()<num) //���Ѷ�С������Ԫ��ʱ
	            	q.pop(),q.push(num);//�Ѷ����ӣ�Ԫ�����
	        }                        //������Զ��������k��Ԫ�� 
	        else
	        	printf("%d\n",q.top()); //�Ѷ���Ϊ��k��Ԫ��
        }
    }
    return 0;
}
