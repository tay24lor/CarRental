#ifndef CAR_H_
#define CAR_H_

#include <string>

class Car {
public:

	// Constructor
	Car();
	Car(int id, std::string make, std::string model, int year, std::string condition);

	// Getters
	int			getID();                                // - returns the id of the car as an int
	std::string getMake();								// - returns the make of the car as a string
	std::string getModel();								// - returns the model of the car as a string
	int		    getYear();								// - returns the year of the car as an int
	std::string getCondition();							// - returns the condition of the car as a string
	bool	      isRented();								// - returns the value of rented as a bool

	// Setters
	void		setCondition(std::string condition);	// - takes a string for the conditionand assigns it to condition
	void		toggleRented();			// -  toggles the value of rented

	// Other
	void displayCar();

private:

	int			id;
	std::string make;
	std::string model;
	int			year;
	std::string condition;
	bool		rented;
};

#endif