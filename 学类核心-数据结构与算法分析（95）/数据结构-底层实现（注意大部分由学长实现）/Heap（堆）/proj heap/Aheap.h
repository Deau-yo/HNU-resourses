#include "heap.h"
//��������ʵ�ֵĶ� 
template <typename E, typename Comp> class Aheap:public {
private:
  E* Heap;     //Pointer to the heap array ָ������� 
  int maxsize; // Maximum size of the heap ��������� 
  int n;       // Number of elements now in the heap ���е�ǰԪ�ظ��� 

  // Helper function to put element in its correct place 
  //����Ԫ�ص���ȷλ�� 
  void siftdown(int pos) {
    while (!isLeaf(pos,n)) { // Stop if pos is a leaf ��Ҷ�ӽڵ��ֹͣ 
      int j = leftchild(pos);  int rc = rightchild(pos);
      if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
        j = rc;          
      if (Comp::prior(Heap[pos], Heap[j])) return; 
      swap(Heap, pos, j);
      pos = j;            
    }
  }

public:
  	Aheap(E* h, int num, int max)     
    { Heap = h;  n = num;  maxsize = max;  buildHeap(); }
  	int size() const       
    { return n; }
  	void buildHeap() // Heapify contents of Heap ���� 
    { for (int i=n/2-1; i>=0; i--) siftdown(i); }

  // Insert "it" into the heap ����Ԫ�ص����� 
  void insert(const E& it) {
    Assert(n < maxsize, "Heap is full");
    int curr = n++;
    Heap[curr] = it;           
    // Now sift up until curr's parent > curr
    //����ֱ��λ����ȷ 
    while ((curr!=0) &&(Comp::prior(Heap[curr], Heap[parent(curr)]))) {
      swap(Heap, curr, parent(curr));
      curr = parent(curr);
    }
  }
  // Remove first value ɾ�����Ԫ�� 
  E removefirst() {
    Assert (n > 0, "Heap is empty");
    swap(Heap, 0, --n);       // Swap first with last value �����ֵ�����һ��Ԫ�ؽ��� 
    if (n != 0) siftdown(0);  // Siftdown new root val ����Ԫ�� 
    return Heap[n];           // Return deleted value ����ɾ����Ԫ�� 
  }

  // Remove and return element at specified position
  //ɾ��ָ��λ�õ�Ԫ�� 
  E remove(int pos) {
    Assert((pos >= 0) && (pos < n), "Bad position");
    if (pos == (n-1)) n--; // Last element, no work to do�������һ����ֱ��ɾ�� 
    else
    {
      swap(Heap, pos, --n);          // Swap with last value �����һ������ 
      while ((pos != 0) &&
             (Comp::prior(Heap[pos], Heap[parent(pos)]))) {
        swap(Heap, pos, parent(pos)); 
        pos = parent(pos);
      }
      if (n != 0) siftdown(pos);     
    }
    return Heap[n];
  }
};
