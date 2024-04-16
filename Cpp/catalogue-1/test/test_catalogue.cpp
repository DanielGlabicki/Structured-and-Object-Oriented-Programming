//
// Created by Daniel on 20/04/2023.
//
#include "gtest/gtest.h"

#include "catalogue.hpp"

TEST(CatalogueTest, containsKeyIsNotPresent){
    Product p ("RB01", "Robot", 10.2);
    Catalogue c;

    EXPECT_FALSE(c.contains("RB01"));
}

TEST(CatalogueTest, containsKeyIsPresent){
    Product p ("RB01", "Robot", 10.2);
    Catalogue c;
    c.add_product(p);

    EXPECT_TRUE(c.contains("RB01"));
}

TEST(CatalogueTest, getProductsWithAppropriatePrice) {
    Product p1("X1", "Toy X1", 10.3);
    Product p2("X2", "Toy X2", 8.3);

    Catalogue catalogue(std::map<std::string, Product>{
            {p1.get_id(), p1},
            {p2.get_id(), p2},
    });

    std::function<bool (double)> predicate = [](double price) {
        return (price < 10.0);
    };
    auto filtered_products = catalogue.get_products_with_appropriate_price(predicate);

    ASSERT_EQ(filtered_products.size(), 1U);
    EXPECT_EQ(filtered_products[0].get_id(), p2.get_id());
}