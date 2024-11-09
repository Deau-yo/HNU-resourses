// General tree representation for UNION/FIND
//һ������ʾ���鼯 

class ParPtrTree {
private:
  int* array;                    // Node array �������� 
  int size;                      // Size of node array
  int FIND(int) const;           // Find root���Ҹö���ĸ� 
public:
  ParPtrTree(int);                   // Constructor���캯�� 
  ~ParPtrTree() { delete [] array; } // Destructor�������� 
  void UNION(int, int); 	// Merge equivalences�ϲ� 
  bool differ(int, int);    // True if not in same tree�ж��Ƿ�������ͬһ���� 
};
ParPtrTree::ParPtrTree(int sz) { // Constructor���캯�� 
  size = sz;
  array = new int[sz];           // Create node array������������ 
  for(int i=0; i<sz; i++) array[i] = ROOT;
}

// Return True if nodes are in different trees
//������ͬһ��������true 
bool ParPtrTree::differ(int a, int b) {
  int root1 = FIND(a);           // Find root of node a.��a�ĸ� 
  int root2 = FIND(b);           // Find root of node b.��b�ĸ� 
  return root1 != root2;         // Compare roots.�Ƚ����� 
}

void ParPtrTree::UNION(int a, int b) { // Merge subtrees.�ϲ��� 
  int root1 = FIND(a);           // Find root of node a
  int root2 = FIND(b);           // Find root of node b
  if (root1 != root2) array[root2] = root1; // Merge
}
// FIND with path compression ���ظ���ֵ 
int ParPtrTree::FIND(int curr) const {
  if (array[curr] == ROOT) return curr; // At root�Ѿ��Ǹ��򷵻� 
  array[curr] = FIND(array[curr]);
  return array[curr];
}

