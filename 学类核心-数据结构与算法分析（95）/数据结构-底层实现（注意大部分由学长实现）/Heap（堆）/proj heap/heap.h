//�ѵĳ����� 
template <typename E> class heap {
private:
  void operator =(const heap&) {}     
  heap(const heap&) {}        
  virtual void siftdown(int pos) = 0;
public:
  	heap() {}                       
	virtual ~heap() {}   
	//���Ѳ���           
  	virtual void buildHeap() = 0;   
	//����в���һ��Ԫ��        
  	virtual void insert(const E& it) = 0;
  	//ɾ�����ֵ 
 	virtual E removefirst() = 0;
	//ɾ��ָ��λ�õ�Ԫ��	
	virtual E remove(int pos) = 0;

};
