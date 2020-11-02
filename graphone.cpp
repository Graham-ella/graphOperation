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
	MTGraph* G = createUndigraphByMatrix();
	showUndiMatrix(G);
	cout << endl;
	cout << "无向图邻接表：" << endl;
	AdjGraph* G2 = createUndigraphByList();
	showUndiList(G2);


}