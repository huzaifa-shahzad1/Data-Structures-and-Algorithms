#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node() {
		data = 0;
		next = nullptr;
		prev = nullptr;
	}
};
Node* temp = NULL;
class circularList {
private:
	Node* head;
	Node* tail;
public:
	circularList() {
		head = nullptr;
		tail = nullptr;
	}

	void insertFront() {
		int value = 0;
		temp = new Node;
		cout << "Enter the Value of the Node: ";
		cin >> value;
		temp->data = value;
		if (head == NULL) {
			head = temp;
			tail = temp;
			cout << "Value [" << value << "] inserted at Head.\n";
			return;
		}
		temp->next = head;
		temp->prev = tail;
		head = temp;
		cout << "Value [" << value << "] inserted at Head.\n";
	}

	void insertReverse() {
		int value = 0;
		temp = new Node;
		cout << "Enter the Value of the Node: ";
		cin >> value;
		temp->data = value;
		if (head == NULL) {
			head = temp;
			tail = temp;
			cout << "List is Empty so Value [" << value << "] is inserted at Head.\n";
			return;
		}
		temp->next = head;
		head->prev = temp;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		cout << "Value [" << value << "] inserted at Tail.\n";
	}
	void displayForward() {
		if (head == NULL) {
			cout << "List is Empty.\n";
			return;
		}
		temp = head;
		while (temp->next != head) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}

	void displayReverse() {
		if (head == NULL) {
			cout << "List is Empty.\n";
			return;
		}
		temp = tail;
		while (temp->prev != tail) {
			cout << temp->data << "\t";
			temp = temp->prev;
		}
		cout << endl;
	}
};


int main() {
	circularList var;

	var.insertFront();
	var.insertReverse();
	var.insertReverse();
	var.insertReverse();
	var.displayForward();

	return 0;
}