/*
Title: Project 2
Name: Tim Zhen
Description: The interface for the Bird class
Date: 9/10/2019
*/

#ifndef BIRD_H_
#define BIRD_H_

#pragma once
#include "Animal.hpp"
#include <iostream>
using namespace std;

class Bird : public Animal
{
	public:
		//constructors
		Bird();
		Bird(string name, bool domestic = false, bool predator = false);
		
		//accessors
		bool isAirborne() const;
		bool isAquatic() const;
		
		//mutators
		void setAirborne();
		void setAquatic();
	
	private:
		//data members
		bool airborne_;
		bool aquatic_;
};

#endif //BIRD_H_
