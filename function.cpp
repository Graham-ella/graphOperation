#include "head.h"


void CreateMTGraph(MTGraph* G) {
	int i, j, k, w;
	cin >> G->n >> G->e;//读入顶点个数n，边的条数e

	for (i = 0; i < G->n; i++) {
		G->verlist[i] = getchar();//初始化顶点
	}
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			G->edge[i][j] = 0;//将所有的边设为0
		}
	}
	for (k = 0; k < G->e; k++) {//无向图
		cin >> i >> j;//读取边和对应的权值
		G->edge[i][j] = 1;
		G->edge[j][i] = 1;
	}
}

