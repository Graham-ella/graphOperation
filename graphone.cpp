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
	//cout << "无向图邻接矩阵：" << endl;
	//MTGraph* G1 = createUndigraphByMatrix();
	//showUndiMatrix(G1);
	//深度优先遍历:邻接矩阵
	//DFSTraverse1(G1);
	//广度优先遍历：邻接矩阵
	//BFSTraverse1(G1);
	//深度优先遍历（非递归）:邻接矩阵
	//DFSNoRecurTraverse1(G1);
	

	//cout << endl;


	//cout << "无向图邻接表：" << endl;
	//AdjGraph* G2 = createUndigraphByList();
	//showUndiList(G2);
	//深度优先遍历:邻接表
	//DFSTraverse2(G2);
	//广度优先遍历：邻接表
	//BFSTraverse2(G2);
	//深度优先遍历（非递归）：邻接表
	//DFSNoRecurTraverse2(G2);
	
	

	/*
	AdjGraph* G3 = new AdjGraph;
	MtToAdj(G1,G3);
	showUndiList(G3);
	MTGraph* G4 = new MTGraph;
	AdjToMt(G2, G4);
	showUndiMatrix(G4);
	*/
	MTGraph* G1 = new MTGraph;
	AdjGraph* G2 = new AdjGraph;
	MTGraph* G4 = new MTGraph;
	AdjGraph* G3 = new AdjGraph;
	MTGraph* DG1 = new MTGraph;
	AdjGraph* DG2 = new AdjGraph;
	MTGraph* DG4 = new MTGraph;
	AdjGraph* DG3 = new AdjGraph;

	int flag;//flag = 0代表无向图,flag = 1代表有向图
	int select = 0;
	cout << "请输入:0(无向图),1(有向图）" << endl;
	cin >> flag;
	if (flag == 0) {
		while (true) {
			showMenu();
			cin >> select;
			switch (select) {
			case 1:
				G1 = createUndigraphByMatrix();
				showUndiMatrix(G1);
				system("pause");
				system("cls");
				break;
			case 2:
				G2 = createUndigraphByList();
				showUndiList(G2);
				system("pause");
				system("cls");
				break;
			case 3:
				MtToAdj(G1, G3);
				showUndiList(G3);
				system("pause");
				system("cls");
				break;
			case 4:
				AdjToMt(G2, G4);
				showUndiMatrix(G4);
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "先深序列如下：";
				DFSTraverse1(G1);
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "先深序列如下：";
				DFSTraverse2(G2);
				system("pause");
				system("cls");
				break;
			case 7:
				cout << "非递归先深序列如下：";
				DFSNoRecurTraverse1(G1);
				system("pause");
				system("cls");
				break;
			case 8:
				cout << "非递归先深序列如下：";
				DFSNoRecurTraverse2(G2);
				system("pause");
				system("cls");
				break;
			case 9:
				cout << "先广序列如下：";
				BFSTraverse1(G1);
				system("pause");
				system("cls");
				break;
			case 10:
				cout << "先广序列如下：";
				BFSTraverse2(G2);
				system("pause");
				system("cls");
				break;
			case 0:
				cout << "欢迎下次再来!" << endl;
				system("pause");
				return 0;
			default:
				cout<< "非法输入，请重新输入" << endl;
				break;
			}
		}
	}
	else {
		while (true) {
			showMenu();
			cin >> select;
			switch (select) {
			case 1:
				DG1 = createDigraphByMatrix();
				showUndiMatrix(DG1);
				system("pause");
				system("cls");
				break;
			case 2:
				DG2 = createDigraphByList();
				showUndiList(DG2);
				system("pause");
				system("cls");
				break;
			case 3:
				MtToAdj2(DG1, DG3);
				showUndiList(DG3);
				system("pause");
				system("cls");
				break;
			case 4:
				AdjToMt2(DG2, DG4);
				showUndiMatrix(DG4);
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "先深序列如下：";
				DFSTraverse1(DG1);
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "先深序列如下：";
				DFSTraverse2(DG2);
				system("pause");
				system("cls");
				break;
			case 7:
				cout << "非递归先深序列如下：";
				DFSNoRecurTraverse1(DG1);
				system("pause");
				system("cls");
				break;
			case 8:
				cout << "非递归先深序列如下：";
				DFSNoRecurTraverse2(DG2);
				system("pause");
				system("cls");
				break;
			case 9:
				cout << "先广序列如下：";
				BFSTraverse1(DG1);
				system("pause");
				system("cls");
				break;
			case 10:
				cout << "先广序列如下：";
				BFSTraverse2(DG2);
				system("pause");
				system("cls");
				break;
			case 0:
				cout << "欢迎下次再来!" << endl;
				system("pause");
				return 0;
			default:
				cout << "非法输入，请重新输入" << endl;
				break;
			}
		}
	}
}