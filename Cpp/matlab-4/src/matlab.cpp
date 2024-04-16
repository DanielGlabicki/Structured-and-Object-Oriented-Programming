#include "matlab.hpp"

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect v_sum(v1.size());

    std::transform(std::cbegin(v1),std::cend(v1),
                   std::cbegin(v2),std::begin(v_sum),
                   [](auto const& a, auto const& b)
                   { return a + b; });

    return v_sum;
}

Matrix::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

void print_vector(int* v, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

double MatVect::norm() const {
    /*double sum = 0;
    for (auto e : v_){
        sum += e * e;
    }
    return sqrt(sum);*/

    return sqrt(std::accumulate(v_.begin(), v_.end(), 0.0,
                                [](double acc, double elem)
                                { return acc + elem * elem; }));
}

int MatVect::sum() {
    int s = 0;
    std::accumulate(v_.begin(), v_.end(), s);
    return s;
}

std::string to_string(const MatVect& v){
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

Matrix add_matrices(const Matrix& m1, const Matrix& m2){
    Matrix m(m1.size(), (m1.size() == 0) ? 0 : m1[0].size()); ///dobre zabezpieczenie
    /*for (std::size_t i = 0; i < m1.size(); ++i){
        for (std::size_t j = 0; i < m1.size(); ++i){
            m[i][j] = m1[i][j] + m2[i][j];
        }
    }
    for(auto i : m){
        for(auto j : i){
            i[j] = m1[i][j] + m2[i][j]; ///i to nie int :(
        }
    }*/
    std::transform(m1.begin(), m1.end(), m2.begin(), m.begin(), add_vectors);

    return m;
}

int Matrix::sum() {
    int sum = 0;
    int i = 0;
    for (auto it : matrix_){
        sum += std::accumulate(matrix_[i].begin(), matrix_[i].end(), 0);
        i++;
    }
    return sum;
}

std::string to_string(const Matrix& m){
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
