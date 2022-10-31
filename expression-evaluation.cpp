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

	char getTop() {
		return top->data;
	}

	int length() {
		int count = 0;
		Node* temp = top;
		while (top != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
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

	char pop() {
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return ' ';
		}
		char value = top->data;
		top = top->next;
		return value;
	}

	void display() {
		if (isEmpty()) {
			cout << "Stack Underflow.\n";
			return;
		}
		Node* temp = top;
		while (top != NULL) {
			cout << temp->data << "   ";
			temp = temp->next;
		}
		cout << endl;
	}
};


int precedance(char value) {
	if (value == '^')
		return 3;
	else if (value == '*' || value == '/')
		return 2;
	else if (value == '+' || value == '-')
		return 1;
	else 
		return 0;
}

bool isDigit(char value) {
	return (isalpha(value) || isdigit(value));
}


string infixToPostfix(string exp) {
	exp = '(' + exp + ')';
	Stack obj;
	string result;
	for (int i = 0; i < exp.size(); i++) {
		if (isDigit(exp[i]))
			result += exp[i];
		else if (exp[i] == '(')
			obj.push(exp[i]);
		else if (exp[i] == ')') {
			while (obj.getTop() != '(')
				result += obj.pop();
			obj.pop();
		}
		else {
			if (!isDigit(obj.getTop()))
			{
				if (exp[i] == '^') {
					while (precedance(exp[i]) <= precedance(obj.getTop())) {
						result += obj.pop();
					}
				}
			}
			else {
				while (precedance(exp[i]) < precedance(obj.getTop()))
					result += obj.pop();
			}
			obj.push(exp[i]);
		}
	}
	while (!obj.isEmpty()) {
		result += obj.getTop();
		obj.pop();
	}

	return result;
}


string infixToPrefix(string exp) {
	int length = exp.size();
	reverse(exp.begin(), exp.end());

	for (int i = 0; i < length; i++) {
		if (exp[i] == '(')
			exp[i] = ')'; 
		else if (exp[i] == ')')
			exp[i] = '(';
	}

	string result;
	exp = '(' + exp + ')';
	Stack obj;

	for (int i = 0; i < length; i++) {
		if (isDigit(exp[i]))
			result += exp[i];

		else if (exp[i] == '(')
			obj.push(exp[i]);
		else if (exp[i] == ')')
		{
			while (obj.getTop() != '(')
				result += obj.pop();
			obj.pop();
		}

		else {
			if (!isDigit(obj.getTop())) {
				if (exp[i] == '^') {
					while (precedance(exp[i]) <= precedance(obj.getTop()))
						result += obj.pop();
				}
				else {
					while (precedance(exp[i]) < precedance(obj.getTop()))
						result += obj.pop();
				}
				obj.push(exp[i]);
			}
		}
	}

	while (!obj.isEmpty()) {
		result += obj.getTop();
		obj.pop();
	}

	reverse(result.begin(), result.end());

	return result;
}

int main() {
	string exp;
	cout << "Enter the Expression: ";
	cin >> exp;
	string tExp = infixToPostfix(exp);

	cout << tExp << endl;

	string exp2;
	cout << "Enter the Expression: ";
	cin >> exp2;
	string Wp = infixToPrefix(exp2);

	cout << Wp << endl;
}