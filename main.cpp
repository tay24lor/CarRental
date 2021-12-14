#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "car.h"

void PrintMenu();

void ExecuteMenu(char option, vector<Car>& theCars);


void addCar(vector<Car>& cars);
void deleteCar(vector<Car>& cars);
void updateCarCondition(vector<Car>& cars);
void displayCar(vector<Car>& cars);
void displayAllCars(vector<Car>& cars);
bool rentCar(vector<Car>& cars);
bool returnCar(vector<Car>& cars);

int main()
{
    char option;
    vector<Car> cars;

    do {
        PrintMenu();
        do {
            cout << "Choose an option:" << endl << endl;
            cin >> option;
        } while (option != 'a' && option != 'd' && option != 'u' && option != 's' && option != 'i' &&
            option != 'c' && option != 'r' && option != 'q');
        cin.ignore();
        ExecuteMenu(option, cars);
    } while (option != 'q');

    return 0;

}

void PrintMenu() {
    cout << "CAR RENTAL AGENCY MENU" << endl;
    cout << "a - Add car to inventory" << endl;
    cout << "d - Delete car by id from inventory" << endl;
    cout << "u - Update car by id condition in inventory" << endl;
    cout << "s - Display one car by id from inventory" << endl;
    cout << "i - Display list of all cars in inventory" << endl;
    cout << "c - Rent a car by id in inventory" << endl;
    cout << "r - Return a car by id to inventory" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, vector<Car>& theCars) {

    switch (option) {

    case 'a': // - Add car to inventory

        addCar(theCars);

        break;

    case 'd': // - Delete car by id from inventory

        deleteCar(theCars);

        break;

    case 'u': // - Update car by id condition in inventory

        updateCarCondition(theCars);

        break;

    case 's': // - Display one car by id from inventory

        displayCar(theCars);

        break;

    case 'i': // - Display list of all cars in inventory

        displayAllCars(theCars);

        break;

    case 'c': // - Rent a car by id in inventory

        rentCar(theCars);

        break;

    case 'r': // - Return a car by id to inventory

        returnCar(theCars);

        break;

    case 'q': // - Quit

        cout << "Done" << endl;

        break;

    default:  // - invalid input

        break;
    }
}

void addCar(vector<Car>& cars) {
    int id;
    std::string make;
    std::string model;
    int year;
    std::string condition;

    cout << "ADD CAR TO INVENTORY" << endl;
    cout << "Enter an ID:" << endl;
    cin >> id;
    cout << "Enter the make:" << endl;
    cin >> make;
    cout << "Enter the model:" << endl;
    cin >> model;
    cout << "Enter the year:" << endl;
    cin >> year;
    cout << "Enter the condition (new, slightly_used, used):" << endl;
    cin >> condition;
    cout << endl;
    Car car = Car(id, make, model, year, condition);
    cars.push_back(car);
}

void deleteCar(vector<Car>& cars) {
    int carID;

    cout << "REMOVE CAR FROM INVENTORY" << endl;
    cout << "Enter the ID of the car to delete:" << endl << endl;
    cin >> carID;

    bool found = false;

    for (unsigned int i = 0; i < cars.size(); ++i) {

        if (cars[i].getID() == carID) {
            cars.erase(cars.begin() + i);
            found = true;
            break;
        }
    }
}

void updateCarCondition(vector<Car>& cars) {
    int carID;
    std::string condition;

    cout << "UPDATE CAR CONDITION IN INVENTORY" << endl;
    cout << "Enter the ID of the car to update condition:" << endl;
    cin >> carID;
    cout << "Enter the condition (new, slightly_used, used):" << endl << endl;
    cin >> condition;
    bool found = false;

    for (unsigned int i = 0; i < cars.size(); ++i) {

        if (cars[i].getID() == carID) {
            cars[i].setCondition(condition);
            found = true;
            break;
        }
    }
}

void displayCar(vector<Car>& cars) {
    int carID;

    cout << "DISPLAY CAR IN INVENTORY" << endl;
    cout << "Enter the ID of the car to display:" << endl << endl;
    cin >> carID;
    bool found = false;

    for (unsigned int i = 0; i < cars.size(); ++i) {

        if (cars[i].getID() == carID) {
            cars[i].displayCar();
            found = true;
            break;
        }
    }
    cout << endl;
}

void displayAllCars(vector<Car>& cars) {
    cout << "DISPLAY ALL CARS IN INVENTORY" << endl;

    for (unsigned int i = 0; i < cars.size(); ++i) {
        cars[i].displayCar();
    }
    cout << endl;
}

bool rentCar(vector<Car>& cars) {
    int carID;

    cout << "RENT CAR IN INVENTORY" << endl;
    cout << "Enter the ID of the car to rent:" << endl << endl;
    cin >> carID;

    for (unsigned int i = 0; i < cars.size(); ++i) {

        if (cars[i].getID() == carID && cars[i].isRented() == false) {
            cout << "Car rented successfully" << endl << endl;
            cars[i].toggleRented();
            return true;
        }
        else if (cars[i].getID() == carID && cars[i].isRented() == true) {
            cout << "Car is already rented" << endl << endl;
            return false;
        }
        else {
            cout << "Car " << carID << " not found in inventory" << endl << endl;
            return false;
        }
    }
    return 0;
}
bool returnCar(vector<Car>& cars) {
    int carID;

    cout << "RETURN CAR TO INVENTORY" << endl;
    cout << "Enter the ID of the car to return:" << endl << endl;
    cin >> carID;

    for (unsigned int i = 0; i < cars.size(); ++i) {
        if (cars[i].getID() == carID && cars[i].isRented() == true) {
            cout << "Car returned successfully" << endl << endl;
            cars[i].toggleRented();
            return true;
        }
        else if (cars[i].getID() == carID && cars[i].isRented() == false) {
            cout << "Car has not been rented" << endl << endl;
            return false;
        }
        else {
            cout << "Car " << carID << " not found in inventory" << endl << endl;
            return false;
        }
    }

    return 0;
}