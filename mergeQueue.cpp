#include "eventQueue.h"

Node* merge(Node *q1, Node *q2) {
	Node *mergeQ, *mergeHead = NULL, *temp;
	while(q1 != NULL && q2 != NULL) {
			mergeQ = new Node;
			if(q1 -> event.time > q2 -> event.time) {
				mergeQ -> event = q2 -> event;
				mergeQ -> next = NULL;
				q2 = q2 -> next;
			}
			else {
				mergeQ -> event = q1 -> event;
				mergeQ -> next = NULL;
				q1 = q1 -> next;
			}

			if(mergeHead == NULL) {
				mergeHead = mergeQ;
				temp = mergeQ;
			}
			else {
				temp -> next = mergeQ;
				temp = temp -> next;
			}
	}

	while( q1 != NULL) {

		mergeQ = new Node;
		mergeQ -> event = q1 -> event;
		mergeQ -> next = NULL;
		if(mergeHead == NULL) {
			mergeHead = mergeQ;
			temp = mergeQ;
		}
		else {
			temp -> next = mergeQ;
			temp = temp -> next;
		}
		q1 = q1 -> next;
	}

	while( q2 != NULL) {
		
		mergeQ = new Node;
		mergeQ -> event = q2 -> event;
		mergeQ -> next = NULL;
		if(mergeHead == NULL) {
			mergeHead = mergeQ;
			temp = mergeQ;
		}
		else {
			temp -> next = mergeQ;
			temp = temp -> next;
		}
		q2 = q2 -> next;
	}
	return mergeHead;
} 

int main () {
	int ch,n=2;
	Node *p[2] = {NULL, NULL}, *mergeQueueHead;

	std::cout<< ("Enter a list or queue\n");
	std::cin >> ch;

	switch(ch){
		case 1: p[0] = listOptions();
				break;
		case 2: 
				while(n--) {
					std::cout<< ("---------------%d and %d\n", n, -(n-1));
					p[-(n-1)] = queueOptions();
				}
				
				break;
		default : std::cout<< ("Wrong entry \n");
	}

	std::cout<< ("----Merging----\n");

	display(p[0]);
	display(p[1]);
	mergeQueueHead = merge(p[0], p[1]);
	std::cout<< ("----After Merge----\n");
	display(mergeQueueHead);

	std::cout<< ("Good Bye!!\n");
	return 0;
}
