// Napon Krassner (Jett)
// CSC 2430, Homework 4
// 05-19-2015
// Due: 05-27-2015 (extended)
// Name: Test Program for Binary Search Tree - testProgBinarySearchTree.cpp
// Description: This is the main program that tests all the functions for
//				binaryTree and binarySearchTree classes as well as using the
//				visit functions that were created.
//******************************************************************************


#include <iostream>
#include "binarySearchTree.h"
#include <string>
#include <time.h>

using namespace std;

// Global var to store sum
_int64 THESUM;

// Function definition
void print(int& x);									
void sum(int& x);	
void report(bSearchTreeType<int>);
void report(bSearchTreeType<string>);

int main()											
{
	cout << "****Welcome to Binary Search Tree Exercises by Napon Krassner (Jett)****" << endl << endl;
	
	////////// Testing part (a.) ////////
	//**********Tree with int**********
	cout << "===============Testing Part (a.)===============" << endl;
	cout << "**********Testing <int> tree**********" << endl;

    bSearchTreeType<int> intTreeRoot;
		
    int num;

    cout << "Enter numbers ending with -999." << endl;
    cin >> num;

	// Test insert
    while (num != -999)
    {
        intTreeRoot.insert(num);
        cin >> num;
	}

	// Test report for int tree
	report(intTreeRoot);
	cout << endl;

	//**********End testing with int**********

	//**********Tree with string**********
	cout << "**********Testing <string> tree**********" << endl;

    bSearchTreeType<string> strTreeRoot;
		
    string str;

    cout << "---------Enter string ending with /n." << endl;
    cin >> str;

	// Test insert
    while (str != "/n")
    {
        strTreeRoot.insert(str);
        cin >> str;
	}

	// Test report for int tree
	report(strTreeRoot);
	cout << endl << endl << endl;

	//**********End testing with string**********
	//////// End testing part (a.) /////////
	
	//////// Testing part (b.) ////////
	cout << "===============Testing Part (b.)===============" << endl;
	bSearchTreeType<int> anotherIntTreeRoot;

	// use random number generator
	int seed = (unsigned) time(0);
	srand(seed);

	// populate with 1 mil 30-bit values
	for (int i = 0; i < 1000000; i++)
	{
		int x = rand() * rand();

		// store x as value in a node
		anotherIntTreeRoot.insert(x);
	}

	//********Short report********
	// Tree height
	cout << "Gigantic tree height: " << anotherIntTreeRoot.treeHeight() << endl;

	// Node count
	cout << "Gigantic tree node count: " << anotherIntTreeRoot.treeNodeCount() << endl;

	// Leaf count
	cout << "Gigantic tree leaf node count: " << anotherIntTreeRoot.treeLeavesCount() << endl;

	// Average of all values in tree
	THESUM = 0;
	anotherIntTreeRoot.inorderTraversal(sum);
	double average = (double) (THESUM / anotherIntTreeRoot.treeNodeCount());
	cout << "----The average of all values in the tree: " << average << endl;

	//////// End testing part (b.) ////////
	
    return 0;
}
// print for int tree
void print(int& x)
{
    cout << x << " ";
}

// print for str tree
void printStr(string& str)
{
	cout << str << " ";
}

// Description: Sum of all values in tree,
//				traverse with visit function that adds up the sum of all node
// Notes: use int64 to hold sum
void sum(int& x)
{
	THESUM += x;
}

// Generate report for int tree
void report(bSearchTreeType<int> aTree)
{
	// Test tree height
	cout << "----Tree Height:" << aTree.treeHeight() << endl;

	// Test count number of nodes
	cout << "----Total Nodes: " << aTree.treeNodeCount() << endl;

	// Test count number of leave nodes
	cout << "----Total Leave Nodes: " << aTree.treeLeavesCount() << endl;

	// Test preorder traversal with user-defined func as param
	cout << "----preorderTraversal: ";
	aTree.preorderTraversal(print);
	cout << endl;

	// Test inorder traversal with user-defined func as param
	cout << "----inorderTraversal: ";
	aTree.inorderTraversal(print);
	cout << endl;

	// Test postorder traversal with user-defined func as param
	cout << "----postorderTraversal: ";
	aTree.postorderTraversal(print);
	cout << endl;

	// Test delete node
	int delInfo;
	cout << "---------Enter info you wish to delete from tree: ";
	cin >> delInfo;
	aTree.deleteNode(delInfo);
	cout << "----postorderTraversal after delete: ";
	aTree.postorderTraversal(print);
	cout << endl << endl;

	// Test search
	int searchInfo;
	bool found;
	cout << "---------Enter info you wish to search in tree: ";
	cin >> searchInfo;
	found = aTree.search(searchInfo);
	cout << "----Search result: " << found << endl;
}

// Generate report for string tree
void report(bSearchTreeType<string> aTree)
{
	// Test tree height
	cout << "----Tree Height:" << aTree.treeHeight() << endl;

	// Test count number of nodes
	cout << "----Total Nodes: " << aTree.treeNodeCount() << endl;

	// Test count number of leave nodes
	cout << "----Total Leave Nodes: " << aTree.treeLeavesCount() << endl;

	// Test preorder traversal with user-defined func as param
	cout << "----preorderTraversal: ";
	aTree.preorderTraversal(printStr);
	cout << endl;

	// Test inorder traversal with user-defined func as param
	cout << "----inorderTraversal: ";
	aTree.inorderTraversal(printStr);
	cout << endl;

	// Test postorder traversal with user-defined func as param
	cout << "----postorderTraversal: ";
	aTree.postorderTraversal(printStr);
	cout << endl;

	// Test delete node
	string delInfo;
	cout << "---------Enter info you wish to delete from tree: ";
	cin >> delInfo;
	aTree.deleteNode(delInfo);
	cout << "----postorderTraversal after delete: ";
	aTree.postorderTraversal(printStr);
	cout << endl << endl;

	// Test search
	string searchInfo;
	bool found;
	cout << "---------Enter info you wish to search in tree: ";
	cin >> searchInfo;
	found = aTree.search(searchInfo);
	cout << "----Search result: " << found << endl;
}