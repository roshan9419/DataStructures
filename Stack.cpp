#include<bits/stdc++.h>
using namespace std;

/*
Postfix Notation(RPN)
RPN- Reverse Polish Notation
Most compilers convert an expression in infix notation to postfix

a * b + c  [Infix]
a b * c +  [Postfix]

Prefix: operators come before the operands
2 3 4 + 5 6  - - * (do By Hand)

*/

class StackADT {
private:
	int *A;
	int top;
public:
	StackADT(int n) {
		top=-1;
		A = new int[n];
	}
	int topElement();
	void push();
	void pop();
};

class StackList {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* top;
public:
	StackList() {
		top=NULL;
	}
	void push(int data);
	void pop();
	void display();
};

void StackList::push(int data) {
	Node *n = new Node;
	n->data = data;
	n->next = top;
	top = n;
}

void StackList::pop() {
	if(top==NULL) {
		printf("Stack Underflow\n");
		return;
	}
	Node* temp = top;
	top = top->next;
	delete temp;
	// temp = NULL;
}

void StackList::display() {
	if(top==NULL) {
		printf("Stack is Empty\n");
		return;
	}
	Node* temp = top;
	while(temp!=NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main() {
	StackList s;
	s.push(3);
	s.push(4);
	s.push(2);
	s.pop();
	s.push(7);
	s.display();
	return 0;
}
