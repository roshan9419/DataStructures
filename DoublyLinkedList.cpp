#include<bits/stdc++.h>
using namespace std;

class DoublyLL {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* last;
public:
	DoublyLL() {
		head = NULL;
		last = NULL;
	}
	void InsertAtHead(int x); //O(1)
	void InsertAtTail(int x); //O(1)
	void InsertAtPosition(int pos, int x);//O(n)
	void deleteFromFront(); //O(1)
	void deleteFromLast(); //O(1)
	void print(); //O(n)
	void reversePrint(); //O(n)
};

void DoublyLL::InsertAtHead(int x) {
	Node* n = new Node;
	n->data = x;
	n->next = NULL;
	n->prev = NULL;

	if(head == NULL) {
		head = n;
		last = n;
		return;
	}

	head->prev = n;
	n->next = head;
	head = n;
}

void DoublyLL::InsertAtTail(int x) {
	Node* n = new Node;
	n->data = x;
	n->next = NULL;

	if(last == NULL) {
		InsertAtHead(x);
		return;
	}
	n->prev = last;
	last->next = n;
	last = n;
}

void DoublyLL::InsertAtPosition(int pos, int x) {
	if(pos<=0) {
		// cout << "Invalid Position\n";
		return;
	}
	if(pos==1) {
		InsertAtHead(x);
		return;
	}
	Node* n = new Node;
	n->data = x;
	n->next = NULL;
	n->prev = NULL;

	Node* temp = head;
	--pos;
	while(--pos) {
		temp=temp->next;
	}
	n->next = temp->next;
	n->prev = temp;
	temp->next->prev = n;
	temp->next = n;
}

void DoublyLL::deleteFromFront() {
	if(head==NULL) {
		return;
	}
	Node* temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}

void DoublyLL::deleteFromLast() {
	if(last==NULL) {
		return;
	}
	last->prev->next = NULL;
	last = last->prev;
}

void DoublyLL::print() {
	if(head==NULL) {
		cout << "Empty\n";
		return;
	}
	Node* temp = head;
	while(temp!=NULL) {
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << endl;
}

void DoublyLL::reversePrint() {
	if(head==NULL) {
		cout << "Empty\n";
		return;
	}
	Node* temp = last;
	while(temp!=NULL) {
		cout << temp->data << " ";
		temp=temp->prev;
	}
	cout << endl;
}

int main() {
	DoublyLL d;

	d.InsertAtHead(10);
	d.InsertAtHead(20);
	d.InsertAtHead(30);

	d.InsertAtTail(40);
	d.InsertAtTail(50);
	d.InsertAtTail(60);

	d.InsertAtPosition(2, 90);
	d.InsertAtPosition(0, 78);

	d.deleteFromFront();
	d.deleteFromLast();

	d.print();
	d.reversePrint();
	return 0;
}
