#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
    }

    Node(int val, Node* left, Node* right) 
    {
        this->data = val;
        this->left = left;
        this->right = right;
    }
    ~Node(){
        free(this->left);
        free(this->right);
    }
    
};
namespace ariel{
class Tree{

private:
    Node *node;


public:
       Tree(){
            node = NULL;
            
       }
       Tree(int n){
           node->data = n;
           node->left = NULL;
           node->right = NULL;
       }
       ~Tree();
       void DeleteRecursive(Node* node);
       void insert(int num);
       Node* insert(int num,Node* node);
       Node* remove(Node *node, int data);
       Node* deleteNode( Node* node, int key);
       Node* minValueNode(Node* node);
       Node* FindMin(Node* node);
       void Inorder(Node *node);
       void remove(int i);
       int size();
       int size(Node* node);
       bool contains(Node* node,int i);
       bool contains(int num);
       int root();
       int parent(int i);
       int parent(Node* node,int i);
       int left(int i);
       int left(Node* node,int i);
       int right(int i);
       int right(Node* node,int i);
       void print();
       void print(Node* node,int a);
       Node* search(Node* node, int key);
};
}