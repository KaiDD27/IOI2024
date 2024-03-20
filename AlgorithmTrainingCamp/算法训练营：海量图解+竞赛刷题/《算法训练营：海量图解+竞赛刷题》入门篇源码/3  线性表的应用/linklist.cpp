#include<iostream>
using namespace std;

typedef struct Lnode{
	int data; //����������
	struct Lnode *next; //����ָ����
}Lnode,*LinkList; //LinkListΪָ��ṹ��LNode��ָ������

bool InitList_L(LinkList &L){//����һ���յĵ�����L
    L=new Lnode;     //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	if(!L)
		return false;  //���ɽ��ʧ��
	L->next=NULL;   //ͷ����ָ�����ÿ�
	return true;
}

void CreateList_H(LinkList &L){//ǰ�巨����������
	//����n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
	int n;
	LinkList s; //����һ��ָ�����
	L=new Lnode;
	L->next=NULL; //�Ƚ���һ����ͷ���Ŀ�����
	cout<<"������Ԫ�ظ���n��"<<endl;
	cin>>n;
	cout<<"����������n��Ԫ�أ�"<<endl;
	cout<<"ǰ�巨����������..."<<endl;
	while(n--){
		s=new Lnode; //�����½��s
		cin>>s->data; //����Ԫ��ֵ�����½���������
		s->next=L->next;
		L->next=s; //���½��s���뵽ͷ���֮��
	}
}

void CreateList_R(LinkList &L){//β�巨����������
	//����n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	int n;
	LinkList s, r;
	L=new Lnode;
	L->next=NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r=L; //βָ��rָ��ͷ���
	cout<<"������Ԫ�ظ���n��"<<endl;
	cin>>n;
	cout<<"����������n��Ԫ�أ�"<<endl;
	cout<<"β�巨����������..."<<endl;
	while(n--){
		s=new Lnode;//�����½��
		cin>>s->data; //����Ԫ��ֵ�����½���������
		s->next=NULL;
		r->next=s;//���½��s����β���*r֮��
		r=s;//rָ���µ�β���s
	}
}

bool GetElem_L(LinkList L, int i, int &e){//�������ȡֵ
	//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ��
	//��e��¼L�е�i������Ԫ�ص�ֵ
	int j;
	LinkList p;
	p=L->next;//pָ���һ����㣬
	j=1; //jΪ������
	while(j<i&&p){ //˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p=p->next; //pָ����һ�����
		j++; //������j��Ӧ��1
	}
	if(!p||j>i)
		return false; //iֵ���Ϸ�i��n��i<=0
	e=p->data; //ȡ��i������������
	return true;
}

bool LocateElem_L(LinkList L,int e){ //��ֵ����
	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LinkList p;
	p=L->next;
	while(p&&p->data!=e)//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
		p=p->next; //pָ����һ�����
	if(!p)
        return false; //����ʧ��pΪNULL
    return true;
}

bool ListInsert_L(LinkList &L,int i,int e){//������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
	int j;
	LinkList p,s;
	p=L;
	j=0;
	while(p&&j<i-1){ //���ҵ�i-1����㣬pָ��ý��
		p=p->next;
		j++;
	}
	if(!p||j>i-1)//i��n+1����i��1
		return false;
	s=new Lnode;     //�����½��
	s->data=e;       //���½�����������Ϊe
	s->next=p->next; //���½���ָ����ָ����ai
	p->next=s;       //�����p��ָ����ָ����s
	return true;
}

bool ListDelete_L(LinkList &L, int i){ //�������ɾ��
	//�ڴ�ͷ���ĵ�����L�У�ɾ����i��λ��
	LinkList p, q;
	int j;
	p=L;
	j=0;
	while((p->next)&&(j<i-1)){ //���ҵ�i-1����㣬pָ��ý��
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1))//��i>n��i<1ʱ��ɾ��λ�ò�����
		return false;
	q=p->next;        //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷſռ�
	p->next=q->next; //�ı�ɾ�����ǰ������ָ����
	delete q;        //�ͷű�ɾ�����Ŀռ�
	return true;
}

void Listprint_L(LinkList L){ //����������
    LinkList p;
    p=L->next;
    while(p){
        cout<<p->data<<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main(){
	int i,x,e,choose;
	LinkList L;
	cout<<"1. ��ʼ��\n";
	cout<<"2. ����������ǰ�巨��\n";
	cout<<"3. ����������β�巨��\n";
	cout<<"4. ȡֵ\n";
	cout<<"5. ����\n";
	cout<<"6. ����\n";
	cout<<"7. ɾ��\n";
	cout<<"8. ���\n";
	cout<<"0. �˳�\n";
	choose=-1;
	while(choose!=0){
		cout<<"����������ѡ��:";
		cin>>choose;
		switch(choose){
		case 1: //��ʼ��һ���յĵ�����
			if(InitList_L(L))
				cout<<"��ʼ��һ���յĵ�����!\n";
			break;
		case 2: //����������ǰ�巨��
			CreateList_H(L);
            cout<<"ǰ�巨����������������:\n";
            Listprint_L(L);
			break;
        case 3: //����������β�巨��
			CreateList_R(L);
            cout<<"β�巨����������������:\n";
            Listprint_L(L);
			break;
		case 4: //������İ����ȡֵ
			cout<<"������һ��λ��i����ȡֵ:";
			cin>>i;
			if (GetElem_L(L,i,e)){
				cout<<"���ҳɹ�\n";
				cout<<"��"<<i<<"��Ԫ���ǣ�"<<e<<endl;
			}
			else
				cout<<"����ʧ��\n\n";
			break;
		case 5: //������İ�ֵ����
			cout<<"��������Ҫ����Ԫ��x:";
			cin>>x;
			if(LocateElem_L(L,x))
				cout<<"���ҳɹ�\n";
			else
				cout<<"����ʧ��! "<<endl;
			break;
		case 6: //������Ĳ���
			cout<<"����������λ�ú�Ԫ�أ��ÿո������:";
			cin>>i;
			cin>>x;
			if(ListInsert_L(L,i,x))
				cout<<"����ɹ�.\n\n";
			else
				cout<<"����ʧ��!\n\n";
			break;
		case 7: //�������ɾ��
			cout<<"��������Ҫɾ����Ԫ��λ��i:";
			cin>>i;
			if(ListDelete_L(L,i))
				cout<<"ɾ���ɹ�!\n";
			else
				cout<<"ɾ��ʧ��!\n";
			break;
		case 8: //����������
			cout<<"��ǰ�����������Ԫ�طֱ�Ϊ:\n";
			Listprint_L(L);
			cout<<endl;
			break;
		}
	}
	return 0;
}

