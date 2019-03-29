#include <iostream>
#include "Tree.hpp"

using namespace std;


ariel::Tree::~Tree()
{
    //call the remove function
   DeleteRecursive(node);
}


void ariel::Tree::DeleteRecursive(Node* node)
{
    if (node)
    {
        DeleteRecursive(node->left);// remove recusive on the left side
        DeleteRecursive(node->right);// remove recusive on the right side
        delete node;
    }
}



Node* ariel::Tree::insert(int num,Node* node){
    //if the tree is empty
    if(node == NULL)
    {
        node = new Node(num,NULL,NULL);//make the node
    }
    //if the palce of the node is in the right
    else if(num < node->data)
        node->left = insert(num, node->left);//recursive call on the left side of the tree
    else if(num > node->data)
        node->right = insert(num, node->right);//recursive call on the right side of the tree
    //if the number already exist
    else if(num == node->data){
        ::__throw_bad_exception();
        
    }
    return node;
}
int ariel::Tree::size(Node* node){
    //if the tree is empty
    if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));//recursive call for running on the tree
}




bool ariel::Tree::contains(Node* node,int i)
{
    //if the tree is empty
    if(node == NULL)
        return false;
    else if(i < node->data)//recursive call on the left side of the tree
        return contains(node->left, i);
    else if(i > node->data)//recursive call on the right side of the tree
        return contains(node->right, i);
    else
        return true;
    return false;
}
int ariel::Tree::root(){
    if(node == NULL)
    {
        ::__throw_bad_exception();
    }
    return node->data;
    
}
int ariel::Tree::parent(Node* node,int i){
    
    if( (node->left != NULL && node->left->data == i)
        || (node->right != NULL && node->right->data == i))
       return node->data;

    if(node->data > i)
       return parent(node->left,i);

    if(node->data < i)
       return parent(node->right,i);
    if(node->data == i || node == NULL)
    {
        ::__throw_bad_exception();
    }
    return 0;
}
void ariel::Tree::print(Node *node, int space)  
{  
    
    if (node == NULL)  
        return;
    space += 10;  
  
    
    ariel::Tree::print(node->right, space);  
  
    cout<<endl;  
    for (int i = 10; i < space; i++)  
        cout<<" ";  
    cout<<node->data<<"\n";  
  
   
    ariel::Tree::print(node->left, space);  
}  
int ariel::Tree::right(Node* node,int i)
{
    if(ariel::Tree::contains(i) == false){
        ::__throw_bad_exception();
    }
    else
    {
        Node* find;
        find = ariel::Tree::search(node,i);
        if(find->right == NULL){
           ::__throw_bad_exception();
        }
        return find->right->data;
    }

    
}
int ariel::Tree::left(Node* node,int i)
{
    if(ariel::Tree::contains(i) == false){
        ::__throw_bad_exception();
    }
    else
    {
        Node* find;
        find = ariel::Tree::search(node,i);
        if(find->left == NULL){
           ::__throw_bad_exception();
        }
        return find->left->data;
        
    }
    
}
Node* ariel::Tree::search(Node* node, int key) 
{ 
    // Base Cases: node is null or key is present at node 
    if (node == NULL || node->data == key) 
       return node; 
     
    // Key is greater than node's key 
    if (node->data < key) 
       return search(node->right, key); 
  
    // Key is smaller than node's key 
    return search(node->left, key); 
} 
void ariel::Tree::remove (int i){
        if (node==NULL)
        {
             ::__throw_bad_exception();
        }
        else if (contains(i)==false)
        {
             ::__throw_bad_exception ();
        }
        else
        {
            Node *temp = node;
            node = deleteNode(temp,i);
            
        }
        
    }


 Node* ariel::Tree::deleteNode( Node* node, int key) 
{ 
    // base case 
    if (node == NULL) 
    return node; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < node->data) 
        node->left = deleteNode(node->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > node->data) 
        node->right = deleteNode(node->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (node->left == NULL) 
        { 
            Node *temp = node->right; 
            free(node); 
            return temp; 
        } 
        else if (node->right == NULL) 
        { 
            Node *temp = node->left; 
            free(node); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* temp = minValueNode(node->right); 
  
        // Copy the inorder successor's content to this node 
        node->data = temp->data; 
  
        // Delete the inorder successor 
        node->right = deleteNode(node->right, temp->data); 
    } 
    return node; 
} 
Node* ariel::Tree::minValueNode(Node* node) 
{ 
     Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
}




///////////////////////////////////////////
void ariel::Tree::print()  
{  
     ariel::Tree::print(node, 0);  
}  
void ariel::Tree::insert(int x)
{
        node = insert(x, node);
        
}
int ariel::Tree::size()
{
    int size = ariel::Tree::size(node);
    return size;
}

bool ariel::Tree::contains(int num)
{
    bool ans = contains(node,num);
    return ans;
}
int ariel::Tree::parent(int i)
{
    int data = parent(node,i);
    return data;
}

int ariel::Tree::right(int i)
{
    int data = right(node,i);
    return data;
}
int ariel::Tree::left(int i)
{
    int data = left(node,i);
    return data;
}

