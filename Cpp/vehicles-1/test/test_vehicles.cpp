//
// Created by Daniel on 23/04/2023.
/// pamietac o uzpelnieniu gtest'a
#include "gtest/gtest.h"

#include "vehicles.hpp"

TEST(CarTest, getMaxSpeed){
    Car mazdunia ("JMZ", "Mazda", 105);

    EXPECT_EQ(mazdunia.get_max_speed(), 105);
}

TEST(BikeTest, getMaxSpeed){
    Bicycle meridka ("123", "Merida", 8);

    EXPECT_EQ(meridka.get_max_speed(), 24);
}

TEST(VehicleTest, toString){
    Car mazdunia ("JMZ", "Mazda", 105);

    EXPECT_EQ(to_string(mazdunia), "JMZ : Mazda");
}

TEST(VehicleAuxTest, computeMinTravelDuration){
    Car mazdunia ("JMZ", "Mazda", 105);

    EXPECT_EQ(compute_min_travel_duration_as_string(105, mazdunia), "1.000 h");
}

TEST(VehiclesAlgorithms, filter){
    Car mazdunia ("JMZ", "Mazda", 105);
    Car toyota ("KR 00001", "Toyota", 90);
    Bicycle meridka ("123", "Merida", 8);

    std::vector<Vehicle*> vehicles = {&mazdunia, &toyota, &meridka};

    std::function<bool(const Vehicle&)> faster_than_100kph = [](const Vehicle& vehicle){
        return vehicle.get_max_speed() > 100.0;
    };

    std::vector<Vehicle*> filtered_vehicles =
            filter_vehicles(vehicles.begin(),vehicles.end(), faster_than_100kph);

    ASSERT_EQ(filtered_vehicles.size(), 1U);
    EXPECT_EQ(filtered_vehicles[0]->get_brand(), mazdunia.get_brand());
}