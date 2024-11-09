#define MAXCODELEN 20       // Max length of a huffman code ������������󳤶� 
#define CODETABLELEN 100    // Maximum number of codes storable �������󳤶� 
// CodeTable maps objects to their associated codes.�������Ԫ�غͱ���һһ��Ӧ 
template <typename E>
class CodeTable {
private:
  	E* obs;     
  	char** codes;  // Associated code values ��Ӧ����ֵ 
  	int currsize;  // Current number of objects in table �����ǰԪ�ظ��� 
  	int maxsize;   // Max objects permitted in table ����������� 
public:
  	CodeTable(int size) {
    obs = new E[size];
    codes = new char*[size];
    for (int i = 0; i<size; i++) {
      	codes[i] = new char[MAXCODELEN+1];
      	for(int j=0; j<=MAXCODELEN; j++)
        	codes[i][j] = '-';
		codes[i][MAXCODELEN] = '\0';
    }
    maxsize = size;  currsize = 0;
  }

  void addobject(E& obj) {
    Assert(currsize < maxsize, "CodeTable is full!");
    obs[currsize++] = obj;
  }

  char* getcode(E obj) {
    for (int i=0; i<currsize; i++)
      if(obj == obs[i]) return codes[i];
    return NULL;
  }
};  
