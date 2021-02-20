#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

struct Node* head = NULL;

void addNode(int data){
    if(head == NULL)
    {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = data;
        return;
    }
    
    Node *ptr = head;
    Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    newNode->prev = ptr;
}

void printLL(){
    if(head == NULL)
        cout << "Linked list is empty";
        
    Node *ptr = head;
     while(ptr->next != NULL)
    {
        cout<< ptr -> data <<"->";
        ptr = ptr->next;
    }
    cout<< ptr -> data;
}

void deletion_from_start(){
    if(head == NULL)
        cout << "Linked list is empty";
        
    Node* ptr = head;
    head = ptr->next;
    head->prev = NULL;
    ptr->next = NULL;
    free(ptr);
}

void deletion_from_end(){
    if(head == NULL)
        cout << "Linked list is empty";
    
    Node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    free(ptr);
}

void deletion_from_middle(int y)
{
    Node *ptr = head;
    
    while(ptr != NULL)
    {
        if(ptr->data == y)
            break;
        
        ptr = ptr->next;
    }
    if(ptr == NULL)
        cout<<"element not found";
    
    else if(ptr->next == NULL)
        deletion_from_end();
    
    else if(ptr == head)
        deletion_from_start();
        
    else{
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        ptr->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }
}

int search(int x){
    if(head == NULL)
        cout << "Linked list is empty";
    
    Node* ptr = head;
    int count =1;
    while(ptr!= NULL){
        if(ptr->data == x)
        {
            return count;
            break;
        }
    
        ptr = ptr->next;
        count++;
    }
    return 0;
}

int main(){
  
  addNode(10);
  addNode(20);
  addNode(30);
  addNode(50);
  addNode(80);
  
  cout<<"Original list"<<endl;
  printLL();
  int x = search(80);
  if(x == 0)
    cout<<endl<<endl<<"Element not found"<<endl<<endl;
  else
    cout<<endl<<endl<<"Element 80 found at position "<<x<<endl<<endl;
    
  deletion_from_start();
  cout<<"After deletion from the start"<<endl;
  printLL();
  deletion_from_end();
  cout<<endl<<"After deletion from the end"<<endl;
  printLL();
  deletion_from_middle(50);
  cout<<endl<<"After deletion from middle"<<endl;
  printLL();
}