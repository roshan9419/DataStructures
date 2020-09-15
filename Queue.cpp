/////////////////////
/*Using Linked List*/
/////////////////////
#include<bits/stdc++.h>
using namespace std;

class QueueList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;
public:
    QueueList() {
        front = rear = NULL;
    }
    void enqueue(int x);
    void dequeue();
    void printQueue();
};

void QueueList::enqueue(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if(rear==NULL) {
        front = n;
        rear = n;
        return;
    }
    rear->next = n;
    rear = n;
}

void QueueList::dequeue() {
    if(front==NULL) {
        // printf("Empty Queue\n");
        return;
    }
    if(front==rear) {
        front = NULL;
        rear = NULL;
        return;
    }
    Node* temp = front;
    front = front->next;
    free(temp);
}

void QueueList::printQueue() {
    if(front==NULL) {
        printf("Empty Queue\n");
        return;
    }
    Node* temp = front;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    QueueList qL;
    cout << "\t\t# QueueList #\n\n";
    
    cout << "1. enqueue()\n";
    cout << "2. dequeue()\n";
    cout << "3. printQueue()\n";
    cout << "4. Exit\n";
    
    int choice = 0;
    while(choice != 4) {
        cout << "\nChoice: ";
        cin>>choice;
        switch(choice) {
            case 1: {
                int x;
                cout << "Enter the element: ";
                cin>>x;
                qL.enqueue(x); break;
            }
            case 2: qL.dequeue(); break;
            case 3: qL.printQueue(); break;
            default: continue;
        }
    }
    
    cout << "\n\nDo you want to do it again(y/n): ";
	char ch;
	cin >> ch;
	if(ch=='y'||ch=='Y') main();
	
    return 0;
}


///////////////
/*Using Array*/
///////////////
#include <bits/stdc++.h>
using namespace std;

class QueueADT {
private:
	int *A;
	int N;
	int front;
	int rear;
public:
	QueueADT(int n) {
		front = rear = -1;
		N = n;
		A = new int[N];
	}
	void enqueue(int x);
	int dequeue();
	int Front();
	bool isEmpty();
	bool isFull();
	void insert(int data);
	void printQueue();
};
int QueueADT::Front() {
	if(isEmpty()) return -1;
	return A[front];
}
void QueueADT::enqueue(int x) {
	if(isFull()) return;

	if(isEmpty()) {
		front = rear = 0;
	}
	else {
		rear = (rear+1)%N;
	}
	A[rear] = x;
}
int QueueADT::dequeue() {
	if(isEmpty()) return -1;
	if(front==rear) {
		front=rear=-1;
	}
	else {
		if(front==n-1) front=0;
		else front++;
	}
}
bool QueueADT::isFull() {
	if((rear+1)%N == front) return true;
	return false;
}
bool QueueADT::isEmpty() {
	if(front==-1 && rear==-1) return true;
	return false;
}


void QueueADT::insert(int data) {
	if((front==0 && rear==N-1) || front==rear+1) 
		return;//OVERFLOW

	if(front==-1) front = rear = 0;
	else if(rear==N-1) rear = 0;
	else rear++;

	A[rear] = data;
}

void QueueADT::printQueue() {
	if(isEmpty()) {
		printf("Empty\n");
		return;
	}
	if(rear<front) {
		for(int i=front; i<N; i++) {
			printf("%d ", A[i]);
		}
		for(int i=0; i<=rear; i++) {
			printf("%d ", A[i]);
		}
	}
	else {
		for(int i=front; i<=rear; i++) {
			printf("%d ", A[i]);
		}
	}
	printf("\n");
}


class QueueList {
private:
	struct Node	{
		int data;
		Node* next;
	};
	Node* front;
	Node* rear;
public:
	QueueList() {
		front = rear = NULL;
	}
	void enqueue(int x);
	void dequeue();
	void printQueue();
};

void QueueList::enqueue(int x) {
	Node *n = new Node;
	n->data = x;
	n->next = NULL;
	if(rear==NULL) {
		front = n;
		rear = n;
		return;
	}
	rear->next = n;
	rear = n;
}
void QueueList::dequeue() {
	Node* temp = front;
	if(front==NULL) return;
	if(front==rear) {
		front = NULL;
		rear = NULL;
		return;
	}
	front = front->next;
	free(temp);
}
void QueueList::printQueue() {
	if(front==NULL) {
		cout << "Empty\n";
		return;
	}
	Node* temp = front;
	while(temp!=NULL) {
		printf("%d ", temp->data);
		temp=temp->next;
	}
	cout << endl;
}





int main() {
	// QueueADT q(5);
	// q.insert(10);
	// q.insert(20);
	// q.insert(30);
	// q.insert(40);
	// q.insert(50);
	// q.dequeue();
	// q.dequeue();
	// q.insert(70);
	// q.dequeue();
	// q.insert(60); //Overflow
	// q.enqueue(10);
	// q.enqueue(20);
	// q.enqueue(30);
	// q.enqueue(40);
	// q.enqueue(50);
	// q.dequeue();
	// q.enqueue(50);
	// q.printQueue();
	

	QueueList qL;
	qL.printQueue();
	qL.enqueue(10);
	qL.enqueue(20);
	qL.enqueue(30);
	qL.enqueue(40);
	qL.enqueue(50);
	qL.printQueue();
	qL.dequeue();
	qL.dequeue();
	qL.enqueue(10);
	qL.enqueue(90);
	qL.dequeue();
	qL.dequeue();
	qL.dequeue();
	qL.dequeue();
	qL.dequeue();
	qL.enqueue(89);
	qL.enqueue(9);
	qL.dequeue();
	qL.printQueue();

	return 0;
}
