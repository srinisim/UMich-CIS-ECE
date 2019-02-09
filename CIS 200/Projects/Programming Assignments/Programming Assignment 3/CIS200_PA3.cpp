#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
	typedef enum { // u_int32
		North, //0
		South, //1
		East, //2
		West //3
	} Direction;

	//Vehicle Constructor
	Vehicle() {
		age = 0;
		price = 0.0;
		heading = North;
	}

	//Vehicle Age
	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
		cout << "Age is: " << age << endl;
	}

	//Vehicle Move
	void addMove(int distance) {
		this->distance += distance;
	}

	int getMove(){
		cout << "Distance Traveled: " << distance << endl;
		return distance;
	}

	//Vehicle Price
	void setPrice(float price) {
		this->price = price;
	}

	int getPrice() {
		cout << "Price is: " << price << endl;
		return price;
	}

	//Vehicle Turning
	int turnLeft() {
		int heading;

		cout << "Which direction are you facing?" << endl;
		cin >> heading;

		switch (heading) {
		case North:
			heading = West;
			cout << "Heading West" << endl;
			break;
		case South:
			heading = East;
			cout << "Heading East" << endl;
			break;
		case West:
			heading = South;
			cout << "Heading South" << endl;
			break;
		case East:
			heading = North;
			cout << "Heading North" << endl;
			break;
		}
		return heading;
		cout << "Heading: " << heading << endl;
	}

	int turnRight() {
		int heading;
		
		cout << "Which direction are you facing?" << endl;
		cin >> heading;
		
		switch (heading) {
		case North:
			heading = East;
			cout << "Heading East" << endl;
			break;
		case South:
			heading = West;
			cout << "Heading West" << endl;
			break;
		case West:
			heading = North;
			cout << "Heading North" << endl;
			break;
		case East:
			heading = South;
			cout << "Heading South" << endl;
			break;
		}		
		return heading;
		cout << "Heading: " << heading << endl;
	}

	//Vehicle Direction
	void setHeading(Direction dir) {
		heading = dir;
	}

	int getHeading() {
		cout << "Heading: " << heading << endl;
		return heading;
	}

	//Vehicle Enable
	void start() {
		isOff = false;
		isRunning = true;
		cout << "Vehicle is running" << endl;
	}

	void stop() {
		isRunning = false;
		isMoving = false;
		cout << "Vehicle has stopped" << endl;
	}

	void off() {
		isOff = true;
		cout << "Vehicle is off" << endl;
	}

	//Vehicle Speed
	void accelerate(float speed) {
		speed++;
		cout << "Vehicle has accelerated" << speed << endl;

	}

	void decelerate(float speed) {
		if (speed - 1 > 0)
			speed--;
		cout << "Vehicle has decelerated" << speed << endl;
	}

	int getSpeed(){
		return speed;
		cout << "Speed is: " << speed << endl;
	}

private:
	int age;
	int distance;
	float price;
	float speed = 0.0;
	bool isMoving;
	bool isRunning;
	bool isOff;
	Direction heading; //The direction the vehicle is heading
};

class LandVehicle : public Vehicle
{
public:
	//LandVehicle Constructor
	LandVehicle() {
		gear = 1;
		numOfPassengers = 0;
	}

	//LandVehicle Gear
	void setGear(bool isMoving, bool isRunning, bool isOff, int gear) {
		if (isOff == false && isRunning == true && isMoving == true) {
			this->gear = gear;
		}
		else {
			cout << "Vehicle is off, please start vehicle." << endl;
		}
	}

	int getGear() {
		return gear;
		cout << "Gear is: " << gear << endl;
	}

	//LandVehicle Passengers
	void setNumOfPassengers(int numOfPassengers) {
		numOfPassengers = numOfPassengers;
	}

	int getNumOfPassengers() {
		cout << "Number of Passengers: " << numOfPassengers << endl;
		return numOfPassengers;
	}

private:
	int gear = 1;
	int numOfPassengers = 0;
};

class Car : public LandVehicle
{
public:
	Car() {
		setAge(0);
		setPrice(0.0);
		setHeading(North);
		bool raceCarStatus = false;
		string color = "Black";
	}

	void setRaceCarStatus(bool raceCarStatus) {
		this->raceCarStatus = raceCarStatus;
	}

	bool getRaceCarStatus() {
		return raceCarStatus;
		cout << "Race Car Status: " << raceCarStatus << endl;
	}

	void setColor(string color) {
		this->color = color;
	}

	string getColor() {
		return color;
		cout << "Color: " << color << endl;
	}

	void setHandleCarChoice(Car *car) {
		string choice;
		cout << "What model of car to drive?";
		cin >> choice;
		cout << "Model of car: " << choice << endl;
	}

	private:
		bool raceCarStatus;
		string modelName;
		string color;
};

class Truck : public LandVehicle
{
public:
	Truck() {
		setAge(0);
		setPrice(0.0);
		dieselTypeStatus = false;
		cargoCapacityLbs = 0;
	}

	void setDieselTypeStatus(bool dieselTypeStatus) {
		this->dieselTypeStatus = dieselTypeStatus;
	}

	bool getDieselTypeStatus() {
		return dieselTypeStatus;
		cout << "Diesel Type Status: " << dieselTypeStatus << endl;
	}

	void loadCargo(int amount) {
		cargoCapacityLbs += amount;
	}

	void unloadCargo(int amount) {
		cargoCapacityLbs -= amount;
	}

	void unloadAllCargo() {
		cargoCapacityLbs = 0;
	}

private:
	bool dieselTypeStatus;
	int cargoCapacityLbs;
};

class Plane : public Vehicle {
public:
	Plane() {
		altitude = 0.0;
	}

	void takeOff() {
		altitude = 10000;
	}

	void land() {
		altitude = 0.0;
	}

private:
	float altitude;
};

class Boat : public Vehicle {
private:
	bool isDocked;

public:
	Boat() {
		isDocked = true;
	}

	void setTakeOff(bool isDocked) {
		this->isDocked = isDocked;
	}

	bool getTakeOff() {
		return isDocked;
		cout << "Is it docked: " << isDocked << endl;
	}
};

int main()
{
	Vehicle vehicle;
	Car car;
	Truck truck;
	Boat boat;
	Plane plane;
	string choice;

	//Main Questions
	// (set instructions for usage here)
	cout << "What is your vehicle of choice [car, truck, plane, boat]" << endl;
	cin >> choice;
	if (choice == "car") {
		bool loop = true;
		while (loop == true)
		{
			cout << "What action would you like to take?" << endl;
			cout << "0) End Trip" << endl;
			cout << "1) Set Age" << endl;
			cout << "2) Get Age" << endl;
			cout << "3) Move forward distance" << endl;
			cout << "4) Get distance traveled" << endl;
			cout << "5) Set Price" << endl;
			cout << "6) Get Price" << endl;
			cout << "7) Turn Left" << endl;
			cout << "8) Turn Right" << endl;
			cout << "9) Set Heading Direction" << endl;
			cout << "10) Get Heading Direction" << endl;
			cout << "11) Start Vehicle" << endl;
			cout << "12) Stop Vehicle" << endl;
			cout << "13) Off Vehicle" << endl;
			cout << "14) Accelerate Vehicle" << endl;
			cout << "15) Decelerate Vehicle" << endl;
			cout << "16) Get Speed" << endl;

			cout << "Enter Input: " << endl;
			int input;
			string s;
			cin >> input;

			switch (input) {
			case 0: //EXIT Object
				loop = false;
				break;

			case 1: //Set Age
				int age;
				cout << "Input Age: " << endl;
				cin >> age;
				car.setAge(age);
				break;

			case 2: //Get Age
				cout << car.getAge();
				break;

			case 3:	//Move Forward Distance
				int dist;
				cout << "Input Forward Distance: " << endl;
				cin >> dist;
				car.addMove(dist);
				break;

			case 4: //Get Distance Traveled
				car.getMove();
				break;

			case 5:	//Set Price
				float price;
				cout << "Input Price: " << endl;
				cin >> price;
				car.setAge(price);
				break;

			case 6: //Get Price
				cout << car.getPrice();
				break;

			case 7:	//Turn Left
				car.turnLeft();
				break;

			case 8: //Turn Right
				car.turnRight();
				break;

			case 9: //Set Heading Direction
				Vehicle::Direction x;
				cout << "Set Direction: " << endl;
				cin >> s;
				if (s == "North"){
					x = Vehicle::Direction::North;
					car.setHeading(x);
				}
				else if (s == "South"){
					x = Vehicle::Direction::South;
					car.setHeading(x);
				}
				else if (s == "East") {
					x = Vehicle::Direction::East;
					car.setHeading(x);
				}
				else if (s == "West") {
					x = Vehicle::Direction::West;
					car.setHeading(x);
				}
				else {
					cout << "Wrong Input" << endl;
				}
				break;

			case 10: //Get Heading Direction
				cout << car.getHeading();
				break;

			case 11: //Start Vehicle
				car.start();
				break;

			case 12: //Stop Vehicle
				car.stop(); 
				break;

			case 13: //Off Vehicle
				car.off(); 
				break;

			case 14: //Accelerate Vehicle
				float y;
				cout << "Input Acceleration Value: " << endl;
				cin >> y;
				car.accelerate(y);
				break;

			case 15: //Decelerate Vehicle
				float w;
				cout << "Input Deceleration Value: " << endl;
				cin >> w;
				car.decelerate(w);
				break;

			case 16: //Get Speed
				cout << car.getSpeed();
				break;
			}
		}
	}
	else if (choice == "truck") {
		bool loop = true;
		while (loop == true)
		{
			cout << "What action would you like to take?" << endl;
			cout << "0) End Trip" << endl;
			cout << "1) Set Age" << endl;
			cout << "2) Get Age" << endl;
			cout << "3) Move forward distance" << endl;
			cout << "4) Get distance traveled" << endl;
			cout << "5) Set Price" << endl;
			cout << "6) Get Price" << endl;
			cout << "7) Turn Left" << endl;
			cout << "8) Turn Right" << endl;
			cout << "9) Set Heading Direction" << endl;
			cout << "10) Get Heading Direction" << endl;
			cout << "11) Start Vehicle" << endl;
			cout << "12) Stop Vehicle" << endl;
			cout << "13) Off Vehicle" << endl;
			cout << "14) Accelerate Vehicle" << endl;
			cout << "15) Decelerate Vehicle" << endl;
			cout << "16) Get Speed" << endl;
			cout << "17) Set Gear" << endl;
			cout << "18) Get Gear" << endl;
			cout << "19) Set Number of Passengers" << endl;
			cout << "20) Get Number of Passengers" << endl;


			cout << "Enter Input: " << endl;
			int input;
			string s;
			cin >> input;

			switch (input) {
			case 0: //EXIT Object
				loop = false;
				break;

			case 1: //Set Age
				int age;
				cout << "Input Age: " << endl;
				cin >> age;
				truck.setAge(age);
				break;

			case 2: //Get Age
				cout << truck.getAge();
				break;

			case 3:	//Move Forward Distance
				int dist;
				cout << "Input Forward Distance: " << endl;
				cin >> dist;
				truck.addMove(dist);
				break;

			case 4: //Get Distance Traveled
				truck.getMove();
				break;

			case 5:	//Set Price
				float price;
				cout << "Input Price: " << endl;
				cin >> price;
				truck.setAge(price);
				break;

			case 6: //Get Price
				cout << truck.getPrice();
				break;

			case 7:	//Turn Left
				truck.turnLeft();
				break;

			case 8: //Turn Right
				truck.turnRight();
				break;

			case 9: //Set Heading Direction
				Vehicle::Direction x;
				cout << "Set Direction: " << endl;
				cin >> s;
				if (s == "North") {
					x = Vehicle::Direction::North;
					car.setHeading(x);
				}
				else if (s == "South") {
					x = Vehicle::Direction::South;
					car.setHeading(x);
				}
				else if (s == "East") {
					x = Vehicle::Direction::East;
					car.setHeading(x);
				}
				else if (s == "West") {
					x = Vehicle::Direction::West;
					car.setHeading(x);
				}
				else {
					cout << "Wrong Input" << endl;
				}
				break;

			case 10: //Get Heading Direction
				cout << truck.getHeading();
				break;

			case 11: //Start Vehicle
				truck.start();
				break;

			case 12: //Stop Vehicle
				truck.stop();
				break;

			case 13: //Off Vehicle
				truck.off();
				break;

			case 14: //Accelerate Vehicle
				float q;
				cout << "Input Acceleration Value: " << endl;
				cin >> q;
				truck.accelerate(q);
				break;

			case 15: //Decelerate Vehicle
				float y;
				cout << "Input Deceleration Value: " << endl;
				cin >> y;
				truck.decelerate(y);
				break;

			case 16: //Get Speed
				cout << truck.getSpeed();
				break;

			case 17: //Set Gear
				int a;
				cout << "Set Gear: " << endl;
				cin >> a;
				truck.setGear(true, true, false, a);
				break;
				
			case 18: //Get Gear
				cout << truck.getGear();
				break;

			case 19: //Set NumOfPassengers
				int b;
				cout << "Enter Number of Passengers: " << endl;;
				cin >> b;
				truck.setNumOfPassengers(b);
				break;

			case 20:
				truck.getNumOfPassengers();
				break;
			}
		}
	}
	else if (choice == "plane") {
		bool loop = true;
		while (loop == true)
		{
			cout << "What action would you like to take?" << endl;
			cout << "0) End Trip" << endl;
			cout << "1) Take Off" << endl;
			cout << "2) Land" << endl;

			cout << "Enter Input: " << endl;
			int input;
			string s;
			cin >> input;

			switch (input) {
			case 0: //EXIT Object
				loop = false;
				break;

			case 1: //Take Off
				plane.takeOff();
				cout << "Plane has taken off" << endl;
				break;

			case 2: //Land
				plane.land();
				cout << "Plane has landed" << endl;
				break;
			}
		}
	}
	else if (choice == "boat") {
		bool loop = true;
		while (loop == true)
		{
			cout << "What action would you like to take?" << endl;
			cout << "0) End Trip" << endl;
			cout << "1) Set Take Off" << endl;
			cout << "2) Get Take Off" << endl;

			cout << "Enter Input: " << endl;
			int input;
			string s;
			cin >> input;

			switch (input) {
			case 0: //EXIT Object
				loop = false;
				break;

			case 1: //Set Take Off
				bool e;
				cout << "Enter 'true' or 'false' for if boat has taken off" << endl;
				cin >> e;
				boat.setTakeOff(e);
				cout << "Boat has taken off: " << e << endl;
				break;

			case 2: //Get Take Off
				boat.getTakeOff();
				cout << "Boat has docked" << endl;
				break;
			}
		}
	}
	else {
		cout << "You entered an invalid vehcile entry. Please restart the program" << endl;
		return 1;
	}

	// Promise: At this point `vehicle` is a type of Vehicle

	return 0;
}