#include "event.h"


// create a simple node
class Node {
public:
	class Event event;
	class Node *next;
}*head = NULL;

static int listSize = 0;  // initialize list size

//----CREATE FUNCTION TO INSERT INTO LIST----
int insert(int lSize) {
	int t,n;
	class Node *newNode;
	
	std::cout <<("Enter time : ");
	std::cin >> t;
	char *d = new char[50];
	std::cout <<("Enter description (size limit 50 chars): ");
	std::cin >>  d;
	std::cout <<("Description you have entered is %s\n", d);

	newNode = new Node;
	newNode -> event.time = t;
	newNode -> event.description = d;
	newNode -> next = NULL;

	if (head == NULL) {
		std::cout <<("new head created\n");
		head = newNode;
		lSize++;
	}
	else {
		newNode -> next = head;
		head = newNode;
		lSize++;
	}
	return (lSize);	
}

//-----CREATE FUNCTION TO DELETE FROM LIST-----
int delet(int lSize) {
	int t, flag = 0;
	std::cout <<("Enter an event time to delete : ");
	std::cin >> t;
	Node *removed;
	if (head != NULL) {
		while (head -> event.time == t) {
			removed = head;
			head = removed -> next;
			std::cout <<("Removed %s at time : %d\n", removed -> event.description, removed -> event.time);
			delete removed;
			lSize--;
			flag = 1;
			if (head == NULL)
				break;
		}
	}
	if (head != NULL) {
		Node *temp = head;
		while (temp -> next != NULL) {
			if (temp -> next -> event.time == t) {
				removed = temp -> next;
				temp -> next = removed -> next;
				std::cout <<("Removed %s at time : %d\n", removed -> event.description, removed -> event.time);
				delete removed;
				lSize--;
				flag = 1;
				continue;
			}
			temp = temp -> next;
		}
	}
	if (!flag)
		std::cout <<("Event not found\n");
	return (lSize);
}

//CREATE FUNCTION TO SEARCH AN EVENT , BY EVENT TIME -- GIVEN LIST HEAD AS ARGUEMENT
void search(Node *h) {
	int t,flag = 0;
	std::cout <<("Enter an event time to search : ");
	std::cin >> t;
	Node *temp = h;
	while(temp != NULL) {
		if (temp -> event.time == t) {
			flag = 1;
			std::cout <<("Event described as %s found at %d\n",temp -> event.description, temp -> event.time);
		}
		temp = temp -> next;
	}
	if(!flag)
		std::cout <<("Event search failed to find any event at %d\n",t);
}

//CREATE FUNCTION TO DISPLAY LIST --- GIVEN LIST HEAD AS ARGUMENT 
void display(Node *h) {
	if (h == NULL) {
		std::cout <<("EMPTY!!!! \n");
		return;
	}
	Node *temp = h;
	while(temp != NULL) {		
		std::cout <<("Event time is : %d ,Event described as : %s\n", temp -> event.time, temp -> event.description);
		temp = temp -> next;
	}
}

//FUNCTION TO SORT LIST , --- GIVEN LIST HEAD AND LIST-SIZE AS ARGUMENTS
void sort(Node *h, int lSize) {
	int i,j;
	Node *temp,*swap;
	if (lSize) {
		std::cout <<("Size of the list : %d\n", listSize);
		for(i=1; i < lSize; i++) {
			temp = h;
			for(j=0; j < lSize-i; j++) {
				if(temp -> event.time > temp -> next -> event.time) {
					swap = new Node;
					swap -> event = temp -> event;
					temp -> event = temp -> next -> event;
					temp -> next -> event = swap -> event;
					temp = temp -> next;
					delete swap;
				}
				else {
					temp = temp -> next;
				}
			}
		}
	}	
}

// Function to display different list actions and perform accordingly
Node* listOptions() {
	int ch=1;
	while(ch) {
		std::cout <<("\nEnter 0.To exit 1. To insert 2. To delete 3. To search 4. To display\n");
		std::cout <<("Enter your choice : ");
		std::cin >> ch;
		//if (ch == 5)
		//	break;
		switch(ch) {
			case 0: std::cout <<("Exiting_-_-_-_!\n");
					break;
			case 1: std::cout <<("Insert\n");
				listSize = insert(listSize);
				break;
			case 2: std::cout <<("delete\n");
				listSize = delet(listSize);
				break;
			case 3: std::cout <<("search\n");
				search(head);
				break;
			case 4: std::cout <<("Displaying\n");
				display(head);
				break;
			default : std::cout <<("Wrong entry\n");
		}
	}
	return head;
}

/*
int main() {
	listOptions();
	return 0;
}*/
