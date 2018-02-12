//Young Joong Gwon
#include<iostream>
#include<ctime>
#include<string>
#include"Division.h"
using namespace std;

ostream& operator<<(ostream& strm, const Division& right)
{
	strm << "Division Quiz " << right.num1 << " - " << right.num2 << " = ?\n";
	return strm;
}

void Division::validate(string str1)
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

Division::Division()
{
	theAnswer = 0;
	userResponse = 0;
	randomize();
}

void Division::randomize()
{
	//This work is from my Math game in CSIT 139 last year
	srand(time(0));
	num2 = rand() % 10 + 1;
	theAnswer = rand() % 10 + 1; //geterate a radom answer
	num1 = theAnswer*num2; //make num1 the multiple of num2
}

bool Division::checkAnswer()
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

ostream& operator<<(ostream& strm, const Division& right)
{
	strm << "Division Quiz " << right.num1 << " - " << right.num2 << " = ?\n";
	return strm;
}