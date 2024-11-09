template <typename E> 
class Heapnode{
public:
	bool isLeaf(int pos,int n) const 
    { 
		return (pos >= n/2) && (pos < n); 
	}
  	int leftchild(int pos) const
    { 
		return 2*pos + 1; 
	}    // Return leftchild position ���������±� 
  	int rightchild(int pos) const
    { 
		return 2*pos + 2; 
	}    // Return rightchild position �����Һ����±� 
  	int parent(int pos) const  // Return parent position ���ظ�����±� 
    { 
		return (pos-1)/2; 
	}	
} 
