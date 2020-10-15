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
	
	private:
		//data member
		bool venomous_;
};

#endif //FISH_H_
