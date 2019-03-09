//
// Created by yaroslav on 09.03.19.
//

#include "Vehicle.h"
#include <exception>

void Vehicle::setCurrentVector(Vector *currentVector) {
    Vehicle::currentVector = currentVector;
}

void Vehicle::move(int timeForMove) {
    if (currentVector == nullptr) {
        throw std::invalid_argument("Current vector is not set.");
    }

    for (int i = 0; i < timeForMove; i++) {
        if (recording && (time % recordSpan == 0)) {
            recordVector.push_back(currentCoordinates);
        }
        time++;
        currentCoordinates = currentCoordinates + currentVector;
    }
}

void Vehicle::setRecording(bool recording) {
    Vehicle::recording = recording;
}

void Vehicle::setRecordSpan(int recordSpan) {
    Vehicle::recordSpan = recordSpan;
}

const std::vector<Vector> Vehicle::getRecordVector() const {
    return recordVector;
}

const Vector &Vehicle::getCurrentCoordinates() const {
    return currentCoordinates;
}

Vehicle::Vehicle() {}

Vehicle::Vehicle(Vehicle& target) {
    this->recordVector = target.recordVector;
    this->currentCoordinates = target.currentCoordinates;
    this->currentVector = target.currentVector;
    this->recordSpan = target.recordSpan;
    this->recording = target.recording;
    this->time = target.time;
}
