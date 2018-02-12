// Young Joong Gwon
#include<iostream>
#include <string> 
#include <fstream>
#include"Game.h"
#include"Addition.h"
#include"Subtraction.h"
#include"Multiplication.h"
#include"Division.h"
using namespace std;

Game::Game()
{
	//Game young is checking in main
	userName = "";//variable to store the user name
	totalWages = 0;//variable to store the total earning
	totalCorrect = 0;//variable to store the total of correct responses
	totalWrong = 0;//variable to store the total of incorrect responses
}

void Game::splashScreen()
{
	//splashscreen in main.cpp
	cout << "*****************************************" << endl;
	cout << "*****************************************" << endl;
	cout << "*****************************************" << endl;
	cout << "*********                     ***********" << endl;
	cout << "*********   The  Math  Game   ***********" << endl;
	cout << "*********   By Young Joong    ***********" << endl;
	cout << "*********        Gwon         ***********" << endl;
	cout << "*********                     ***********" << endl;
	cout << "*****************************************" << endl;
	cout << "*****************************************" << endl;
	cout << "Y/y to continue, any other char to exit" << endl;
}

void Game::menu()
{
	cout << "********    CHOOSE A PROBLEM    *********" << endl;
	cout << "********                        *********" << endl;
	cout << "*****************************************" << endl;
	cout << "************                *************" << endl;
	cout << "************ 1. ADD         *************" << endl;
	cout << "************ 2. SUBSTRACT   *************" << endl;
	cout << "************ 3. MULTIPLY    *************" << endl;
	cout << "************ 4. DIVIDE      *************" << endl;
	cout << "************ 5. STATS       *************" << endl;
	cout << "************ n/N to QUIT    *************" << endl;
	cout << "************                *************" << endl;
	cout << "*****************************************" << endl;
	cout << "*****************************************" << endl;
}

void Game::updateStats(bool correct)
{
	if (correct)
	{
		totalCorrect++;
	}
	else if(correct ==false)
	{
		totalWrong++;
	}

	totalWages = totalCorrect*0.05 - totalWrong*0.03;
}

void Game::displayStats()
{
	cout << "*****************************************\n";
	cout << "*****************************************\n";
	cout << "*****************************************\n";
	cout << "     Hi " << userName << endl << endl;
	cout << "     Total correct: " << totalCorrect << endl;
	cout << "     Total wrong: " << totalWrong << endl;
	cout << "     Total wages: $" << totalWages << endl;
	cout << "*****************************************\n";
	cout << "*****************************************\n";
	cout << "*****************************************\n";
	system("pause");
	system("cls");
}

void Game::requestName()
{
	ifstream file1;
	ofstream file2;
	cout << "Enter your name" << endl;
	//type the user
	//userName is included in this function (userName, totalWages, totalCorrect, totalWrong are setted)
	getline(cin, userName);
	validate(userName);
	file1.open(userName + ".txt"); 
	//text file is made by ifstream
	file1 >> userName >> totalCorrect >> totalWrong >> totalWages;
	file1.close();
	if (!file1) 
	//make a file if the file doesn't exist
	{
		file2.open(userName + ".txt");
		file2.close();
		//new text file is made
	}
	system("cls");
}

void Game::validate(string& str1) 
//This function is checking valid name
{
	int length = str1.length();
	int counter = 0;
	while (counter < length || length == 0)
	{
		// the counter is checking how many string user typed
		//for example, if I type "string", length is looping 5 times
		if (length == 0 || !isalpha(str1[counter]))
		{
			cout << "Invalid input. Try again.\n";
			getline(cin, str1);
			length = str1.length();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
}

void Game::saveStats() //record the data to the file
{
	ofstream file1;
	file1.open(userName + ".txt");
	file1 << userName << endl
	<< totalCorrect << endl
	<<	totalWrong << endl 
	<< totalWages;
	file1.close();
}