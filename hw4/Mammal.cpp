/*
Title: Project 2
Name: Tim Zhen
Description: The implementation for the Mammal class
Date: 9/12/2019
*/

#include "Mammal.hpp"
#include <iostream>
using namespace std;

Mammal::Mammal()
{
	hair_ = false;
	airborne_ = false;
	aquatic_ = false;
	toothed_ = false;
	fins_ = false;
	tail_ = false;
	legs_ = 0;
}

Mammal::Mammal(string name, bool domestic, bool predator)
{
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
	hair_ = false;
	airborne_ = false;
	aquatic_ = false;
	toothed_ = false;
	fins_ = false;
	tail_ = false;
	legs_ = 0;
}

bool Mammal::hasHair() const
{
	return hair_;
}

bool Mammal::isAirborne() const
{
	return airborne_;
}

bool Mammal::isAquatic() const
{
	return aquatic_;
}

bool Mammal::isToothed() const
{
	return toothed_;
}

bool Mammal::hasFins() const
{
	return fins_;
}

bool Mammal::hasTail() const
{
	return tail_;
}

int Mammal::legs() const
{
	return legs_;
}	

void Mammal::setHair()
{
	hair_ = true;
}

void Mammal::setAirborne()
{
	airborne_ = true;
}

void Mammal::setAquatic()
{
	aquatic_ = true;
}

void Mammal::setToothed()
{
	toothed_ = true;
}

void Mammal::setFins()
{
	fins_ = true;
}

void Mammal::setTail()
{
	tail_ = true;
}

void Mammal::setLegs(int legs)
{
	legs_ = legs;
}

/* will display:
	"animal_name is [not] domestic and [it is / is not] a predator,\n
 	it is [not] airborne and it is [not] aquatic,\n
 	it has [no] hair, [no] teeth, [no] fins, [no] tail and legs_ legs.\n\n” */
void Mammal::display()
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
		cout << "and it is aquatic," << endl;
	if (isAquatic() == false)
		cout << "and it is not aquatic," << endl;
	
	//check hair
	if (hasHair() == true)
		cout << "it has hair, ";
	if (hasHair() == false)
		cout << "it has no hair, ";
	
	//check teeth
	if (isToothed() == true)
		cout << "teeth, ";
	if (isToothed() == false)
		cout << "no teeth, ";
	
	//check fins
	if (hasFins() == true)
		cout << "fins, ";
	if (hasFins() == false)
		cout << "no fins, ";
		
	//check tail
	if (hasTail() == true)
		cout << "tail and ";
	if (hasTail() == false)
		cout << "no tail and ";
		
	//print how many legs
	cout << legs() << " legs." << endl << endl;
	
}
