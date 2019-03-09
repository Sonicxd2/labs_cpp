//
// Created by yaroslav on 09.03.19.
//

#ifndef TESTINGPLACE_CAR_H
#define TESTINGPLACE_CAR_H


#include "Vehicle.h"

class Car : public Vehicle {
private:
    double patrol = 0;
    double patrolConsumption = 0;
public:
    double getPatrol() const;

    void setPatrol(double patrol);

    void setPatrolConsumption(double patrolConsumption);

    Car();

    Car(Car &target);

    void move(int timeForMove) override;
};


#endif //TESTINGPLACE_CAR_H
