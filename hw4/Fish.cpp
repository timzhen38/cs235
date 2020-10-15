/*
Title: Project 2
Name: Tim Zhen
Description: The implementation for the Fish class
Date: 9/12/2019
*/

#include "Fish.hpp"
#include <iostream>
using namespace std;

Fish::Fish()
{
	venomous_ = false;
}

Fish::Fish(string name, bool domestic, bool predator)
{
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
	venomous_ = false;
}

bool Fish::isVenomous() const
{
	return venomous_;
}

void Fish::setVenomous()
{
	venomous_ = true;
}

/* will display: 
	“animal_name is [not] domestic, [it is / is not] a predator\n
 	and it is [not] venomous.\n\n" */
void Fish::display()
{
	cout << getName();
	
	//check domestic
	if (isDomestic() == true)
		cout << " is domestic, ";
	if (isDomestic() == false)
		cout << " is not domestic, ";
		
	//check predator
	if (isPredator() == true)
		cout << "it is a predator" << endl;
	if (isPredator() == false)
		cout << "is not a predator" << endl;
		
	//check venomous
	if (isVenomous() == true)
		cout << "and it is venomous." << endl << endl;
	if (isVenomous() == false)
		cout << "and it is not venomous." << endl << endl;
}
