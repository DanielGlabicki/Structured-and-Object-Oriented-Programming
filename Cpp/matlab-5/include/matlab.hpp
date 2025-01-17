#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

void print_vector(int* v, std::size_t n);

class MatVect {
private:
    std::vector<int> v_;
public:
    MatVect(std::size_t n = 3) : v_(n, 0) {}

    MatVect(const std::vector<int>& v) : v_(v) {}

    MatVect(const MatVect&) = default;

    const int& operator[](std::size_t pos) const { return v_[pos]; }
    int& operator[](std::size_t pos) { return v_[pos]; }

    std::size_t size() const {return v_.size(); }
    double norm() const;
    int sum();

    std::vector<int>::iterator begin()  { return v_.begin(); }
    std::vector<int>::const_iterator begin() const  { return v_.cbegin(); }
    std::vector<int>::const_iterator end() const { return v_.cend(); }
    std::vector<int>::iterator end() { return v_.end(); }
    std::vector<int>::const_iterator cbegin() const { return v_.cbegin(); }
    std::vector<int>::const_iterator cend() const  { return v_.cend(); }

};

class Matrix{
private:
    std::vector<MatVect> matrix_;
public:
    Matrix(std::size_t n_rows, std::size_t n_cols) :
     matrix_(n_rows, MatVect(n_cols)) {}

    Matrix(const std::vector<std::vector<int>>& m); ///: matrix_(m) {} <-pykloby?

    Matrix(const Matrix&) = default;

    std::size_t size() const { return matrix_.size(); }
    int sum();

    const MatVect& operator[](std::size_t pos) const { return matrix_[pos]; }
    MatVect& operator[](std::size_t pos) { return matrix_[pos]; }

    std::vector<MatVect>::iterator begin()  { return matrix_.begin(); }
    std::vector<MatVect>::const_iterator begin() const  { return matrix_.cbegin(); }
    std::vector<MatVect>::const_iterator end() const { return matrix_.cend(); }
    std::vector<MatVect>::iterator end() { return matrix_.end(); }
    std::vector<MatVect>::const_iterator cbegin() const { return matrix_.cbegin(); }
    std::vector<MatVect>::const_iterator cend() const  { return matrix_.cend(); }

};

MatVect add_vectors(const MatVect& v1, const MatVect& v2);

std::string to_string(const MatVect& v);

Matrix add_matrices(const Matrix& m1, const Matrix& m2);

std::string to_string(const Matrix& m);
#endif /* INCLUDE_MATLAB_HPP_ */
