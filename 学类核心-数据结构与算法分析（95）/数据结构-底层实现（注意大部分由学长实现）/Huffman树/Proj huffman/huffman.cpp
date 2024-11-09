#include <cstring>
#include "book.h"
#include "heap.h"
#include "codetable.h"
#include "huffnode.h"
#include "hufftree.h"

//���Ժ������� 
void do_commands(HuffTree<char>* theTree,CodeTable<char>* theTable, FILE *fp); 
int read_freqs(CodeTable<char>* ct, FILE* fp);
void buildcode(HuffNode<char>* root, CodeTable<char>* ct,char* prefix, int level, double& total);
void decode(HuffTree<char>* theTree, char* code, char& msg, int& cnt);

//"<<"���������
template <typename E>
ostream& operator << (ostream& s, HuffNode<E>* z)
{
  	if (z->isLeaf())
    	return s << ((LeafNode<E>*)z)->val();
  	else
    	return s << z->weight();
}

// Comparator for the heap �Ƚ������Ѵ�С���ز���ֵ 
class minTreeComp {
public:
  	static bool prior(HuffTree<char>* x, HuffTree<char>* y)
	{ return x->weight() < y->weight(); }
};

// Space for the heap's array �����洢�ѵ����� 
HuffTree<char>** TreeArray = NULL;

// Build a Huffman tree from a collection of frequencies
//�����ռ���Ƶ�������������� 
template <typename E> HuffTree<E>* buildHuff(HuffTree<E>** TreeArray, int count) {
  	heap<HuffTree<E>*,minTreeComp>* forest =
    	new heap<HuffTree<E>*, minTreeComp>(TreeArray,count, count); 
  	HuffTree<char> *temp1, *temp2, *temp3 = NULL;
  	while (forest->size() > 1) {
	    temp1 = forest->removefirst(); 	//Pull first two trees off the list  
	    temp2 = forest->removefirst();	//ȡ����ǰ��������� 
	    temp3 = new HuffTree<E>(temp1, temp2);//�ϲ������� 
	    forest->insert(temp3);  // Put the new tree back on list �����������б�
	    delete temp1;        // Must delete the remnants of the trees we created
	    delete temp2;        // ɾ��ԭ����������  
  	}
  	return temp3;
}

//���������Բ��� 
int main() {
  // This will be the eventual Huffman tree 
  //�洢���ս��ɵĹ������� 
  HuffTree<char>* theTree;
  CodeTable<char>* theTable = new CodeTable<char>(CODETABLELEN);
  // Working storage for the tree traversal that builds the code table 
  //�洢��������ֵ����������� 
  char prefix[MAXCODELEN+1];//prefix ǰ׺ 
  // total is used to calculate the average code length
  double total = 0;
  FILE *fp;  // The file pointer�ļ�ָ�� 

  Assert((fp = fopen("huffbook.huff", "rt")) != NULL, "No such file");

  // Now, read in the list of frequencies, and initialize the forest of Huffman trees.
  //��ȡƵ���ļ��б���ʼ����������ɭ��(���������㣩 
  cout << "��ȡ�ļ���ÿ��Ԫ�ؼ����Ӧ��Ƶ��\n";
  int count = read_freqs(theTable, fp);

  // Now, build the tree.������������ 
  theTree = buildHuff<char>(TreeArray, count);
  cout << "�ѹ�����������\n";
  
  // Now, output the tree, which also creates the code table.
  //����ѹ����ñ����Ĺ������� 
  cout << "����������������\n";
  buildcode(theTree->root(), theTable, prefix, 0, total);
  cout << "ƽ�����볤��Ϊ��"
       << total/(double)theTree->weight() << "\n";

  // Finally, do the encode/decode commands to test the system.
  //��󣬲��Ա���ͽ������� 
  do_commands(theTree, theTable, fp);
  return 0;
}

//do_commands�����ִ��decode(���룩��encode(����)���й��ܲ��� 
void do_commands(HuffTree<char>* theTree,CodeTable<char>* theTable, FILE *fp)
{
  	int currchar;
  	char buff[80];

  	while(fgets(buff, 99, fp)) {
    if(strncmp(buff, "decode", 6) == 0) {
      	for (currchar=0; buff[currchar] != '"'; currchar++);
      	cout << "���룺" << &buff[currchar++];
      	while (buff[currchar] != '"') {
        	int cnt = 0;
        	char msg;
        	decode(theTree, &buff[currchar], msg, cnt);
        	cout << msg << endl;
			currchar += cnt;
      	}
    }
    else if(strncmp(buff, "encode", 6) == 0) {
      	for (currchar=0; buff[currchar] != '"'; currchar++);
      	cout << "���룺" << &buff[currchar++];
      	for(; buff[currchar] != '"' ; currchar++) 
        	if (buff[currchar] == ' ') cout << ' ';
        	else cout << theTable->getcode(buff[currchar]);
    }
  }
}
void decode(HuffTree<char>* theTree, char* code, char& msg, int& cnt) 
{
  	HuffNode<char>* currnode = theTree->root();
  	while (!currnode->isLeaf()) {
    	cnt++;
    	if (code[cnt-1] == '0') currnode = ((IntlNode<char>*)currnode)->left();
    	else if (code[cnt-1] == '1') currnode = ((IntlNode<char>*)currnode)->right();
    	else Assert(false, "Bad code character");
  	}
  	msg = ((LeafNode<char>*)currnode)->val();
}

// Read the list of frequencies, make the forest, and set the list of 
//entries into the code table. ��ȡƵ���ļ����ݣ���ʼ���������ݽڵ� 
int read_freqs(CodeTable<char>* ct, FILE* fp)
{ 	
	// Read a list of strings and frequencies from standard input,
  	// building a list of Huffman coding tree nodes
  	//�ӱ�׼�����ȡһ���ַ���Ƶ��������������������ڵ��б� 
	char buff[100];
	char buff2[100];
	char *ptr;
	char *ptr2;
	int freq;

  	Assert(fgets(buff, 99, fp) != NULL, "Couldn't read character count");//��ȡԪ���ܸ��� 
  	ptr = buff;
	Assert(isdigit(*ptr) != 0, "Must be a digit here.");
	int count = atoi(ptr);
	TreeArray = new HuffTree<char>*[count];
	for (int i=0; i<count; i++) { 
	  	//�ļ���Ԫ�ظ��������������ֹ 
	    Assert(fgets(buff, 99, fp) != NULL, "Ran out of codes too early");  
	    // process the entry, creating a new HuffTree
	    //����ÿ����ڣ��Զ�ȡ�����ַ�����һ�ù������� 
	    for(ptr=buff; *ptr==' '; ptr++);  
	    Assert(*ptr == '"', "First char was not a quote mark.");
	    for (ptr2=buff2,ptr++; *ptr!='"'; ptr++)
	      	*ptr2++ = *ptr;
	    *ptr2 = '\0'; // End of string �ַ���������־ 
	    for (ptr++; *ptr==' '; ptr++);
	    Assert(isdigit(*ptr) != 0, "Must be a digit here.");
	    freq = atoi(ptr);
	    ct->addobject(buff2[0]);
	    TreeArray[i] = new HuffTree<char>(buff2[0], freq);
  	}
  	return count;
}
//�������������� 
void buildcode(HuffNode<char>* root, CodeTable<char>* ct,char* prefix, int level, double& total)
{
  	if (root->isLeaf()) {
    	cout << ((LeafNode<char>*)root)->val() << "\t" << prefix << "\n";
    	strcpy(ct->getcode(((LeafNode<char>*)root)->val()), prefix);
    	total += level * root->weight();
  	}
  	else{
    prefix[level] = '0';
    prefix[level+1] = '\0';
    buildcode(((IntlNode<char>*)root)->left(), ct, prefix, level+1, total);
    prefix[level] = '1';
    prefix[level+1] = '\0';
    buildcode(((IntlNode<char>*)root)->right(), ct, prefix, level+1, total);
    prefix[level] = '\0';
  	}
}

