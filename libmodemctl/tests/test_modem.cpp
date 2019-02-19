#include <cassert>
#include "Modem.h"

int main(int argc, char **argv) {
    assert(!std::is_copy_constructible<Modem>::value);
    assert(!std::is_copy_assignable<Modem>::value);
}

