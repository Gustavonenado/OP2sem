//Створити файл із переліком технічних перерв у роботі каси: час початку та час кінця
//перерви. При введенні даних перевіряти, чи не накладається нова перерва на вже наявну.
//Визначити, чи встигне касир обслужити N клієнтів (N ввести з клавіатури), які стоять у 
//черзі, якщо на одного клієнта в середньому витрачається 15 хв.

#include "header.h"
using namespace std;

int main()
{
	string path = "File.dat";                     
	ofstream FileOut(path, ios::binary);
	Period working_hours = Input_Working_Hours();   
	int num;                                        
	cout << "\nNumber of breaks: "; cin >> num;
	Output_Breaks_In_File(FileOut, Input_Breaks(num), working_hours, num);
	FileOut.close();

	ifstream FileIn(path, ios::binary);
	Output_File_In_Console(FileIn);
	FileIn.clear();
	FileIn.seekg(0, ios::beg);

	int N;                                          
	int time_for_one_customer = 15;               
	cout << "\nNumber of clients: "; cin >> N;
	if (Check_For_Serving_Customers(FileIn, working_hours, N, time_for_one_customer)) {
		cout << "\ncustomers will be served by cashier" << N << " customers for the working day\n";
	}
	else {
		cout << "\ncashier will NOT have time to serve" << N << " customers for the working day\n";
	}
	FileIn.close();
	system("pause");
	return 0;
}