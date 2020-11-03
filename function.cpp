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
	G2->n = G1->n;
	G2->e = G1->e;
	for (int i = 0; i < G1->n; i++)
	{
		G2->vexlist[i].vertex = G1->verlist[i];
		G2->vexlist[i].firstedge = NULL;
	}
	int tail, head;
	int k = 0;//��������ͼ�������ڽӾ����ǶԳƵģ�����ֻҪ��ȡһ������ݾ���
	for (int i = 0; i < G1->n; i++)
	{
		for (int j = k; j < G1->n; j++)
		{
			if (G1->edge[i][j] != 0)
			{
				tail = i;
				head = j;
				EdgeNode* p = new EdgeNode;
				p->adjvex = head;
				p->cost = G1->edge[i][j];
				p->next = G2->vexlist[tail].firstedge;
				G2->vexlist[tail].firstedge = p;
				
				p = new EdgeNode; 
				p->adjvex = tail;
				p->cost = G1->edge[j][i];
				p->next = G2->vexlist[head].firstedge;
				G2->vexlist[head].firstedge = p;
			}
		}
		k++;
	}
}

//�ڽӱ�ת��Ϊ�ڽӾ���
void AdjToMt(AdjGraph* G1, MTGraph* G2) {
	G2->n = G1->n;
	G2->e = G1->e;
	int i, j;
	for (i = 0; i < G1->n; i++)
	{
		for (j = 0; j < G1->n; j++)
		{
			G2->edge[i][j] = 0;
		}
	}//���ڽӾ����ʼ��
	for (i = 0; i <G1->n; i++)
	{
		G2->verlist[i] = G1->vexlist[i].vertex;
	}//�Զ��㸳ֵ
	int x, y;
	EdgeNode* p = new EdgeNode;
	for (int k = 0; k < G1->n; k++) {
		x = k;
		p = G1->vexlist[k].firstedge;
		while (p != NULL) {
			y = p->adjvex;
			G2->edge[x][y] = p->cost;
			p = p->next;
		}
	}

}