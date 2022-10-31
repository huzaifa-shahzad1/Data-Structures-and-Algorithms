#include <iostream>
using namespace std;

void menu() {
	cout << "1. Multiply Two Numbers\n";
	cout << "2. Power of a Number\n";
	cout << "3. Factorial of a Number\n";
	cout << "4. Fibonacci of a Number\n";
	cout << "5. Search Value from a Link List\n";
	cout << "6. Insert Value in List\n";
	cout << "7. Greatest Value from the List\n";
	cout << "8. Display List in Reverse Order\n";
	cout << "9. Quit Program\n";
}

class Node {
public:
	int data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
};

class linkList {
public:
	Node* head;
	Node* tail;

	linkList() {
		head = NULL;
		tail = NULL;
	}

	bool isEmpty() {
		return (head == NULL);
	}

	void insertAtBegin(int value) {
		Node* temp = new Node;
		temp->data = value;

		if (isEmpty()) {
			head = temp;
			tail = temp;
			return;
		}

		temp->next = head;
		head = temp;
	}
};


int multiplyNumbers(int a, int b);
int power(int a, int b);
int factorial(int a);
int fibonacci(int num);
bool searchElement(Node* node, int num);
int max(Node* node);
void insertAtTail(Node* node, int value);
void displayReverse(Node* node);

int main() {
	int choice = 0;
	char rep = ' ';
	int num1 = 0, num2 = 0;
	bool flag = false;
	linkList list;
	do {
		menu();
		cout << "Enter the Operation: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter First Number: ";
			cin >> num1;
			cout << "Enter Second Number: ";
			cin >> num2;

			cout << "Result: " << multiplyNumbers(num1, num2) << endl;
			break;
		case 2:
			cout << "Enter First Number: ";
			cin >> num1;
			cout << "Enter Second Number: ";
			cin >> num2;

			cout << "Result: " << power(num1, num2) << endl;
			break;
		case 3:
			cout << "Enter First Number: ";
			cin >> num1;
			cout << "Result: " << factorial(num1) << endl;
			break;
		case 4:
			cout << "Enter First Number: ";
			cin >> num1;
			cout << "Result: " << fibonacci(num1) << endl;
			break;
		case 5:
			cout << "Enter the Value to Find: ";
			cin >> num1;

			flag = searchElement(list.head, num1);

			if (!flag)
				cout << "Not Found.\n";
			else
				cout << "Found.\n";
			break;
		case 6:
			cout << "1. Insert at Head\n2. Insert at Tail\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter the Value: ";
				cin >> num1;
				list.insertAtBegin(num1);
				break;
			case 2:
				cout << "Enter the Value: ";
				cin >> num1;
				insertAtTail(list.tail, num1);
				break;
			default:
				cout << "Invalid Operation\n";
				break;
			}
			break;
		case 7:
			cout << "Maximum value: " << max(list.head) << endl;
			break;
		case 8:
			displayReverse(list.head);
			cout << endl;
			break;
		case 9:
			cout << "\n*****PROGRAM ENDED*****\n";
			return 0;
		default:
			cout << "invalid Operation.\n";
			break;
		}
		cout << "Enter Y to Repeat: ";
		cin >> rep;
		system("cls");
	} while (rep == 'Y' || rep == 'y');

	return 0;
}

int multiplyNumbers(int a, int b)
{
	if (a > b) {
		if (a == 0)
			return 0;
		else
			return (a + multiplyNumbers((a - 1), b));
	}

	if (a < b) {
		if (b == 0)
			return 0;
		else
			return (b + multiplyNumbers(a, b - 1));
	}
}

int power(int a, int b)
{
	if (b == 1) {
		return a;
	}
	else
		return (a * power(a, b - 1));
}

int factorial(int a)
{
	if (a == 1)
		return a;
	
	return(a * factorial(a - 1));
}

int fibonacci(int num)
{
	if (num <= 1)
		return num;
	return (fibonacci(num - 1), fibonacci(num - 2));
}

bool searchElement(Node* node, int num)
{
	if (node == NULL)
		return false;
	else {
		if (node->data == num)
			return true;
		return(searchElement(node->next, num));
	}
	
}

int max(Node* node)
{
	static int maximum = 0;
	if (node == NULL)
		return maximum;
	else {
		if (node->data > maximum) {
			maximum = node->data;
		}
		return max(node->next);
	}
}

void insertAtTail(Node* node, int value)
{
	if (node->next == NULL) {
		Node* temp = new Node;
		temp->data = value;
		node->next = temp;
	}

	else
		insertAtTail(node->next, value);
}

void displayReverse(Node* node)
{
	if (node == NULL) 
		return;

	displayReverse(node->next);
	cout << node->data << "->";
}

