/*
Title: Project 1
Name: Tim Zhen
Description: The interface for the Animal class
Date: 8/30/2019
*/
#pragma once
#include <iostream>
using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal
{
	public:
		//constructors
		Animal();
		Animal(string name, bool domestic = false, bool predator = false);
		
		//accessors
		string getName() const;
		bool isDomestic() const;
		bool isPredator() const;
		
		//mutators
		void setName(string name);
		void setDomestic();
		void setPredator();
		
		/**@post displays animal data in the form:
 		"animal_name is [not] domestic and [it is / is not] a predator\n"
 		**/
 		virtual void display(); //its polymorphism time
 		
 		
 		/*friend function to make sure add() doesnt run into problems
 		comparing two animals*/
 		friend bool operator==(const Animal animalOne, const Animal animalTwo);
	protected:
		//data members
		string name_;
		bool domestic_;
		bool predator_;

};
#endif



