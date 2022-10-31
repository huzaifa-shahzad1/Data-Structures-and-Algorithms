#include <iostream>
using namespace std;

class Stack {
	int capacity_;
	int top_;
	int* arr;
public:
	Stack() {
		cout << "Enter the Capacity of Stack: ";
		cin >> capacity_;
		top_ = -1;
		arr = new int[capacity_];
	}

	bool isEmpty() {
		return (top_ < 0) ? true : false;
	}

	bool isFull() {
		return (top_ >= (capacity_-1)) ? true : false;
	}

	void push() {
		if (top_>=(capacity_-1)) {
			cout << "Stack Capacity is Full.\n";
			return;
		}
		int value = 0;
		cout << "Enter the Value to Push: ";
		cin >> value;
		top_++;
		arr[top_] = value;
		cout << "[" << value << "] pushed into the Stack.\n";
	}

	void pop() {
		if (top_ < 0) {
			cout << "Stack is Empty.\n";
			return;
		}

		cout << "[" << arr[top_--] << "] popped out of the Stack.\n";
		capacity_--;
	}

	void peek() {
		if (top_ < 0) {
			cout << "Stack is Empty.\n";
			return;
		}

		cout << "[" << arr[top_] << "] is at TOP of the Stack.\n";
	}

	void display() {
		if (isEmpty()) {
			cout << "Stack is Empty.\n";
			return;
		}
		cout << "Elements of the Stack are: ";
		for (int i = 0; i < capacity_; i++) {
				cout << arr[i] << " -> ";
		}
	}
	
};

int main() {
	Stack s;

	s.push();
	s.push();
	s.push();
	s.push();
	s.pop();
	s.display();
}