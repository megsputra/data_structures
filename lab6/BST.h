//
//  BST.h
//  Lab6_Xcode
//
//  Created by Mega Putra on 5/20/17.
//  Copyright © 2017 Mega Putra. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <cstddef>
#include <string>
#include <assert.h>

using namespace std;

template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* left;
        Node* right;
        
        Node(bstdata newdata):left(NULL), right(NULL), data(newdata) {}
    };
    
    typedef struct Node* NodePtr;
    
    NodePtr root;
    
    /**Private helper functions*/
    void insertData(NodePtr root, bstdata value);
    //private helper function for insert
    //recursively inserts a value into the BST
    
    void inOrderPrint(ostream& out, NodePtr root);
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest
    
    void preOrderPrint(ostream& out, NodePtr root);
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order
    
    void postOrderPrint(ostream& out, NodePtr root);
    //private helper function for postOrderPrint
    //recursively prints tree values in post order
    
    void makeCopy(NodePtr copy);
    //recursive helper function to the copy constructor
    
    void freeNode(NodePtr root);
    //private helper function for the destructor
    //recursively frees the memory in the BST
    
    bool search(NodePtr root, bstdata value);
    //recursive helper function to search
    //returns whether the value is found in the tree
    
    bstdata minimum(NodePtr root);
    //recursive helper function to minimum
    //returns the minimum value in the tree
    
    bstdata maximum(NodePtr root);
    //recursive helper function to maximum
    //returns the maximum value in the tree
    
    NodePtr deleteData(NodePtr root, bstdata value);
    //recursive helper function to removeData
    //removes value from the tree
    
    void size(NodePtr root, int& size);
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size
    
    int height(NodePtr root);
    //recursive helper function to the height function
    //returns the height of the tree
    
public:
    
    /**constructors and destructor*/
    
    BST();
    //Instantiates a new BST
    
    BST(const BST &bst);
    //copy constructor
    
    ~BST();
    //deallocates the tree memory
    
    /**access functions*/
    
    bstdata minimum();
    //returns the minimum value in the BST
    //pre: !empty()
    
    bstdata maximum();
    //returns the maximum value in the BST and returns it
    //pre: !empty()
    
    bool empty();
    //determines whether the BST is empty
    
    int size();
    //returns the size of the tree
    
    bstdata getRoot();
    //returns the value stored at the root of the BST
    //pre: !empty()
    
    int height();
    //returns the height of the tree
    
    bool search(bstdata value);
    //returns whether the value is found in the tree
    //pre: !empty()
    
    /**manipulation procedures*/
    
    void insertData(bstdata value);
    //inserts a new value into the BST
    
    void removeData(bstdata value);
    //removes the specified value from the tree
    //pre: value is located in the tree
    
    /**additional functions*/
    
    void inOrderPrint(ostream& out);
    //calls the inOrderPrint function to print out the values
    //stored in the BST
    
    void preOrderPrint(ostream& out);
    //calls the reOrderPrint function to print out the values
    //stored in the BST
    
    void postOrderPrint(ostream& out);
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};

#endif /* BST_H_ */

/**Private helper functions*/
template <class bstdata>
void BST<bstdata>::insertData(NodePtr root, bstdata value)
{
    if (value == root->data)
        return;
    
    NodePtr N = new Node(value);
    if (value < root->data)
    {
        if(root->left != NULL)
            insertData(root->left, value);
        else
            root->left = N;
    }
    else if (value > root->data)
    {
        
        if(root->right !=NULL)
            insertData(root->right, value);
        else
            root->right = N;
    }
}

template <class bstdata>
void BST<bstdata>:: inOrderPrint(ostream& out, NodePtr root)
{
    if (root == NULL)
        return;
    inOrderPrint(out, root->left);
    out << root->data << " ";
    inOrderPrint(out, root->right);
}

template <class bstdata>
void BST<bstdata>:: preOrderPrint(ostream& out, NodePtr root)
{
    if (root == NULL)
        return;
    out << root->data << " ";
    preOrderPrint(out, root->left);
    preOrderPrint(out, root->right);
}

template <class bstdata>
void BST<bstdata>:: postOrderPrint(ostream& out, NodePtr root)
{
    
    if (root == NULL)
        return;
    postOrderPrint(out, root->left);
    postOrderPrint(out, root->right);
    out << root->data << " ";
}

template <class bstdata>
void BST<bstdata>::makeCopy(NodePtr copy)
{
    if (copy)
    {
        insertData(copy->data);
        makeCopy(copy->left);
        makeCopy(copy->right);
    }
}

template <class bstdata>
void BST<bstdata>::freeNode(NodePtr root)
{
    if (root == NULL)
        return;
    freeNode(root->left);
    freeNode(root->right);
    delete root;
}

template <class bstdata>
bool BST<bstdata>::search(NodePtr root, bstdata value)
{
    if(value == root->data)
        return true;
    if(value < root->data)
    {
        if (root->left == NULL)
            return false;
        else
            return search(root->left, value);
    }
    else
    {
        if (root->right == NULL)
            return false;
        else
            return search(root->right, value);
    }
    return false;
}

template<typename bstdata>
bstdata BST<bstdata>::minimum(NodePtr root)
{
    assert(!empty());
    if (root->left == NULL)
        return root->data;
    else
        return minimum(root->left);
}

template <class bstdata>
bstdata BST<bstdata>:: maximum(NodePtr root)
{
    assert(!empty());
    if (root->right !=NULL)
        return maximum(root->right);
    else
        return root->data;
}

template<class bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::deleteData(NodePtr root, bstdata value)
{
    if(root == NULL)
        return root;
    else if (value < root->data)
        root->left = deleteData(root->left, value);
    else if (value > root->data)
        root->right = deleteData(root->right, value);
    else
    {
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        } else if (root->right == NULL){
            NodePtr temp = root;
            root = root->left;
            delete temp;
        } else if (root->left == NULL){
            NodePtr temp = root;
            root = root->right;
            delete temp;
        } else {
            root->data = minimum(root->right);
            root->right = deleteData(root->right, minimum(root->right));
        }
    }
    return root;
}

template <class bstdata>
void BST<bstdata>:: size(NodePtr root, int& size)
{
    if (root == NULL)
        return;
    size(root->left, size+1);
    size(root->right, size+1);
    size++;
}
//    //recursive helper function to the size function
//    //calculates the size of the tree
//    //stores the result in size


template<class bstdata>
int BST<bstdata>::height(NodePtr root)
{
    if(root == NULL){
        return -1;
    } else {
        return (max(height(root->left), height(root->right)) + 1);
    }
}

/**constructors and destructor*/

template <class bstdata>
BST<bstdata>::BST()
{
    root = NULL;
}

template <class bstdata>
BST<bstdata>::BST(const BST &bst)
{
    root = NULL;
    makeCopy(bst.root);
}

template <class bstdata>
BST<bstdata>::~BST()
{
    freeNode(root);
}

template <class bstdata>
bstdata BST<bstdata>::minimum()
{
    assert(!empty());
    return minimum(root);
}
template <class bstdata>
bstdata BST<bstdata>::maximum()
{
    assert(!empty());
    return maximum(root);
}

template <class bstdata>
bool BST<bstdata>::empty()
{
    return (root == NULL);
}


//template <class bstdata>
//int BST<bstdata>:: size()
//{
//    if(root == NULL)
//        return 0;
//    size(root, size);
//}

template<typename bstdata>
bstdata BST<bstdata>::getRoot()
{
    assert(!empty());
    return root->data;
}

template<typename bstdata>
int BST<bstdata>::height()
{
    assert(!empty());
    return height(root);
}

template <class bstdata>
bool BST<bstdata>::search(bstdata value)
{
    assert(!empty());
    if (value == root->data)
        return true;
    else
        return search(root, value);
}

template <class bstdata>
void BST<bstdata>::insertData(bstdata value)
{
    if (root == NULL)
        root = new Node(value);
    else
        insertData(root, value);
}

template<class bstdata>
void BST<bstdata>::removeData(bstdata value)
{
    assert(!empty());
    assert(search(value));
    root = deleteData(root, value);
}

/**additional functions*/

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out)
{
    inOrderPrint(out, root);
}
template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out)
{
    preOrderPrint(out, root);
}
template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out)
{
    postOrderPrint(out, root);
}
