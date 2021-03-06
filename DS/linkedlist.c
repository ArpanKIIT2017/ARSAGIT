#include<stdio.h>
#include<stdlib.h>

#define CHECK_NULL(pointer) if (pointer == NULL) { printf("NULL POINTER ENCOUNTERED!!!"); exit(-1); }

// Definition of a Node
typedef struct node {
	int data;
	struct node* next;

} Node;

Node* newNode(int data) {
	// This function allocates a node in heap space and return the address
	// Reuse this function whenever you need to create a new node
	Node* node;
	// TODO: allocate a node using malloc and save the address to node -> DONE
	
	node = (Node*) malloc(sizeof(Node));
	
	node->data = data; // assign data to the newly created Node
	node->next = NULL; // initialize the next pointer with NULL

	return node;
}

Node* insertAtEnd(Node* head, int data) {
	// TODO: Insert at end and return head address
	
	CHECK_NULL(head)
	
	
	Node* temp = head; // Initialize temp with head

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode(data);
	return head;
}

Node* insertAtHead(Node* head, int data) {
	// TODO: Insert at head and return new head address
	
	CHECK_NULL(head)

	Node* newHead = newNode(data);
	newHead->next = head;

	return newHead;
}

Node* insertAfter(Node* head, Node* entry, int data) {
	// insert data after the node pointed by entry
	// Return head
	
	CHECK_NULL(head)
	CHECK_NULL(entry)

	// TODO: read this function carefully, I have implemented it for reference
	
	Node* temp = entry->next;
	entry->next = newNode(data);
	entry->next->next = temp;

	return head;
}

Node* entryAt(Node* head, int index) {
	// Return the pointer to the element a given index
	// call exit(-1) if index is not in list
	//
	// index = 0 is head of linked list
	
	CHECK_NULL(head)

	Node* entry;
	// TODO: Your code to find the required entry - DONE
	Node* temp = head;

	int i = 0;
	while (temp != NULL) {
		if (i == index) {
			break;
		}

		temp = temp->next;
		i++;
	}

	entry = temp;
	return head;
}

Node* insertAtIndex(Node* head, int index, int data) {
	// Insert at any index and return new head
	// Reuse entryAt() function
		
	CHECK_NULL(head)

	Node* entry = entryAt(head, index - 1);

	// TODO: Write your code for the same
	return insertAfter(head, entry, data);
}

/*
Node* deleteEntry(Node* head, Node* entry) {
	// delete the entry from the list
	// and return head
	
	
	CHECK_NULL(head)
	CHECK_NULL(entry)

	// TODO: Write your code for the same
	
	Node* temp = head;
	Node* prev = NULL;

	while (temp != entry) {
		prev = temp;
		temp = temp->next;
	}

	if (!prev) {
		head = entry->next;	
	} else {
		prev = entry->next;
	}
	
	free(entry);
	return head;
}*/

Node* deleteEntry(Node* head, Node* entry) {
	Node** indirect = &head;

	while ((*indirect) != entry) {
		indirect = &(*indirect)->next;
	}

	*indirect = entry->next;
	free(entry);

	return head;
}


Node* deleteFromIndex(Node* head, int index) {
	// delete from index
	// reuse the deleteEntry and entryAt
	
	CHECK_NULL(head)

	Node* entry = entryAt(head, index);
	return deleteEntry(head, entry);
}

void printList(Node* head) {
	// Code to traverse and print the list
	// Giving you as a sample on how to traverse the list
	
	CHECK_NULL(head)
	Node* temp = head; // Initialize temp with head

	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	Node* head = newNode(5); 			// 5 -> NULL
	printList(head);

	head = insertAtEnd(head, 2); 		// 5 -> 2 -> NULL
	printList(head);

	head = insertAtEnd(head, 3); 		// 5 -> 2 -> 3 -> NULL
	printList(head);

	head = insertAtHead(head, 1); 		// 1 -> 5 -> 2 -> 3 -> NULL
	printList(head);

	head = insertAtIndex(head, 1, 6); 	// 1 -> 6 -> 5 -> 2 -> 3 -> NULL
	printList(head);

	head = deleteFromIndex(head, 1); 	// 1 -> 5 -> 2 -> 3 -> NULL
	printList(head);

	return 0;
}

