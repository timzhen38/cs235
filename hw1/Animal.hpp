/*
Title: Project 1
Name: Tim Zhen
Description: The interface for the Animal class
Date: 8/30/2019
*/
#pragma once
#include <iostream>
using namespace std;

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
	private:
		//data members
		string name_;
		bool domestic_;
		bool predator_;

};
