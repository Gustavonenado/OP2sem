/// Відповідно до виразу, що читається з текстового файлу, 
/// побудувати дерево-формулу та обчислити значення цієї формули.

#include "Functions.h"
#include "Node.h"
using namespace std;

int main()
{

	ifstream inFile("text.txt");                        
	if (!inFile.is_open()) {
		cout << "Cant open file!\n\n";
		return -1;
	}
	vector<string> mass = readFile(inFile);             
	inFile.close();
	ofstream outFile("result.txt");                    

	if (mass[0] == "") {
		cout << "Incorrect input of expression!\n\n";
		outFile << "Incorrect input of expression!";
		outFile.close();
		return -1;
	}

	outFile << "Entered expression:\n";
	outputVector(mass, outFile);

	BinaryTree Tree(mass);
	outFile << "\n\nBuilt tree-expression:\n\n";
	Tree.printTree(outFile);

	double result = Tree.countValueOfExpression();     
	outFile << "\n\nResult of calculating the expression: " << result;
	cout << "The constructed tree and the obtained result were successfully output to a file.\n\n";

	Tree.clearMemory();
	outFile.close();

	system("pause");
	return 0;
}