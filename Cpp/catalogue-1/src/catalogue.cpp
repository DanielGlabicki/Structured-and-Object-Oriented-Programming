//
// Created by Daniel on 20/04/2023.
//
#include "catalogue.hpp"

#include <iomanip>
#include <sstream>

std::string to_string(const Product& p){
    std::ostringstream oss;
    oss << p.get_name() << " [" << p.get_id() << "] : $"
            << std::setprecision(2) << std::fixed << p.get_price();
    return oss.str();
}

std::vector<Product> Catalogue::get_products_with_appropriate_price(
        std::function<bool(double)> cryt) const {

    std::vector<Product> products;

    for (const auto& entry : inventory_) {
        const auto& product = entry.second;
        if (cryt(product.get_price())) {
            products.push_back(product);
        }///funkcja "cryt" dopiero robiona jak sie jej bedzie potrzebowac
    }

    return products;
}