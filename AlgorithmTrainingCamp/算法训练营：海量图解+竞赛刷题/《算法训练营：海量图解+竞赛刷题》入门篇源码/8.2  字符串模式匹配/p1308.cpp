#include<iostream>
#include<cstring>
using namespace std;
int len1,len2;//�����ַ������� 

void tolower(char *a){//ȫ����дתСд
    for(int i=0;a[i];i++)
		if(a[i]>='A'&&a[i]<='Z')
			a[i]+=32;
}

int BF(char *w,char *s,int pos){//ģʽƥ��BF�㷨 
    int i=pos;
    int j=0;//�±��0��ʼ 
    while(j<len1&&i<len2){
        if(s[i]==w[j]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>=len1)//ƥ��ɹ� 
        return i-len1;
    return -1;
}

int main(){
    char word[16],sentence[1000010];
	cin.getline(word+1,16);//����ʱ��0��Ԫ�ճ������洢 
    cin.getline(sentence+1,1000005);
	word[0]=' ';//��β���ո� 
	len1=strlen(word);
    word[len1++]=' ';
    word[len1]='\0';
    sentence[0]=' ';//��β���ո�
    len2=strlen(sentence);
	sentence[len2++]=' '; 
	sentence[len2]='\0';
	tolower(word);
	tolower(sentence);
    int posfirst=BF(word,sentence,0);//��¼�����״γ��ֵ�λ��
	if(posfirst==-1){
        cout<<-1;
        return 0;
    }
    int cnt=1;//���ߵ���˵�������ѳ���һ����
    int t=posfirst+len1-1;
    while(t<len2){
        t=BF(word,sentence,t);
        if(t==-1)
            break;
        cnt++;
        t=t+len1-1;
    }
    cout<<cnt<<" "<<posfirst;
    return 0;
}
