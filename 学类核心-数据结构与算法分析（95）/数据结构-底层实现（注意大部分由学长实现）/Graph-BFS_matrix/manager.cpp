#include <iostream>
#include <cstring>
#include "graphm.h"
#include "graph.h"
#include "create.h"
#include "aqueue.h"

using namespace std;

Queue<int>* Q;
void PreVisit(Graph<string>* G, int v) {
  cout << "PreVisit vertex " << G->getVex(v) << "\n";
}

void PostVisit(Graph<string>* G, int v) {
  cout << "PostVisit vertex " << G->getVex(v) << "\n";
}

void BFS(Graph<string>* G, int start, Queue<int>* Q) {
  int v, w;
  Q->enqueue(start);         // Initialize Q
  G->setMark(start, VISITED);
  while (Q->length() != 0) { // Process all vertices on Q
    v = Q->dequeue();
    PreVisit(G, v);          // Take appropriate action
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (G->getMark(w) == UNVISITED) {
        G->setMark(w, VISITED);
        Q->enqueue(w);
      }
    //PostVisit(G,v);
  }
}

void doTraverse(Graph<string>* G, int v) {
  cout<< "--------------------------------"<<endl
			<<"�Ӷ���" << G->getVex(v) << "��BFS����: \n";
  BFS(G, v, Q);
}

void graphTraverse(Graph<string>* G) {
  int v;
  for (v=0; v<G->n(); v++)
    G->setMark(v, UNVISITED);  // Initialize mark bits
  for (v=0; v<G->n(); v++)
    if (G->getMark(v) == UNVISITED)
      doTraverse(G, v);
}

int main(){

	FILE *fid;
	fid = fopen("test.gph", "rt");
	
	Graph<string>* G;
	//����ͼ��create.h) 
	G = createGraph(fid);
	//��ӡͼ��create.h) 
	Gprint(G);
	
	Q = new AQueue<int>(G->n());
	//����ͼ 
  graphTraverse(G);
	
	return 0;
}
