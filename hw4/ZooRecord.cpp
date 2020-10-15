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

ZooRecord::~ZooRecord()
{
  clear();
}
/**parameterized constructor
@pre the input file is expected to be in CSV (comma separated value) format
as:
"animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbo
ne,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
@param input_file_name the name of the input file
@post adds Animal pointers to Animal-derived dynamic objects to record as
per the data in the input file
**/
ZooRecord::ZooRecord(string input_file_name):List()
{
	string theAnimal, word, animal_name, species;
	bool predator_status, domestic_status, airborne_status, aquatic_status, venomous_status, 
	hair_status, teeth_status, fins_status, tail_status;
	int legs_num;
	ifstream fin(input_file_name);
	getline(fin,theAnimal);
	while (getline(fin,theAnimal))
	{
		int counter = 0; //counter for which column we are currently checking
		
		stringstream s(theAnimal); //splits the row into strings
		
		while (getline(s, word, ',')) //reads each string in the row that is separated by commas
		{
			if (counter == 0) //name
			{
				animal_name = word;
			}
			if (counter == 1) //hair
			{
				if (word == "1")
					hair_status = true;
				if (word == "0")
					hair_status = false;
			}
			if (counter == 5) //airborne
			{
				if (word == "1")
					airborne_status = true;
				if (word == "0")
					airborne_status = false;
			}
			if (counter == 6) //aquatic
			{
				if (word == "1")
					aquatic_status = true;
				if (word == "0")
					aquatic_status = false;
			}
			if (counter == 7) //predator
			{
				if (word == "1")
					predator_status = true;
				if (word == "0")
					predator_status = false;
			}
			if (counter == 8) //toothed
			{
				if (word == "1")
					teeth_status = true;
				if (word == "0")
					teeth_status = false;
			}
			if (counter == 11) //venomous
			{
				if (word == "1")
					venomous_status = true;
				if (word == "0")
					venomous_status = false;
			}
			if (counter == 12) //fins
			{
				if (word == "1")
					fins_status = true;
				if (word == "0")
					fins_status = false;
			}
			if (counter == 13) //legs
			{
				legs_num = stoi(word);
			}
			if (counter == 14) //tail
			{
				if (word == "1")
					tail_status = true;
				if (word == "0")
					tail_status = false;
			}
			if (counter == 15) //domestic
			{
				if (word == "1")
					domestic_status = true;
				if (word == "0")
					domestic_status = false;
			}
			if (counter == 17) //checks if its mammal, bird or fish
			{
				if (word[0] == '1')
					species = "mammal";
				if (word[0] == '2')
					species = "bird";
				if (word[0] == '4')
					species = "fish";
			}
			counter++;
		}
		
		if (species == "mammal")
		{
			Mammal* mam = new Mammal(animal_name, domestic_status, predator_status);
			if(hair_status)
				mam->setHair();
			if(airborne_status)
				mam->setAirborne();
			if(aquatic_status)
				mam->setAquatic();
			if(teeth_status)
				mam->setToothed();
			if(fins_status)
				mam->setFins();
			if(tail_status)
				mam->setTail();
			mam->setLegs(legs_num);
			
			insert(getLength(), mam);
		}
		
		if (species == "bird")
		{
			Bird* birdy = new Bird(animal_name, domestic_status, predator_status);
			if(airborne_status)
				birdy->setAirborne();
			if(aquatic_status)
				birdy->setAquatic();
			
			insert(getLength(), birdy);
		}
		
		if (species == "fish")
		{
			Fish* fishy = new Fish(animal_name, domestic_status, predator_status);
			if(venomous_status)
				fishy->setVenomous();
		
			insert(getLength(),fishy);
		}
		
		
		
	}
}

void ZooRecord::clear()
{
  Node<Animal*>* node_to_delete = first_;
  while (first_ != nullptr)
  {
    first_ = first_->getNext();
    
    // Return node to the system
    node_to_delete->setNext(nullptr);
    node_to_delete->setPrevious(nullptr);
    delete node_to_delete;
    
    node_to_delete = first_;
  }  // end while
  // head_ptr_ is nullptr; node_to_delete is nullptr
  last_ = nullptr;
  item_count_ = 0;
}

bool ZooRecord::remove(size_t position)
{
  //get pointer to position
  Node<Animal*>* pos_ptr = getPointerTo(position);
  
  if(pos_ptr == nullptr)
    return false;
  else
  {
    // Remove node from chain
    
    if (pos_ptr == first_)
    {
      // Remove first node
      first_ = pos_ptr->getNext();
      first_->setPrevious(nullptr);
      
      // Return node to the system
      pos_ptr->setNext(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
    }
    else if (pos_ptr == last_)
    {
      //remove last node
      last_ = pos_ptr->getPrevious();
      last_->setNext(nullptr);
      
      // Return node to the system
      pos_ptr->setPrevious(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
      
    }
    else
    {
      //Remove from the middle
      pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
      pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());
      
      // Return node to the system
      pos_ptr->setNext(nullptr);
      pos_ptr->setPrevious(nullptr);
      delete pos_ptr;
      pos_ptr = nullptr;
      
    }
    
    item_count_--;  // decrease count of entries
    return true;
  }
  
}

/**@post displays all animals in record, one per line by calling appropriate
object’s display method” **/
void ZooRecord::display()
{
	for(int i =0; i < getLength(); i++)
	{
	  try
	  {
	    getItem(i)->display();
	  }
	  catch(const PrecondViolatedExcep& err)
	  {
	    cout << err.what() << endl;
	  }
	}
}

