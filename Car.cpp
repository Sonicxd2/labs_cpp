//
// Created by yaroslav on 09.03.19.
//

#include "Car.h"
#include <stdexcept>


void Car::move(int timeForMove) {
    double consumption = timeForMove * patrolConsumption;
    if (patrol >= consumption) {
        Vehicle::move(timeForMove);
        patrol -= consumption;
    } else {
        throw std::invalid_argument("Not enough fuel!");
    }
}

double Car::getPatrol() const {
    return patrol;
}

void Car::setPatrol(double patrol) {
    Car::patrol = patrol;
}

void Car::setPatrolConsumption(double patrolConsumption) {
    Car::patrolConsumption = patrolConsumption;
}

Car::Car(Car &target): Vehicle(target) {
    this->patrol = target.patrol;
    this->patrolConsumption = target.patrolConsumption;
}

Car::Car(): Vehicle() {

}