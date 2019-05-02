#pragma once
/*
Lab 6
Made by Zach Dubuc
May 02, 2019

Header File for Lab6

*/
class Lab6
{
public:
	Lab6();
	~Lab6();

	void getValues();
	void calculateSeries();
	void display();


private:
	double m_FirstTerm;
	double m_CommonRatio;
	double m_Precision;
	double m_Total;


};