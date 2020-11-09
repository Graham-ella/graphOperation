#include "head.h"
STACK MakeNull() {
	STACK s = new stackNode;
	s->next = NULL;
	return s;
}

bool Empty(STACK stk) {
	if (stk->next) {
		return false;
	}
	else {
		true;
	}
}

void Push(ElemType elm, STACK stk) {
	STACK s = new stackNode;
	s->data = elm;
	s->next = stk->next;
	stk->next = s;
}

void Pop(STACK stk) {
	STACK s;
	if (stk->next) {
		s = stk->next;
		stk->next = s->next;
		free(s);
	}
}

ElemType Top(STACK stk) {
	if (stk->next) {
		return stk->next->data;
	}
	else {
		return  -1;
	}
}