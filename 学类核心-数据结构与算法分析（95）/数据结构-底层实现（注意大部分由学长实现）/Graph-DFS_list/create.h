#include<iostream>
#define LINELEN 80
using namespace std;

char* getl(char* buffer, int n, FILE* fid) {
  char* ptr;
  ptr = fgets(buffer, n, fid);
  while ((ptr != NULL) && (buffer[0] == '#'))
    ptr = fgets(buffer, n, fid);
  return ptr;
}
/*
����ͼ
*/ 
//template <typename GType>
Graph<string>* createGraph(	FILE* fid) {
  char buffer[LINELEN+1]; // Line buffer for reading
  int i, v1, v2, dist;

	/*����ȡ��������� */
  if (getl(buffer, LINELEN, fid) == NULL) // Unable to get number of vertices
	{ cout << "Unable to read number of vertices\n";
    return NULL;
	}
	int num=atoi(buffer);
	/*����ͼ��ʼ���� */
  Graph<string>* G = new Graphl<string>(num);

	
	/*����ȡͼ�Ķ�����Ϣ���洢�� */
  if (getl(buffer, LINELEN, fid) == NULL) // Unable to get graph type
	{ cout << "Unable to read info of vertices\n";
    return NULL ;
	}
	char* cbuff=buffer;

	string ver=strtok(cbuff," ");//�ո�ָ��������Ϣ 
	//�洢ǰn-1�� 
	for(i=0;i<num-1;i++){
		G->putVex(i,ver);//�洢������Ϣ 
		ver=strtok(NULL," ");
	} 
	//���һ��������Ϣ֮����ַ�������\t֮����ַ��ʲ��ܺ�����һ��
	//ֱ���ÿո�ָ� 
	int k=0;
	while(ver[k]>=33&&ver[k]<=126){
		k++;
	}
	ver=ver.substr(0,k);//��ȡ���һ��������Ϣ 
	G->putVex(i,ver);//�洢������Ϣ 
	
	/*����ȡͼ�����͡� */
  if (getl(buffer, LINELEN, fid) == NULL) // Unable to get graph type
	{ cout << "Unable to read graph type\n";
    return NULL ;
	}
  if (buffer[0] == 'U')//����ͼ 
    G->setType(true);//undirected = true;
  else if (buffer[0] == 'D')//����ͼ 
    G->setType(false);//undirected = false;
  else {
    cout << "Bad graph type: |" << buffer << "|\n";
    return NULL;
  }

  /*����ȡ�����ͱߡ� */
  if (getl(buffer, LINELEN, fid) == NULL) // Unable to get graph type
	{ cout << "Unable to read num of edges\n";
    return NULL ;
	}
	int num_edge=atoi(buffer);
  for(int m=0;m<num_edge;m++){
  	getl(buffer, LINELEN, fid);
  	string sbuff=buffer;
  	string tvalue;
  	
  	int loc1=sbuff.find(' ');//�ҵ���һ���ָ�ո��λ�� 
  	tvalue=sbuff.substr(0,loc1);//��ȡ��һ��������Ϣ��tvalue 
  	//cout<<"��һ������" <<tvalue<<endl;////////////
  	//�ҵ���һ��������ͼ�е�λ��
  	v1 = G->locateVex(tvalue);
		int loc2=sbuff.find(' ',loc1+1);//�ҵڶ����ָ�ո��λ�� 

  	tvalue=sbuff.substr(loc1+1,loc2-loc1-1);//��ȡ�ڶ���������Ϣ��tvalue 
  	//cout<<"�ڶ�������" <<tvalue<<endl;////////////
		//�ҵ��ڶ���������ͼ�е�λ��
		v2 = G->locateVex(tvalue);
   	//��ȡdist��Ȩֵ 
   	i=loc2+1;
   	dist=atoi(&buffer[i]);
		//cout<<"dist="<<dist<<endl; 
		//�洢��
		G->setEdge(v1,v2,dist); 
  }
  return G;
}

/*��ӡͼ*/ 
void Gprint(Graph<string>* G) {
  int i, j;
  cout << "��������" << G->n() << "\n";
  cout << "��  ��: " << G->e() << "\n";
	cout << "ͼ����: "<<(G->getType()?"����ͼ":"����ͼ")<<endl; 
	cout << "������Ϣ��\n";
	for(i=0;i<G->n();i++){
		cout<<G->getVex(i)<<"  ";
	} 
	cout<<endl;
  cout<<"����Ϣ��\n";
  if(G->getType()){
  	for (i=0; i<G->n(); i++) {
	    for(j=i; j<G->n(); j++){
	    	if(G->weight(i, j)!=0){
	    		cout<<G->getVex(i)<<" <--> "<<G->getVex(j)<<":"<<G->weight(i, j)<<endl;
				}
			}
  	}
	} 
	else{
		for (i=0; i<G->n(); i++) {
	    for(j=0; j<G->n(); j++){
	    	if(G->weight(i, j)!=0){
	    		cout<<G->getVex(i)<<" --> "<<G->getVex(j)<<":"<<G->weight(i, j)<<endl;
				}
			}
  	}
	}
    cout << "�ڽӱ�Ϊ:\n";
    int v,w;
    for(v=0;v<G->n();v++){
      cout<<G->getVex(v);
      for(w=G->first(v);w<G->n();w = G->next(v,w)){
        cout<<" --> "<<G->getVex(w);
      }
    cout<<endl;
    } 
}
