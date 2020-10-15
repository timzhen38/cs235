/*
Title: Project 2
Name: Tim Zhen
Description: The implementation for the Bird class
Date: 9/12/2019
*/

#include "Bird.hpp"
#include <iostream>
using namespace std;

Bird::Bird()
{
	airborne_ = false;
	aquatic_ = false;
}

Bird::Bird(string name, bool domestic, bool predator)
{
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
	airborne_ = false;
	aquatic_ = false;
}

bool Bird::isAirborne() const
{
	return airborne_;
}

bool Bird::isAquatic() const
{
	return aquatic_;
}

void Bird::setAirborne()
{
	airborne_ = true;
}

void Bird::setAquatic()
{
	aquatic_ = true;
}

/* will display:
	“animal_name is [not] domestic and [it is / is not] a predator,\n
 	it is [not] airborne and it is [not] aquatic.\n\n” */
void Bird::display()
{
	cout << getName();
	
	//check domestic
	if (isDomestic() == true)
		cout << " is domestic ";
	if (isDomestic() == false)
		cout << " is not domestic ";
		
	//check predator
	if (isPredator() == true)
		cout << "and it is a predator," << endl;
	if (isPredator() == false)
		cout << "and is not a predator," << endl;
		
	//check airborne
	if (isAirborne() == true)
		cout << "it is airborne ";
	if (isAirborne() == false)
		cout << "it is not airborne ";
	
	//check aquatic
	if (isAquatic() == true)
		cout << "and it is aquatic." << endl << endl;
	if (isAquatic() == false)
		cout << "and it is not aquatic." << endl << endl;
		

}
