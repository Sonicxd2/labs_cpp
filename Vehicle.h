//
// Created by yaroslav on 09.03.19.
//

#ifndef TESTINGPLACE_VEHICLE_H
#define TESTINGPLACE_VEHICLE_H

#include "Vector.h"
#include  <vector>
#include <stdexcept>


class Vehicle {
private:
    int time = 0;
    bool recording = false;
    int recordSpan = 1;
    std::vector<Vector> recordVector;
protected:
    Vector currentCoordinates = Vector(0, 0, 0);
    Vector *currentVector;
public:
    virtual const Vector &getCurrentCoordinates() const;

    virtual void setCurrentVector(Vector *currentVector);

    virtual void move(int timeForMove);

    virtual void setRecording(bool recording);

    virtual void setRecordSpan(int recordSpan);

    virtual const std::vector<Vector> getRecordVector() const;

    Vehicle();

    Vehicle(Vehicle& target);
};


#endif //TESTINGPLACE_VEHICLE_H
