#include "list.h"
#include "alist.h"
#include<iomanip>
#include<iostream>

using namespace std;
void print(AList<int>& A,int n);

// Main routine for array-based list driver class
int main(){
	int n;
	AList<int> L1(100);
  	cout<<"**************************"<<endl; 
  	cout<<"*˳����и�������������ʾ*"<<endl;// Declare some sample lists
	cout<<"**************************"<<endl<<endl;
  	cout<<"��˳������������Ԫ��12��15��9��48��55"<<endl;
  	//����˳����е�append���� 
  	L1.append(12);
  	L1.append(15);
  	L1.append(9);
  	L1.append(48);
  	L1.append(55);
  	cout<<"���Ԫ�غ�˳���������Ϊ��"<<endl; 
  	n=L1.length();//��ȡ˳����� 
  	print(L1,n);
  	cout<<"��ǰ˳�����Ϊ:"<<endl<<L1.length()<<endl<<endl; 
  	
  	cout<<"�鿴��ǰcurr��ֵΪ��"<<endl;
  	cout<<L1.currPos()<<endl<<endl;
  	
  	cout<<"�������Ա���դ��curr��λ��Ϊ2"<<endl;
	L1.moveToPos(2);
	cout<<"���ڵ�ǰλ��curr����Ԫ��4"<<endl;
	//����˳����еĲ������ 
	L1.insert(4);
	cout<<"����Ԫ�غ�˳���������Ϊ��"<<endl;
	n=L1.length();//��ȡ˳�����  
	print(L1,n);
	
  	cout<<"�������Ա���դ��curr��λ��Ϊ4"<<endl;
  	L1.moveToPos(4);
  	cout<<"��ɾ����ǰλ��curr����Ԫ��" <<endl;
  	//����˳����ɾ������ 
  	L1.remove(); 
  	cout<<"ɾ��Ԫ�غ�˳����е�����Ϊ��"<<endl;
  	n=L1.length();//��ȡ˳�����
	print(L1,n);
}
/***********************
*function of print
*��ӡ˳�����Ԫ��
************************/ 
void print(AList<int>& A,int n){
	//cout<<"��ǰ˳�����Ԫ��Ϊ��"<<endl;
	int i;
	for(i=0;i<n;i++){
		A.moveToPos(i);
		//����getValue�����õ���ǰԪ�� 
		cout<<A.getValue()<<" ";
	}
	cout<<endl<<endl; 
}

