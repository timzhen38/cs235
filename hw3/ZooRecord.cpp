/*
Title: Project 3
Name: Tim Zhen
Description: The implementation of Zoo Record
Date: 9/24/19
*/

#include <iostream>
#include "ZooRecord.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//default constructor
ZooRecord::ZooRecord():ArrayBag()
{

}

/**parameterized constructor
 @pre the input file is expected to be in CSV
 (comma separated value) format as:
 "animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,
 backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
 @param input_file_name the name of the input file
 @post adds Animal objects to record as per the data in the input file
 **/
ZooRecord::ZooRecord(string input_file_name):ArrayBag()
{
	string theAnimal, word, animal_name, predator_temp, domestic_temp;
	bool predator_status, domestic_status;
	ifstream fin(input_file_name);
	getline(fin,theAnimal);
	while (getline(fin,theAnimal))
	{
		int counter = 0; //counter for which column we are currently checking
		
		stringstream s(theAnimal); //splits the row into strings
		
		while (getline(s, word, ',')) //reads each string in the row that is separated by 									commas
		{
			if (counter == 0)
			{
				animal_name = word;
			}
			if (counter == 7)
			{
				predator_temp = word; //converting the string into a boolean
				if (word == "1")
					predator_status = true;
				if (word == "0")
					predator_status = false;
			}
			if (counter == 15)
			{
				domestic_temp = word; //convert string into a boolean
				if (word == "1")
					domestic_status = true;
				if (word == "0")
					domestic_status = false;
			}
			counter++;
		}
		Animal tempAnimal(animal_name, domestic_status, predator_status);
		add(tempAnimal); //add the animal into the ArrayBag
		
	}
}

/**@post displays all animals in record, one per line by calling animal's
display method” **/
void ZooRecord::display()
{
	for(int i =0; i < getCurrentSize(); i++){
		items_[i].display();
	}
}

