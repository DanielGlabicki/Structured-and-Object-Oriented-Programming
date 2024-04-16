//
// Created by Daniel on 23/04/2023.
//
#include "vehicles.hpp"


std::string to_string(const Vehicle& v){
    std::string res = v.get_id() + " : " + v.get_brand();
    return res;
}

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end){
    std::ostringstream oss;

    for(auto it = vehicles_begin; it != vehicles_end; ++it){
        oss << to_string(**it)  << std::endl;
    }

    return oss.str();
}

double compute_min_travel_duration(double distance,const Vehicle& vehicle){
    return distance / vehicle.get_max_speed();
}

std::string compute_min_travel_duration_as_string(double distance,const Vehicle& vehicle){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << compute_min_travel_duration(distance, vehicle) << " h";
    return oss.str();
}

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool (const Vehicle&)> predicate){
    std::vector<Vehicle*> vehicles_filtered;
    std::copy_if(vehicles_begin, vehicles_end,
                 std::back_inserter( vehicles_filtered),
                 [&predicate](const Vehicle* vehicle_ptr)
                 { return predicate(*vehicle_ptr); });
    return vehicles_filtered;
}

std::string to_string(const Driver& d){
    if(d.get_vehicle() == nullptr){
        return d.get_name() + " : [no vehicle]";
    }
    else{
        return d.get_name() + " : [" + to_string(*d.get_vehicle()) + "]";
    }
}

Driver& Driver::operator=(Driver&& other) {
    name_ = other.name_;
    vehicle_ptr_ = std::move(other.vehicle_ptr_);
    gender_ = other.gender_;

    return (*this);
}

void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner){
    if(vehicles.size() > 0) {
        owner.assign_vehicle(std::move(*(vehicles.end()-1)));
        vehicles.erase(vehicles.end()-1);
    } else {
        owner.assign_vehicle(nullptr);
    }
}