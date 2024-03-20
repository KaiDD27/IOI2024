#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define m 15//��ϣ��ı�
#define NULLKEY 0//��ԪΪ�յı��
int HT[m],HC[m];

int H(int key){//��ϣ����
	return key%13;
}

int Linedetect(int HT[],int H0,int key,int &cnt){
    int Hi;
    for(int i=1;i<m;++i){
        cnt++;
        Hi=(H0+i)%m; //��������̽�ⷨ������һ����ϣ��ַHi
        if(HT[Hi]==NULLKEY)
            return Hi;	//����ԪHiΪ�գ�������Ԫ�ز�����
        else if(HT[Hi]==key)
            return Hi; //����ԪHi��Ԫ�صĹؼ���Ϊkey
    }
    return -1;
}

int Seconddetect(int HT[],int H0,int key,int &cnt){
    int Hi;
    for(int i=1;i<=m/2;++i){
        int i1=i*i;
        int i2=-i1;
        cnt++;
        Hi=(H0+i1)%m; //��������̽�ⷨ������һ����ϣ��ַHi
        if(HT[Hi]==NULLKEY)//����ԪHiΪ�գ�������Ԫ�ز�����
            return Hi;
        else if(HT[Hi]==key)//����ԪHi��Ԫ�صĹؼ���Ϊkey
            return Hi;
        cnt++;
        Hi=(H0+i2)%m; //��������̽�ⷨ������һ����ϣ��ַHi
        if(Hi<0)
            Hi+=m;
        if(HT[Hi]==NULLKEY)//����ԪHiΪ�գ�������Ԫ�ز�����
            return Hi;
        else if(HT[Hi]==key)//����ԪHi��Ԫ�صĹؼ���Ϊkey
            return Hi;
    }
    return -1;
}

int SearchHash(int HT[],int key){
    //�ڹ�ϣ��HT�в��ҹؼ���Ϊkey��Ԫ�أ������ҳɹ������ع�ϣ��ĵ�Ԫ��ţ����򷵻�-1
    int H0=H(key); //���ݹ�ϣ����H��key�������ϣ��ַ
    int Hi,cnt=1;
    if(HT[H0]==NULLKEY)//����ԪH0Ϊ�գ�������Ԫ�ز�����
        return -1;
    else if(HT[H0]==key){//����ԪH0��Ԫ�صĹؼ���Ϊkey������ҳɹ�
            cout<<"���ҳɹ����Ƚϴ�����"<<cnt<<endl;
            return H0;
        }
        else{
            Hi=Linedetect(HT,H0,key,cnt);
            if(HT[Hi]==key){//����ԪHi��Ԫ�صĹؼ���Ϊkey������ҳɹ�
                cout<<"���ҳɹ����Ƚϴ�����"<<cnt<<endl;
                return Hi;
            }
            else
                return -1;	//����ԪHiΪ�գ�������Ԫ�ز�����
        }
}

bool InsertHash(int HT[],int key){
    int H0=H(key); //���ݹ�ϣ����H��key�������ϣ��ַ
    int Hi=-1,cnt=1;
    if(HT[H0]==NULLKEY){
        HC[H0]=1;//ͳ�ƱȽϴ���
        HT[H0]=key;	//����ԪH0Ϊ�գ�����
        return 1;
    }
    else{
        Hi=Linedetect(HT,H0,key,cnt);//����̽��
        //Hi=Seconddetect(HT,H0,key,cnt);//����̽��
        if((Hi!=-1)&&(HT[Hi]==NULLKEY)){
            HC[Hi]=cnt;
            HT[Hi]=key;//����ԪHiΪ�գ�����
            return 1;
        }
    }
    return 0;
}

void print(int HT[]){
    for(int i=0;i<m;i++)
        cout<<HT[i]<<"\t";
    cout<<endl;
}

int main(){
	int x;
	memset(HT,0,sizeof(HT));
	memset(HC,0,sizeof(HC));
	print(HT);
	cout<<"����12���ؼ��֣������ϣ���У�"<<endl;
	for(int i=0;i<12;i++){
		cin>>x;
		if(!InsertHash(HT,x)){
		    cout<<"������ϣ��ʧ�ܣ�"<<endl;
		    return 0;
		}
	}
	cout<<"�����ϣ��"<<endl;
	print(HT);
	print(HC);
	cout<<"����Ҫ���ҵĹؼ���"<<endl;
	cin>>x;
	int result=SearchHash(HT,x);
	if(result!=-1)
		cout<<"�ڵ�"<<result+1<<"λ���ҵ�"<<endl;
	else
		cout<<"δ�ҵ�"<<endl;
    return 0;
}
//�������ݣ�14 36 42 38 40 15 19 12 51 65 34 25
