/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Adrian Bogatu
  * Echipa SD, 2013
  *
  * Modificari: Cosmin Petrisor
  * Echipa SD, 2015
  *
  * License: LGPL
  */

#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

template <typename T>
class BinaryTree
{
private:

    T *pData;

    BinaryTree<T> *leftNode;
    BinaryTree<T> *rightNode;

public:

    //constructor TODO 1.1
    BinaryTree() {
	    pData = NULL;
	    leftNode = NULL;
	    rightNode = NULL;
    }

    //destructor TODO 1.1
    ~BinaryTree() {
	    if( leftNode != NULL ){
		    delete leftNode;
	    }
	    if( rightNode != NULL ){
		    delete rightNode;
	    }
	    if( pData != NULL ) {
		    delete pData;
	    }
    }

    // Inspect if the current node has data. TODO 1.2
    bool hasData() {
	    if( pData == NULL ){
		    return false;
	    }
	    return true;
    }

    // Set data for current node. TODO 1.2
    void setData(T data) {
	    pData = new T;
	    *pData = data;
    }

    // Get current node's data. TODO 1.2
    T getData() {
	    if( pData != NULL ){
		    return *pData;
	    }

	    T junk;
	    return junk;
    }

    // Set left subtree. TODO 1.2
    void setLeftSubtree(BinaryTree<T> *node) {
	    leftNode = node;
    }

    // Get the left subtree. TODO 1.2
    BinaryTree<T> *getLeftSubtree() {
	    if( leftNode != NULL ) {
		    return leftNode;
	    }
	    return NULL;
    }

    // Set right subtree. TODO 1.2
    void setRightSubtree(BinaryTree<T> *node) {
	    rightNode = node;
    }

    // Get the right subtree. TODO 1.2
    BinaryTree<T> *getRightSubtree() {
	    if( rightNode != NULL ) {
		    return rightNode;
	    }
	    return NULL;
    }

    // Insert data recursively randomly where it is possible. TODO 1.3
    void insert(T data) {
	    srand(time(NULL));
	    int paritate = rand() % 2;

	    if( paritate == 0 ){
		    if ( leftNode == NULL ){
			    leftNode = new BinaryTree<T>;
			    leftNode->setData(data);
		    }
		    else {
			    leftNode->insert(data);
		    }
	    } else {
		    if ( rightNode == NULL ) {
			    rightNode = new BinaryTree<T>;
			    rightNode->setData(data);
		    } else {
			    rightNode->insert(data);
		    }
	    }
    }

    // Insert data into left subtree. TODO 1.3
    void insertLeft(T data) {
	    if(leftNode != NULL){
		    leftNode->setData(data);
	    } else {
		    leftNode = new BinaryTree<T>;
		    leftNode->setData(data);
	    }
    }

    // Insert data into right subtree. TODO 1.3
    void insertRight(T data) {
	    if(rightNode != NULL){
		    rightNode->setData(data);
	    } else {
		    rightNode = new BinaryTree<T>;
		    rightNode->setData(data);
	    }
    }
    // Display the binary tree to output. TODO 2.1
    void displayTree(int indentLevel) {
	    for (int i = 0; i < indentLevel; ++i)
	    	cout << '\t';
	   cout << pData << " ";
	   if(leftNode != NULL){
		   leftNode->displayTree(indentLevel + 1);
	   }
	   if(rightNode != NULL){
		   rightNode->displayTree(indentLevel + 1);
	   }
	   return 0;
    }

    // Return the height of the binary tree. TODO 2.2
    int getTreeHeight() {
	    int cntl = 0, cntr = 0;
	    if(leftNode == NULL && rightNode == NULL){
	    		return 1;
	    } else {
		    if(leftNode != NULL){
			    cntl = leftNode->getTreeHeight();
		    }
		    if(rightNode != NULL){
			    cntr = rightNode->getTreeHeight();
		    }
		}
	    return 1 + max(cntl, cntr);
    }

    // Return the number of nodes in the tree. TODO 2.3
    int getNumNodes() {
	    int cnt = 0;
	    actualGetNumNodes(cnt);
	    return cnt;
    }
    int actualGetNumNodes(int& cnt) {
	    cnt++;
	    if(rightNode != NULL){
		    rightNode->actualGetNumNodes(cnt);
	    }
	    if(leftNode != NULL){
		    leftNode->actualGetNumNodes(cnt);
	    }

	    return cnt;
    }
};

#endif // __BINARY_TREE_H
