/*
Title: Project 2
Name: Tim Zhen
Description: The implementation for the Fish class
Date: 9/12/2019
*/

#include "Fish.hpp"
#include <iostream>
using namespace std;

Fish::Fish()
{
	venomous_ = false;
}

Fish::Fish(string name, bool domestic, bool predator)
{
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
	venomous_ = false;
}

bool Fish::isVenomous() const
{
	return venomous_;
}

void Fish::setVenomous()
{
	venomous_ = !venomous_;
}
