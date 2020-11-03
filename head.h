#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define max 20

typedef struct graph {
	char verlist[max];
	int edge[max][max];
	int n, e;
}MTGraph;//图的邻接矩阵

typedef struct node {
	int adjvex;
	int cost;
	struct node* next;
}EdgeNode;//边表结点

typedef struct vertexnode{
	char vertex;
	EdgeNode* firstedge;
}VertexNode;//顶点表结点

typedef struct adjgraph{
	VertexNode vexlist[max];
	int n, e;
}AdjGraph;//图的邻接表

MTGraph* createUndigraphByMatrix();

AdjGraph* createUndigraphByList();

void showUndiMatrix(MTGraph* G);

void showUndiList(AdjGraph* G);

void MtToAdj(MTGraph* G1, AdjGraph* G2);

void AdjToMt(AdjGraph* G1, MTGraph* G2);
