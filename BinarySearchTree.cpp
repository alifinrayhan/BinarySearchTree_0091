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
    }
}