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
        else if (element > parent->info) // id the value in the data fiels of the newnode is greater than that of the parent
        {
            parent->rightchild = newNode; // make the right child of the parent point to the newnode

        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        // this function searches the currentNode pf the specified Node as well as the current node of its parent
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL)&& (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode == currentNode->rightchild;

        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << "";
            inorder(ptr->rightchild);
        }

    }

    void preorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;

        }
        if (ptr != NULL)
        {
            cout << ptr->info << "";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr)
    {
        // performs the postorder traversal of the tree
        if ( ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << "";
        }
    }


    
};

int main()
{
    BinaryTree obj;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement Insert operation" << endl;
        cout << "2. Perform Inorder traversal" << endl;
        cout << "3. Perform Preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word : ";
            string word;
            cin >> word;
            obj.Insert(word);
            break;
        }
        case '2':
        {
            obj.inorder(obj.ROOT);
            break;
        }
        case '3':
        {
            obj.preorder(obj.ROOT);
            break;
        }
        case '4' :
        {
            obj.postorder(obj.ROOT);
            break;
        }
        case '5' :
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}