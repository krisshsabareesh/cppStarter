#include "sortedList.h"

static struct Node * qHead = NULL;

void insertEvent(struct Event e) {
	
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
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
			struct Node *temp = qHead;
			while (temp -> next != NULL) {
				printf("--------%d-------\n", temp -> event.time);
				if (e.time < temp -> next -> event.time) {
					break;
				}
				temp = temp -> next;
			}
			if (temp -> next == NULL) {
				temp -> next = newNode;
			}
			else {
				printf("=======%d========\n", temp -> event.time);
				newNode -> next = temp -> next;
				temp -> next = newNode;
			}

		}
	}
}

struct Node * popEvent() {
	struct Node *removed = NULL;
	if (qHead != NULL) {
		removed = qHead;
		qHead = removed -> next;
	}
	return removed;
}

int main () {
	int ch=1;
	struct Event event;
	struct Node *pop;

	createList();

	qHead = eventQueue();
	printf("\n____Event Queue created____\n");

	display(qHead);

	while (ch) {
		printf("Enter your choice to modify the queue \n0. To exit \n1. To insert \n2. To delete an event \n3. To display\n YOUR CHOICE : ");
		scanf("%d", &ch);
		switch(ch) {
			case 0: printf("Good Bye!!\n");
					break;

			case 1: printf("Enter time : ");
					scanf("%d", &event.time);
					event.description = (char *)malloc(50);
					printf("Enter description (size limit 50): ");
					scanf("%s", event.description);
					insertEvent(event);
					break;

			case 2: pop = popEvent();
					if (pop != NULL) {
						printf("1 Item deleted \n");
						printf("Item description %s at %d\n", pop -> event.description, pop -> event.time);
					} else {
						printf("Empty Queue\n");
					}
					free(pop);
					break;

			case 3: display(qHead);
					break;
			default: printf("wrong entry --- No such option\n");
		}
	}

	return 0;
}
