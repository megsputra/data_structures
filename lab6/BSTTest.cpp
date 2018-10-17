//
//  BSTTest.cpp
//  Lab6_Xcode
//
//  Created by Mega Putra on 5/20/17.
//  Copyright © 2017 Mega Putra. All rights reserved.
//

#include <stdio.h>
#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
    BST <int> FirstTree;
    FirstTree.insertData(5);
    FirstTree.insertData(8);
    FirstTree.insertData(9);
    FirstTree.insertData(2);
    FirstTree.insertData(12);
    FirstTree.inOrderPrint(cout); cout << endl;
    FirstTree.preOrderPrint(cout); cout << endl;
    FirstTree.postOrderPrint(cout); cout << endl;
    //cout << FirstTree.size() << endl;
    FirstTree.removeData(2);
    FirstTree.inOrderPrint(cout); cout << endl;
    FirstTree.preOrderPrint(cout); cout << endl;
    FirstTree.postOrderPrint(cout); cout << endl;
    cout << FirstTree.height() << endl;
    BST <int> Tree(FirstTree);
    
    Tree.inOrderPrint(cout); cout << endl;
    Tree.preOrderPrint(cout); cout << endl;
    Tree.postOrderPrint(cout); cout << endl;
    
    if(Tree.empty())
        cout << "Tree is empty!" << endl;
    else
        cout << "Tree is not empty!" << endl;
    
    cout <<"min value: "<< Tree.minimum()<<endl;
    cout <<"max value: "<<Tree.maximum()<<endl;
    
    
    
    if (Tree.search(8))
        cout <<"8 is found in tree"<<endl;
    else
        cout << "NOT FOUND BRAH" << endl;
    

}
