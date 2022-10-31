#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	char data;
	Node* next;

	Node() {
		data = ' ';
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

	void push(char value) {
		Node* temp = new Node;
		temp->data = value;
		if (isEmpty()) {
			top = temp;
			return;
		}

		temp->next = top;
		top = temp;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Cannot be popped. Stack Underflow.\n";
			return;
		}

		top = top->next;
	}

	char getTop() {
		return top->data;
	}
	void display() {
		Node* temp = new Node;
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return;
		}

		while (top != NULL) {
			cout << top->data;
			top = top->next;
		}
	}

};

bool balanceCheck() {
	string exp;
	cout << "Enter the Expression: ";
	cin >> exp;
	Stack stack;

	for (int i = 0; i < exp.length(); i++) {
		if (stack.isEmpty()) {
			stack.push(exp[i]);
		}
		else if (stack.getTop() == '(' && exp[i] == ')'
			|| stack.getTop() == '{' && exp[i] == '}'
			|| stack.getTop() == '[' && exp[i] == ']'
			)
			 {
					stack.pop();
			 }
		else {
			stack.push(exp[i]);
		}
	}

	if (stack.isEmpty())
		return true;
	else
		return false;
}
int main() {
	bool check = balanceCheck();
	if (!check)
		cout << "Expression is Not Balanced.\n";
	else
		cout << "Epression is Balanced.\n";
}