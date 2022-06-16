
#include "header.h"
using namespace std;


void Output_File_In_Console(ifstream& file)
{
	Period breaks;                    
	cout << "\nThe list of technical breaks in the work of cashier:\n\n";
	while (file.read((char*)&breaks, sizeof(Period))) {
		cout.fill('0');
		cout << setw(2) << breaks.start.hour << ":" << setw(2) << breaks.start.min << " - "
			<< setw(2) << breaks.end.hour << ":" << setw(2) << breaks.end.min << endl;
	}
}

Period Input_Working_Hours()
{
	Period work;                       
	char ch;                           
	cout << "Enter the start time of the working day (in the format hh:mm): ";
	cin >> work.start.hour >> ch >> work.start.min;
	cout << "Enter the end time of the business day (in the format hh:mm): ";
	cin >> work.end.hour >> ch >> work.end.min;
	return work;
}


Period* Input_Breaks(int n)
{
	char ch;                           
	Period* breaks = new Period[n];    
	cout << "Please enter breaks in ascending order!\n" <<
		"\n--- Start entering the list of technical breaks--- \n";
	for (int i = 0; i < n; ++i) {
		cout << "\nEnter the start time of the break (in the format hh:mm): ";
		cin >> breaks[i].start.hour >> ch >> breaks[i].start.min;
		cout << "Enter the end time of the break (in the format hh:mm): ";
		cin >> breaks[i].end.hour >> ch >> breaks[i].end.min;
	}
	return breaks;
}

void Output_Breaks_In_File(ofstream& file, Period* breaks, Period work, int n)
{
	for (int i = 0; i < n; ++i) {
		if (Check_Break(breaks, breaks[i], work, i)) {
			file.write((char*)&breaks[i], sizeof(Period));
		}
	}
	delete[] breaks;
}

bool Check_Break(Period* breaks, Period& a_break, Period work, int k)
{

	if (!Break_Is_In_Work_Time(a_break, work))
		return false;
	for (int i = 0; i < k; ++i) {
		if (Breaks_Is_Overlap(breaks[i], a_break))
			return false;
	}
	return true;
}

bool Break_Is_In_Work_Time(Period& breaks, Period work)
{
	if (breaks.end.hour < work.start.hour ||
		breaks.end.hour == work.start.hour && breaks.end.min <= work.start.min)
		return false;
	if (breaks.start.hour > work.end.hour ||
		breaks.start.hour == work.end.hour && breaks.start.min >= work.end.min)
		return false;
	if (breaks.start.hour < work.start.hour ||
		breaks.start.hour == work.start.hour && breaks.start.min < work.start.min)
	{
		breaks.start.hour = work.start.hour;
		breaks.start.min = work.start.min;
	}
	if (breaks.end.hour > work.end.hour ||
		breaks.end.hour == work.end.hour && breaks.end.min > work.end.min)
	{
		breaks.end.hour = work.end.hour;
		breaks.end.min = work.end.min;
	}
	return true;
}

bool Breaks_Is_Overlap(Period A, Period& B)
{
	if ((B.start.hour > A.start.hour || B.start.hour == A.start.hour && B.start.min >= A.start.min)
		&& B.end.hour < A.end.hour || B.end.hour == A.end.hour && B.end.min <= A.end.min)
		return true;
	if ((A.start.hour < B.start.hour || A.start.hour == B.start.hour && A.start.min <= B.start.min)
		&& (A.end.hour > B.start.hour || A.end.hour == B.start.hour && A.end.min > B.start.min))
	{
		B.start.hour = A.end.hour;
		B.start.min = A.end.min;
	}
	else if ((A.end.hour > B.end.hour || A.end.hour == B.end.hour && A.end.min >= B.end.min)
		&& (A.start.hour > B.start.hour || A.start.hour == B.start.hour && A.start.min > B.start.min))
	{
		B.end.hour = A.start.hour;
		B.end.min = A.start.min;
	}
	return false;
}

int Count_Duration(Period period)
{
	return (period.end.hour * 60 + period.end.min) - (period.start.hour * 60 + period.start.min);
}

bool Check_For_Serving_Customers(ifstream& file, Period work, int num_of_cust, int time_for_one_cust)
{
	int working_day_duration = Count_Duration(work);         
	Period breaks;                                           
	int break_time = 0;                                       
	while (file.read((char*)&breaks, sizeof(Period))) {
		break_time += Count_Duration(breaks);
	}
	int work_time = working_day_duration - break_time;       
	int time_for_customers = time_for_one_cust * num_of_cust; 
	cout << "\nTotal length of the working day: " << working_day_duration << " minutes\n";
	cout << "Total duration of breaks: " << break_time << " minutes\n";
	cout << "Working hours (including breaks): " << work_time << " minutes\n";
	if (work_time >= time_for_customers) return true;
	else return false;
}