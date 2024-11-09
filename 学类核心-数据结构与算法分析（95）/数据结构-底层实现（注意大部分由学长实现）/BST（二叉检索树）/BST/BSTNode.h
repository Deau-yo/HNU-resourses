#include <iostream>
typedef int E;
class BSTNode{
private:
	E data;//�������ڵ�洢��ֵ   
	BSTNode* lc;
	BSTNode* rc;//���Һ���ָ��  
public:
	BSTNode()//��ʼ���ڵ� 
	{ 
		lc=rc=NULL;
	}  
	BSTNode(E e,BSTNode* l=NULL,BSTNode* r=NULL)//����һ���ǿսڵ� 
	{
		data=e;lc=l;rc=r;	
	}
	E getData(){ return data;}
	BSTNode* left(){ return lc; }
	BSTNode* right(){ return rc; }
	void setLeft(BSTNode* b){lc=b;}
	void setRight(BSTNode* b){rc=b;}
	void setElement(const E& e) { data=e; }
};
