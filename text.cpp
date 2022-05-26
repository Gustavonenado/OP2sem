#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void create_first_file(string path1)
{
	string Text;
	ofstream FstFile(path1);
	cout << "enter text (ctrl + z - to stop):\n";
	while (getline(cin, Text, '\26')) {
		FstFile << Text << endl;
	}
	FstFile.close();
}

int delete_2_symb_words(string path1, string path2)
{
	ifstream FstFile(path1);
	ofstream SndFile(path2);
	if (!FstFile) {
		cout << "cant open file\n";
		return -1;
	}
	string Text, word;
	int Count = 0;
	while (FstFile)
	{
		Text = "";
		getline(FstFile, Text);
		word = "";
		int k = 0,
			m;
		while (k < Text.length()) {
			m = Text.find(" ", k);
			if (m == string::npos) {
				m = Text.length();
			}
			if (m == k) {
				k++;
			}
			else {
				word = Text.substr(k, m - k);
				if (word.length() == 2) {
					Count++;
					if (k == 0 && m == Text.length()) {
						Text.erase(k, m - k);
					}
					else if (m != Text.length()) {
						Text.erase(k, m - k + 1);
					}
					else {
						Text.erase(k - 1, m - k + 1);
					}
				}
				else {
					k = m + 1;
				}
			}
		}
		SndFile << Text << endl;
	}
	FstFile.close();
	SndFile.close();
	return Count;
}

int add_number_of_del_words(string path, int Count)
{
	ofstream SndFile(path, ios::app);
	if (!SndFile) {
		cout << "Could not open file\n";
		return 0;
	}
	SndFile << "Number of deleted words: " << Count;
	SndFile.close();
	return 1;
}

void output_text_of_file(string path)
{
	ifstream File(path);
	if (!File) {
		cout << "Could not open file for output to console!\n";
	}
	else {
		string Text;
		while (File) {
			Text = "";
			getline(File, Text);
			cout << Text << endl;
		}
		File.close();
	}
}