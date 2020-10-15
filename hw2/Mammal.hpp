/*
Title: Project 2
Name: Tim Zhen
Description: The interface for the Mammal class
Date: 9/10/2019
*/

#ifndef MAMMAL_H_
#define MAMMAL_H_

#pragma once
#include "Animal.hpp"
#include <iostream>
using namespace std;

class Mammal : public Animal
{
	public:
		//constructors
		Mammal();
		Mammal(string name, bool domestic = false, bool predator = false);
		
		//accessors
		bool hasHair() const;
		bool isAirborne() const;
		bool isAquatic() const;
		bool isToothed() const;
		bool hasFins() const;
		bool hasTail() const;
		int legs() const;
		
		//mutators
		void setHair();
		void setAirborne();
		void setAquatic();
		void setToothed();
		void setFins();
		void setTail();
		void setLegs(int legs);
		
	private:
		//data members
		bool hair_;
		bool airborne_;
		bool aquatic_;
		bool toothed_;
		bool fins_;
		bool tail_;
		int legs_;
};

#endif //MAMMAL_H_
