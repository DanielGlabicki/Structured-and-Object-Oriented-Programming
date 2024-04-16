#include "matlab.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    int v[] = {1, 2, 3};
    print_vector(v, 3);

    Matrix m(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{4, 5}
    });

    std::cout << m.sum();

    return EXIT_SUCCESS;
}
