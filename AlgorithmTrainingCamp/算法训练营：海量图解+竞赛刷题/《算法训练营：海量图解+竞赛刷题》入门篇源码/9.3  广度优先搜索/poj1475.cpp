#include<cstdio>
#include<cstring>
#include<string> 
#include<queue>
using namespace std;
int N,M;
char mp[25][25];
int sx,sy,bx,by;//人和箱子的初始位置 
const int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
const char dpathB[4]={'N','S','E','W'};
const char dpathP[4]={'n','s','e','w'};
string ans;

struct person{
    int x,y;
    string path;
    person(int x_,int y_,string path_){x=x_,y=y_,path=path_;} 
};

struct node{
    int px,py,bx,by;
    string path;
	node(int px_,int py_,int bx_,int by_,string path_){
		px=px_,py=py_,bx=bx_,by=by_,path=path_;
	} 
};

bool check(int x,int y){
    if(x<0||x>=N||y<0||y>=M) return false;
    if(mp[x][y]=='#') return false;
    return true;
}

bool bfs2(int ppx,int ppy,int bbx,int bby,int tx,int ty,string &path){
    int vis[25][25];//局部标识数组，不要定义全局 
	memset(vis,0,sizeof(vis));//清零 
    vis[ppx][ppy]=1;//人的位置 
    vis[bbx][bby]=1;//箱子的位置
    queue<person> Q;
    Q.push(person(ppx,ppy,""));
    while(!Q.empty()){
        person now=Q.front();
        Q.pop();
        if(now.x==tx&&now.y==ty){//目标位置，即箱子的前一个位置 
            path=now.path;
            return true;
        }
        for(int i=0;i<4;i++){
            int npx=now.x+dir[i][0];//人的新位置 
            int npy=now.y+dir[i][1];
            if(check(npx,npy)&&!vis[npx][npy]){
                vis[npx][npy]=1;
                Q.push(person(npx,npy,now.path+dpathP[i]));
            }
        }
    }
    return false;
}

bool bfs(){
    int vis[25][25];
	memset(vis,0,sizeof(vis));//清零 
    vis[bx][by]=1;
    queue<node> q;
    q.push(node(sx,sy,bx,by,""));
    while(!q.empty()){
        node now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nbx=now.bx+dir[i][0];//箱子的新位置
            int nby=now.by+dir[i][1];
            int tx=now.bx-dir[i][0];//箱子的前一个位置 
            int ty=now.by-dir[i][1];
            string path="";
            if(check(nbx,nby)&&check(tx,ty)&&!vis[nbx][nby]){
                if(bfs2(now.px,now.py,now.bx,now.by,tx,ty,path)){
                    if(mp[nbx][nby]=='T'){
                        ans=now.path+path+dpathB[i];
                        return true;
                    }
					vis[nbx][nby]=1;
                    q.push(node(now.bx,now.by,nbx,nby,now.path+path+dpathB[i]));
                }
            }
        }
    }
    return false;
}

int main(){
    int cas=0;
    while(~scanf("%d%d",&N,&M),N&&M){
        for(int i=0;i<N;i++){
            scanf("%s",mp[i]);
            for(int j=0;j<M;j++){
                if(mp[i][j]=='S')
                    sx=i,sy=j;
                if(mp[i][j]=='B')
                    bx=i,by=j;
            }
        }
        printf("Maze #%d\n",++cas);
        if(bfs())
            printf("%s\n\n",ans.c_str());
        else printf("Impossible.\n\n");
    }
    return 0;
}
