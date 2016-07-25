//
// Linked List Example
// Dr Anton Gerdelan <gerdela@scss.tcd.ie>
// Trinity College Dublin, Ireland
// First v. 25 July 2016
//

/* TODO
* graphical or console display output
* add and remove and find nodes buttons
* perf and measure costs
*/

#include <stdio.h> // standard I/O functions
#include <assert.h> // force crash on major errors
#include <string.h> // strings and data copies
#include <stdbool.h> // for bool in C99
#include <stdlib.h> // memory allocation

typedef struct Node Node;
struct Node{
	char data[256];
	Node* next;
};

bool add_node(Node** list, const char* data){
	assert(data);
	Node* new_node = (Node*)malloc(sizeof(Node));
	if(!new_node){
		fprintf(stderr, "ERROR: out of memory. %s:%i\n", __FILE__, __LINE__);
		return false;
	}
	new_node->next = *list;
	strcpy(new_node->data, data);
	*list = new_node;
	return true;
}

void print_all_nodes(Node* list){
	printf("entire list data contents:\n");
	Node* ptr = list;
	while(ptr != NULL){
		printf("%s\n", ptr->data);
		ptr = ptr->next;
	}
}

int main(){
	Node* linked_list = NULL;
	if(!add_node(&linked_list, "Anton Gerdelan")){
		return 1;
	}
	if(!add_node(&linked_list, "Keith Hardwick, PhD")){
		return 1;
	}
	print_all_nodes(linked_list);
	return 0;
}
