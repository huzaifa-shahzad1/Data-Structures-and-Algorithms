/*****PROGRAM DESCRIPTION*****/
/*
* PURPOSE: MENU DIVEN Program of Basic Stack Functionality

* Functions: PUSH, POP, PEEK and DISPLAY

* PUSH: Add a new Element at the TOP of the Stack.
* POP: Remove an Element from the TOP of the Stack.
* PEEK: Display the TOP of the Stack.
* DISPLAY: Prints all the Elements of the Stack.
*/

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node()
	{
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

	//check weather stack is Empty or Not
	bool isEmpty() {
		return (top == NULL) ? true : false;
	}

	// add an element
	void push() {
		Node* temp = new Node;
		int value = 0;
		cout << "Enter the Value: ";
		cin >> value;
		temp->data = value;
		// if top is NULL, set the TOP
		if (isEmpty()) {
			top = temp;
			cout << "[" << value << "] pushed into the Stack.\n";
			return;
		}

		// add element and move the TOP 
		temp->next = top;
		top = temp;
		cout << "[" << value << "] pushed into the Stack.\n";
	}

	// remove an element
	void pop() {
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return;
		}
		int value = top->data;

		// remove the top by moving the top to the next element of the Stack
		top = top->next;

		cout << "[" << value << "] popped out of the Stack.\n";
	}

	// display first element
	void peek() {
		Node* temp = new Node;
		temp = top;
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return;
		}

		cout << "[" << temp->data << "] is at the top of Stack.\n";
	}

	// display all the Elements
	void display() {
		Node* temp = new Node;
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return;
		}
		temp = top;
		cout << "Elements of the Stack are:   ";

		while (temp != NULL) {
			if (temp->next != NULL) {
				cout << temp->data << "->";
			}
			else
				cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

void menu() {
	cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Quit Program\n";
	cout << "Enter the Operation: ";
}
int main() {

	Stack s;
	int choice = 0;
	char rep = ' ';
	do {
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:

			// add as much elements as required
			cout << "Enter the Number of Elements: ";
			cin >> choice;
			for (int i = 0; i < choice; i++) {
				s.push();
			}
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.peek();
			break;
		case 4:
			s.display();
			break;
		case 5:
			cout << "/******Program Ended.******/\n";
			return 0;
		default:
			cout << "/******Invalid Operation.******/\n";
			break;
		}

		cout << "Enter Y to Repeat: ";
		cin >> rep;
	} while (rep == 'y' || rep == 'Y');

	return 0;
}