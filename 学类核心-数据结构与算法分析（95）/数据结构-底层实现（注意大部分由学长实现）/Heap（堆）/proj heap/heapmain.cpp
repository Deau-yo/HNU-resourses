#include "book.h"
#include "compare.h"
#include "Aheap.h"
using namespace std; 
int main() {
	int i, j;
	int n=10,count=0;
	Int A[10] = {9,3,0,2,4,7,5,6,8,1};
	Int C[10] = {73, 6, 57, 88, 60, 34, 83, 72, 48, 85};
	cout<<"��ʼ���ݣ�"<<endl;
	for (i=0; i<10; i++)
		cout << C[i] << "  ";
	cout<<endl<<"����ing..."<<endl;
  	Aheap<Int, maxIntCompare> BH(C, 0, 20);
  	cout<<"�������" <<endl<<endl;
	cout<<"���ղ�α�����˳�����������Ԫ�أ�"<<endl;
  	for (i=0; i<10; i++)
    	cout << C[i] << "  ";
  	cout << endl;
  	
 	cout<<endl<<"-------��ʾ���β������ݽ��ѹ���-------"<<endl; 
  	cout<<"��ʼ��Ϊ��"<<endl;
  	Aheap<Int, maxIntCompare> H(A, 0, 10);
  	for (i=0; i<n; i++){
		cout<<"����Ԫ��"<<A[i];
		H.insert(A[i]);
		count++;
		cout<<",���Ŀǰ�ѽ��õĶ�Ԫ�أ�"<<endl;
		for(j=0;j<count;j++){
			cout << A[j] << "  ";
		}
		cout<<endl;		 
	}
	
	cout<<endl<<"ɾ���������±�Ϊ3��Ԫ��:"<<H.remove(3)<<endl;
	cout<<"���ɾ�������Ԫ�أ�"<<endl;
	for (i=0; i<9; i++)
		cout << A[i] << "  ";
	cout<<endl;
	
	cout<<endl<<"ɾ���������ֵ��"<<H.removefirst()<<endl;
	cout<<"���ɾ�������Ԫ�أ�"<<endl;
	for (i=0; i<8; i++)
		cout << A[i] << "  ";
	cout<<endl;
	
  	return 0;
}
