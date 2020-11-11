#include "head.h"

MTGraph* createUndigraphByMatrix() {
	MTGraph* G = new MTGraph;
	FILE* fp;
	fopen_s(&fp, "wuxiangtumatrix.txt", "r");
	if (fp == NULL)
	{
		cout << "打开文件失败！" << endl;
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
		cout << "文件打开失败！" << endl;
		exit(0);
	}
	fscanf_s(fp, "%d", &G->n);
	fscanf_s(fp, "%d", &G->e);
	
	for (int i = 0; i < G->n; i++) {
		fscanf_s(fp, " %c", &G->vexlist[i].vertex);//输入顶点信息
		G->vexlist[i].firstedge = NULL;//边表置为空
	}
	int tail, head, weight;

	for (int i = 0; i < G->e; i++) {
		fscanf_s(fp, "%d,%d,%d", &tail, &head,&weight);//tail：第几行？ head:下标  weight:权值
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
	cout << "图G的邻接矩阵如下:" << endl;
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
		temp = G->vexlist[i].firstedge;
		if (temp != NULL) {
			cout << G->vexlist[i].vertex << "->";
		}
		else {
			cout << G->vexlist[i].vertex;
		}
		
		
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


//邻接矩阵转化为邻接表
void MtToAdj(MTGraph* G1, AdjGraph* G2) {
	G2->n = G1->n;
	G2->e = G1->e;
	for (int i = 0; i < G1->n; i++)
	{
		G2->vexlist[i].vertex = G1->verlist[i];
		G2->vexlist[i].firstedge = NULL;
	}
	int tail, head;
	int k = 0;//对于无向图，它的邻接矩阵是对称的，所以只要读取一半的数据就行
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

//邻接表转化为邻接矩阵
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
	}//对邻接矩阵初始化
	for (i = 0; i <G1->n; i++)
	{
		G2->verlist[i] = G1->vexlist[i].vertex;
	}//对顶点赋值
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

//深度优先遍历主算法
bool visited1[max];
int dfn1[max] = { -1 };
int countNumber1 = 1;

void DFSTraverse1(MTGraph* G) {//邻接矩阵
	int i;
	countNumber1 = 1;
	for (i = 0; i < G->n; i++) {
		visited1[i] = false;
	}
	for (i = G->n; i < max; i++) {
		visited1[i] = true;
	}
	for (i = 0; i < G->n; i++) {
		if (!visited1[i]) {//如果没被访问过，从该结点遍历
			DFS1(G, i);
		}
		cout << " ";
	}
	cout << endl;
}

void DFS1(MTGraph* G, int i) {//邻接矩阵
	int j;
	cout << G->verlist[i];
	visited1[i] = true;
	dfn1[i] = countNumber1;
	countNumber1++;
	for (j = 0; j < G->n; j++) {
		if ((G->edge[i][j] == 1) && !visited1[j]) {
			DFS1(G, j);
		}
	}
}

void DFSTraverse2(AdjGraph* G) {//邻接表
	int i;
	countNumber1 = 1;//将countNumber重新赋值为1
	for (i = 0; i < G->n; i++) {
		visited1[i] = false;
	}
	for (i = G->n; i < max; i++) {
		visited1[i] = true;
	}
	for (i = 0; i < G->n; i++) {
		if (!visited1[i]) {
			DFS2(G, i);
		}
		cout << " ";
	}
	cout << endl;
}

void DFS2(AdjGraph* G, int i) {//邻接表
	EdgeNode* p;
	cout << G->vexlist[i].vertex;
	visited1[i] = true;
	dfn1[i] = countNumber1++;
	p = G->vexlist[i].firstedge;
	while (p) {
		if (!visited1[p->adjvex]) {
			DFS2(G, p->adjvex);
		}
		p = p->next;
	}
}

//广度优先遍历主算法
bool visited2[max];
int dfn2[max] = { -1 };
int countNumber2 = 1;

void BFSTraverse1(MTGraph* G) {
	int i;
	int countNumber2 = 1;
	for (i = 0; i < G->n; i++) {
		visited2[i] = false;
	}
	for (i = G->n; i < max; i++) {
		visited2[i] = true;
	}
	for (i = 0; i < G->n; i++) {
		if (!visited2[i]) {
			BFS1(G, i);
		}
		cout << " ";
	}
	cout << endl;
}

void BFS1(MTGraph* G, int k) {
	int i, j;
	QUEUE Q;
	MAKENULL(Q);
	cout << G->verlist[k];//访问vk
	visited2[k] = true;
	dfn2[k] = countNumber2;
	countNumber2++;
	EnQueue(k,Q);
	while (!EMPTY(Q)) {
		i = FRONT(Q);
		DeQueue(Q);
		for (j = 0; j < G->n; j++) {
			if (G->edge[i][j] == 1 && !visited2[j]) {
				cout << G->verlist[j];
				visited2[j] = true;
				EnQueue(j, Q);
			}
		}
	}//外层循环，判断队列空否
}

void BFSTraverse2(AdjGraph* G) {
	int i;
	int countNumber2 = 1;
	for (i = 0; i < G->n; i++) {
		visited2[i] = false;
	}
	for (i = G->n; i < max; i++) {
		visited2[i] = true;
	}
	for (i = 0; i < G->n; i++) {
		if (!visited2[i]) {
			BFS2(G, i);
		}
		cout << " ";
	}
	cout << endl;
}

void BFS2(AdjGraph* G,int k) {
	int i;
	EdgeNode* p;
	QUEUE Q;
	MAKENULL(Q);
	cout << G->vexlist[k].vertex;
	visited2[k] = true;
	dfn2[k] = countNumber2;
	countNumber2++;
	EnQueue(k, Q);
	while (!EMPTY(Q)) {
		i = FRONT(Q);
		DeQueue(Q);
		p = G->vexlist[i].firstedge;
		while (p) {
			if (!visited2[p->adjvex]) {
				cout << G->vexlist[p->adjvex].vertex;
				visited2[p->adjvex] = true;
				EnQueue(p->adjvex, Q);
			}
			p = p->next;
		}
	}
}

//深度优先遍历主算法（非递归）
bool visited3[max];
int dfn3[max] = { -1 };
int countNumber3 = 1;

void DFSNoRecurTraverse1(MTGraph* G) {
	AdjGraph* newG = new AdjGraph;
	MtToAdj(G, newG);
	int i;
	countNumber3 = 1;
	for (i = 0; i < G->n; i++) {
		visited3[i] = false;
	}
	for (i = G->n; i < max; i++) {
		visited3[i] = true;
	}
	for (i = 0; i < G->n; i++) {
		if (!visited3[i]) {//如果没被访问过，从该结点遍历
			DFSNoRecur1(newG, i);
		}
		cout << " ";
	}
	cout << endl;
}

void DFSNoRecur1(AdjGraph* G, int i) {
	int k;
	EdgeNode* p = new EdgeNode;
	STACK S = MakeNull();
	Push(i, S);
	while (!Empty(S)) {
		k = Top(S);
		Pop(S);
		cout << G->vexlist[k].vertex;
		dfn3[k] = countNumber3;
		countNumber3++;
		visited3[k] = true;
		p = G->vexlist[k].firstedge;
		while (p) {
			if (!visited3[p->adjvex]) {
				Push(p->adjvex, S);
				visited3[p->adjvex] = true;
			}
			p = p->next;
		}
	}
}

void DFSNoRecurTraverse2(AdjGraph* G) {
	MTGraph* newG = new MTGraph;
	AdjToMt(G, newG);
	int i;
	countNumber3 = 1;
	for (i = 0; i < G->n; i++) {
		visited3[i] = false;
	}
	for (i = G->n; i < max; i++) {
		visited3[i] = true;
	}
	for (i = 0; i < G->n; i++) {
		if (!visited3[i]) {//如果没被访问过，从该结点遍历
			DFSNoRecur2(newG, i);
		}
		cout << " ";
	}
	cout << endl;
}

void DFSNoRecur2(MTGraph* G, int i) {
	STACK S = MakeNull();
	Push(i, S);
	int k;
	while (!Empty(S)) {
		k = Top(S);
		Pop(S);
		cout << G->verlist[k];
		dfn3[k] = countNumber3;
		countNumber3++;
		visited3[k] = true;
		for (int m = 0; m < G->n; m++) {
			if ((G->edge[k][m] != 0) && !visited3[m]) {
				Push(m, S);
				visited3[m] = true;
			}
		}
	}
}


void showMenu() {
	cout << "1、从邻接矩阵读取" << endl;
	cout << "2、从邻接表读取" << endl;
	cout << "3、邻接矩阵转化成邻接表" << endl;
	cout << "4、邻接表转化成邻接矩阵" << endl;
	cout << "5、图的深度优先搜索（递归,邻接矩阵）" << endl;
	cout << "6、图的深度优先搜索（递归,邻接表）" << endl;
	cout << "7、图的深度优先搜索（非递归，邻接矩阵）" << endl;
	cout << "8、图的深度优先搜索（非递归，邻接表）" << endl;
	cout << "9、图的广度优先搜索（邻接矩阵）" << endl;
	cout << "10、图的广度优先搜索（邻接表）" << endl;
	cout << "0、退出" << endl;
}

MTGraph* createDigraphByMatrix() {
	MTGraph* G = new MTGraph;
	FILE* fp;
	fopen_s(&fp, "youxiangtumatrix.txt", "r");
	if (fp == NULL)
	{
		cout << "打开文件失败！" << endl;
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
	}
	fclose(fp);
	G->n = temp;
	return G;
}

AdjGraph* createDigraphByList() {
	AdjGraph* G = new AdjGraph;
	FILE* fp;
	fopen_s(&fp, "youxiangtulist.txt", "r");
	if (fp == NULL)
	{
		cout << "文件打开失败！" << endl;
		exit(0);
	}
	fscanf_s(fp, "%d", &G->n);
	fscanf_s(fp, "%d", &G->e);

	for (int i = 0; i < G->n; i++) {
		fscanf_s(fp, " %c", &G->vexlist[i].vertex);//输入顶点信息
		G->vexlist[i].firstedge = NULL;//边表置为空
	}
	int tail, head, weight;

	for (int i = 0; i < G->e; i++) {
		fscanf_s(fp, "%d,%d,%d", &tail, &head, &weight);//tail：第几行？ head:下标  weight:权值
		EdgeNode* p = new EdgeNode;
		p->adjvex = head;
		p->cost = weight;
		p->next = G->vexlist[tail].firstedge;
		G->vexlist[tail].firstedge = p;
	}
	fclose(fp);
	return G;
}

void MtToAdj2(MTGraph* DG1, AdjGraph* DG2) {
	DG2->n = DG1->n;
	DG2->e = DG1->e;
	for (int i = 0; i < DG1->n; i++)
	{
		DG2->vexlist[i].vertex = DG1->verlist[i];
		DG2->vexlist[i].firstedge = NULL;
	}
	int tail, head;
	for (int i = 0; i < DG1->n; i++)
	{
		for (int j = 0; j < DG1->n; j++)
		{
			if (DG1->edge[i][j] != 0)
			{
				tail = i;
				head = j;
				EdgeNode* p = new EdgeNode;
				p->adjvex = head;
				p->cost = DG1->edge[i][j];
				p->next = DG2->vexlist[tail].firstedge;
				DG2->vexlist[tail].firstedge = p;
			}
		}
	}
}

void AdjToMt2(AdjGraph* DG1, MTGraph* DG2) {
	DG2->n = DG1->n;
	DG2->e = DG1->e;
	int i, j;
	for (i = 0; i < DG1->n; i++)
	{
		for (j = 0; j < DG1->n; j++)
		{
			DG2->edge[i][j] = 0;
		}
	}//对邻接矩阵初始化
	for (i = 0; i < DG1->n; i++)
	{
		DG2->verlist[i] = DG1->vexlist[i].vertex;
	}//对顶点赋值
	int x, y;
	EdgeNode* p = new EdgeNode;
	for (int k = 0; k < DG1->n; k++) {
		x = k;
		p = DG1->vexlist[k].firstedge;
		while (p != NULL) {
			y = p->adjvex;
			DG2->edge[x][y] = p->cost;
			p = p->next;
		}
	}
}

