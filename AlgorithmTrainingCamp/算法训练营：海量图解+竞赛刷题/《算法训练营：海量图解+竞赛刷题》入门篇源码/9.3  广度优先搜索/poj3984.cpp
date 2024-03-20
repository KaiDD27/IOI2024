#include<cstdio>
#include<queue>
using namespace std;
int mp[5][5],vis[5][5];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int x,y;
};
node pre[10][10];

void bfs(){
    queue<node> que;
    node st;
    st.x=st.y=0;
    que.push(st);
    vis[0][0]=1;
    while(!que.empty()){
        node now=que.front();
        que.pop();
        if(now.x==4&&now.y==4)
            return;
        for(int i=0;i<4;i++){
            node next;
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x>=0&&next.x<5&&next.y>=0&&next.y<5&&!mp[next.x][next.y]&&!vis[next.x][next.y]){
                vis[next.x][next.y]=1;
                que.push(next);
                pre[next.x][next.y]=now;
            }
        }
    }
}

void print(node cur){
    if(cur.x==0&&cur.y==0){
        printf("(0, 0)\n");
        return;
    }
    print(pre[cur.x][cur.y]);//ÄæÐòÊä³ö
    printf("(%d, %d)\n",cur.x,cur.y);
}

int main(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&mp[i][j]);
    bfs();
    node ed;
    ed.x=ed.y=4;
    print(ed);
    return 0;
}
