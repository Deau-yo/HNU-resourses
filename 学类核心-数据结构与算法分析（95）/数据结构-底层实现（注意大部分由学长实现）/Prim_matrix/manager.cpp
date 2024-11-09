#include<iostream>
#include<cstring>
#include "book.h"
#include "graphm.h"
#include "graph.h"
#include "create.h" 
#define INFINITY 9999

using namespace std;

void AddEdgetoMST(Graph<string>* G,int v1, int v2) {
  cout << "���ӱ� " << G->getVex(v1) << " <--> " << G->getVex(v2) << ":"<<G->weight(v1,v2)<<endl;
}

int minVertex(Graph<string>* G, int* D) { // Find min cost vertex
  int i, v = -1;
  for (i=0; i<G->n(); i++) // Initialize v to some unvisited vertex;
    if (G->getMark(i) == UNVISITED) { v = i; break; }
  for (i=0; i<G->n(); i++)  // Now find smallest value
    if ((G->getMark(i) == UNVISITED) && (D[i] < D[v])) v = i;
  return v;
}

void Prim(Graph<string>* G, int* D, int s) { // Prim's MST algorithm
  int V[G->n()];                     // Store closest vertex
  int i, w;
  for (i=0; i<G->n(); i++) {         // Process the vertices
    int v = minVertex(G, D);
    G->setMark(v, VISITED);
    if (v != s)
      AddEdgetoMST(G,V[v], v);         // Add edge to MST
    if (D[v] == INFINITY) return;    // Unreachable vertices
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > G->weight(v,w)) {
        D[w] = G->weight(v,w);       // Update distance
        V[w] = v;                    // Where it came from
      }
  }
}
int main(){
	
	FILE *fid;
	fid = fopen("test.gph", "rt");
	
	Graph<string>* G;

	//����ͼ��create.h) 
	G = createGraph(fid);
	//��ӡͼ��create.h) 
	Gprint(G);
	
	int D[G->n()];
  for (int i=0; i<G->n(); i++)     // Initialize
    D[i] = INFINITY;
  
	//��λ��Ϊ0�Ķ���A��Ϊ��� 
	D[0] = 0;
	cout<<"--------------------------------\n"
			<<"�Զ���AΪ��ʼ������Prim�����С��������\n";
	Prim(G, D, 0);
	cout<<"MST������ɣ�\n";
	cout<<"--------------------------------\n"
			<<"���յõ���D[i]����(�Զ���ViΪһ�˵���̱ߵ�Ȩֵ)Ϊ��\n"; 
  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;
	
	return 0;
}
