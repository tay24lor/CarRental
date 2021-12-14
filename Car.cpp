#include <string>

#include "car.h"
#include <iostream>

// Constructor
Car::Car(int id, std::string make, std::string model, int year, std::string condition)
	: id(id), make(make), model(model), year(year), condition(condition) {
	rented = false;
}

// Getters
int			Car::getID() { return id; }

std::string Car::getMake() { return make; }

std::string Car::getModel() { return model; }

int			Car::getYear() { return year; }

std::string Car::getCondition() { return condition; }

bool	    Car::isRented() { return rented; }

// Setters
void		Car::setCondition(std::string userCondition) { condition = userCondition; }

void		Car::toggleRented() { rented = !rented; }

void		Car::displayCar() {
	if (rented == false) {
		std::cout << "ID: " << id << ", " << make << " " << model << ", " << year << ", " << condition << ", is available" << std::endl;
	}

	else {
		std::cout << "ID: " << id << ", " << make << " " << model << ", " << year << ", " << condition << ", is not available" << std::endl;
	}
}