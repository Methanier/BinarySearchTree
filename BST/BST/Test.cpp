/*
	Charles Cozart
	Test program for BinarySearchTree
	CSC382
*/

#include"BinarySearchTree.h"
#include<iostream>
#include"Employee.h"

//namespaces being used
using namespace std;
using namespace BST; //BinarySearchTree namespace

//Function prototypes
bool AutoTestDefaultConstruct();
bool AutoTestConstConstruct();
bool AutoTestNonConstConstruct();
bool AutoTestDestructor();
bool AutoTestConstInsert();
bool AutoTestNonConstInsert();
bool AutoTestDelete();
void RunAutoTests();
void RunManualTests();
bool CreateEmptyBinaryTree(int);
void ChooseTreeToAddTo();
void ChooseTreeToPrint();
void ChooseTreeToSearch();
void ChooseTreeToDeleteFrom();
void InsertToTree(int);
void DeleteFromTree(int);
Employee* CreateEmployee();
Employee* DefaultEmployee();
void PrintIntTree();
void PrintFloatTree();
void PrintEmployeeTree();
void UserOptions();

//BinarySearchTrees for auto tests
BinarySearchTree<int> *autoTestTree;
BinarySearchTree<int> *autoTestTreeTwo;

//BinarySearchTrees for manual tests
BinarySearchTree<int> *manualTestInt;
BinarySearchTree<float> *manualTestFloat;
BinarySearchTree<Employee> *manutalTestEmployee;

//Main function
int main()
{
	UserOptions();
}

//Runs auto test of default constructor
bool AutoTestDefaultConstruct()
{
	bool result = false;
	BinarySearchTree<int> *binaryTree = new BinarySearchTree<int>(); //Creates BinarySearchTree of type in

	//If binaryTree is not emptye sets result to true
	if (binaryTree != nullptr)
	{
		result = true;
	}

	return result;
}

//Runs auto test of Const copy constructor
bool AutoTestConstConstruct()
{
	
	bool result = false;

	//Const integer variables
	const int ten = 10;
	const int five = 5;
	const int seven = 7;

	autoTestTree = new BinarySearchTree<int>(); //Creates empty BST of type int

	//Inserts variables into the tree
	autoTestTree->Insert(seven);
	autoTestTree->Insert(ten);
	autoTestTree->Insert(five);

	BinarySearchTree<int> *temp = new BinarySearchTree<int>(*autoTestTree); //creates new BST passing in autoTestTree into the constructor

	//If the temp tree has all the same values as autoTestTree sets result to true
	if (temp->Contains(ten) && temp->Contains(five) && temp->Contains(seven))
	{
		result = true;
	}
	
	return result;
}

//Runs auto test for non-const copy constructor
bool AutoTestNonConstConstruct()
{

	bool result = false;
	//Variabels used for Insert
	int ten = 10;
	int five = 5;
	int seven = 7;


	autoTestTreeTwo = new BinarySearchTree<int>(); //Creates empty BST

	//Inserts variables into autoTestTreeTwo
	autoTestTreeTwo->Insert(seven);
	autoTestTreeTwo->Insert(ten);
	autoTestTreeTwo->Insert(five);

	BinarySearchTree<int> *temp = new BinarySearchTree<int>(*autoTestTreeTwo); //Creates temp BST passing in autoTestTreeTwo into constructor

	//If temp tree has same values as autoTestTreeTwo sets result to true
	if (temp->Contains(ten) && temp->Contains(five) && temp->Contains(seven))
	{
		result = true;
	}
	return result;
}

//Auto test for Destructor
bool AutoTestDestructor()
{
	bool result = false;
	//Variables used for Insert
	const int ten = 10;
	const int five = 5;
	const int seven = 7;
	const int two = 2;
	const int twelve = 12;
	const int nine = 9;


	autoTestTree = new BinarySearchTree<int>(); //Creates empty BST
	//Insers variables into BST
	autoTestTree->Insert(seven);
	autoTestTree->Insert(ten);
	autoTestTree->Insert(five);
	autoTestTree->Insert(two);
	autoTestTree->Insert(twelve);
	autoTestTree->Insert(nine);

	autoTestTree->BinarySearchTree::~BinarySearchTree(); //Explicity call to BST destructor

	//calls GetRoot on BST if it is equal to null point sets result to true
	if (autoTestTree->GetRoot() == nullptr)
		result = true;

	return result;
}

//Auto Test for Insert of const variable types
bool AutoTestConstInsert()
{
	bool result = false;
	//Const variable
	const int insert = 10;

	autoTestTree = new BinarySearchTree<int>(); //Creates empty BST

	//Inserts variable into BST
	autoTestTree->Insert(insert);

	//If BST contains variable sets result to true
	if (autoTestTree->Contains(insert))
	{
		result = true;
	}
	return result;
}

//Auto test for Insert of non-const variable types
bool AutoTestNonConstInsert()
{
	bool result = false;
	
	//variable for insert
	int insert = 10;

	autoTestTree = new BinarySearchTree<int>(); //Creates empty BST

	autoTestTree->Insert(insert); //Inserts variable

	//If BST contains variable, sets result to true
	if (autoTestTree->Contains(insert))
	{
		result = true;
	}
	return result;
}

//Auto test for Delete function
bool AutoTestDelete()
{
	bool result = false;

	//Variables for Insert
	const int ten = 10;
	const int five = 5;
	const int seven = 7;
	

	autoTestTree = new BinarySearchTree<int>(); //Creates empty BST

	//Inserts variables
	autoTestTree->Insert(ten);
	autoTestTree->Insert(five);
	autoTestTree->Insert(seven);

	autoTestTree->Delete(five); //Deletes variabel five

	//If BST does not contain variable five sets result to true
	if (!autoTestTree->Contains(five))
	{
		result = true;
	}
	return result;
}

/*
	RunAutoTests function called from UserOptions, runs each AutoTest and prints to console the results of each test
*/
void RunAutoTests()
{
	if (AutoTestDefaultConstruct())
	{
		cout << endl << "Default Constructor Works." << endl;
	}
	else
	{
		cout << endl << "Fail on Default Constructor." << endl;
	}
	if (AutoTestConstConstruct())
	{
		cout << endl << "Const Copy Constructor Works." << endl;
	}
	else
	{
		cout << endl << "Fail on Const Copy Consturctor." << endl;
	}
	if (AutoTestNonConstConstruct())
	{
		cout << endl << "NonConst Copy Constructor Works." << endl;
	}
	else
	{
		cout << endl << "Fail on NonConst Copy Consturctor." << endl;
	}
	if (AutoTestDestructor())
	{
		cout << endl << "Destructor Works." << endl;
	}
	else
	{
		cout << endl << "Fail on Destructor." << endl;
	}
	if (AutoTestConstInsert())
	{
		cout << endl << "Const Insert Works" << endl;
	}
	else
	{
		cout << endl << "Fail on Const Insert." << endl;
	}
	if (AutoTestNonConstInsert())
	{
		cout << endl << "NonConst Insert Works." << endl;
	}
	else
	{
		cout << endl << "Fail on NonConst Insert." << endl;
	}
	if (AutoTestDelete())
	{
		cout << endl << "Const Delete Works." << endl;
	}
	else
	{
		cout << endl << "Fail on Const Delete." << endl;
	}
}

//Run Manual Test called from User Options
void RunManualTests()
{
	int userInput = -1; //Sets userInput

	//Loop to run while userInput does not equal 9
	while (userInput != 9)
	{
		//Manual test options
		cout << endl;
		cout << "Manual Testing Choose an option" << endl;
		cout << "1. Create Binary Search Tree of Type Integer" << endl;
		cout << "2. Create Binary Search Tree of Type Float" << endl;
		cout << "3. Create Binary Search Tree of Type Employee" << endl;
		cout << "4. Add to a Tree" << endl;
		cout << "5. Print a Tree" << endl;
		cout << "6. Search a Tree" << endl;
		cout << "7. Delete from a Tree" << endl;
		cout << "8.  Previous Menu" << endl;

		string inputString; //String to hold userInput from command line

		//Try block to catch exceptions from user input
		try {
			getline(cin, inputString); //Get user input from command line, set inputString to the value entered by the user

			userInput = stoi(inputString); //Convert user input to integer, set userInput variable to the integer

			//Switch based on userInput
			switch (userInput)
			{
			case 1:
				//Calls CreateEmptyBinaryTree if result is true prints to console
				if (CreateEmptyBinaryTree(userInput))
					cout << "Succesfully created Binary Search Tree of type Integer." << endl;
				break;
			case 2:
				//Calls CreateEmptyBinaryTree if result is true prints to console
				if (CreateEmptyBinaryTree(userInput))
					cout << "Succesfully created Binary Search Tree of type Float." << endl;
				break;
			case 3:
				//Calls CreateEmptyBinaryTree if result is true prints to console
				if (CreateEmptyBinaryTree(userInput))
					cout << "Succesfully created Binary Search Tree of type Employee." << endl;
				break;
			case 4:
				ChooseTreeToAddTo();
				break;
			case 5:
				ChooseTreeToPrint();
				break;
			case 6:
				ChooseTreeToSearch();
				break;
			case 7:
				ChooseTreeToDeleteFrom();
				break;
			case 8:
				UserOptions();
				break;
			default:
				//If userInput didn't throw an exception, but didn't fit this case calls RunManualTests funtion again
				cout << "Invalid Input. Please select an option" << endl;
				RunManualTests();
				break;
			}
		}
		//Catches invalid arugment exceptions for string to integer conversions, prints exception to console, then calls RunManualTests funtion
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			RunManualTests();
		}
	}
}

//Creates empty binary tree based on user input
bool CreateEmptyBinaryTree(int input)
{
	bool result = false;
	//Switch based on user input
	switch (input)
	{
	case 1:
		manualTestInt = new BinarySearchTree<int>(); //Creates empty BST of type int
		//If BST of int is not null pointer returns true
		if (manualTestInt != nullptr)
			result = true;
		break;
	case 2:
		manualTestFloat = new BinarySearchTree<float>(); //Creates empty BST of type float
		//If BST of float is not null point returns ture
		if (manualTestFloat != nullptr)
			result = true;
		break;
	case 3:
		manutalTestEmployee = new BinarySearchTree<Employee>(); //Creates empty BST of type Employee
		//If BST of Employee is not null point returns true
		if (manutalTestEmployee != nullptr)
			result = true;
		break;
	}

	return result;
}

//Menu for choosing BST to insert objects to
void ChooseTreeToAddTo()
{
	//Variables for holding user input
	int input;
	string inputString;

	//Try block to catch input exceptions
	try
	{
		//Prints menu
		cout << endl;
		cout << "Chose a Tree to Add items to" << endl;
		cout << "1. Integer Tree" << endl;
		cout << "2. Float Tree" << endl;
		cout << "3. Employee Tree" << endl;
		cout << "4. Previous Menu" << endl;
		getline(cin, inputString); //Gets user input from console
		input = stoi(inputString); //converts user input to integer, sets input to that value

		//If user input is 4 calls RunManualTests function
		if (input == 4)
			RunManualTests();
		//Else calls InsertToTree function passing the users input
		else
			//Insert to Tree
			InsertToTree(input);
	}
	//Catches exception in the string to integer converstions, if value is not an interger, prints exception then recusively calls this function
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseTreeToAddTo();
	}
}

//Function for choosing which BST to print
void ChooseTreeToPrint()
{
	//Variables for user input
	string inputString;
	int input;

	//Try block to catch invalid arugment exceptions
	try
	{
		//Prints menu
		cout << endl;
		cout << "Select a tree to print" << endl;
		cout << "1. Integer Tree" << endl;
		cout << "2. Float Tree" << endl;
		cout << "3. Employee Tree" << endl;
		cout << "4. Previous Menu" << endl;
		getline(cin, inputString); //Gets user input
		input = stoi(inputString); //converts input to integer sets input variable to that value

		//Switch based on user input
		switch (input)
		{
		case 1:
			//Prints int tree
			PrintIntTree();
			break;
		case 2:
			//Prints float tree
			PrintFloatTree();
			break;
		case 3:
			//Prints Employee Tree
			PrintEmployeeTree();
			break;
		case 4:
			//Calls RunManualTests (previous menu)
			RunManualTests();
			break;
		default:
			//If user entered an integer that isn't on the menu, prints error recursively calls this function
			cout << "Invalid Input, please select an option" << endl;
			ChooseTreeToPrint();
			break;
		}
	}
	//Catches invalid arument exception, prints exception recursively calls this function
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseTreeToPrint();
	}
}

//Function for choosing which BST to search
void ChooseTreeToSearch()
{
	//Variables for user input
	string inputString;
	int input;

	//Variables to hold values to search
	int intToFind;
	float floatToFind;
	Employee *empToFind;

	//Try block to catch user input exceptions
	try
	{
		//Prints menu
		cout << endl;
		cout << "Select a list to search" << endl;
		cout << "1. Integer List" << endl;
		cout << "2. Float List" << endl;
		cout << "3. Employee List" << endl;
		cout << "4. Previous Menu" << endl;

		getline(cin, inputString); //Gets user input
		input = stoi(inputString); //Converts user input to integer

		//Switch block based on user input
		switch (input)
		{
			//Integer case
		case 1:
			//Prints option
			cout << "Would you like to search for an integer? y/n" << endl;
			getline(cin, inputString); //Gets user Input

			//If users type y or Y
			if (inputString == "y" || inputString == "Y")
			{
				//Print
				cout << "Enter the integer you want to find." << endl;
				getline(cin, inputString); //gets user input
				intToFind = stoi(inputString); //converts input to integer, sets intToFind to that value

				//If the manualTestInt BST contains intToFind
				if (manualTestInt->Contains(intToFind))
				{
					//Prints it was found call this function again for another search
					cout << intToFind << " is in the Tree." << endl;
					ChooseTreeToSearch();
				}
				else
				{
					//Prints it was not found call this function again for another search
					cout << intToFind << " was not found." << endl;
					ChooseTreeToSearch();
				}
			}
			//If user type n or N
			else if (inputString == "n" || inputString == "N")
			{
				//Calls RunManualTest(previous menu)
				RunManualTests();
			}
			//User didn't input a proper value, prints error, calls this function again
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseTreeToSearch();
			}
			break;
			//Float case
		case 2:
			//Prints option
			cout << "Would you like to search for a float? y/n" << endl;
			getline(cin, inputString); //Gets user input
			//If user input y or Y
			if (inputString == "y" || inputString == "Y")
			{
				//Prints option
				cout << "Enter the float you want to find." << endl;
				getline(cin, inputString); //Gets user input
				floatToFind = stof(inputString); //converts input to float sets floatToFind to that value

				//If manualTestFloat BST conatins floatToFind
				if (manualTestFloat->Contains(floatToFind))
				{
					//Prints float was found, calls this function again for another search
					cout << floatToFind << " is in the Tree." << endl;
					ChooseTreeToSearch();
				}
				else
				{
					//Prints float was not found, calls this function again for another search
					cout << floatToFind << " was not found." << endl;
					ChooseTreeToSearch();
				}
			}
			//If user input n or N calls RunManualTests (previous menu)
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTests();
			}
			//If user input was not an option, prints error, calls this function again
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseTreeToSearch();
			}
			break;
			//Employee Case
		case 3:
			//Prints option
			cout << "Would you like to search for an Employee? y/n" << endl;
			getline(cin, inputString); //gets user input
			//If user input y or Y
			if (inputString == "y" || inputString == "Y")
			{
				empToFind = CreateEmployee(); //Calls CreateEmployee function and sets empToFind to the value returned

				//If manualTestEmployee contains empToFind
				if (manutalTestEmployee->Contains(*empToFind))
				{
					//Prints employee was found and calls this function again for another search
					cout << "\"" << empToFind->ToString() << "\" is in the Tree" << endl;
					ChooseTreeToSearch();
				}
				else
				{
					//Prints employee was not found and calls this function again for another search
					cout << "\"" << empToFind->ToString() << "\" was not found" << endl;
					ChooseTreeToSearch();
				}
			}
			//If user input n or N calls RunManualTests (previous menu)
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTests();
			}
			//If user input was not correct, prints error, calls this function again
			else
			{
				cout << "Invalid input, please select an option" << endl;
				ChooseTreeToSearch();
			}
			break;
			//Previous Menu case, calls RunManualTests function
		case 4:
			RunManualTests();
			break;
			//If input didn't throw exception but not correct value, prints error calls this function again
		default:
			cout << "Invalid input, please select an option" << endl;
			ChooseTreeToSearch();
			break;
		}
	}
	//Catches exception for string to int, or string to float converstions, prints exception and calls this function again
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseTreeToSearch();
	}
}

//Function for choosing which BST to delete from
void ChooseTreeToDeleteFrom()
{
	//Variables for user input
	string inputString;
	int input;

	//Try block to catch exceptions from user input
	try
	{
		//Prints menu
		cout << endl;
		cout << "Selete a list to delete from" << endl;
		cout << "1. Integer List" << endl;
		cout << "2. Float List" << endl;
		cout << "3. Employee List" << endl;
		cout << "4. Previous Menu" << endl;

		getline(cin, inputString); //Gets user input
		input = stoi(inputString); //Converts user input to string, sets input variable to that value

		//Switch based on input
		switch (input)
		{
			//Int case
		case 1:
			//Float case
		case 2:
			//Employee case
		case 3:
			DeleteFromTree(input); //Calls DeleteFromTree passing in user input, the first three cases will all use this call
			break;
			//Calls RunManualTests (preivous menu)
		case 4:
			RunManualTests();
			break;
			//Prints error if input was not a valid option calls this function again
		default:
			cout << "Invlaid input, please select an option" << endl;
			ChooseTreeToDeleteFrom();
			break;
		}
	}
	//Catches exception for string to int conversion, prints exception, calls this function again
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		ChooseTreeToDeleteFrom();
	}
}

//Inserts to tree based on user input
void InsertToTree(int input)
{
	//Variables for insert
	int intToAdd;
	float floatToAdd;
	int caseInput = -1;

	//Variable for user input
	string inputString;

	//Try block to catch input exceptions
	try
	{
		//prints spacer
		cout << endl;
		//Switch block based on user input
		switch (input)
		{
			//Int case
		case 1:
			//If manualTestInt BST is created
			if (manualTestInt != nullptr)
			{
				//Prints option
				cout << "Would you like to insert an integer to the list? y/n" << endl;
				getline(cin, inputString); //Gets user input
				//If user input y or Y
				if (inputString == "y" || inputString == "Y")
				{
					//prints option
					cout << endl;
					cout << "Enter an integer to add to the list" << endl;
					getline(cin, inputString); //gets user input
					intToAdd = stoi(inputString); //converts string to int, sets intToAdd to that value
					manualTestInt->Insert(intToAdd); //Calls Insert function on manualTestInt passing intToAdd
					//Prints the int was added
					cout << "The number " << intToAdd << " was added to the list" << endl;
					InsertToTree(input); //Calls this function again to add another value
				}
				//If user input n or N returns out of this function
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				//if user input was not a valid option, prints error, calls this function again
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToTree(input);
				}
			}
			//If manualTestInt is not created, prints error, calls this function again
			else
			{
				cout << "The integer list does not exist. Please initilize one first" << endl;
				ChooseTreeToAddTo();
			}
			break;
			//Float case
		case 2:
			//If manualTestFloat is created
			if (manualTestFloat != nullptr)
			{
				//Prints options
				cout << "Would you like to insert a float to the list? y/n" << endl;
				getline(cin, inputString); //gets user input
				//If user input y or Y
				if (inputString == "y" || inputString == "Y")
				{
					//Prints option
					cout << endl;
					cout << "Enter a float to add to the list" << endl;
					getline(cin, inputString); //gets user input
					floatToAdd = stof(inputString); //converts string to float sets floatToAdd to that value
					manualTestFloat->Insert(floatToAdd); //Calls Insert function on manualTestFloat
					//Prints the float was added
					cout << "The number " << floatToAdd << " was added to the list" << endl;
					InsertToTree(input); //Calls this function again to add another value
				}
				//If user input n or N returns out of this function
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				//If user input was invalid, prints error calls this function again
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToTree(input);
				}
			}
			//If manualTestFloat has not been created, prints error, calls this function again
			else
			{
				cout << "The float list does not exist. Please initialize one first" << endl;
				ChooseTreeToAddTo();
			}
			break;
			//Employee case
		case 3:
			//if manualTestEmployee has been created
			if (manutalTestEmployee != nullptr)
			{
				//Prints options
				cout << "Would you like to insert an Employee to the list? y/n" << endl;
				getline(cin, inputString); //gets user input
				//If user input y or Y
				if (inputString == "y" || inputString == "Y")
				{
					//Creates loop based on user input
					while (caseInput != 3)
					{
						//Prints menu
						cout << endl;
						cout << "Select an option" << endl;
						cout << "1. Create Custom Employee" << endl;
						cout << "2. Use Default Employee" << endl;
						cout << "3. Back" << endl;
						getline(cin, inputString); //Gets user input
						caseInput = stoi(inputString); //converts string to int sets caseInput to that value

						//Swithc based on user input
						switch (caseInput)
						{
							//Create custom employee
						case 1:
							Employee *customEmp;
							customEmp = CreateEmployee();
							manutalTestEmployee->Insert(*customEmp);
							break;
							//Create default employee
						case 2:
							Employee *defaultEmp;
							defaultEmp = DefaultEmployee();
							manutalTestEmployee->Insert(*defaultEmp);
							break;
							//Invalid input, prints error, back to begining of loop
						default:
							cout << "Invalid Input, please select an option" << endl;
							break;
						}
					}
				}
				//If user input n or N returns out of this function
				else if (inputString == "n" || inputString == "N")
				{
					return;
				}
				//If user input was invalid, print error, call this function again
				else
				{
					cout << "Invlaid input please select an option" << endl;
					InsertToTree(input);
				}
			}
			//If manualTestEmployee was not created, print error, call this function again
			else
			{
				cout << "The Employee list does not exist. Please initialize one first" << endl;
				ChooseTreeToAddTo();
			}
			break;
			//If user input was invalid, print error, call this function again
		default:
			cout << "Invalid input. Please select an option" << endl;
			ChooseTreeToAddTo();
			break;
		}
	}
	//If string to int, or string to float conversion threw exception, print exception, call this function again
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		InsertToTree(input);
	}
}

//Function to delete from BST based on user input
void DeleteFromTree(int input)
{
	string inputString; //Variable for user input

	//Variables for values to delete
	int deleteInt;
	float deleteFloat;
	Employee *deleteEmployee;

	//Try block to catch invalid argument exceptions
	try
	{
		//Prints spacer
		cout << endl;
		//Switch based on user input
		switch (input)
		{
			//Int case
		case 1:
			//Prints option
			cout << "Would you like to remove a value from the integer Tree? y/n" << endl;
			getline(cin, inputString); //Gets user input
			//if user input y or Y
			if (inputString == "y" || inputString == "Y")
			{
				//Prints option
				cout << "Enter the integer value you want to remove." << endl;
				getline(cin, inputString); //gets user input
				deleteInt = stoi(inputString); //converts user input to int sets deleteInt to that value

				//if manualTestInt does not contain deleteInt, prints message, calls this function again
				if (!manualTestInt->Contains(deleteInt))
				{
					cout << "The value entered was not in the Tree." << endl;
					DeleteFromTree(input);
				}
				//If manualTestInt contains deleteInt, calls Delete function, prints message, calls this function again
				else
				{
					manualTestInt->Delete(deleteInt);
					cout << deleteInt << " was removed from the Tree." << endl;
					DeleteFromTree(input);
				}
			}
			//If user input n or N, calls RunManualTests (previous Menu)
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTests();
			}
			//If user input was invalid, prints error, calls this fucntion again
			else
			{
				cout << "Invalid input, please select an option." << endl;
				DeleteFromTree(input);
			}
			break;
			//Float case
		case 2:
			//Prints option
			cout << "Would you like to remove a value from the float Tree? y/n" << endl;
			getline(cin, inputString); //Gets user input
			//If user input y or Y
			if (inputString == "y" || inputString == "Y")
			{
				//Prints option
				cout << "Enter the float value you want to remove." << endl;
				getline(cin, inputString); //Gets user input
				deleteFloat = stof(inputString); //Converst user input to float, sets deleteFloat to that value

				//If manualTestFloat does not contain deleteFloat, prints message, calls this function again
				if (!manualTestFloat->Contains(deleteFloat))
				{
					cout << "The value entered was not found in the Tree." << endl;
					DeleteFromTree(input);
				}
				//If manualTestFloat contains deleteFloat
				else
				{
					manualTestFloat->Delete(deleteFloat); //Calls Delete Function
					cout << deleteFloat << " was removed from the Tree." << endl; //Prints message
					DeleteFromTree(input); //Calls this function again
				}
			}
			//If user input n or N, calls RunManualTests (previous Menu)
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTests();
			}
			//if user input was invalid, prints error, calls this function again
			else
			{
				cout << "Invalid input, please select an option." << endl;
				DeleteFromTree(input);
			}
			break;
			//Employee Case
		case 3:
			//Prints option
			cout << "Would you like to remove a value from the Employee Tree? y/n" << endl;
			getline(cin, inputString); //Gets user input
			//If user input y or Y
			if (inputString == "y" || inputString == "Y")
			{
				deleteEmployee = CreateEmployee(); //Calls createEmployee function sets deleteEmployee to the value returned

				//If manualTestEmployee does not contain deleteEmployee, prints message, calls this function again
				if (!manutalTestEmployee->Contains(*deleteEmployee))
				{
					cout << "The Employee was not found in the Tree." << endl;
					DeleteFromTree(input);
				}
				//if manualTestEmployee contains deleteEmployee, calls Delete function, prints message, calls this function again
				else
				{
					manutalTestEmployee->Delete(*deleteEmployee);
					cout << "The following employee was removed from the Tree." << deleteEmployee->ToString() << endl;
					DeleteFromTree(input);
				}
			}
			//If user input n or N, calls RunManualTest (Previous menu)
			else if (inputString == "n" || inputString == "N")
			{
				RunManualTests();
			}
			//If user input was invalid, prints error, calls this function again
			else
			{
				cout << "Invalid input, please select an option" << endl;
				DeleteFromTree(input);
			}
			break;
		}
	}
	//Catches exception thrown from string to int, or string to float conversion, prints exception, calls this function again
	catch (invalid_argument e1)
	{
		cout << e1.what() << endl << endl;
		DeleteFromTree(input);
	}
}

//Creates a Custom employee object
Employee* CreateEmployee()
{
	//Variables for employee object
	string empName;
	int empID;
	float empSalary;

	bool validInput = false;

	//variable for user input
	string inputString;

	//Loop continues while user input remains invalid
	while (!validInput)
	{
		//try block for invalid argument exceptions
		try
		{
			//Prints option
			cout << endl;
			cout << "Enter the Employee Name" << endl;
			getline(cin, inputString); //Gets user input
			empName = inputString; //Sets employee name to user input

			//Prints option
			cout << endl << "Enter Employee ID number" << endl;
			getline(cin, inputString); //gets user input
			empID = stoi(inputString); //converts user input to int, sets empID to that value

			//Prints option
			cout << endl << "Enter Employee salary" << endl;
			getline(cin, inputString); //gets user input
			empSalary = stof(inputString); //converts user input to float, sets empSalary to that float
			validInput = true;
		}
		//Catches exceptions thrown from string to int or string to float conversions, prints exception, sets validInput to false
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			validInput = false;
		}
	}

	Employee *temp = new Employee(empName, empID, empSalary); //Creates employee object with the user input values for empName, empID, and empSalary.

	return temp; //returns created employee

}

//Creates an Employee object using default constructor
Employee* DefaultEmployee()
{
	Employee *temp = new Employee();

	return temp;
}

//Function prints int BST
void PrintIntTree()
{
	//if manualTestInt bst has not been created, prints message, returns out of function
	if (manualTestInt == nullptr)
	{
		cout << endl;
		cout << "Integer Tree has not been created." << endl;
		return;
	}
	//If manualTestInt has been created, but no values have been added, prints message, returns out of function
	else if (manualTestInt->GetRoot() == nullptr)
	{
		cout << endl << "Integer Tree has no data." << endl;
		return;
	}
	//Prints message, calls manualTestInt Print function
	else
	{
		cout << endl << "Binary Search Tree of type Integer." << endl;
		manualTestInt->Print();
	}
}

//Function prints float BST
void PrintFloatTree()
{
	//if manualTestFloat has not been created, prints message, returns out of function
	if (manualTestFloat == nullptr)
	{
		cout << endl;
		cout << "Float Tree has not been created." << endl;
		return;
	}
	//if manualTestFloat has been created, but no values have been added, prints message, returns out of function
	else if (manualTestFloat->GetRoot() == nullptr)
	{
		cout << endl << "Float Tree has no data." << endl;
		return;
	}
	//Prints message, calls manualTestFloat's Print function
	else
	{
		cout << endl << "Binary Search Tree of type Float." << endl;
		manualTestFloat->Print();
	}
}

//Function prints Employee BSt
void PrintEmployeeTree()
{
	//if manualTestEmployee has not been created, prints message, returns out of function
	if (manutalTestEmployee == nullptr)
	{
		cout << endl;
		cout << "Employee Tree has not been created." << endl;
		return;
	}
	//If manualTestEmployee has been created, but no values have been added, prints message, returns out of function
	else if (manutalTestEmployee->GetRoot() == nullptr)
	{
		cout << endl << "Employee Tree has no data." << endl;
		return;
	}
	//Prints message, calls manualTestEmployee's Print Function
	else
	{
		cout << endl << "Binary Search Tree of type Employee." << endl;
		manutalTestEmployee->Print();
	}
}

//Function for User Options Menu
void UserOptions()
{
	int input = -1; //Variable for user input

	//Loop continues as long as input does not equal 3
	while (input != 3)
	{
		//Prints menu
		cout << endl << "Choose an Option Below!" << endl;
		cout << "1. Run Manual Testing of BinarySearchTree Class" << endl;
		cout << "2. Run Automatic Testing of BinarySearchTree Class" << endl;
		cout << "3. Exit Application" << endl;

		string inputString; //Variable for user input

		//Try block for invalid user input
		try
		{
			getline(cin, inputString); //gets user input

			input = stoi(inputString); //converts user input to int, sets input variable to that value


			//If user input was 1, calls RunManualTests
			if (input == 1)
			{
				RunManualTests();
			}
			//If user input was 2, calls RunAutoTests
			else if (input == 2)
			{
				RunAutoTests();
			}
			//If user input is anything but 1, 2 or 3, prints error, calls UserOptions again
			else if (input != 3)
			{
				cout << "Invalid Input please select an option" << endl << endl;
				UserOptions();
			}
		}
		//Catches exception from user input, prints exception, calls this function again
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			UserOptions();
		}
	}
	exit(0); //exits application
}


