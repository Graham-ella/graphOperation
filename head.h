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
}MTGraph;//ͼ���ڽӾ���

typedef struct node {
	int adjvex;
	int cost;
	struct node* next;
}EdgeNode;//�߱���

typedef struct vertexnode{
	char vertex;
	EdgeNode* firstedge;
}VertexNode;//�������

typedef struct adjgraph{
	VertexNode vexlist[max];
	int n, e;
}AdjGraph;//ͼ���ڽӱ�

MTGraph* createUndigraphByMatrix();

AdjGraph* createUndigraphByList();

void showUndiMatrix(MTGraph* G);

void showUndiList(AdjGraph* G);

void MtToAdj(MTGraph* G1, AdjGraph* G2);

void AdjToMt(AdjGraph* G1, MTGraph* G2);
