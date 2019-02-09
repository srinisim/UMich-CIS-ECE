//Programmer Name: Srinivas Simhan
//Program Name: Programming Assignment 2 - Program 1 [PA2_P1.cpp]
//Purpose of Program: This main file will test the parent class (vehicle), along with two subclasses (truck & car)
//Last Modified Date: October 23, 2017
//Date Due: October 23, 2017

#include <iostream>
#include "PrimaryClasses.h"

using namespace std;

void main() {
	vehicle v = vehicle();
	v.setAge(5);
	v.setPrice(4.69);
	v.getAge();
	v.getPrice();

	car c = car();
	c.setAge(6);
	c.setPrice(48.69);
	c.setRaceCarStatus(true);
	c.getAge();
	c.getPrice();
	c.getRaceCarStatus();

	
	truck t = truck();
	t.setAge(7);
	t.setPrice(459.69);
	t.setDieselTypeStatus(true);
	t.getAge();
	t.getPrice();
	t.getDieselTypeStatus();
}