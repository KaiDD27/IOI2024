#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int map[27][27],indegree[27],topo[27],temp[27];
int n,flag;//flag=1:有序 flag=-1:不确定
stack<int>s;

int TopoSort(int n){ //拓扑排序
    flag=1;
	for(int i=1;i<=n;i++)
		temp[i]=indegree[i];//一边输入一边拓扑排序，所有入度数组不能改变 
	int m=0,cnt=0;
    for(int i=1;i<=n;i++)//查找入度为零的顶点个数，若>1，拓扑序不确定 
        if(temp[i]==0){
        	s.push(i);
        	cnt++;
		}
	if(cnt==0) return 0; //有环
    if(cnt>1) flag=-1; //不确定
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
		if(cnt>1) flag=-1;//不确定		
	}
	if(m<n)//有环
		return 0;
	return flag;
}

int main(){
    int m,n;
	bool sign;//当sign=1时，已得出结果
    string str;
    while(cin>>n>>m){
        if(m==0&&n==0) break;
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        sign=0;
        for(int i=1;i<=m;i++){
            cin>>str;
            if(sign) continue; //一旦得出结果，对后续的输入不做处理
            int x=str[0]-'A'+1;
            int y=str[2]-'A'+1;
            map[x][y]=1;
            indegree[y]++;
            int s=TopoSort(n);
            if(s==0){ //有环
                printf("Inconsistency found after %d relations.\n",i);
                sign=1;
            }else if(s==1){ //有序
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    cout<<char(topo[j]+'A'-1);
                printf(".\n");
                sign=1;
            }
        }
        if(!sign) //不确定
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
