#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>
#include <vector>
#include <string>

void print_vector(int* v, std::size_t n);

class MatVect {
private:
    std::vector<int> v_;
public:
    MatVect(std::size_t n) : v_(n, 0) {};
    MatVect(const std::vector<int>& v) : v_(v) {};

    const int& operator[](std::size_t pos) const { return v_[pos]; }
    int& operator[](std::size_t pos) { return v_[pos]; }

    //int get_elem(const std::size_t pos) const {return v_[pos]; }
    //void set_elem(const std::size_t pos, int val){v_[pos] = val; }

    std::size_t size() const {return v_.size(); }
    double norm() const;

    std::vector<int>::iterator begin()  { return v_.begin(); }
    std::vector<int>::const_iterator begin() const  { return v_.cbegin(); }
    std::vector<int>::const_iterator end() const { return v_.cend(); }
    std::vector<int>::iterator end() { return v_.end(); }
    std::vector<int>::const_iterator cbegin() const { return v_.cbegin(); }
    std::vector<int>::const_iterator cend() const  { return v_.cend(); }
};

MatVect add_vectors(const MatVect& v1, const MatVect& v2);

std::string to_string(const MatVect& v);

#endif /* INCLUDE_MATLAB_HPP_ */
