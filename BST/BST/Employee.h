/*
Charles Cozart
CSC382
Custom Employee class used to show BinarySearchTree workability with custom classes
*/

#include <string>
#include <iostream>

using namespace std;

class Employee
{

	//Private member variables
private:

	string name;
	int id;
	float salary;

public:
	Employee() { Init(); } //Default Constructor

	Employee(string & n) : name{ n } {} //Constructor taking only employee name

	Employee(string & n, int & i) : name{ n }, id{ i } {} //Constructor taking employee name and id

	Employee(string & n, int & i, float & s) : name{ n }, id{ i }, salary{ s } {} //Constructor taking employee name, id and salary

	string GetName() { return name; } //Returns the employee name

	int GetID() { return id; } //Returns the employee id

	float GetSalary() { return salary; } //Return the employee salaray

	void Init() { name = "New Employee"; id = 0; salary = 0; } //Initializer function for default constructor

	//Overloads the == operator for comparing Employee's
	const bool & operator==(const Employee & in) const
	{
		bool result = false;

		//If the name, id, and salary of this employee, and the compared employee are equal, returns true
		if (in.name == name && in.id == id && in.salary == salary)
			result = true;

		return result;
	}

	//Overloads the != operator for comparing Employee's
	const bool & operator!=(const Employee & in) const
	{
		return !(*this == in); //Returns the opposite value given by the == operator of this Employee and the passed Employee
	}

	//Overloads the > operator for comparing Employees
	const bool & operator >(const Employee & in) const
	{
		return (salary > in.salary); //if this employee's salary is greater than the compared employee, returns true
	}

	//Overloads the < operator for comparing Employees
	const bool & operator <(const Employee & in) const
	{ 
		return (salary < in.salary); //If this employee's salary is less than the compared employee, returns true;
	}

	//Friend function of the employee class for overloading the ostream operator <<
	friend ostream& operator<<(ostream& out, const Employee & emp);

	//Tostring function of the employee class retuns a string formated for the employee name, id and salary
	string ToString() { string emp = "Name: " + name + "\nID: " + to_string(id) + "\nSalary: " + to_string(salary); return emp; }

};

//Overloads the ostream << operator for the Employee class to return the name, id and Salary of the employee
ostream & operator<<(ostream & out, const Employee & emp)
{
	out << "Name: " << emp.name << " ID: " << to_string(emp.id) << " Salary: " << to_string(emp.salary);
	return out;
}
