//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//****************************************************************************************************  
int main()
{
	string line;
	ifstream myfile("AssignmentData.txt");
	if (myfile.is_open())
	{

	}
	else cout << "Unable to open file";

	return 0;
}

//**************************************************************************************************** 
/*

	int bonus;

	bonus = 40;

	if (bonus > 100)
		cout << "Give!\n";

		cout << "Save!\n";
		cout << "Spend!" << endl;

//****************************************************************************************************

	float num1,
		num2,
		num3;

	cout << "Please enter the three numbner" << endl;
	cin >> num1 >> num2 >> num3;

	if (num1 > num2 && num1 > num3)
		cout << num1 << endl;
	else if (num2 > num1 && num2 > num3)
		cout << num2 << endl;
	else
		cout << num3 << endl;

//****************************************************************************************************

	char initial,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		Y,
		X,
		Z;

	if (initial < F)
		cout << "Group 1" << endl;
	else if (initial < Q && initial > F)
		cout << "Group 2" << endl;
	else
		cout << "Group 3" << endl;

//****************************************************************************************************

	int donuts = 10;

	if (donuts == 20)
		donuts += 8;
	else
		donuts += 2;

	cout << donuts << endl;

//****************************************************************************************************

if (a > 5 || b > 10) {
	cout << a << " " << b << endl;
	}

	else {
	cout << a << " " << b << endl;
	}

//****************************************************************************************************

		int a = 7,
		b = 8;

	bool answer;

	answer = (a - 6) <= b;

	cout << answer;

//****************************************************************************************************

		int a = 5,
		b = 10;

	if (!(a < 5 && b <= 10)) {
		cout << "1";
	}

	else {
		cout << "2";
	}

//****************************************************************************************************

	int totalMoneyWeek,
		totalMoneyMonth,
		totalMoneyYear,
		totalMoney,
		hoursWorked,
		weeksWorked,
		monthsWorked,
		yearsWorked;

	const int MONEY_PER_HOUR = 60;


	cout << "How many hours worked this week: ";
	cin >> hoursWorked;

	cout << "How many weeks worked this month: ";
	cin >> weeksWorked;

	cout << "How many months worked this year: ";
	cin >> monthsWorked;

	cout << "How many years worked this life: ";
	cin >> yearsWorked;

	totalMoneyWeek = MONEY_PER_HOUR * hoursWorked;
	totalMoneyMonth = totalMoneyWeek * weeksWorked;
	totalMoneyYear = totalMoneyMonth * monthsWorked;

	totalMoney = totalMoneyYear * yearsWorked;


	cout << "Amount: " << totalMoney << endl;

//****************************************************************************************************

		int totalMoneyWeek,
		totalMoneyMonth,
		totalMoneyYear,
		totalMoney,
		hoursWorked,		  
		weeksWorked,
		monthsWorked,
		yearsWorked,
		moneyPerHour,
		salary;

	cout << "Life Career Calculator" << endl << endl;

	cout << "How much money per hour: ";
	cin >> moneyPerHour;

	cout << "How many hours worked every week (average): ";
	cin >> hoursWorked;

	while (hoursWorked > 80)
	{
		cout << endl;

		cout << "Try again, dummy! " << endl << endl;

		cout << "How many hours worked every week (average): ";
		cin >> hoursWorked;
	}

	cout << "How many weeks worked every month: ";
	cin >> weeksWorked;

	while (weeksWorked > 4)
	{
		cout << endl;

		cout << "Try again, dummy! " << endl << endl;

		cout << "How many weeks worked every month: ";
		cin >> weeksWorked;
	}

	cout << "How many months worked every year (enter 11 for vacations or 12 for no off-time): ";
	cin >> monthsWorked;

	while (monthsWorked > 12)
	{
		cout << endl;

		cout << "Try again, dummy! " << endl << endl;

		cout << "How many months worked every year (enter 11 for vacations or 12 for no off-time): ";
		cin >> monthsWorked;
	}

	cout << "How many years worked this life (total): ";
	cin >> yearsWorked;

	while (yearsWorked > 70)
	{
		cout << endl;

		cout << "Try again, dummy! " << endl << endl;

		cout << "How many years worked this life (total): ";
		cin >> yearsWorked;
	}

	totalMoneyWeek = moneyPerHour * hoursWorked;
	totalMoneyMonth = totalMoneyWeek * weeksWorked;
	totalMoneyYear = totalMoneyMonth * monthsWorked;

	totalMoney = totalMoneyYear * yearsWorked;

	cout << endl;

	cout << "Money earned in life: " << totalMoney << endl << endl;

	salary = totalMoney / yearsWorked;

	cout << "Average Salary (based on hourly wages): " << salary << endl << endl;

	if (yearsWorked >= 25 && totalMoney >= 2000000)
		cout << "Congratulations! You have had a life full of EXTRAORDINARY purpose and AMAZING wealth!" << endl;
	else if (yearsWorked < 25 && totalMoney >= 2000000)
		cout << "Congratulations! You have had a life full of AMAZING wealth!" << endl;
	else if (yearsWorked >= 25 && totalMoney >= 1500000)
		cout << "Congratulations! You have had a life full of GREAT purpose and VERY comfortable living!" << endl;
	else if (yearsWorked < 25 && totalMoney >= 1500000)
		cout << "Congratulations! You have had a life full of VERY comfortable living!" << endl;
	else if (yearsWorked < 25 || yearsWorked >= 25 && totalMoney >= 1000000)
		cout << "Good Job! You have had a life full of nice purpose and comfortable living!" << endl;
	else if (yearsWorked < 25 || yearsWorked >= 25 && totalMoney >= 250000)
		cout << "Prett good. . . You have had a life full of worrying about money and little purpose. . . but still a decently comfortable life." << endl;
	else
		cout << "You're life is sad and without purpose. . . Please find the closest soup kitchen and nicest bridge to sleep under... GOODLUCK!" << endl;

	return 0;
*/
