#include<bits/stcc++.h>
using namespace std;

struct Node{
	int data;
	Node *prev;
	Node *next;
};

struct Node* head = NULL;

void insert(int newdata){
	Node* newNode = new Node();
	newNode->data = newdata;
	newNode->next =
}
