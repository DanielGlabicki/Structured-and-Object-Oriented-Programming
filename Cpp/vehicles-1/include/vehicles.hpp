//
// Created by Daniel on 23/04/2023.
//
#ifndef VECHICLES_1_VECHICLES_HPP
#define VECHICLES_1_VECHICLES_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <functional>

class Vehicle {
private:
    std::string id_;
    std::string brand_;

public:
    Vehicle(std::string id, std::string brand) :
    id_(id), brand_(brand) {}

    virtual ~Vehicle() {};

    std::string get_id()  const { return id_; }
    std::string get_brand() const { return brand_; }
    virtual double get_max_speed() const = 0;
};

class Car : public Vehicle {
private:
    double engine_hp_;
public:
    Car(std::string id, std::string brand, double engine_hp) :
    Vehicle(id, brand), engine_hp_(engine_hp) {}

    double get_max_speed() const override { return engine_hp_; }
};

class Bicycle : public Vehicle{
private:
    int n_gears_;
public:
    Bicycle(std::string id, std::string brand, int n_gears) :
    Vehicle(id, brand), n_gears_(n_gears) {}

    double get_max_speed() const override { return 3 * n_gears_ ;}
};

std::string to_string(const Vehicle& v);

double compute_min_travel_duration(double distance,const Vehicle& vehicle);

std::string compute_min_travel_duration_as_string(double distance,const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool (const Vehicle&)> predicate);

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

#endif //VECHICLES_1_VECHICLES_HPP