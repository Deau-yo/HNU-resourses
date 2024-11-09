template <typename E>
class HuffTree {
private:
  HuffNode<E>* Root; // Tree root �����ڵ� 
public:
  	HuffTree(E& val, int freq) // Leaf constructorҶ�ڵ㹹�캯�� 
    { Root = new LeafNode<E>(val, freq); }
  	// Internal node constructor�ڲ��ڵ㹹�캯�� 
  	HuffTree(HuffTree<E>* l, HuffTree<E>* r)
    { Root = new IntlNode<E>(l->root(), r->root()); }
  	~HuffTree() {}                          // Destructor�������� 
  	HuffNode<E>* root() { return Root; }    // Get root ��ø��ڵ� 
  	int weight() { return Root->weight(); } // Root weight ��ø�Ȩֵ 
};
