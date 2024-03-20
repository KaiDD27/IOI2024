#include<bits/stdc++.h>
using namespace std;
const int maxNum=1005;
int n;//n������
int times[5];//��ʾ5��ָ��������ʱ��
int quantum;//����ʱ��
int val[26];//26������
int p[maxNum];//����������ָ���λ��
vector<string>prg[maxNum];//ָ��
deque<int>readyQ;//��������
queue<int>blockQ;//��������
bool locked;//��
string s;

void run(int i){//ִ��ָ��
    int t=quantum,v;//����ʱ��
    while(t>0){
        string cur;
        cur=prg[i][p[i]];//��ȡָ��
        switch(cur[2]){
            case '=':{//���� a=58,����Ϊ����������С��100
                t-=times[0];
				v=cur[4]-'0';
				if(cur.size()==6)
					v=v*10+cur[5]-'0';//��λ�� 
				val[cur[0]-'a']=v;
                break;
            }
            case 'i':{//���� print a
                t-=times[1];
                cout<<i<<": "<<val[cur[6]-'a']<<endl;
                break;
            }
            case 'c':{
                t-=times[2];
                if(locked){//lock���򽫽��̼�����������
                    blockQ.push(i);
                    return;
                }
                else//����
                	locked=true;
                break;
            }
            case 'l':{ //���� unlock
        		t-=times[3];
                locked=false; // ����
                //���������в�Ϊ�գ����������еĵ�һ�����뵽�������еĵ�һ��
                if(!blockQ.empty()){
                    int u=blockQ.front();
                    blockQ.pop();
                    readyQ.push_front(u);//�����ͷ 
                }
                break;
            }
            case 'd':{//end
                return;
            }
        }
        p[i]++;//ʱ��û���꣬����ý��̵���һ��ָ��
    }
    readyQ.push_back(i);//ʱ�������ˣ����ý��̼��뵽ִ�ж������
}

int main(){
    int T;//T������
    cin>>T;
    while(T--){
        cin>>n;
		for(int i=0;i<5;i++)
			cin>>times[i];
		cin>>quantum;//ʱ������ 
        memset(val,0,sizeof(val));
        for(int i=1;i<=n;i++){
            prg[i].clear();
            while(getline(cin,s)){
                prg[i].push_back(s);
                if(prg[i].back()=="end")
					break;
            }
            readyQ.push_back(i);//����������� 
        }
        memset(p,0,sizeof(p));
        memset(val,0,sizeof(val));
        locked=false;
        while(!readyQ.empty()){
            int pid=readyQ.front();//��ȡ����������ǰ��Ľ��̱��
            readyQ.pop_front();
            run(pid);//ִ��ָ��
        }
        if(T)
        	cout<<endl;
    }
    return 0;
}
