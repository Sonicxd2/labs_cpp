//
// Created by yaroslav on 09.03.19.
//
#include <ctime>
#include <iostream>
#include <functional>
#include "Car.h"


int main() {
    std::srand(unsigned(std::time(0)));
    Car car = Car();
    std::cout << "Автомобиль создан, так сказать" << '\n';
    car.setRecording(true);
    car.setRecordSpan(1);
    car.setPatrolConsumption(1);
    car.setCurrentVector(new Vector(1, 1, 1));
    try {
        car.move(123);
    } catch (std::invalid_argument &e) {
        std::cout << "Ааааа нада заправиться!111" << '\n';
    }
    int patrol = std::rand();
    car.setPatrol(patrol);
    std::cout << "Подзаправимся немного! Количество бензина: " << patrol << '\n';
    car.move(123);
    const std::vector<Vector> &vector = car.getRecordVector();
    car.move(1);
    std::cout << "Количество записей: " << vector.size();
}