#pragma once
#include <iostream>
using namespace std;

#define NumVertices 5
typedef char VertexData;
typedef int EdgeData;
typedef struct graph {
	VertexData verlist[NumVertices];
	EdgeData edge[NumVertices][NumVertices];
	int n, e;
}MTGraph;

void CreateMTGraph(MTGraph* G);