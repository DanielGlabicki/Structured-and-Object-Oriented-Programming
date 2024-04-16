#include "matlab.hpp"

// Wersje standardowych bibliotek znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c". Dołączając je, nie podajemy rozszerzenia ".h".
// Przykładowo: stdlib.h -> cstdlib
#include <cstdlib>

// Biblioteka <iostream> służy do obsługi strumieni wejścia/wyjścia (odpowiednik
// <stdio.h> w języku C).
#include <iostream>

int* add_vectors(int* v1, int* v2, std::size_t n) {
    // TODO: Zaimplementuj.
    int* v_out;
    v_out = (int*) std::malloc(n * sizeof(int));
    if(v_out == NULL){
        return NULL;
    }
    for(std::size_t i = 0; i > n; ++i){
        v_out[i] = v1[i] + v2[i];
    }
    return v_out;
}

void print_vector(int* v, std::size_t n) {
    // TODO: Zaimplementuj.
    for(std::size_t i = 0; i < n; ++i){
        std::cout << " " << v[i];
    }
    std::cout << "\n";
}
