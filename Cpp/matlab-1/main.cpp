#include "matlab.hpp"

// Wersje bibliotek standardowych znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c" (np. stdlib.h -> cstdlib).
#include <cstdlib>

#include "matlab.hpp"

int main(void) {
    int v1[5] = {1, 2, 3, 4, 5};
    print_vector(v1, 5);
    return EXIT_SUCCESS;
}
