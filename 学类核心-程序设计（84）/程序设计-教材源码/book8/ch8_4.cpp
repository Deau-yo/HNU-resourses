//---------------------
//    ch8_4.cpp
//---------------------
#include<iostream>
using namespace std;
//---------------------
int main(){
  int iArray[10];
  int sum=0;
  int* iPtr=&iArray[0];        //��������iArray��ָ���ʼ��

  for(int i=0; i<10; i++)  //�����鸳ֵ
    iArray[i]=i;
  for(int idx=0; idx<10; idx++){  //�ۼ�����Ԫ��
    sum+= iPtr[idx];
    iPtr++;
  }
  cout<<"sum is "<<sum<<endl;
}//--------------------
