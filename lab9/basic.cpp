/**
  * Autor: Cosmin Petrisor
  * Echipa SD, 2015
  *
  * License: LGPL
  */

#include <iostream>
#include <cassert>

#include "BinaryTree.h"

using namespace std;

// Test constructor, destructor, setData, hasData, setLeftSubtree,
// getLeftSubtree, setRightSubtree, getRightSubtree, insertLeft, insertRight,
// insert
void test_ex1(void)
{
	cout<<"\n========== Testing ex 1 ==========\n\n";

	BinaryTree<int> *root = new BinaryTree<int>();

	assert(root->hasData() == false);
	assert(root->getLeftSubtree() == NULL);
	assert(root->getRightSubtree() == NULL);

	cout<<"Constructor test .................................... passed.\n";

	root->setData(5);
	assert(root->hasData() == true);

	cout<<"Set data test ....................................... passed.\n";

	root->setLeftSubtree(new BinaryTree<int>());
	root->setRightSubtree(new BinaryTree<int>());

	assert(root->getLeftSubtree() != NULL &&
	       root->getRightSubtree() != NULL);

	cout<<"Set subtrees test ................................... passed.\n";

	assert(root->getLeftSubtree()->hasData() == false);
	root->insertLeft(6);
	assert(root->getLeftSubtree()->hasData() == true);

	assert(root->getRightSubtree()->hasData() == false);
	root->insertRight(8);
	assert(root->getRightSubtree()->hasData() == true);

	cout<<"Insert left and right test .......................... passed.\n";

	root->insert(4);

	BinaryTree<int> *node1 = root->getLeftSubtree()->getLeftSubtree();
	BinaryTree<int> *node2 = root->getLeftSubtree()->getRightSubtree();
	BinaryTree<int> *node3 = root->getRightSubtree()->getLeftSubtree();
	BinaryTree<int> *node4 = root->getRightSubtree()->getRightSubtree();

	assert(node1 || node2 || node3 || node4);

	cout<<"Insert test ......................................... passed.\n";

	delete root;
}

// Test getTreeHeight, getNumNodes (you have to test displayTree by yourself)
void test_ex2(void)
{
	cout<<"\n========== Testing ex 2 ==========\n\n";

	BinaryTree<int> *root = new BinaryTree<int>();

	assert(root->getTreeHeight() == 1);

	root->setData(5);
	root->insert(1);
	assert(root->getTreeHeight() == 2);

	root->insert(2);
	root->insert(3);
	assert(root->getTreeHeight() > 2);

	cout<<"Tree height test .................................... passed.\n";

	delete root;

	root = new BinaryTree<int>();

	assert(root->getNumNodes() == 1);

	root->setData(5);
	root->insert(1);
	assert(root->getNumNodes() == 2);

	root->insert(2);
	root->insert(3);
	assert(root->getNumNodes() == 4);

	cout<<"Tree number of nodes test ........................... passed.\n";

	delete root;
}

int main(void)
{
	test_ex1();
	test_ex2();

	return 0;
}
