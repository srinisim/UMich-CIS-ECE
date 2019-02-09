#pragma once

//Programmer Name: Srinivas Simhan
//Program Name: Programming Assignment 2 - Program 1 [PrimaryClasses.h]
//Purpose of Program: This program will define the parent class (vehicle), along with two subclasses (truck & car)
//Last Modified Date: October 23, 2017
//Date Due: October 23, 2017

#ifndef PRIMARYCLASSES_H
#define PRIMARYCLASSES_H

#include <iostream>
using namespace std;

class vehicle
{
//Set Behaviors
public:
	vehicle() {
		age = 0;
		price = 0.0;
	}

	void setAge(int age) {
		this->age = age;
	}
	
	void setPrice(float price) {
		this->price = price;
	}

	int getAge() {
		return age;
	}

	int getPrice() {
		return price;
	}

//Set Attributes
private:
	int age;
	float price;
};

class car:public vehicle
{
//Set Behaviors
public:
	car() {
		setAge(0);
		setPrice(0.0);
		raceCarStatus = false;
	}

	void setRaceCarStatus(bool raceCarStatus) {
		this->raceCarStatus = raceCarStatus;
	}

	bool getRaceCarStatus() {
		return raceCarStatus;
	}

//Set Attributes
private:
	bool raceCarStatus;
};

class truck :public vehicle
{
//Set Behaviors
public:
	truck() {
		setAge(0);
		setPrice(0.0);
		dieselTypeStatus = false;
	}

	void setDieselTypeStatus(bool dieselTypeStatus) {
		this->dieselTypeStatus = dieselTypeStatus;
	}

	bool getDieselTypeStatus() {
		return dieselTypeStatus;
	}

//Set Attributes
private:
	bool dieselTypeStatus;
};

#endif