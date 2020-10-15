/*
Title: Project 1
Name: Tim Zhen
Description: The implementation for the Animal class
Date: 9/5/2019
*/

#include <iostream>
#include "Animal.hpp"
using namespace std;

//default constructor
Animal::Animal()
{
	name_ = "";
	domestic_ = false;
	predator_ = false;
}

//constructor for overloading
Animal::Animal(string name, bool domestic, bool predator)
{
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
}

//accessor function for getting the name
string Animal::getName() const
{
	return name_;
}

//accessor function for seeing whether or not the animal is domestic
bool Animal::isDomestic() const
{
	return domestic_;
}

//accessor function for seeing whether or not the animal is a predator
bool Animal::isPredator() const
{
	return predator_;
}

//mutator function for changing the name
void Animal::setName(string name)
{
	name_ = name;
}

//mutator function for changing domestic status
void Animal::setDomestic()
{
	domestic_ = true;
}

//mutator function for changing predator status
void Animal::setPredator()
{
	predator_ = true;
}

/**@post displays animal data in the form:
 "animal_name is [not] domestic and [it is / is not] a predator\n"
 **/
void Animal::display()
{
	//check domestic
	if (isDomestic() == true)
		cout << getName() << " is domestic ";
	if (isDomestic() == false)
		cout << getName() << " is not domestic ";
		
	//check predator
	if (isPredator() == true)
		cout << "and it is a predator" << endl;
	if (isPredator() == false)
		cout << "and is not a predator" << endl;
}	

bool operator==(const Animal animalOne, const Animal animalTwo)
{
	return (animalOne.getName() == animalTwo.getName()) && (animalOne.isDomestic() == animalTwo.isDomestic()) && (animalOne.isPredator() == animalTwo.isPredator());		
}
