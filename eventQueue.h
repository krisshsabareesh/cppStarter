#include "eventList.h"

Node *qHead = NULL;

//INSERT AN ELEMENT TO THE QUEUE
void insertEvent(Event e) {
	
	Node *newNode;
	newNode = new Node;
	newNode -> event.time = e.time;
	newNode -> event.description = e.description;
	newNode -> next = NULL;

	if (qHead == NULL) {
		qHead = newNode;
	} 
	else {		
		
		if ( e.time < qHead -> event.time){
			newNode -> next = qHead;
			qHead = newNode;
		}
		else {
			  Node *temp = qHead;
			while (temp -> next != NULL) {
				// std::cout<<"--------%d-------\n", temp -> event.time;
				if (e.time < temp -> next -> event.time) {
					break;
				}
				temp = temp -> next;
			}
			if (temp -> next == NULL) {
				temp -> next = newNode;
			}
			else {
				// std::cout<<"=======%d========\n", temp -> event.time);
				newNode -> next = temp -> next;
				temp -> next = newNode;
			}

		}
	}
}


//POPS AN ELEMENT FROM QUEUE
  Node * popEvent() {
	  Node *removed = NULL;
	if (qHead != NULL) {
		removed = qHead;
		qHead = removed -> next;
	}
	return removed;
}

// FUNCTION TO CREATE AN EVENT QUEUE USING LIST HEAD 
  Node* eventQueue() {
	  Node *eventQHead = NULL, *eventQTemp, *temp;
	if (head != NULL) {
		temp = head;
		eventQHead = new Node;
		eventQHead -> event.time = temp -> event.time;
		eventQHead -> event.description = temp -> event.description;
		eventQHead -> next = NULL;
		temp = temp -> next;
		while (temp != NULL) {
			eventQTemp = new Node;
			eventQTemp -> event.time = temp -> event.time;
			eventQTemp -> event.description = temp -> event.description;
			eventQTemp -> next = eventQHead;
			eventQHead = eventQTemp;
			temp = temp -> next;
		}
	}
	sort(eventQHead,listSize);  
	// std::cout<<"-----After Sorting----\n");
	//display(eventQHead);
	return(eventQHead);
}

//FUNCTION TO LIST QUEUE OPTIONS AND PERFORM ACCORDINGLY -- returns queue head 
  Node * queueOptions() {
	int ch=1;
	  Event event;
	  Node *pop;

	//createList();

	qHead = NULL;
	 std::cout<<"\n____Event Queue____\n";
	display(qHead);

	while (ch) {
		 std::cout<<"Enter your choice to modify the queue \n0. To exit \n1. To insert \n2. To delete an event \n3. To display\n"
			"YOUR CHOICE : ";
		 std::cin >> ch ;
		switch(ch) {
			case 0:  std::cout<<"Exiting queue!!\n";
					break;

			case 1:  std::cout<<"Enter time : ";
					 std::cin >> event.time;
					event.description = new char[50];
					 std::cout<<"Enter description (size limit 50): ";
					 std::cin >> event.description;
					insertEvent(event);
					break;

			case 2: pop = popEvent();
					if (pop != NULL) {
						 std::cout<<"1 Item deleted \n";
						 std::cout<<"Item description" << pop -> event.description << "at" << pop -> event.time << std::endl;
					} else {
						 std::cout<<"Empty Queue\n";
					}
					delete pop;
					break;

			case 3: display(qHead);
					break;
			default:  std::cout<<"wrong entry --- No such option\n";
		}
	}

	return qHead;
}
