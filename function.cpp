#include "head.h"

MTGraph* createUndigraphByMatrix() {
	MTGraph* G = new MTGraph;
	FILE* fp;
	fopen_s(&fp, "wuxiangtumatrix.txt", "r");
	if (fp == NULL)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		exit(0);
	}
	fscanf_s(fp, "%d", &G->n);
	fscanf_s(fp, "%d", &G->e);
	int temp = G->n;
	for (int i = 0; i < G->n; i++) {
		fscanf_s(fp, " %c", &G->verlist[i]);
	}
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; i < G->n; j++) {
			G->edge[i][j] = 0;
		}
	}
	int i, j;
	for (int k = 0; k < G->e; k++) {
		fscanf_s(fp, "%d,%d", &i, &j);
		G->edge[i][j] = 1;
		G->edge[j][i] = 1;
	}
	fclose(fp);
	G->n = temp;
	return G;
}

AdjGraph* createUndigraphByList() {
	AdjGraph* G = new AdjGraph;
	FILE* fp;
	fopen_s(&fp, "wuxiangtulist.txt", "r");
	if (fp == NULL)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	fscanf_s(fp, "%d", &G->n);
	fscanf_s(fp, "%d", &G->e);
	
	for (int i = 0; i < G->n; i++) {
		fscanf_s(fp, " %c", &G->vexlist[i].vertex);//���붥����Ϣ
		G->vexlist[i].firstedge = NULL;//�߱���Ϊ��
	}
	int tail, head, weight;

	for (int i = 0; i < G->e; i++) {
		fscanf_s(fp, "%d,%d,%d", &tail, &head,&weight);//tail���ڼ��У� head:�±�  weight:Ȩֵ
		EdgeNode* p = new EdgeNode;
		p->adjvex = head;
		p->cost = weight;
		p->next = G->vexlist[tail].firstedge;
		G->vexlist[tail].firstedge = p;

		p = new EdgeNode;
		p->adjvex = tail;
		p->cost = weight;
		p->next = G->vexlist[head].firstedge;
		G->vexlist[head].firstedge = p;
	}
	fclose(fp);
	return G;

}


void showUndiMatrix(MTGraph* G) {
	cout << "ͼG���ڽӾ�������:" << endl;
	int i, j;
	for (i = 0; i < G->n; i++){
		for (j = 0; j < G->n; j++) {
			cout << G->edge[i][j];
		}
		cout << endl;
	}
}


void showUndiList(AdjGraph* G) {
	EdgeNode* temp = new EdgeNode;
	for (int i = 0; i < G->n; i++) {
		cout << G->vexlist[i].vertex << "->";
		temp = G->vexlist[i].firstedge;
		while (temp != NULL) {
			if (temp->next == NULL) {
				cout << G->vexlist[temp->adjvex].vertex;
			}
			else {
				cout << G->vexlist[temp->adjvex].vertex << "->";
			}
			
			temp = temp->next;
		}
		cout << endl;
	}
}


//�ڽӾ���ת��Ϊ�ڽӱ�
void MtToAdj(MTGraph* G1, AdjGraph* G2) {

}
