// LinkedList.c: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct node {
	int val;
	struct node * next;
}node_t;

//Display the list
void Display(node_t * head) {
	node_t * current = head;
	while (current != NULL) {
		printf(" %d ->", current->val);
		current = current->next;
	}
	printf(" NULL\n");
}

//Hey! Take of this
node_t * CreateList() {
	node_t * head = malloc(sizeof(node_t));
	head->next = NULL;
	head->val =-1;
	return head;
}

//Adding an item to the end of the list
void Push(node_t * head, int x) {
	node_t * current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current->next->val = x;
	current->next->next = NULL;
}

//Add beginning of the list
void AddBeginning(node_t * head, int x) {
	node_t * newNode = malloc(sizeof(node_t));
	newNode->val = x;
	node_t * temp = head;
	if (temp->next != NULL) {
		temp = temp->next;
		head->next = newNode;
		newNode->next = temp;
	}
	else {
		head->next = newNode;
		newNode->next = NULL;
	}
	
}

//Using double pointer
void AddBeginning_Alternative(node_t ** head, int val) {
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

//Pop first item
int Pop(node_t * head) {
	int value = -1;

	if (head->next == NULL) {
		free(head);
		return value;
	}

	node_t * nextNode = head;
	nextNode = nextNode->next;
	value = nextNode->val;

	if (nextNode->next == NULL) {	
		free(nextNode);
		head->next = NULL;
		
	}
	else
	{
		head->next = nextNode->next;
		free(nextNode);
	}
	return value;
}

//Remove last item
int RemoveLast(node_t * head) {
	int value = -1;
	if (head->next == NULL) {
		free(head);
		return value;
	}

	node_t * current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	value = current->next->val;
	free(current->next);
	current->next = NULL;
	return value;

}

//Remove by index
int RemoveByIndex(node_t * head, int index) {

	int value = -1;
	if (index == 0) {
		return Pop(head);
	}
	node_t * current = head;
	node_t * tempNode = NULL;
	for (int i = 0; i < index - 1 ; i++) {
		if (current->next == NULL)
			return -1;
		current = current->next;
	}

	tempNode = current->next;
	value = tempNode->val;
	current->next = tempNode->next;
	free(tempNode);
	//free(current);
	return value;

}

void RemoveByValue(node_t * head, int value) {

	if (value == -1) {
		Pop(head);
	}
	node_t * current = head;
	node_t * tempNode = NULL;
	while (current->next != NULL) {
		tempNode = current->next;
		if (tempNode->val == value) {
			current->next = tempNode->next;
			free(tempNode);
			break;
		}
		current = tempNode;
	}
	//Hmm.
	free(tempNode);
}

int main()
{
	node_t * head = CreateList();
	for (int i = 1; i < 5; i++) {
		Push(head, i);
	}
	Display(head);
	AddBeginning(head, 5);
	Display(head);
	RemoveLast(head);
	Display(head);
	/*
	node_t * head2 = CreateList();
	Push(head2, 23);
	Display(head2);
	*/
	getchar();
    return 0;
}

