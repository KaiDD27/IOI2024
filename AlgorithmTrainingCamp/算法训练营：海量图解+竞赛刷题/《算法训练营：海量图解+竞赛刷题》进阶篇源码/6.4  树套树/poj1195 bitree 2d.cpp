#include<cstdio>
#include<cstring>
#define maxn 1050
#define lowbit(x) (x)&(-x)
int c[maxn][maxn],n;

void add(int x,int y,int z){//������� 
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            c[i][j]+=z;
}

int sum(int x,int y)//����ͣ����Ͻ�(1,1)�����½�(x,y)��������� 
{
    int s=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            s+=c[i][j];
    return s;
}

int sum(int x1,int y1,int x2,int y2)//�����Ͻ�(x1,y1)�����½�(x2,y2)�Ӿ�������� 
{
	return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
}

int main()
{
    int opt,x,y,a,l,b,r,t;
	while(scanf("%d",&opt)!=EOF)
	{
		if(opt==3) break;
		if(opt==0)
		{
			scanf("%d",&n);
    		memset(c,0,sizeof(c));
		}
		else if(opt==1)
		{
            scanf("%d%d%d",&x,&y,&a);
            ++x;++y;
            add(x,y,a);
        }
        else
		{
            scanf("%d%d%d%d",&l,&b,&r,&t);
            ++l,++b,++r,++t;
            printf("%d\n",sum(l,b,r,t));
        }
	}
    return 0;
}
