#pragma once

#include "Node.h"
#include "BinaryTree.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

bool isOperation(string symb);
vector<string> readFile(ifstream& file);
void outputVector(const vector<string>& vect, ofstream& out);