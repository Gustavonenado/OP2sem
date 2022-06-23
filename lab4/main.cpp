/* Визначити клас "Numeral_8", членом якого є вісімкове число. Реалізувати для даного класу декілька
конструкторів, геттери, методи перетворення числа у двійкове, у тому числі і скороченим способом.
Перевантажити оператори: префіксний "++" - для інкрементації вісімкового числа, "+=" - для збільшення
його на вказану величину, "+" - для додавання двох вісімкових чисел. Створити три вісімкових числа
(N1, N2, N3), використовуючи різні конструктори. Інкрементувати число N1, а число N2 збільшити на
вказану величину. Знайти суму змінених чисел N1 та N2 і зберегти її в N3. Перевести отримане значення
N3 у двійковий формат двома способами (звичайним і скороченим). */

#include "Functions.h"
using namespace std;

int main()
{
	long long n1;
	cout << "Enter an octal number N1: "; cin >> n1;
	while (!isNumeral8(n1)) {
		cout << "You have entered a number that does not correspond to the octal midrange! Enter N1 again: "; cin >> n1;
	}
	Numeral_8 N1(n1), N2(N1), N3;
	cout << "\nCurrent data:";
	outputNums(N1, N2, N3);

	long long n;
	cout << "\nEnter the amount by which you want to increase N2 (octal notation): "; cin >> n;
	while (!isNumeral8(n)) {
		cout << "You entered a number in the wrong number system! Please try again: "; cin >> n;
	}
	++N1;
	N2 += n;
	N3 = N1 + N2;
	cout << "\nChanged data:";
	outputNums(N1, N2, N3);
	cout << "\nN3, converted to binary midrange in the usual way:  " << N3.convertToBinUsual();
	cout << "\nN3, converted to binary midrange in an abbreviated manner: " << N3.convertToBinReduced() << "\n\n";
	system("pause");
	return 0;
}