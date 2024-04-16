//
// Created by Daniel on 20/04/2023.
//
#include "gtest/gtest.h"

#include "catalogue.hpp"

TEST(ProductTest, toString) {
    Product p ("RB01", "Robot", 10.2);
    std::string res = to_string(p);

    EXPECT_EQ(res, "Robot [RB01] : $10.20");
}

TEST(ProductTest, create){
    Product p ("RB01", "Robot", 10.2);

    EXPECT_EQ(p.get_id(), "RB01");
    EXPECT_EQ(p.get_name(), "Robot");
    EXPECT_EQ(p.get_price(), 10.2);
}