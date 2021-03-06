//Young Joong Gwon
#include<iostream>
#include<ctime>
#include<string>
#include"Subtraction.h"
using namespace std;

ostream& operator<<(ostream& strm, const Subtraction& right)
{
	strm << "Subtraction Quiz " << right.num1 << " - " << right.num2 << " = ?\n";
	return strm;
}

void Subtraction::validate(string str1)
{
	//This code is cited from CSIT139 validation of youtube video
	//csit139 validation by Flores Lecture(10:14),(24:44),(28:17)
	int length = str1.length();
	int counter = 0;
	char nextchar;
	while (counter < length || length == 0)
	{
		if (length == 0 || !isdigit(str1[counter]))
		{
			cout << "Invalid. Try again." << endl;
			getline(cin, str1);
			length = str1.length();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}

	counter = 0;
	for (counter = 0; counter < length; counter++)
	{
		nextchar = str1[counter];
		userResponse = userResponse * 10 + (nextchar - '0');
	}
}
Subtraction::Subtraction()
{
	theAnswer = 0;
	userResponse = 0;
	randomize();
}

void Subtraction::randomize()
{
	//This work is from my Math game in CSIT 139 last year
	srand(time(0));
	num1 = rand() % 10 + 1;// Number 0~10
	num2 = rand() % 10 + 1;
	if (num1 < num2) //num2 should be positive number
	{
		int positive = num1;
		num1 = num2;
		num2 = positive;
	}
	theAnswer = num1 - num2;
}

bool Subtraction::checkAnswer()
{
	if (theAnswer == userResponse)
	{
		cout << "****************Correct****************" << endl;
		return true;
	}
	else
	{
		cout << "****************Incorrect**************" << endl;
		return false;
	}

}
