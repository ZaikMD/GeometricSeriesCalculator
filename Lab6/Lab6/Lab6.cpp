/*
Lab 6 
Made by Zach Dubuc
May 02, 2019

The purpose of this lab is to calculate a geometric serires and output the result to the user

*/

#include "pch.h"
#include <iostream>
#include <string>
#include "Lab6.h"

using namespace std;
//Main
int main()
{
	Lab6 lab;
	lab.getValues();
	lab.calculateSeries();
	lab.display();
}
//Constuctor, set to -1 for error checking
Lab6::Lab6()
{
	m_FirstTerm = -1;
	m_CommonRatio = -1;
	m_Precision = -1;
	m_Total = -1;
}

//Deconstructor
Lab6::~Lab6()
{

}

//Get Values will get the values from the user and make sure that they are valid inputs for each variable.
//I was going to make another function to error check, but as it's only three inputs and each has different parameters they need to be within,
//I just kept it all in get Values
void Lab6::getValues()
{
	
	while (m_FirstTerm <= 0)
	{
		cout << "First term: " << endl;
		cin >> m_FirstTerm;

		if (m_FirstTerm <= 0)
		{
			cout << "Error: Must be greater than 0" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	while (m_CommonRatio <= -1 || m_CommonRatio >= 1)
	{
		cout << "Common Ratio: " << endl;
		cin >> m_CommonRatio;

		if (m_CommonRatio <= -1 || m_CommonRatio >= 1)
		{
			cout << "Error: Must be between -1 and 1" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	while (m_Precision < 0)
	{
		cout << "Precision: " << endl;
		cin >> m_Precision;

		if (m_Precision < 0)
		{
			cout << "Error: Must be greater than 0" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
	
}
//Calculate series will calculate the geometric series
void Lab6::calculateSeries()
{
	m_Total = 0;
	double term = m_FirstTerm;
	while (term > m_Precision || -term > m_Precision)
	{
		m_Total += term;
		term *= m_CommonRatio;
	}
}
//Display will display the total to the user, rounded to the precision that the user inputs
void Lab6::display()
{
	//String for the decimal places
	string decimalPlaces = to_string(m_Precision);
	//get the length of the string - 3 (3 because two zeroes are added for some reason) to get the correct amount of decimal places the user wants
	int precision = decimalPlaces.length() - 3;
	//set the precision for cout
	cout.precision(precision);
	cout << "Total: " <<  m_Total << endl;
}
