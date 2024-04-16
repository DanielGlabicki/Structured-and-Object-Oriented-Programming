#include "matlab.hpp"

// Wersje standardowych bibliotek znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c". Dołączając je, nie podajemy rozszerzenia ".h".
// Przykładowo: stdlib.h -> cstdlib
#include <cstdlib>

// Biblioteka <iostream> służy do obsługi strumieni wejścia/wyjścia (odpowiednik
// <stdio.h> w języku C).
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect v_sum(v1.size());

    /*for (std::size_t i = 0; i < v1.size(); i++) {
        v_sum.set_elem(i, v1.get_elem(i) + v2.get_elem(i));
    }*/
    std::transform(std::cbegin(v1),std::cend(v1),
                   std::cbegin(v2),std::begin(v_sum),
                   [](auto const& a, auto const& b)
                   { return a + b; });

    return v_sum;
}

void print_vector(int* v, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

/*MatVect::MatVect(std::size_t n){
    for (std::size_t i = 0; i < n; ++i){
        v_.push_back(0); /// v_[i]=0 zle!!!
    }
}

MatVect::MatVect(const std::vector<int>& v) {
    const std::size_t n = v.size();
    for (std::size_t i = 0; i < n; ++i){
        v_.push_back(v[i]);
    }/// czy tak tez moze byc? <- tak
}*/

double MatVect::norm() const {
    double sum = 0;
    for (auto e : v_){
        sum += e * e;
    }
    return sqrt(sum);
}

std::string to_string(const MatVect& v){
    std::ostringstream oss;
    for(const auto& e : v){
        oss << e << " ";
    }
    return oss.str();
}
