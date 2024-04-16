//
// Created by Daniel on 27/04/2023.
//
#include "gtest/gtest.h"
#include "vehicles.hpp"

TEST(DriverAuxTest, assignVehicleToDriver){
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    vehicles.push_back(std::make_unique<Car>("JMZ", "Mazda", 105));
    vehicles.push_back(std::make_unique<Bicycle>("123", "Merida", 8));

    Driver d1("Daniel", Gender::Male);
    assign_vehicle_to_driver(vehicles, d1);

    ASSERT_EQ(vehicles.size(), 1U);
    EXPECT_EQ(d1.get_vehicle()->get_brand(), "Merida");
}