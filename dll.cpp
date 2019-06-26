#include <iostream>

class Node {
	int data;
public:
	Node *next,*prev;
	Node(int d) : data(d) { }
	~Node() { }
	int getData() { return data; }
}*head = NULL, *tail = NULL;

void insert() {
	int in;
	std::cout << "Enter a number : ";
	std::cin >> in;
	Node *temp = new Node(in);
	temp->next = NULL;
	temp->prev = NULL;
	if(head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

void del(int d) {
	Node *temp,*dnode;
	if(head == NULL)
		std::cout << "List is empty" << std::endl;
	else {
		temp = head;
		while(temp != NULL) {
			if(temp->getData() == d) {
				dnode = temp;
				if(temp == head && temp == tail) {
					head = NULL;
					tail = NULL;
					temp = NULL;
				} else if(temp == head){
					temp->next->prev = NULL;
					head = temp->next;
					temp = head;
				} else if(temp == tail) {
					temp->prev->next = NULL;
					tail  = temp->prev;
					temp = NULL;
				}
				else {
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
					temp = temp->next;
				}
				std::cout << "Deleting" << std::endl;
				delete dnode;
			}
			else { temp = temp->next; }
		}
	}
}

void display() {
	Node *temp = head;
	while(temp!=NULL) {
		std::cout << "-" << temp->getData() << "--" << std::endl;
		temp =  temp->next;
	}
}

int main() {
	int ch,n;
	do {
		std::cout << "1. Insert 2. Delete 3.Display 4. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> ch;
		switch(ch) {
			case 1: insert();
				break;
			case 2: std::cout << "Enter a number to delete : ";
				std::cin >> n;
				del(n);
				display();
				break;
			case 3: std::cout << "----Displaying the current list----" << std::endl;
				display();
				break;
			case 4: std::cout << "Thank you!! Bye!!!" << std::endl;
				break;
			default:
				std::cout << "Wrong entry" << std::endl;
		}
	}while(ch!=4);
	return 0;
}
