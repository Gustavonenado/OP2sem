#pragma once
#include "Node.h"
#include <vector>
#include <fstream>
using namespace std;

class BinaryTree
{
	static Node* createTree(const vector<string>& symbs, int& index);
	static void printTree(Node* node, int level, ofstream& out);
	static void clearMemory(Node* node);
	static double count(Node* node);

public:
	Node* Root;

	BinaryTree(const vector<string>& symbs);

	double countValueOfExpression();
	void printTree(ofstream& out);
	void clearMemory();
};
