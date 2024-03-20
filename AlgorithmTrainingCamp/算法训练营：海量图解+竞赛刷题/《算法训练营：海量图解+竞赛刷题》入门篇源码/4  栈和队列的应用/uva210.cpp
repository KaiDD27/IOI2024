#include<bits/stdc++.h>
using namespace std;
const int maxNum=1005;
int n;//n个进程
int times[5];//表示5个指令所花的时间
int quantum;//周期时间
int val[26];//26个变量
int p[maxNum];//进程运行在指令的位置
vector<string>prg[maxNum];//指令
deque<int>readyQ;//就绪队列
queue<int>blockQ;//阻塞队列
bool locked;//锁
string s;

void run(int i){//执行指令
    int t=quantum,v;//周期时间
    while(t>0){
        string cur;
        cur=prg[i][p[i]];//获取指令
        switch(cur[2]){
            case '=':{//举例 a=58,常量为正整数，且小于100
                t-=times[0];
				v=cur[4]-'0';
				if(cur.size()==6)
					v=v*10+cur[5]-'0';//两位数 
				val[cur[0]-'a']=v;
                break;
            }
            case 'i':{//举例 print a
                t-=times[1];
                cout<<i<<": "<<val[cur[6]-'a']<<endl;
                break;
            }
            case 'c':{
                t-=times[2];
                if(locked){//lock，则将进程加入阻塞队列
                    blockQ.push(i);
                    return;
                }
                else//上锁
                	locked=true;
                break;
            }
            case 'l':{ //举例 unlock
        		t-=times[3];
                locked=false; // 解锁
                //当阻塞队列不为空，则将阻塞队列的第一个加入到就绪队列的第一个
                if(!blockQ.empty()){
                    int u=blockQ.front();
                    blockQ.pop();
                    readyQ.push_front(u);//加入队头 
                }
                break;
            }
            case 'd':{//end
                return;
            }
        }
        p[i]++;//时间没用完，进入该进程的下一条指令
    }
    readyQ.push_back(i);//时间用完了，将该进程加入到执行队列最后
}

int main(){
    int T;//T组用例
    cin>>T;
    while(T--){
        cin>>n;
		for(int i=0;i<5;i++)
			cin>>times[i];
		cin>>quantum;//时间周期 
        memset(val,0,sizeof(val));
        for(int i=1;i<=n;i++){
            prg[i].clear();
            while(getline(cin,s)){
                prg[i].push_back(s);
                if(prg[i].back()=="end")
					break;
            }
            readyQ.push_back(i);//加入就绪队列 
        }
        memset(p,0,sizeof(p));
        memset(val,0,sizeof(val));
        locked=false;
        while(!readyQ.empty()){
            int pid=readyQ.front();//获取就绪队列最前面的进程编号
            readyQ.pop_front();
            run(pid);//执行指令
        }
        if(T)
        	cout<<endl;
    }
    return 0;
}
