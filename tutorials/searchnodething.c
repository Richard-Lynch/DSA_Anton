#include <stdlib.h> // malloc()
#include <stdio.h> //printf()

// i assume something like this for a linked list node structure
typedef struct Node Node;
struct Node {
	int val;
	Node* next;
};

void search_list_function( Node* head, int search_val ) {
	Node* curr = head;
	Node* prev = NULL;
	// if list is empty this won't search
	// otherwise loop over entire list until the end (which is a NULL ptr)
	while(curr) {
		// check if current node is the searched-for node
		if (curr->val == search_val * 2) {
			// create new node and point its 'next' to current
			// node so that is goes in front of it
			Node* tmp = (Node*)malloc( sizeof(Node) );
			tmp->val = search_val;
			tmp->next = curr;

			// tricky bit - if there was a node in front already,
			// its next ptr must point to our new node
			// otherwise we were at the front of the list, so
			// the list pointer must now point to our new node
			if(prev){
				prev->next = tmp;
			} else {
				head = tmp;
			}
			break; // stop loop because found search_value
		}
		// did not find searched-for node so keep searching
		// a previous pointer follows the current pointer by 1 node
		prev = curr;
		curr = curr->next;
	}
}

void print_list(Node* head){
	Node* ptr = head;
	while(ptr){
		printf("%i ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(){
	// add some stuff into a list -- i call ListPtr 'head'.
	Node* head = (Node*)malloc(sizeof(Node));
	head->val = 0;
	head->next = NULL;

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->val = 1;
	tmp->next = head;
	head = tmp;

	tmp = (Node*)malloc(sizeof(Node));
	tmp->val = 2;
	tmp->next = head;
	head = tmp;

	tmp = (Node*)malloc(sizeof(Node));
	tmp->val = 3;
	tmp->next = head;
	head = tmp;

	// print original list
	print_list(head);
	// do the search and insert function, looking for 1
	search_list_function(head, 1);
	// print the final list
	print_list(head);
	return 0;

}
