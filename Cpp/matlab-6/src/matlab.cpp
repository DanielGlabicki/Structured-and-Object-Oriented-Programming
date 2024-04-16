#include "matlab.hpp"

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

Matlab::Vector add_vectors(const Matlab::Vector& v1, const Matlab::Vector& v2) {
    Matlab::Vector v_sum(v1.size());

    std::transform(std::cbegin(v1),std::cend(v1),
                   std::cbegin(v2),std::begin(v_sum),
                   [](auto const& a, auto const& b)
                   { return a + b; });

    return v_sum;
}

Matlab::Matrix::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

void print_vector(int* v, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

double Matlab::Vector::norm() const {
    /*double sum = 0;
    for (auto e : v_){
        sum += e * e;
    }
    return sqrt(sum);*/

    return sqrt(std::accumulate(v_.begin(), v_.end(), 0.0,
                                [](double acc, double elem)
                                { return acc + elem * elem; }));
}

int Matlab::Vector::sum() {
    return std::accumulate(v_.begin(), v_.end(), 0);
}

std::string to_string(const Matlab::Vector& v){
    std::ostringstream oss;

    /*for(const auto& e : v){
        oss << e << " ";
    }
    return oss.str();*/

    oss << "[ ";
    for(auto it = v.begin(); it != v.end(); ++it){
        oss << *it << ((it != v.end() - 1) ? ", ": " ]");
    }
    return oss.str();
}

Matlab::Matrix add_matrices(const Matlab::Matrix& m1, const Matlab::Matrix& m2){
    Matlab::Matrix m(m1);

    std::transform(m1.begin(), m1.end(), m2.begin(), m.begin(), add_vectors);

    return m;
}

int Matlab::Matrix::sum() {
    return std::accumulate(matrix_[0].begin(), matrix_[matrix_.size()].end(), 0);
}

std::string Matlab::to_string(const Matlab::Matrix& m){
    std::string res;
    res = "[\n";
    /*for (std::size_t n_rows = 0; n_rows < m.size(); ++n_rows){
        res += to_string(m[n_rows]) + '\n';
    }
    res += ']';
    return res;*/
    int i = 0;
    for(auto it = m.begin(); it != m.end(); ++it){
        res += (it != m.end() - 1) ? ("  " + to_string(m[i]) + ",\n") : ("  " + to_string(m[i]) + "\n]");
        i++;
    }
    return res;
}
