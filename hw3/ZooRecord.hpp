/*
TiTle: Project 3
Name: Tim Zhen
Description: The interface for the Zoo Record class
Date:9/24/19
*/
#ifndef ZOO_HPP_
#define ZOO_HPP_

#include <iostream>
#include "ArrayBag.hpp"
#include "Animal.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class ZooRecord:public ArrayBag<Animal>
{
	public:
		ZooRecord(); //default constructor
		
		/**parameterized constructor
 		@pre the input file is expected to be in CSV
 		(comma separated value) format as:
 		"animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,
 		backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
 		@param input_file_name the name of the input file
 		@post adds Animal objects to record as per the data in the input file
 		**/
 		ZooRecord(string input_file_name);
 		
 		/**@post displays all animals in record, one per line by calling animal's
		display method” **/
 		void display(); 
};

#endif
