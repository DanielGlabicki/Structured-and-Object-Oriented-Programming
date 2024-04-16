//
// Created by Daniel on 20/04/2023.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>

#ifndef CATALOGUE_1_CATALOGUE_HPP
#define CATALOGUE_1_CATALOGUE_HPP

class Product{
private:
    std::string id_;
    std::string name_;
    double price_;

public:
    Product (std::string id, std::string name, double price) :
    id_(id), name_(name), price_(price) {}; ///TO JEST DOPIERO
    /// LISTA ININCJALIZACYJNA!!!!!!!!!!!!!!

    std::string get_id() const { return id_; };

    std::string get_name() const { return name_; };

    double get_price() const { return price_; };

};

class Catalogue{
private:
    std::map<std::string, Product> inventory_;

public:
    Catalogue (const std::map<std::string, Product>& inventory
    = std::map<std::string, Product> {}) :
    inventory_(inventory) {};
    ///bez domyslego nie bedzie mozna utworzyc obiektu w tym przypadku

    void add_product(const Product& product){ inventory_.emplace(product.get_id(), product); }
    ///mamy element "inventory_", który jest typu std::map, wiec mozna
    ///do niego uzyc fcji std::map::emplace

    bool contains(std::string id) const { return inventory_.find(id) != inventory_.end(); }

    std::vector<Product> get_products_with_appropriate_price(std::function<bool(double)> cryt) const;
};

std::string to_string(const Product& p);

#endif //CATALOGUE_1_CATALOGUE_HPP
