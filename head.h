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


typedef int ElemType;
struct celltype {
	ElemType data;
	celltype* next;
};
struct QUEUE {
	celltype* front;
	celltype* rear;
};

void MAKENULL(QUEUE& Q);
bool EMPTY(QUEUE Q);
ElemType FRONT(QUEUE Q);
void EnQueue(ElemType x, QUEUE& Q);
void DeQueue(QUEUE& Q);

struct stackNode {
	ElemType data;
	stackNode* next;
};
typedef stackNode* STACK;
STACK MakeNull();
bool Empty(STACK stk);
void Push(ElemType elm, STACK stk);
void Pop(STACK stk);
ElemType Top(STACK stk);

MTGraph* createUndigraphByMatrix();

AdjGraph* createUndigraphByList();

void showUndiMatrix(MTGraph* G);

void showUndiList(AdjGraph* G);

void MtToAdj(MTGraph* G1, AdjGraph* G2);

void AdjToMt(AdjGraph* G1, MTGraph* G2);

void DFSTraverse1(MTGraph* G);

void DFS1(MTGraph* G, int i);

void DFSTraverse2(AdjGraph* G);

void DFS2(AdjGraph* G, int i);

void BFSTraverse1(MTGraph* G);

void BFS1(MTGraph* G, int k);

void BFSTraverse2(AdjGraph* G);

void BFS2(AdjGraph* G, int k);

void DFSNoRecurTraverse1(MTGraph* G);

void DFSNoRecur1(AdjGraph* G,int i);

void DFSNoRecurTraverse2(AdjGraph* G);

void DFSNoRecur2(MTGraph* G, int i);

void showMenu();

MTGraph* createDigraphByMatrix();

AdjGraph* createDigraphByList();

void MtToAdj2(MTGraph* DG1, AdjGraph* DG2);

void AdjToMt2(AdjGraph* DG1, MTGraph* DG2);

