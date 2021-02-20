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
        head->next = head;
        return;
    }
    
    Node *ptr = head;
    Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = ptr;
}

void printLL(){
    if(head == NULL)
        cout << "Linked list is empty";
        
    Node *ptr = head;
     while(ptr->next != head)
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
    Node* ptr2 = head;
    
    while(ptr->next != head){
        ptr = ptr->next;
    }
    
    head = ptr2->next;
    head->prev = ptr;
    ptr->next = head;
    ptr2->prev = NULL;
    ptr2->prev = NULL;
    free(ptr2);
}

void deletion_from_end(){
    if(head == NULL)
        cout << "Linked list is empty";
    
    Node* ptr = head;
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = head;
    head->prev = ptr->prev;
    ptr->prev = NULL;
    ptr->next = NULL;
    free(ptr);
}

void deletion_from_middle(int y)
{
    Node *ptr = head;
    int count = 0;
    
    do
    {
        if(ptr->data == y){
            count++;
            break;
        }
        
        ptr = ptr->next;
    }while(ptr != head);
    
    if(ptr == head && count != 1)
        cout<<"element not found";
    
    else if(ptr->next == head)
        deletion_from_end();
    
    else if(ptr == head && count==1)
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
    do{
        if(ptr->data == x)
        {
            return count;
            break;
        }
    
        count++;
        ptr = ptr->next;
    }while(ptr != head);
    
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
  int x = search(0);
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
  deletion_from_middle(30);
  cout<<endl<<"After deletion from middle"<<endl;
  printLL();
}