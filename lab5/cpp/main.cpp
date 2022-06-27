/*Створити клас TIntNumber, який представляє ціле число у будь-якій системі числення і містить методи
для додавання іншого числа, порівняння чисел та переведення числа у вказану систему числення (із заданого
переліку). На основі цього класу створити класи-нащадки TIntNumber2 та TIntNumber8, що представляють
двійкові та вісімкові числа. Створити m двійкових та n вісімкових чисел. Знайти суму двійкових та вісімкових
чисел. Перевести отримане значення суми вісімкових чисел у двійковий формат. Визначити, сума яких чисел менша
(двійкових чи вісімкових).*/

#include "Functions.h"
using namespace std;

int main()
{
	int m, n;
	cout << "Enter m (number of binary numbers): "; cin >> m;
	cout << "Enter n (number of octal numbers): "; cin >> n;

	cout << "\n---Start entering binary numbers---\n\n";
	vector<TIntNumber2> binNums = inputNums<TIntNumber2>(m, 2);
	cout << "\n---Start entering octal numbers---\n\n";
	vector<TIntNumber8> octNums = inputNums<TIntNumber8>(n, 8);

	cout << "\n---The data you entered---\n";
	cout << "\nBinary numbers: ";
	outputNums<TIntNumber2>(binNums);
	cout << "\nOctal numbers: ";
	outputNums<TIntNumber8>(octNums);

	TIntNumber2 sumBin = countSum<TIntNumber2>(binNums);
	TIntNumber8 sumOct = countSum<TIntNumber8>(octNums);
	cout << "\n\nThe sum of binary numbers: " << sumBin;
	cout << "\nThe sum of octal numbers: " << sumOct;
	TIntNumber2 sumOctInBin = sumOct.convertToBase();
	cout << "\nThe value of the sum of octal numbers in binary format: " << sumOctInBin << "\n";

	findMin(sumBin, sumOctInBin);

	system("pause");
	return 0;
}