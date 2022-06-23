#include "Functions.h"
using namespace std;

void outputNums(Numeral_8 N1, Numeral_8 N2, Numeral_8 N3)
{
	cout << "\n       N1 = " << N1.getNum()
		<< "\n       N2 = " << N2.getNum()
		<< "\n       N3 = " << N3.getNum() << "\n";
}

bool isNumeral8(long long num)
{
	while (num) {
		if (num % 10 < 8) {
			num /= 10;
		}
		else {
			return false;
		}
	}
	return true;
}

long long convertToDec(long long num, int base)
{
	long long dec = 0;
	int i = 0;
	while (num) {
		dec += (num % 10) * (long long)pow(base, i++);
		num /= 10;
	}
	return dec;
}

long long convertFromDec(long long dec, int base)
{
	long long num = 0;
	int i = 0;
	while (dec > base - 1) {
		num += (dec % base) * (long long)pow(10, i++);
		dec /= base;
	}
	return num + dec * (long long)pow(10, i);
}