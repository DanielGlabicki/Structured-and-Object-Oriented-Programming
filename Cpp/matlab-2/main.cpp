#include "matlab.hpp"

// Wersje bibliotek standardowych znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c" (np. stdlib.h -> cstdlib).
#include <cstdlib>

int main() {
    int v[] = {1, 2, 3};
    print_vector(v, 3);

    return EXIT_SUCCESS;
}
