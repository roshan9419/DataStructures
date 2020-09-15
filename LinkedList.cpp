/*
	Linked list: linear collection of self-referential class objects, called nodes
	Connected by pointer links

	Types::
	Singly Linked List
	Circular singly Linked List
	Doubly Linked List
	Circular doubly linked list

	struct node {
		int data;
		node* next;
	}

	Access to elements: O(n)
	Insertion: O(n) //to traverse through the elements first

	#Header Linked Lists
		-Grounded Header Link List
	
	To delete a node without head node:
	*(node) = *(node->next);

*/

#include<bits/stdc++.h>
using namespace std;

class DoublyLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};
	Node *first, *last;
public:
	DoublyLinkedList() {
		first = last = NULL;
	}
	void insertAtFront(int data);
	void insertAtBack(int data);
	void printDoublylist();
};

class LinkedList {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}
	int search(int data);
	void sortedInsert(int data);
	void push_front(int data);
	void push_back(int data);
	void insert(int data, int pos);
	void pop_back();
	void pop_front();
	void deleteNode(int pos);
	void print_list();
	void insertBeforeLargest(int data);
	void sort();
	bool isPalindrome();
	bool detectLoop();
	void deleteMidNode();
	int count();
	void unionOfLinkedList();
	void reverse();
	~LinkedList() {
		free(head);
	}
};
void LinkedList::sortedInsert(int data) {
    Node* n = new Node;
    n->data = data;
    n->next = NULL;
    
    if(head==NULL || data <= head->data) {
        n->next = head;
        head = n;
        return;
    }
    
    Node *t=head, *prev=NULL;
    while(t!=NULL && data > t->data) {
        prev = t;
        t = t->next;
    }
    n->next = t;
    prev->next = n;
    
}

void LinkedList::reverse() {
	Node *current, *next, *prev;
	current = head;
	prev = NULL;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;

	/*
	//Using Recursion
	Reverse(Node* p) {
		if(p->next==NULL) {
			head = p;
			return;
		}
		Reverse(p->next);
		Node* q = p->next;
		q->next = p;
		p->next = NULL;
	}
	*/
}

void LinkedList::unionOfLinkedList() {
	/*
	Node *t1 = head1, *t2 = head2;
	set<int, greater<int>> s;
	while(t1!=NULL) {
		s.insert(t1->data);
		t1=t1->next;
	}
	while(t2!=NULL) {
		s.insert(t2->data);
		t2=t2->next;
	}
	Node* head3 = NULL;
	set<int, greater<int>>::iterator itr; //for(itr=s.begin(); itr!=s.end(); itr++) *itr(value)

	for(auto i: s) {
		Node* n = new Node;
		n->data = i;
		n->next = head3;
		head3 = n;
	}
	*/
}

void LinkedList::deleteMidNode() {
	if(head==NULL) {
		cout << "Empty List\n";
		return;
	}
	Node *slow=head, *fast=head, *prev=head;
	while(fast!=NULL && fast->next!=NULL) {
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	prev->next = slow->next;
}

bool LinkedList::detectLoop() {
	//Floyd's Cyclie-Finding Algorithm
	Node *slow=head, *fast=head;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast) return true;
	}
	return false;
}

bool LinkedList::isPalindrome() {
	Node *t = head;
	stack<int>s;
	while(t!=NULL) {
		s.push(t->data);
		t=t->next;
	}
	t = head;
	while(!s.empty()) {
		if(s.top() != t->data) return false;
		s.pop();
		t=t->next;
	}
	return true;
}

void LinkedList::sort() {
	if(head==NULL) {
		cout << "Empty List\n";
		return;
	}
	Node *i, *j;
	for(i=head; i!=NULL; i=i->next) {
		for(j=i; j!=NULL; j=j->next) {
			if(j->data > j->next->data) {
				swap(j->data, j->next->data);
			}
		}
	}
}

void LinkedList::insertBeforeLargest(int item) {
	Node *n = new Node;
	n->data = item;
	n->next = NULL;
	if(head==NULL || head->data >= item) {
		n->next = head;
		head=n;
		return;
	}
	Node *t=head;
	while(t->next->data < item && t->next!=NULL) {
		t=t->next;
	}
	n->next = t->next;
	t->next = n;
}

int LinkedList::search(int data) {
	Node* temp = head;
	int loc=0;
	while(temp!=NULL) {
		if(temp->data==data) {
			return loc;
		}
		loc++;
		temp=temp->next; //temp=next[temp];
	}
	return -1;
}

void LinkedList::deleteNode(int pos) {
	Node *temp1, *temp2;
	if(pos==1) {
		head=head->next;
		delete temp1;
	}
	temp1=head;
	for(int i=0; i<pos-2; i++) {
		temp1 = temp1->next;
	}
	//temp1 points to (n-1)th node
	temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}

void LinkedList::insert(int data, int pos) {
	Node* n = new Node, *t = head;
	n->data = data;
	if(pos==1) {
		n->next = head;
		head=n;
		return;
	}
	pos-=2;
	while(pos--) {
		t=t->next;
	}
	n->next = t->next;
	t->next = n;
}

void LinkedList::pop_front() {
	if(head==NULL) {
		printf("Empty List\n");
		return;
	}
	head = head->next;
}

void LinkedList::pop_back() {
	if(head==NULL) {
		printf("Empty List\n");
		return;
	}
	if(head->next==NULL) {
		pop_front();
		return;
	}
	Node* t = head,*prev=head;
	while(t->next->next!=NULL) {
		t = t->next;
	}
	t->next = NULL;
	// t->next = NULL;
}

void LinkedList::push_front(int data) {
	Node* n = new Node;
	n->data = data;
	n->next = head;
	head=n;
}

void LinkedList::push_back(int data) {
	Node* n = new Node;
	n->data = data;
	n->next = NULL;
	if(head==NULL) {
		head = n;
		return;
	}
	Node* t = head;
	while(t->next!=NULL) {
		t = t->next;
	}
	t->next = n;
}
int LinkedList::count() {
	Node *t=head;
	int cnt=0;
	while(t!=NULL) {
		cnt++;
		t=t->next;
	}
	return cnt;
}
void LinkedList::print_list() {
	Node* t = head;
	if(head==NULL) {
		printf("Empty List\n");
		return;
	}
	while(t!=NULL) {
		printf("%d ", t->data);
		t=t->next;
	}
	printf("\n");
	/*
	//TO PRINT USING RECURSION
	void print_list(Node* p) {
		if(p==NULL) return;
		printf("%d ", p->data);
		print_list(p->next);
	}
	//TO PRINT IN REVERSE ORDER USING RECURSION
	void reverse_print(Node* rp) {
		if(rp==NULL) return;
		reverse_print(rp->next);
		printf("%d ", rp->data);
	}
	*/
}

int main(int argc, char const *argv[])
{
	LinkedList l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_front(30);
	l1.push_back(32);
	
	l1.print_list();
	l1.reverse();
	l1.print_list();

	return 0;
}
