				/*****************PROGRAM DESCRIPTION*****************/
/*
	This program includes the basic funcionality on the link list like
	1. Insertion (at Start, after a Specific Node or at End)
	2. Search 
	3. Deletion  (by Value, by Index)
	4. Updation
	5. Display of a List
	6. Length of the Link list
*/

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
Node* temp;
class linkList {
	Node* first;
	Node* last;
public:
	linkList() {
		first = NULL;
		last = NULL;
	}

	//	FUNCTION TO INSERT NODE AT START
	void insertAtHead() {
		int value = 0;
		temp = new Node;
		cout << "Enter the Value of the Element: ";
		cin >> value;
		temp->data = value;
		if (first == NULL) {
			first = temp;
			last = temp;
			return;
		}

		temp->next = first;
		first = temp;

		cout << "Element inserted at Head Successfully.\n";
	}

	//	FUNCTION TO INSERT NODE AT END
	void insertAtEnd() {
		int value = 0;
		temp = new Node;
		cout << "Enter the Value of the Element: ";
		cin >> value;
		temp->data = value;
		if (first == NULL) {
			first = temp;
			last = temp;
			return;
		}

		last->next = temp;
		last = temp;
		cout << "Element Inserted at Tail Successfully.\n";
	}

	//	INSERT AFTER A GIVEN NODE
	void insertAfterNode() {
		int search = 0;			//Node to Find
		int value = 0;			// For Data element of new Node
		bool flag = false;
		if (first == NULL) {
			cout << "List is Empty.\n";
			return;
		}
		cout << "Enter the Element: ";
		cin >> search;
		temp = first;
		while (temp != NULL) {
			if (temp->data == search) {
				Node* newNode = new Node;
				cout << "Enter the Value of the Element: ";
				cin >> value;
				newNode->data = value;
				newNode->next = temp->next;
				temp->next = newNode;
				cout << "Element [" << value << "] added after the Node [" << search << "].\n";
				flag = true;
			}
			temp = temp->next;
		}
		if (!flag)
			cout << "Element [" << search << "] not found in the List.\n";
	}
	//	FUNCTION TO UPDATE ANY ELEMENT OF THE LIST 
	void update() {
		int value = 0, update = 0;
		bool flag = false;
		if (first == NULL) {
			cout << "List is Empty.\n";
			return;
		}
		cout << "Enter the Value to Update: ";
		cin >> value;
		temp = first;
		while (temp != NULL) {
			if (temp->data == value)
			{
				cout << "Enter the Update Value: ";
				cin >> update;
				temp->data = update;
				flag = true;
			}
			temp = temp->next;
		}
		if (flag) {
			cout << "Value[" << value << "] update successfully to [" << update << "].\n";
			return;
		}
		cout << "Element Not Found.\n";
	}

	//	SEARCH A NODE BY VALUE
	void searhByValue() {
		int search = 0;
		int count = 0;
		bool flag = false;
		if (first == NULL) {
			cout << "List is Empty.\n";
			return;
		}

		temp = first;
		cout << "Enter the Value to Search: ";
		cin >> search;
		while (temp != NULL) {
			count++;
			if (temp->data == search)
			{
				cout << "Element [" << search << "] found at Node Number: " << count << endl;
				flag = true;
			}
			temp = temp->next;
		}
		if (!flag)
			cout << "Element [" << search << "] does not exist in the List.\n";

	}

	// FUNCTION TO DELETE ELEMENT OF A SPECIFIC KEY
	void deleteByValue() {
		temp = first;
		int key = 0;
		bool flag = false;
		Node* prev = NULL;

		//	CHECKING WEATHER THE LIST IS EMPTY
		if (temp == NULL)
		{
			cout << "list is Empty.\n";
			return;
		}
		cout << "Enter the Value of the Element to Delete: ";
		cin >> key;

		//if element to be deleted is the head of the list
		if (temp->data == key) {
			first = temp->next;
			cout << "\nelement deleted successfully.\n";
			linkList::display();
			delete temp;
			return;
		}
		//if the Element at any Index other than HEAD
		while (temp != NULL) {
			if (temp->data == key)
			{
				prev->next = temp->next;
				cout << "\nElement Deleted Successfully.\n";
				linkList::display();
				flag = true;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}

		//if the element does not exist in the List
		if (!flag)
			cout << "Element [" << key << "] does not Exist in the List.\n";
	}

	//	FUNCTION TO DELETE THE ELEMENT BY INDEX
	void deleteByIndex() {
		if (first == NULL) {
			cout << "List is Empty.\n";
			return;
		}

		temp = first;
		Node* prev = NULL;
		int index = 0;
		int count = 0;
		bool flag = false;		//To check weather the Element exists or not
		cout << "Enter the Index: ";
		cin >> index;
		while (temp != NULL) {
			count++;
			if (index == count) {
				prev->next = temp->next;
				cout << "\nElement at [" << index << "] Deleted Successfully.\n";
				linkList::display();
				flag = true;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
		//if the element does not exist in the List
		if (!flag)
			cout << "Element [" << index << "] does not Exist in the List.\n";
	}
	//	FUNCTION TO FIND THE LENGTH OF THE LINK LIST
	int lengthOfList() {
		int count = 0;
		
		if (first == NULL)
		{
			cout << "List is Empty.\n";
			return 0;
		}

		temp = first;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}

		return count;
	}

	//	SORT THE LIST IN THE ASCENDING ORDER
	void sortListInAscending() {
		if (first == NULL)
		{
			cout << "List is Empty.\n";
			return;
		}
		cout << "\n/****Unsorted List****/\n";
		linkList::display();
		temp = first;
		Node* Next = NULL;
		
		int var = 0;
		while (temp != NULL)
		{
			Next = temp->next;
			while (Next!=NULL)
			{
				if (temp->data < Next->data)
				{
					var = temp->data;
					temp->data = Next->data;
					Next->data = var;
				}
			}
			temp = temp->next;
		}
		cout << "\n/****Sorted List****/\n";
		linkList::display();
	}
	//	FUNCTION TO DISPLAY THE ELEMENTS OF THE LINK LIST
	void display() {
		if (first == NULL) {
			cout << "List is Empty.\n";
			return;
		}
		
		temp = first;
		cout << "Elements of the Link List are: ";
		while (temp != NULL)
		{
			cout << "\t" << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}

};

void menu() {
	cout << "1. Insert Element at Head\n2. Insert Element at Tail\n3. Insert Element after a Given Node\n";
	cout << "4. Update an Element\n5. Delete an Element\n6. Search an Element\n7. Display the List\n8. Find the Length of the list\n9. Sort the List\n10. Quit the Program\n";
}
void menu2() {
	cout << "1. Delete at Start\n2. Delete at Last\n3. Delete at Middle\n";
}
int main() {
	linkList list;
	int choice = 0;
	char rep = ' ';
	do {
		menu();
		cout << "Enter the Operation: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			list.insertAtHead();
			break;
		case 2:
			list.insertAtEnd();
			break;
		case 3:
			list.insertAfterNode();
			break;
		case 4:
			list.update();
			break;
		case 5:
			cout << "1. Delete By Value\n2. Delete By Index\n";
			cout << "Enter the Operation: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				list.deleteByValue();
				break;
			case 2:
				list.deleteByIndex();
				break;
			default:
				cout << "Invalid Operation.\n";
				break;
			}
			break;
		case 6:
			list.searhByValue();
			break;
		case 7:
			list.display();
			break;
		case 8:
			cout << "No. of ELements: " << list.lengthOfList();
			break;
		case 9:
			cout << "1. Ascending Order\n2. Descending Order\n";
			cout << "Enter the Operation: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				list.sortListInAscending();
				break;
			case 2:
				break;
			default:
				cout << "Invalid Operation.\n";
				break;
			}
			break;
		case 10:
			cout << "/*******PROGRAM ENDED*******/";
			return 0;
		default:
			cout << "Invalid Operation.\n";
			break;
		}
		cout << "Enter Y to repeat: ";
		cin >> rep;
		system("cls");
	} while (rep == 'y' || rep == 'Y');

	return 0;
}