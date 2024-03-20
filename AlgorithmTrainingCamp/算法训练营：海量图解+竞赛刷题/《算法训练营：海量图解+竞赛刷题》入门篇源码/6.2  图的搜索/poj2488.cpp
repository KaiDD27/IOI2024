#include<iostream>
#include<cstring>
using namespace std;
bool map[30][30],flag;
int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int path[30][2];
int n,m;

int dfs(int x,int y,int step)
{
	if(step==n*m)
		return flag=1;
	for(int i=0;i<8;i++)
	{
		int x2=x+dir[i][0];
		int y2=y+dir[i][1];
		if(x2>=1&&x2<=n&&y2>=1&&y2<=m&&!map[x2][y2]&&!flag)
		{
			map[x2][y2]=1;
			path[step][0]=x2;
			path[step][1]=y2;
			dfs(x2,y2,step+1);
			map[x2][y2]=0;
		}		
	}
	return flag;
}

int main()
{
	int T;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		memset(map,0,sizeof(map));
		cin>>m>>n;
		flag=0;
		cout<<"Scenario #"<<k<<":"<<endl;
		path[0][0]=1;
		path[0][1]=1;
		map[1][1]=1;
		if(dfs(1,1,1))
		{
			for(int i=0;i<m*n;i++)
				cout<<char(path[i][0]+'A'-1)<<path[i][1];
			cout<<endl<<endl;
		}
		else
			cout<<"impossible"<<endl<<endl;
	}
	return 0;
}
