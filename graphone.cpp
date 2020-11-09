#include "head.h"

//图为无向图，用邻接矩阵存储
int main() {
	/*
	int flagOne;//选择读取无向图还是有向图,flag=0读取无向图,flag=1读取有向图
	int flagTwo;
	cout << "请输入:0(无向图),1(有向图）" << endl;
	cin >> flagOne;
	if (flagOne == 0) {
		cout << "存储结构:0(邻接矩阵）,1(邻接表)" << endl;
		cin >> flagTwo;
		if (flagTwo == 0) {
			MTGraph* G = createUndigraphByMatrix();
			showUndiMatrix(G);
		}
		if (flagTwo == 1) {
			AdjGraph* G2 = createUndigraphByList();
			showUndiList(G2);
		}
	}
	*/
	cout << "无向图邻接矩阵：" << endl;
	MTGraph* G1 = createUndigraphByMatrix();
	showUndiMatrix(G1);
	//深度优先遍历:邻接矩阵
	DFSTraverse1(G1);
	//广度优先遍历：邻接矩阵
	BFSTraverse1(G1);


	cout << endl;


	cout << "无向图邻接表：" << endl;
	AdjGraph* G2 = createUndigraphByList();
	showUndiList(G2);
	//深度优先遍历:邻接表
	DFSTraverse2(G2);
	//广度优先遍历：邻接表
	BFSTraverse2(G2);
	


	/*
	AdjGraph* G3 = new AdjGraph;
	MtToAdj(G1,G3);
	showUndiList(G3);
	MTGraph* G4 = new MTGraph;
	AdjToMt(G2, G4);
	showUndiMatrix(G4);
	*/


}