/*
Title: Project 2
Name: Tim Zhen
Description: The interface for the Fish class
Date: 9/10/2019
*/

#ifndef FISH_H_
#define FISH_H_

#pragma once
#include "Animal.hpp"
#include <iostream>
using namespace std;

class Fish : public Animal
{
	public:
		//constructors
		Fish();
		Fish(string name, bool domestic = false, bool predator = false);
		
		//accessor
		bool isVenomous() const;
		
		//mutator
		void setVenomous();
		
		/* will display: 
		“animal_name is [not] domestic, [it is / is not] a predator\n
 		and it is [not] venomous.\n\n" */
		virtual void display() override;
	
	private:
		//data member
		bool venomous_;
};

#endif //FISH_H_
