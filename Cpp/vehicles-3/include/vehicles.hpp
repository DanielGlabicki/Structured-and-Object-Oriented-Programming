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
    std::int64_t vin_;
    inline static std::int64_t n_vin = 1;

public:
    Vehicle(std::string id, std::string brand) :
    id_(id), brand_(brand), vin_(n_vin++) {}

    Vehicle(const Vehicle&) = default;

    virtual ~Vehicle() = default;

    std::string get_id()  const { return id_; }
    std::string get_brand() const { return brand_; }
    virtual double get_max_speed() const = 0;
    std::int64_t get_vin() const { return vin_; }
    static void reset_vin_counter() { n_vin = 1; }
};

class Car : public Vehicle {
private:
    double engine_hp_;
public:
    Car(std::string id, std::string brand, double engine_hp) :
    Vehicle(id, brand), engine_hp_(engine_hp) {}

    Car(const Car&) = default;

    double get_max_speed() const override { return engine_hp_; }
};

class Bicycle : public Vehicle{
private:
    int n_gears_;
public:
    Bicycle(std::string id, std::string brand, int n_gears) :
    Vehicle(id, brand), n_gears_(n_gears) {}

    Bicycle(const Bicycle&) = default;

    double get_max_speed() const override { return 3 * n_gears_ ;}
};

enum class Gender {
    Male, Female
};

class Driver{
private:
    std::string name_;
    std::unique_ptr<Vehicle> vehicle_ptr_;
    Gender gender_;
public:
    Driver(std::string name, Gender gender) : Driver(name, nullptr, gender) {}

    Driver(std::string name, std::unique_ptr<Vehicle> vehicle_ptr, Gender gender) :
    name_(name), vehicle_ptr_(std::move(vehicle_ptr)), gender_(gender) {}

    Driver(Driver& other) = delete;
    Driver(Driver&& other) : name_(other.name_), vehicle_ptr_(std::move(other.vehicle_ptr_)), gender_(other.gender_) {}

    Driver& operator=(Driver& other) = delete;
    Driver& operator=(Driver&& other);

    void assign_vehicle(std::unique_ptr<Vehicle> vehicle_ptr) { vehicle_ptr_ = std::move(vehicle_ptr); }
    std::string get_name() const { return name_; }
    const Vehicle* get_vehicle() const { return vehicle_ptr_.get(); }
    Gender get_gender() { return gender_; } ///czm nie const?
};

std::string to_string(const Vehicle& v);

std::string to_string(const Driver& d);

double compute_min_travel_duration(double distance,const Vehicle& vehicle);

std::string compute_min_travel_duration_as_string(double distance,const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool (const Vehicle&)> predicate);

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner);
#endif //VECHICLES_1_VECHICLES_HPP