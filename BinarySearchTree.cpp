#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //Constructor for the node Class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }

};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = NULL; // initializing ROOT to NULL
    }

    void Insert(string element) // Insert a Node in binary search
    {
        Node* newNode = new Node(element, NULL, NULL); //Allocate memory for the new Node
        newNode->info = element; // assign value to the data field of the new Node
        newNode->leftchild = NULL; // make the left child of the new Node point to NULL
        newNode->rightchild = NULL; // make the right child pf the new node point to NULL

        Node* parent = NULL;
        Node* currentNode = NULL;
        search(element, parent, currentNode); // locate the node which will be the parent of the node to be inserted

        if (parent == NULL) // if parent id NULL (tree is empty)
        {
            ROOT = newNode; // mark the new node as ROOT
            return; // exit
        }

        if (element < parent->info) // if value in the data field of the newnode is lees than that of the parent
        {
            parent->leftchild = newNode; // make the left child of the parent point to the newNode
        }
    }
}