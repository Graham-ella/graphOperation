#include "head.h"


void CreateMTGraph(MTGraph* G) {
	int i, j, k, w;
	cin >> G->n >> G->e;//���붥�����n���ߵ�����e

	for (i = 0; i < G->n; i++) {
		G->verlist[i] = getchar();//��ʼ������
	}
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			G->edge[i][j] = 0;//�����еı���Ϊ0
		}
	}
	for (k = 0; k < G->e; k++) {//����ͼ
		cin >> i >> j;//��ȡ�ߺͶ�Ӧ��Ȩֵ
		G->edge[i][j] = 1;
		G->edge[j][i] = 1;
	}
}

