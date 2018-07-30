#pragma once

void Display(node_t * head);

node_t * CreateList();

void Push(node_t * head, int x);

void AddBeginning(node_t * head, int x);

void AddBeginning_Alternative(node_t ** head, int val);

int Pop(node_t * head);

int RemoveLast(node_t * head);

int RemoveByIndex(node_t * head, int index);

void RemoveByValue(node_t * head, int value);
