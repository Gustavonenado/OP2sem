#include "Functions.h"
using namespace std;

bool isNumeralBase(long long num, int base)
{
	while (num) {
		if (num % 10 < base) {
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

void findMin(TIntNumber2& bins, TIntNumber2& octs)
{
	int flag = bins.compare(octs);
	if (flag < 0) {
		cout << "\nThe sum of binary numbers is less than octal\n";
	}
	else if (flag == 0) {
		cout << "\nThe sums of binary and octal numbers are equal\n";
	}
	else {
		cout << "\nThe sum of octal numbers is less than binary numbers\n";
	}
}