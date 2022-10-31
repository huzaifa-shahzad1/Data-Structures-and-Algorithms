#include <iostream>
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

	void push() {
		Node* temp = new Node;
		int value = 0;
		cout << "Enter the Value: ";
		cin >> value;
		temp->data = value;
		if (isEmpty()) {
			top = temp;
			return;
		}

		temp->next = top;
		top = temp;
	}

	int pop() {
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return 0;
		}

		int value = top->data;

		top = top->next;

		return value;
	}

	int lenght() {
		Node* temp = new Node;
		temp = top;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void display() {
		Node* temp = new Node;
		temp = top;
		cout << "Elements of the Satck are:   ";
		while (temp != NULL) {
			cout << temp->data << "   ";
			temp = temp->next;
		}
		cout << endl;
	}
};

class Queue {
	Node* head;
	Node* tail;

public:
	Queue() {
		head = NULL;
		tail = NULL;
	}

	bool isEmpty() {
		return head == NULL;
	}

	void enQueue(int tData) {
		Node* temp = new Node;
		temp->data = tData;
		if (isEmpty()) {
			head = temp;
			tail = temp;
		}

		tail->next = temp;
		tail = temp;
	}

	void deQueue() {
		if (isEmpty()) {
			cout << "Queue is Empty.\n";
			return;
		}
		head = head->next;
	}

	
	void display() {
		Node* temp = new Node;
		temp = head;
		cout << "Elements of the Queue:  ";

		while (temp != NULL)
		{
			cout << temp->data << "    ";
			temp = temp->next;
		}

		cout << endl;
	}
};

void queueUsingStack(Stack stack) {
	Queue queue;
	int size = stack.lenght();
	for (int i = 0; i < size; i++) {
		queue.enQueue(stack.pop());
	}

	queue.display();
}

int main() {
	Stack stack;
	int size = 0;
	cout << "Enter the Number of the Elements: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		stack.push();
	}

	stack.display();

	queueUsingStack(stack);

	stack.display();
}