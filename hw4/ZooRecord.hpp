/*
TiTle: Project 3
Name: Tim Zhen
Description: The interface for the Zoo Record class
Date:9/24/19
*/
#ifndef ZOO_HPP_
#define ZOO_HPP_

#include <iostream>
#include "List.hpp"
#include "Animal.hpp"
#include "Bird.hpp"
#include "Mammal.hpp"
#include "Fish.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class ZooRecord:public List<Animal*>
{
	public:
		ZooRecord() = default; //default constructor
		virtual ~ZooRecord();
		/**parameterized constructor
		@pre the input file is expected to be in CSV (comma separated value) format
		as:
		"animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbo
		ne,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
		@param input_file_name the name of the input file
		@post adds Animal pointers to Animal-derived dynamic objects to record as
		per the data in the input file
		**/
 		ZooRecord(string input_file_name);
 		
 		virtual void clear() override;
 		virtual bool remove(size_t position) override;
 		
 		/**@post displays all animals in record, one per line by calling appropriate
		object’s display method” **/
 		void display(); 
};

#endif
