/*
Title: Project 2
Name: Tim Zhen
Description: The implementation for the Bird class
Date: 9/12/2019
*/

#include "Bird.hpp"
#include <iostream>
using namespace std;

Bird::Bird()
{
	airborne_ = false;
	aquatic_ = false;
}

Bird::Bird(string name, bool domestic, bool predator)
{
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
	airborne_ = false;
	aquatic_ = false;
}

bool Bird::isAirborne() const
{
	return airborne_;
}

bool Bird::isAquatic() const
{
	return aquatic_;
}

void Bird::setAirborne()
{
	airborne_ = !airborne_;
}

void Bird::setAquatic()
{
	aquatic_ = !aquatic_;
}
