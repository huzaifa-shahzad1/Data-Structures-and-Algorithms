#include<iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
};

class Queue {
private:
	Node* head;
	Node* tail;

public:
	Queue() {
		head = NULL;
		tail = NULL;
	}

	bool isEmpty() {
		return (head == NULL);
	}
	void enQueue() {
		int value = 0;
		cout << "Enter the Value: ";
		cin >> value;
		Node* temp = new Node;
		temp->data = value;
		if (isEmpty()) {
			head = temp;
			tail = temp;
			cout << "[" << value << "] inserted in the Queue.\n";
			return;
		}

		tail->next = temp;
		tail = temp;
		tail->next = head;
		cout << "[" << value << "] pushed into the Queue.\n";
	}

	void deQueue() {
		Node* temp = new Node;
		temp = head;
		if (isEmpty()) {
			cout << "Queue is Empty.\n";
			return;
		}
		int value = head->data;

		if (head == tail) {
			head = NULL;
			tail = NULL;
			cout << "[" << value << "] popped out of the Queue. Queue is Empty Now.\n";
			return;
		}
		head = head->next;

		tail->next = head;
		cout << "[" << value << "] popped out of the Queue.\n";
		
	}
};

class Stack {
private:
	Node* top;
public:
	Stack() {
		top = NULL;
	}

	bool isEmpty() {
		return (top == NULL);
	}
	void push(Queue q) {
		if (isEmpty()) {
			
		}
	}
};

int main() {
	Queue q;
	for (int i = 0; i < 4; i++) {
		q.enQueue();
	}

	for (int i = 0; i < 5; i++) {
		q.deQueue();
	}
}