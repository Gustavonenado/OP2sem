#include "Header.h"
using namespace std;

Function_Sinus Input_Object()
{
	float A, B;
	/*Function_Sinus Object;
	cout << "Введiть a: "; cin >> A;
	Object.SetA(A);
	cout << "Введiть b: "; cin >> B;
	Object.SetB(B);*/
	cout << "Enter a: "; cin >> A;
	cout << "Enter b: "; cin >> B;
	Function_Sinus Object(A, B);
	return Object;
}

vector <Function_Sinus> Create_Array()
{
	char flag = 'Y';
	vector <Function_Sinus> Array;
	cout << "\n--- Start entering function arguments sin(ax + b) ---\n\n";
	while (flag == 'Y' || flag == 'y')
	{
		Function_Sinus Element = Input_Object();
		Array.push_back(Element);
		cout << "Do you want to continue the Entering? (Y/N) "; cin >> flag;
	}
	return Array;
}

void Output_Array(vector <Function_Sinus> Array)
{
	printf("\n--- List of functions with entered arguments ---\n\n");
	for (unsigned int i = 0; i < Array.size(); ++i)
	{
		cout << setw(2) << i + 1 << ": sin(" << Array[i].GetA() << "x + " << Array[i].GetB() << ")\n";
	}
}

void Output_Sinuses(vector <Function_Sinus> Array, float x)
{
	printf("\n--- List of sin values ​​at given point ---\n");
	for (unsigned int i = 0; i < Array.size(); ++i)
	{
		if (i % 2 == 0)
			cout << "\n" << setw(2) << i + 1 << ": sin = " << setw(7) << setprecision(4) << Array[i].GetSin(x);
		else
			cout << setw(20) << i + 1 << ": sin = " << setw(7) << setprecision(4) << Array[i].GetSin(x);
	}
	cout << endl;
}

int Find_Max_Value(vector <Function_Sinus> Array, float X)
{
	int i_max = 0;
	for (unsigned int i = 1; i < Array.size(); ++i)
	{
		if (Array[i].GetSin(X) > Array[i_max].GetSin(X))
		{
			i_max = i;
		}
	}
	return i_max;
}