#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int map[27][27],indegree[27],topo[27],temp[27];
int n,flag;//flag=1:���� flag=-1:��ȷ��
stack<int>s;

int TopoSort(int n){ //��������
    flag=1;
	for(int i=1;i<=n;i++)
		temp[i]=indegree[i];//һ������һ��������������������鲻�ܸı� 
	int m=0,cnt=0;
    for(int i=1;i<=n;i++)//�������Ϊ��Ķ����������>1��������ȷ�� 
        if(temp[i]==0){
        	s.push(i);
        	cnt++;
		}
	if(cnt==0) return 0; //�л�
    if(cnt>1) flag=-1; //��ȷ��
    while(!s.empty()){
    	cnt=0;
		int i=s.top();
    	s.pop();
    	topo[m++]=i;
    	for(int j=1;j<=n;j++)
            if(map[i][j]){
            	temp[j]--;
            	if(!temp[j]){
        			s.push(j);
        			cnt++;
				}
			}
		if(cnt>1) flag=-1;//��ȷ��		
	}
	if(m<n)//�л�
		return 0;
	return flag;
}

int main(){
    int m,n;
	bool sign;//��sign=1ʱ���ѵó����
    string str;
    while(cin>>n>>m){
        if(m==0&&n==0) break;
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        sign=0;
        for(int i=1;i<=m;i++){
            cin>>str;
            if(sign) continue; //һ���ó�������Ժ��������벻������
            int x=str[0]-'A'+1;
            int y=str[2]-'A'+1;
            map[x][y]=1;
            indegree[y]++;
            int s=TopoSort(n);
            if(s==0){ //�л�
                printf("Inconsistency found after %d relations.\n",i);
                sign=1;
            }else if(s==1){ //����
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    cout<<char(topo[j]+'A'-1);
                printf(".\n");
                sign=1;
            }
        }
        if(!sign) //��ȷ��
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
