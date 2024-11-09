//book.h�ļ��ж����˳��õ�swap��Assert���� 
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using namespace std;
const int defaultSize = 10; 

//��valΪ0�����Դ���������ַ���s���쳣��ֹ���� 
void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}
// Swap two elements in a generic array ��������������Ԫ�� 
template<typename E>
inline void swap(E A[], int i, int j) {
  E temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}



