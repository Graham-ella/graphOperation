#include "head.h"
void MAKENULL(QUEUE& Q) {
	Q.front = new celltype;
	Q.front->next = NULL;
	Q.rear = Q.front;
}

bool EMPTY(QUEUE Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}

ElemType FRONT(QUEUE Q) {
	if (Q.front->next) {
		return Q.front->next->data;
	}
}

void EnQueue(ElemType x, QUEUE& Q) {
	celltype* q = new celltype;
	q->data = x;
	q->next = NULL;
	Q.rear->next = q;
	Q.rear = q;
}

void DeQueue(QUEUE& Q) {
	if (Q.front == Q.rear) {
		cout << "该队列为空!" << endl;
		return;
	}
	celltype* p;
	p = Q.front->next;
	if (p->next == NULL) {
		Q.rear = Q.front;
	}
	else {
		Q.front->next = p->next;
	}
	free(p);
}