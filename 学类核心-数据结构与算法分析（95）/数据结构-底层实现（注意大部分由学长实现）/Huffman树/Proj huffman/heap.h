// Heap class ���� 
template <typename E, typename Comp> class heap {
private:
  	E* Heap;          // Pointer to the heap array ������ָ�� 
  	int maxsize;     	// Maximum size of the heap ������� 
  	int n;            // Number of elements now in the heap Ԫ�ص�ǰλ�� 

  	// Helper function to put element in its correct place �������� 
  	void siftdown(int pos) {
    	while (!isLeaf(pos)) { 	//Stop if pos is a leaf ��Ҷ�ڵ��ֹͣ���� 
	      int j = leftchild(pos);  
		  int rc = rightchild(pos);
	      if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
	        j = rc;            	// Set j to greater child's value ��j��ֵΪ�ϴ��ӽڵ��ֵ 
	      if (Comp::prior(Heap[pos], Heap[j])) return; 
	      swap(Heap, pos, j);
	      pos = j;             	// Move down ���� 
    }
  }

public:
  	heap(E* h, int num, int max)     // Constructor���캯�� 
    { Heap = h;  n = num;  maxsize = max;  buildHeap(); }
  	int size() const       			// Return current heap size ���ص�ǰ�Ѵ�С 
    { return n; }
  	bool isLeaf(int pos) const 	
    { return (pos >= n/2) && (pos < n); }
  	int leftchild(int pos) const
    { return 2*pos + 1; }    	// Return leftchild position ��������λ�� 
  	int rightchild(int pos) const
    { return 2*pos + 2; }    	// Return rightchild position �����Һ���λ�� 
  	int parent(int pos) const  	// Return parent position ���ظ����λ�� 
    { return (pos-1)/2; }
  	void buildHeap()           	// Heapify contents of Heap ���� 
    { for (int i=n/2-1; i>=0; i--) siftdown(i); }

  	// Insert "it" into the heap ��it����� 
  	void insert(const E& it) {
    Assert(n < maxsize, "Heap is full");
    int curr = n++;
    Heap[curr] = it;       		// Start at end of heap �Ȳ���ĩβ 
    // Now sift up until curr's parent > curr ����ֱ����ǰ�ڵ㸸�����ڵ�ǰ�ڵ� 
    while ((curr!=0) &&
           (Comp::prior(Heap[curr], Heap[parent(curr)]))) {
      swap(Heap, curr, parent(curr));
      curr = parent(curr);
    }
  }
  	// Remove first value ɾ�����ֵ 
  	E removefirst() {
    Assert (n > 0, "Heap is empty");
    swap(Heap, 0, --n);       // Swap first with last value ��������ڵ������һ���ڵ㽻�� 
    if (n != 0) siftdown(0);  // Siftdown new root val �������ڵ� 
    return Heap[n];           // Return deleted value ����ɾ���ڵ� 
  }

  // Remove and return element at specified position ɾ������λ�ýڵ� 
  	E remove(int pos) {
    Assert((pos >= 0) && (pos < n), "Bad position");
    if (pos == (n-1)) n--; // Last element, no work to do ���һ���ڵ��򲻴��� 
    else
    {
      swap(Heap, pos, --n);         
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
