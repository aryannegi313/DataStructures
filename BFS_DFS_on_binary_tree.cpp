#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* addNode(int data){
  Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return(newNode);
}

void BFStrav(Node *root){
    if(root == NULL)
        return;
        
    std::queue<Node*> bfsQ;
    bfsQ.push(root);
    
    while(!bfsQ.empty()){
        Node *node = bfsQ.front();
        bfsQ.pop();
        cout << node->data << " ";
        
        if(node->left)
            bfsQ.push(node->left);
        if(node->right)
            bfsQ.push(node->right);
    }
}

void DFSinorder(Node *root){
    if(root == NULL)
        return;
    
    DFSinorder(root->left);
    cout << root->data << " ";
    DFSinorder(root->right);
}

void DFSpreorder(Node *root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    DFSpreorder(root->left);
    DFSpreorder(root->right);
}

void DFSpostorder(Node *root){
    if(root == NULL)
        return;
    
    DFSpostorder(root->left);
    DFSpostorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node *root = addNode(10);
    root->left = addNode(20);
    root->right = addNode(30);
    root->left->left = addNode(40);
    root->left->right = addNode(50);
    root->right->left = addNode(60);
    root->right->right = addNode(70);
    
    cout<<"BFS traversal"<<endl;
    BFStrav(root);
    cout<< endl<<endl;
    
    cout<<"DFS traversals"<<endl;
    cout<<"inorder"<<endl;
    DFSinorder(root);
    cout << endl;
    
    cout<<"postorder"<<endl;
    DFSpostorder(root);
    cout << endl;
    
    cout<<"preorder"<<endl;
    DFSpreorder(root);
}