#include <iostream>
#include <cstring>
#include "graphl.h"
#include "graph.h"
#include "create.h"
#define INFINITY 9999

using namespace std;
int minVertex(Graph<string>*, int*);

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph<string>* G, int* D, int s) {
  int i, v, w;
  for (i=0; i<G->n(); i++) {      // Process the vertices
    v = minVertex(G, D);
    if (D[v] == INFINITY) return; // Unreachable vertices
    G->setMark(v, VISITED);
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > (D[v] + G->weight(v, w)))
        D[w] = D[v] + G->weight(v, w);
  }
}

int minVertex(Graph<string>* G, int* D) { // Find min cost vertex
  int i, v = -1;
  // Initialize v to some unvisited vertex
  for (i=0; i<G->n(); i++)
    if (G->getMark(i) == UNVISITED) { v = i; break; }
  for (i++; i<G->n(); i++)  // Now find smallest D value
    if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
      v = i;
  return v;
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
	Dijkstra(G, D, 0);
	cout<<"--------------------------------\n"
			<<"�Զ���AΪ��ʼ������Dijkstra��ⵥԴ���·��\n"
			<<"�������㵽����A����̾�������Ϊ��\n"; 
  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;
	
	return 0;
}
