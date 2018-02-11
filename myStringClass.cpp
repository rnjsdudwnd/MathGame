//Young Joong Gwon
//I deleted "myStringClass(const myStringClass* str)" but it does work without the copy constructor.
//Enter your first name, last name, age are related to operator <<, >>
#include <iostream>
#include "myStringClass.h"
using namespace std;
myStringClass::myStringClass()
{
	//Default Constructor Starts
	//myStringClass is checking last, first, and age  -> 3 times rotating
	//Let me start&set userInputLength is equal 0
	userInputLength = 0;
	userInput = new char[1]; //private char* userInput from h file; 
							 //last has an address of userInput     ex)0x007f5128
							 //first has an address of userInput    ex)0x007f50f8
							 //age has an address of userInput      ex)0x007f4e08
	userInput[userInputLength] = '\0';
	//'\0' is the null termination character.
}
//Overloading the stream extraction operator(>>)
//*Both parameters are reference parameters.
//*The first parameter-that is, isObject-is a reference to an istream object.
//*The second parameter is usually a reference to a particular class.
//The data read will be stored in the object
//*The function return type is a reference to an istream object.
istream & operator >> (istream& stream, myStringClass&object1)
{
	
	char char1; //Create Character for references, &stream
	char1 = stream.get(); //@@For Example@@, the user typed "showmethemoney" in Enter your first name only
	object1.userInput = nullptr;//Reference &object1 becomes NULL& userInput becomes NULL
	int count = 0; // count is set for userInput&userInputLength
	int k; //for counting object1
	while (char1 != '\n')//This loop will be finished when Char1 becomes '\n'
	{
		count++;//count is increasing. It depends on &object1
		char *char2 = new char[count];//pointer *char2 is made
		if (object1.userInput != nullptr)
		{
			for ( k = 0; k < count - 1; k++)
			{
				//char2 is counting "showmethemoney"
				//|s|h|o|w|m|e|t|h|e|m|o |n |e |y |\0|
				//|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|
				char2[k] = object1.userInput[k];
			}
		}
		char2[count - 1] = char1;// char2's word is being completed
		delete[] object1.userInput;		//object1 -> userInput becomes NULL& userInputLength becomes 0	
		object1.userInput = char2;//object1's address becomes char2's address
		char2 = nullptr;//char2 becomes nullptr in order to change the nextInput
		char1 = stream.get();//char1 get next character ex)s>h>o>w>m>e>t>h>e>m>o>n>e>y>\0  14times looping
	}
	object1.userInputLength = count; //userInput has "showmethemoney", and userInputLength has 14 in &obj(**IMPORTANT!)
	return stream;
}//Therefore, "first" in myStringClass has userInput's own address, information"showmethemoney", and userInputLength which is 14.
//Like "first", "last" and "age" will continue from this Overloading the stream extraction operator(>>)
//And also this fuction works with array of myStringClass myStringClass arrayOfNames[5];
ostream& operator<< (ostream& stream, const myStringClass* object2)
{
	    //abx < ax
		//axb > aa
		//ab < axb
		//ax > aax
		//abcz > abc
		//abc < abcz
		//abc = abc
		//abx <= ax
		//axb >= aa
		//ab <= axb
		//ax >= aax
		//abcz >= abc
		//abc <= abcz
		//abc = abc
	int g;
	//Chapter 14 More about Classes, Page 848
	for (g = 0; g < object2->stringLength(); g++)
	{
		stream << object2->userInput[g];
	}
	return stream;
}

//Chapter 14 More about Classes, Page 848
//Overloading the stream insertion operator(<<)
//In this function definition:
//*Both parameters are reference parameters.
//*The first parameter-that is, stream-is a reference to an ostream object.
//*The second parameter is a const reference to a particular class.
//*The function return type is a reference to an ostream object.
ostream& operator<< (ostream& stream, const myStringClass& object3)
{
	//overloaded cout
	//cout << "hello " << first << " " << last << ", age: " << age << endl;
	//What user typed 
	int g;
	for (g = 0; g < object3.stringLength(); g++)
	{
		stream << object3.userInput[g];
	}
	return stream;
	//for (int x = 0; x < 5; x++)
	//	cout << arrayOfNames[x] << endl;
}
//arrayOfNames
//[0] has address of userInput, and checks userInputLength user typed  ex)0x00800490
//[1] has address of userInput, and checks userInputLength user typed  ex)0x008004f0
//[2] has address of userInput, and checks userInputLength user typed  ex)0x00800520
//[3] has address of userInput, and checks userInputLength user typed  ex)0x00800850
//[4] has address of userInput, and checks userInputLength user typed  ex)0x008008b0


myStringClass::myStringClass(const char* str) // This function checks string1 and string2
{
	//Let me say the relationship between "abx" and "ax" is 1st calculation, and so on..
	//1st calculation
	//myStringClass string1 = "abx";
	//myStringClass string2 = "ax";
	//2nd' calculation
	//string1 = "axb";
	//string2 = "aa";
	//3rd'calculation
	//string1 = "ab";
	//string2 = "axb";
	//4th'calculation
	//string1 = "ax";
	//string2 = "aax";
	//5th'calculation
	//string1 = "abcz";
	//string2 = "abc";
	//6th'calculation
	//string1 = "abc";
	//string2 = "abcz";
	//7th'calculation
	//string1 = "abc";
	//string2 = "abc";
	//8th'calculation
	//string1 = "abx";
	//string2 = "ax";
	//9th'calculation
	//string1 = "axb";
	//string2 = "aa";
	//10th'calculation
	//string1 = "ab";
	//string2 = "axb";
	//11th'calculation
	//string1 = "ax";
	//string2 = "aax";
	//12th'calculation
	//string1 = "abcz";
	//string2 = "abc";
	//13th'calculation
	//string1 = "abc";
	//string2 = "abcz";
	//14th'calculation
	//string1 = "abc";
	//string2 = "abc";
	
	int g;
	userInputLength = strlen(str);
	//For example, from 1st calculation,
	//char pointer *str has own address with information "abx" in the 1st calculation
	//char pointer *str has own address with information "ax" in the 1st calculation
	userInput = new char[userInputLength + 1];//userInput has own address and a value
	for ( g = 0; g <userInputLength; g++)
	{
		userInput[g] = str[g]; 
		//"abx" has "userInputLength=3",so |0|1|2|
		//"ax" has "userInputLength=2", so |0|1|
	}
	userInput[userInputLength] = '\0'; //After looping, this '\0' makes char to stop
}
//Destructor
myStringClass::~myStringClass()
{
	//At the end of string1 and string2 process
}
int myStringClass::stringLength() const
{
	//For validation
	//userInput and userInputLength got value
	return userInputLength; //For example, UserInputLength = 14 as "showmethemoney"
}
myStringClass& myStringClass::operator=(const myStringClass& calculationString)
//Assigns the myStringClass on the right to the myStringClass object on the left
//Chapter 14 More about Classes, Page 848
{
	//this function checks "abx"&"ax" in Calculation1 with looping
	//next calculations also looping with this function
	int o;
	if (this != &calculationString)
	{
		userInput = new char[userInputLength + 1];
		userInputLength = calculationString.userInputLength;
		
		for (o = 0; calculationString.userInput[o] != '\0'; o++)
		{
			userInput[o] = calculationString.userInput[o];
		}
		userInput[userInputLength] = '\0';
	}
	//"this pointer" is passed as a hidden argument to all nonstatic member function. Page 836
	return *this;
}

//Textbook Page 833 
//Return Type, Function name, Parameter for object on the calculationString of operator
bool myStringClass:: operator==(const myStringClass& calculationString)
{
	//From the 1st calculation,
	//string1 = string2 is true? no this returns false ("abx" is not equal "ax")
	//From the 2nd calculation,
	//string1 = string2 is true? no this returns false ("axb" of 3 is not equal "aa" of 2)
	int s;
	if (userInputLength == calculationString.userInputLength)
	{
		for ( s = 0; s < userInputLength; s++)
		{
			if (userInput[s] != calculationString.userInput[s])
			{
				return false;
			}
		}
		//From the 7th calculation,
		//string1 = string2 is true? yes, this returns True ("abc" = "abc")
		//From the 14th calculation,
		//string1 = string2 is true? yes, this returns True ("abc" = "abc")
		return true;
	}
	else
	{
		return false;
	}
}

bool myStringClass::operator!=(const myStringClass& calculationString)
{
	//Operator is not equal calculationString
	return !(*this == calculationString);
}

bool myStringClass::operator<=(const myStringClass& calculationString)
{
	//From the 8th calculation, string1 <= string2, this "abx" 3 <= calculationString "ax" 2
	//Operator "<" and "==" check together
	return (*this < calculationString) || (*this == calculationString);
}
bool myStringClass:: operator>=(const myStringClass& calculationString)
{
	//From the 9th calculation, string1 >= string2, this "axb" 3 >= calculationString "aa"2
	//Operator ">" and "==" check together
	return (*this == calculationString) || (*this > calculationString);
}

bool myStringClass::operator>(const myStringClass& calculationString)
{
	//Operator Right side should be higher than left, not the same
	return !(*this == calculationString) && !(*this < calculationString);
}
myStringClass myStringClass::operator+=(myStringClass& right)
{
	//Appends a copy of the myStringClass on the right to the myStringClass object on the left. Page 586 textbook
	//"this pointer" is passed as a hidden argument to all nonstatic member function. Page 836
	return *this;
}
myStringClass& myStringClass::operator+(const myStringClass& right)
{
	//Returns a string that is the concatenation of the two myStringClass operands. Page 586 textbook
	//"this pointer" is passed as a hidden argument to all nonstatic member function. Page 836
	return *this;
}
char& myStringClass::operator[](int index)
{
	//textbook 586 page
	//Implements array-subscript notation, as in userInput[index].
	//A reference to the character in the index position in returned.
	return userInput[index];
}
bool myStringClass::operator<(const myStringClass& calculationString)
	//This reference indicates "ax", userInputLength=2
{
	//From the 1st calculation,
	//string1 < string2 is true? yes, this returns True ("abx" < "ax")
	int shorterLength = 0; //calculationString "ax" 2 = shorterLength 2 which means that this int checks short Length
	bool leftSmallChar = false;//Left has smaller Char than Right
	bool leftBigChar = false;//Left has bigger Char than Right
	bool leftLack = false;//Left is shorter than right length
	if (userInputLength < calculationString.userInputLength)//From 1st calculation, userInputLength=3 is less than calculationString? No.
		//From 2nd calculation, userInputLength=3 is less than calculationString 2? No.
	{
		leftLack = true;
		shorterLength = userInputLength;
	}
	else
	{
		shorterLength = calculationString.userInputLength;//From 1st calculation, shorterLength becomes 2 because of calculationString.
	}												  //From 2nd calculation, shorterLength becomes 2 because of calculationString.

	for (int i = 0; i < shorterLength; i++)
	{
		if (userInput[i] > calculationString.userInput[i])//From 1st calculation, i(0) is bigger than 2"ax"? no
		{
			//From 2nd calculation, i(1) is bigger than 3 "abx"? yes.so, leftBigChar is true
			leftBigChar = true;
		}
		else if (userInput[i] < calculationString.userInput[i])//From 1st calculation, i(1) is less than 2"ax"? yes,so leftSmallChar is true.
		{
			leftSmallChar = true;
		}
	}
	bool leftLessRightBig = (leftSmallChar) || (!leftBigChar && leftLack);
	//From 1st calculation, leftLessRightBig = true  THEREFORE, abx < ax
	//From 2nd calculation, leftLessRightBig = false   THEREFORE, axb > aa
	//3rd, 4th, 5th, 6th calculations will go to the same method
	return leftLessRightBig;
}

/////////////////////What does mean in cppfile?/////////
//string2 = "Hello ";
//object declaration
//copy constructor
//myStringClass string3(string2);
//myStringClass string4 = string3 + "World";
//cout << string4 << endl;
//////////////////////////Solution///////////////////////
//string1 userInput = 0x008006a0 "abc", userInputLength=3
//string2 userInput = 0x007fe1a0 "Hello ", userInputLength=6 
//string3 userInput = 0x007fe1a0 "Hello ", userInputLength=6
//string4 userInput = 0x007fe590 "Hello World", userInputLength=11
//////////////////////////////////////////////////////////////////

//This myStringClass:validateUserInput is for checking "first" and "last"
void myStringClass::validateUserInput(myStringClass& myStringClassObject)
{
	//Work cited Flores' video 9:00
	//https://www.youtube.com/watch?v=e-PqiTdogjo&index=16&list=UUG72aPdt0ztnn8hsRG9bShw
	//Work cited from my pre-assignments of validation issue
	int counter = 0;
	int strLength = myStringClassObject.stringLength();
	while (counter < strLength || strLength == 0)
	{
		if (strLength == 0 || !isalpha(myStringClassObject.userInput[counter]))
		{ 
			if (strLength == 0)
				cout << "THE STRING IS EMPTY, TRY AGAIN. " << endl;
			else
				cout << "THS IS NOT A NAME, TRY AGAIN " << endl;
			cin >> myStringClassObject;
			strLength = myStringClassObject.stringLength();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
}
//This myStringClass:validateUserInput is for checking "age"
void myStringClass::validateUserInt(myStringClass& myStringClassObject)
{
	//Work cited Flores' video 9:00
	//https://www.youtube.com/watch?v=e-PqiTdogjo&index=16&list=UUG72aPdt0ztnn8hsRG9bShw
	//Work cited from my pre-assignments of validation issue
	int counter = 0;
	int strLength = myStringClassObject.stringLength();
	while (counter < strLength || strLength == 0)
	{
		if (strLength == 0 || !isdigit(myStringClassObject.userInput[counter]))
		{ 
			if (strLength == 0)
				cout << "THIS STRING IS EMPTY, TRY AGAIN. " << endl;
			else
				cout << "THIS IS NOT A INTEGER, TRY AGAIN. " << endl;
			cin >> myStringClassObject;
			strLength = myStringClassObject.stringLength();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
	// get out of the loop When counter = strLength
}
